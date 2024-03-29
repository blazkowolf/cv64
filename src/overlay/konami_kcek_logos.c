/**
 * File: konami_kcek_logos.c
 * Description: Handles the Konami / KCEK logo screen
 * Associated objects: 0x000E
 *
 * Mapped by the TLB? = No
 */

#include "objects/engine/konami_kcek_logos.h"
#include "cv64.h"
#include "gamestate.h"
#include "gfx/camera.h"
#include "gfx/figure.h"
#include "system_work.h"

cv64_ovl_konamilogo_func_t cv64_ovl_konamilogo_funcs[] = {
    cv64_ovl_konamilogo_init,
    cv64_ovl_konamilogo_fade_in,
    cv64_ovl_konamilogo_wait,
    cv64_ovl_konamilogo_fade_out,
    cv64_ovl_konamilogo_kcek_fade_in,
    cv64_ovl_konamilogo_kcek_wait,
    cv64_ovl_konamilogo_kcek_fade_out,
    object_doNothing
};

void cv64_ovl_konamilogo_entrypoint(cv64_ovl_konamilogo_t* self) {
    ENTER(self, cv64_ovl_konamilogo_funcs);
}

void cv64_ovl_konamilogo_check_btn_press(cv64_ovl_konamilogo_t* self) {
    if ((sys.controllers[0].buttons_pressed | sys.controllers[1].buttons_pressed |
         sys.controllers[2].buttons_pressed | sys.controllers[3].buttons_pressed) &
        (START_BUTTON | RECENTER_BUTTON)) {
        (*object_curLevel_goToFunc)(
            self->header.current_function, &self->header.function_info_ID, KONAMILOGO_KCEK_WAIT
        );
    }
}

void cv64_ovl_konamilogo_init(cv64_ovl_konamilogo_t* self) {
    cv64_object_func_inf_t* curFunc;
    cv64_model_inf_t* model = (*modelInfo_createRootNode)(FIG_TYPE_HUD_ELEMENT, common_camera_HUD);

    self->model                  = model;
    model->dlist                 = &KONAMI_LOGO_DL;
    model->assets_file_ID        = NI_ASSETS_KONAMI_KCEK_LOGOS;
    model->size.x                = 0.9975f;
    model->size.y                = 1.005f;
    sys.background_color.integer = 0x000000FF; // Black (opaque)
    BITS_SET(model->flags, FIG_FLAG_0800);
    model->primitive_color.integer = 0xFFFFFF00; // White (transparent)

    GO_TO_NEXT_FUNC(
        self, cv64_ovl_konamilogo_funcs, curFunc, (*object_curLevel_goToNextFuncAndClearTimer)
    );
}

void cv64_ovl_konamilogo_fade_in(cv64_ovl_konamilogo_t* self) {
    cv64_model_inf_t* model = self->model;

    if (model->primitive_color.a < 0xF3) {
        model->primitive_color.a += 0x0C;
    } else {
        model->primitive_color.a = 0xFF;
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
    }
    sys.background_color.r = model->primitive_color.a;
    sys.background_color.g = model->primitive_color.a;
    sys.background_color.b = model->primitive_color.a;
    cv64_ovl_konamilogo_check_btn_press(self);
}

void cv64_ovl_konamilogo_wait(cv64_ovl_konamilogo_t* self) {
    s32 timer = self->header.current_function[self->header.function_info_ID].timer;

    if (timer >= 169) {
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
        timer = self->header.current_function[self->header.function_info_ID].timer;
    }
    if (timer >= 21) {
        cv64_ovl_konamilogo_check_btn_press(self);
    }
}

void cv64_ovl_konamilogo_fade_out(cv64_ovl_konamilogo_t* self) {
    cv64_model_inf_t* model = self->model;

    if (model->primitive_color.a >= 0x0A) {
        model->primitive_color.a -= 0x09;
    } else {
        model->primitive_color.a = 0x00;
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
    }
    cv64_ovl_konamilogo_check_btn_press(self);
}

void cv64_ovl_konamilogo_kcek_fade_in(cv64_ovl_konamilogo_t* self) {
    cv64_model_inf_t* model = self->model;

    model->size.x = 0.995f;
    model->dlist  = &KCEK_LOGO_DL;
    if (model->primitive_color.a < 0xFC) {
        model->primitive_color.a += 0x03;
    } else {
        model->primitive_color.a = 0xFF;
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
    }
    cv64_ovl_konamilogo_check_btn_press(self);
}

void cv64_ovl_konamilogo_kcek_wait(cv64_ovl_konamilogo_t* self) {
    cv64_model_inf_t* model = self->model;

    model->size.x = 0.995f;
    if (model->primitive_color.a < 0xFC) {
        model->primitive_color.a += 0x03;
    } else {
        model->primitive_color.a = 0xFF;
    }
    model->dlist = &KCEK_LOGO_DL;
    if ((s32) self->header.current_function[self->header.function_info_ID].timer >= 97) {
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
    }
}

void cv64_ovl_konamilogo_kcek_fade_out(cv64_ovl_konamilogo_t* self) {
    cv64_model_inf_t* model = self->model;

    model->dlist = &KCEK_LOGO_DL;
    if (model->primitive_color.a >= 0x0D) {
        model->primitive_color.a -= 0x0C;
    } else {
        model->primitive_color.a = 0x00;
        (*gamestate_change)(GAMESTATE_INTRO_CUTSCENE);
    }
    sys.background_color.r = model->primitive_color.a;
    sys.background_color.g = model->primitive_color.a;
    sys.background_color.b = model->primitive_color.a;
}
