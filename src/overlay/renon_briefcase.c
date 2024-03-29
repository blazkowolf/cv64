/**
 * File: renon_briefcase.c
 * Description: Handles the small cutscene that shows the briefcase spinning
 *              prior to entering Renon's Shop
 * Associated objects: 0x213C
 *
 * Mapped by the TLB? = Yes
 */

#include "objects/menu/renon_briefcase.h"
#include "gfx/camera.h"
#include "sound.h"
#include "system_work.h"

// clang-format off

hierarchy cv64_ovl_renonbriefcase_hierarchy = {
    NI_ASSETS_RENON_BRIEFCASE,
    {
        // RENON_BRIEFCASE_LOWER_LID_DL
        { 0x060026E0, CREATE_NEXT_NODE,    { 0, 7, -75 } },
        // RENON_BRIEFCASE_UPPER_LID_DL
        { 0x06002A40, DONT_CREATE_SIBLING, { 0, 0, 0 } }
    }
};

// clang-format on

u32 cv64_ovl_renonbriefcase_open_anim_rot_data[] = {
    0x00000000, 0x00000000, 0x00000005, 0x0E400000, 0xB1C00000, ANIM_FLAG_LAST_KEYFRAME
};

cv64_ovl_renonbriefcase_func_t cv64_ovl_renonbriefcase_funcs[] = {
    cv64_ovl_renonbriefcase_init, cv64_ovl_renonbriefcase_loop, cv64_ovl_renonbriefcase_destroy
};

void cv64_ovl_renonbriefcase_entrypoint(cv64_ovl_renonbriefcase_t* self) {
    ENTER(self, cv64_ovl_renonbriefcase_funcs);
}

void cv64_ovl_renonbriefcase_init(cv64_ovl_renonbriefcase_t* self) {
    cv64_model_inf_t* model;
    animation_info* anim_info = &self->anim_info;
    u32 i;
    u32 unused;

    // `common_camera_8009B448` is unused on this cutscene
    (*camera_setParams)(common_camera_8009B448, 0);
    common_camera_8009B448->position.x = 0.0f;
    common_camera_8009B448->position.y = 0.0f;
    common_camera_8009B448->position.z = 100.0f;
    // clang-format off
    common_camera_8009B448->look_at_direction.x =
    common_camera_8009B448->look_at_direction.y =
    common_camera_8009B448->look_at_direction.z = 0.0f;
    // clang-format on

    // Initialize the cutscene's camera
    (*camera_setParams)(common_camera_8009B44C, 3);
    common_camera_8009B44C->position.x = 0.0f;
    common_camera_8009B44C->position.y = 0.0f;
    common_camera_8009B44C->position.z = 100.0f;
    // clang-format off
    common_camera_8009B44C->look_at_direction.x =
    common_camera_8009B44C->look_at_direction.y =
    common_camera_8009B44C->look_at_direction.z = 0.0f;
    // clang-format on

    // Create and setup the briefcase model
    self->model = (*modelInfo_buildHierarchy)(
        FIG_TYPE_0400 | FIG_TYPE_HIERARCHY_NODE,
        common_camera_8009B44C,
        &cv64_ovl_renonbriefcase_hierarchy
    );
    model = self->model;
    BITS_SET(model->flags, FIG_FLAG_0800 | FIG_FLAG_0080);
    model->primitive_color.integer = 0xFFFFFFFF;
    model->angle.pitch             = 0;
    model->angle.yaw               = 0x4000;
    model->angle.roll              = 0;
    model->size.x                  = 1.0f;
    model->size.y                  = 1.0f;
    model->size.z                  = 1.0f;
    model->position.x              = 0.0f;
    model->position.y              = 0.0f;
    model->position.z              = -292.0f;

    // clang-format off
    for (i = 0; i < ARRAY_COUNT(self->field_0x34); i++) { self->field_0x34[i] = 0; }
    // clang-format on

    self->current_cutscene_time    = 0;
    PLAY_SD_RENON_BRIEFCASE_SPIN_2 = FALSE;

    // Initialize briefcase animation
    (*animationInfo_create)(anim_info, RENON_BRIEFCASE_NUMBER_OF_LIMBS, 0);
    (*animationInfo_setParams)(
        anim_info, &cv64_ovl_renonbriefcase_open_anim_rot_data, RENON_BRIEFCASE_ANIM_SPEED
    );
    (*func_8000B774)(anim_info, model);

    (*fade_setSettings)(FADE_IN, 15, 0xFF, 0xFF, 0xFF);
    (*object_curLevel_goToNextFuncAndClearTimer)(
        self->header.current_function, &self->header.function_info_ID
    );
}

void cv64_ovl_renonbriefcase_loop(cv64_ovl_renonbriefcase_t* self) {
    cv64_model_inf_t* model = self->model;
    f32 volume;

    // Step 1. Briefcase is approaching the camera
    if (self->current_cutscene_time < 90.0) {
        // Move the briefcase towards the camera
        model->position.z -= ((model->position.z - 300.0f) / 90.0);

        // Rotate the briefcase in circles
        model->angle.pitch += 3640.88897705078125;
        model->angle.yaw += 2730.66673278808594;
        model->angle.roll -= 3640.88897705078125;

        // Play the "spinning" sound every third of a second
        if ((self->current_cutscene_time % 10) == 0) {
            // Update the sound's volume based on the briefcase's
            // proximity towards the camera
            volume = 1.0f -
                (*computeNormalizedPosition)(
                         (*vec3f_distance)(&model->position, &common_camera_8009B44C->position),
                         10.0f,
                         400.0f
                );

            // Unused since `PLAY_SD_RENON_BRIEFCASE_SPIN_2` is always set to `false`
            if (PLAY_SD_RENON_BRIEFCASE_SPIN_2) {
                (*func_800139D4)(SD_RENON_BRIEFCASE_SPIN_2, 0.0f, volume);
                PLAY_SD_RENON_BRIEFCASE_SPIN_2 = FALSE;
            } else {
                (*func_800139D4)(SD_RENON_BRIEFCASE_SPIN_1, 0.0f, volume);
                PLAY_SD_RENON_BRIEFCASE_SPIN_2 = TRUE;
            }
        }
    }

    // Step 2. Stop the briefcase after it reaches its destination
    if (self->current_cutscene_time == 90.0) {
        model->angle.pitch = 0;
        model->angle.yaw   = 0;
        model->angle.roll  = 0;
    }

    // Step 3. Play the "open briefcase" animation
    // The animation is set to play for 60 frames,
    // but it will only play for 19 frames on practice
    if ((u32) (self->current_cutscene_time - 90.0) <= 60.0) {
        (*func_8000B774)(&self->anim_info, model);
    }

    self->current_cutscene_time++;

    //  Step 4. Fade out and destroy the object
    if (self->current_cutscene_time == 93) {
        (*fade_setSettings)(FADE_OUT, 30, 0, 0, 0);
    }

    if (self->current_cutscene_time >= 109) {
        (*object_curLevel_goToNextFuncAndClearTimer)(
            self->header.current_function, &self->header.function_info_ID
        );
    }
}

void cv64_ovl_renonbriefcase_destroy(cv64_ovl_renonbriefcase_t* self) {
    sys.background_color.integer = 0x000000FF;
    self->header.destroy(self);
}
