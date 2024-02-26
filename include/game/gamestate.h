#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <ultra64.h>

#define NUM_GAMESTATES 11

// Forward declaration of `GameStateMgr`
struct GameStateMgr;

// clang-format off
typedef enum cv64_gamestate_id {
    GAMESTATE_KONAMI_LOGO     = 1,
    GAMESTATE_GAMEPLAY        = 2,
    GAMESTATE_GAME_OVER       = 3,
    GAMESTATE_STAGE_SELECT    = 4,
    GAMESTATE_INTRO_CUTSCENE  = 5,
    GAMESTATE_TITLE_SCREEN    = 6,
    GAMESTATE_DATA_MENU       = 7,
    GAMESTATE_OPTIONS_MENU    = 8,
    GAMESTATE_TITLE_DEMO      = 9,
    GAMESTATE_GAMENOTE_DELETE = 10,
    GAMESTATE_CREDITS         = 11
} cv64_gamestate_id_t;
// clang-format on

#define NUM_GSS_SLOTS 16
#define GSS_SLOT(flags, function_or_objID)                                     \
    ((flags << 24) | (s32) function_or_objID)

typedef struct {
    // Max delay before most of the code can be executed. Used for framerate
    // timing. 0 = 60fps, 1 = 30fps. Update rate.
    u32 code_execution_max_delay;
    void (*init_function)(struct GameStateMgr* self);
    s32 slots[NUM_GSS_SLOTS];
} gameState_settings_struct;

void gamestate_create(s32 gamestate_id);
void gamestate_change(s32 gamestate_id);
void end_frame(void);
extern void setup_background_color(void);
extern void setup_framebuffer(void);
extern void setup_rsp(Gfx**);
extern void setup_z_buffer(void);

#endif
