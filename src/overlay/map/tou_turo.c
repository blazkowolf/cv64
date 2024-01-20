/**
 * File: tou_turo.c
 * Description: Contains the code for objects exclusive to TOU TURO
 * (Room of Clocks)
 * Associated objects: 0x1224
 *
 * Mapped by the TLB? = No
 */

#include "cv64.h"
#include "sound.h"
#include "random.h"
#include "effect.h"
#include "objects/map/tou_turo/door.h"
#include "system_work.h"
#include "gfx/struct_47.h"
#include <ultra64.h>

void cv64_ovl_touturo_door_entrypoint(cv64_ovl_touturo_door_t* self) {
    ENTER(self, cv64_ovl_touturo_door_funcs);
}

void cv64_ovl_touturo_door_init(cv64_ovl_touturo_door_t* self) {
    s32 unused;
    cv64_actor_settings_t* settings = self->settings;
    cv64_model_inf_t* model;

    if (settings) {
    } // Needed for matching

    model = self->model =
        modelInfo_createRootNode(FIG_TYPE_STANDALONE, D_8018CDE0[0]);

    if (settings) {
    } // Needed for matching

    actor_model_set_pos_and_angle((cv64_actor_t*) self, model);
    model->flags |= (0x800 | 0x100);

    model->assets_file_ID = sys.map_assets_file_IDs[0];
    model->dlist = cv64_ovl_touturo_door_dlists[settings->variable_1];

    CV64_COLOR_RGBA_TO_U32(model->primitive_color) =
        CV64_COLOR_RGBA_TO_U32(sys.primitive_color);
    CV64_COLOR_RGBA_TO_U32(model->fog_color) =
        CV64_COLOR_RGBA_TO_U32(sys.background_color);

    self->header.ID |= OBJ_FLAG_STAGE_OBJECT;

    self->map_actor_model =
        getMapActorModelEntryFromArray(model->dlist, model->assets_file_ID);
    model->map_actor_model = self->map_actor_model;

    self->close_time = 30;

    (*object_curLevel_goToNextFuncAndClearTimer)(self->header.current_function,
                                                 &self->header.functionInfo_ID);
}

void cv64_ovl_touturo_door_loop(cv64_ovl_touturo_door_t* self) {
    cv64_actor_settings_t* settings = self->settings;
    cv64_model_inf_t* model = self->model;

    if ((*actor_checkSpawn)(self, settings->position.x, settings->position.y,
                            settings->position.z) != FALSE) {
        self->header.destroy(self);
        return;
    } else {
        CV64_COLOR_RGBA_TO_U32(model->primitive_color) =
            CV64_COLOR_RGBA_TO_U32(sys.primitive_color);
        CV64_COLOR_RGBA_TO_U32(model->fog_color) =
            CV64_COLOR_RGBA_TO_U32(sys.background_color);
        if (settings->variable_1 == 0) {
            ENTER(self, cv64_ovl_touturo_door_exit_funcs);
        } else {
            ENTER(self, cv64_ovl_touturo_door_entrance_funcs);
        }
    }
}

void cv64_ovl_touturo_door_exit_check_event_flags(
    cv64_ovl_touturo_door_t* self) {
    cv64_model_inf_t* model = self->model;

    if (sys.SaveStruct_gameplay.event_flags[EVENT_FLAG_ID_CLOCK_TOWER] &
            EVENT_FLAG_CLOCK_TOWER_DEFEATED_DEATH ||
        sys.SaveStruct_gameplay.event_flags[EVENT_FLAG_ID_CLOCK_TOWER] &
            EVENT_FLAG_CLOCK_TOWER_DEFEATED_ACTRISE) {
        model->position.y = 35.0f;
    } else {
        model->position.y = 0.0f;
    }
    (*object_curLevel_goToNextFuncAndClearTimer)(self->header.current_function,
                                                 &self->header.functionInfo_ID);
}

void cv64_ovl_touturo_door_entrance_check_event_flags(
    cv64_ovl_touturo_door_t* self) {
    cv64_model_inf_t* model = self->model;

    if (sys.SaveStruct_gameplay.event_flags[EVENT_FLAG_ID_MISC_STAGES] &
        EVENT_FLAG_MISC_STAGES_ENTERED_ROOM_OF_CLOCKS) {
        model->position.y = 6.0f;
        (*object_curLevel_goToFunc)(self->header.current_function,
                                    &self->header.functionInfo_ID,
                                    FUNC_801578FC);
    } else {
        sys.SaveStruct_gameplay.event_flags[EVENT_FLAG_ID_MISC_STAGES] |=
            EVENT_FLAG_MISC_STAGES_ENTERED_ROOM_OF_CLOCKS;
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.functionInfo_ID);
    }
}

void cv64_ovl_touturo_door_entrance_close_door(cv64_ovl_touturo_door_t* self) {
    s16 i;
    f32 rand_Z_pos;
    cv64_effect_t* effect;
    cv64_model_inf_t* model = self->model;

    model->position.y -=
        (0.8166666666666667 *
         (((self->close_time / 30.0f) * self->close_time) / 30.0f));
    self->close_time++;

    if (model->position.y <= 6.0f) {
        model->position.y = 6.0f;

        // Create dust effects when the door closes
        for (i = 0; i < 6; i++) {
            rand_Z_pos = ((*rand_f32)() * 40.0f) - 20.0f;

            effect = (*createEffectObjectUnderEffectMgr)(1, NULL, 0);

            if (model && func_8005B78C)
                ; // Needed for matching

            if (effect != NULL) {
                (*func_8005B78C)(effect, 3);
                (*effect_setPosition)(effect, model->position.x + 3.0f,
                                      model->position.y + 1.0f,
                                      model->position.z + rand_Z_pos, 8);
                (*effect_setScale)(effect, 0.3f, 0.2f, 0.3f, 8);
            }
        }

        (*play_sound_in_position)(SD_TOU_TURO_DOOR_CLOSE, &model->position);
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.functionInfo_ID);
    }
}
