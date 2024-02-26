#ifndef OBJECT_ID_H
#define OBJECT_ID_H

#define CV64_OBJECT_ID(kind, id) (((kind) << 8) | (id))

// clang-format off

/**
 * The flags that are part of the `ID` field of `cv64_object_hdr_t`, NOT
 * `field_0x02`. Used with `cv64_object_id_t`.
 */
typedef enum cv64_object_kind {
    OBJ_KIND_NONE         = 0x00,
    /**
     * Non-enemy map actors. Sometimes 0x18 is used as well.
     */
    OBJ_KIND_STAGE_OBJECT = 0x10,
    OBJ_KIND_MAP_OVERLAY  = 0x20,
    OBJ_KIND_DESTROY      = 0x80
} cv64_object_kind_t;

/**
 * Same as `cv64_object_kind_t` but with the additional zeroes, so that we can
 * use inside code
 */
typedef enum cv64_object_flag {
    OBJ_FLAG_NONE         = 0x0000,
    /**
     * Non-enemy map actors. Sometimes 0x18 is used as well.
     */
    OBJ_FLAG_STAGE_OBJECT = 0x1000,
    OBJ_FLAG_MAP_OVERLAY  = 0x2000,
    OBJ_FLAG_DESTROY      = 0x8000
} cv64_object_flag_t;

typedef enum cv64_object_id_raw {
    ID_GAMESTATEMGR                  = 0x001,
    ID_OBJECT_002                    = 0x002,
    ID_OBJECT_003                    = 0x003,
    ID_DMAMGR                        = 0x004,
    ID_GAMEPLAYMGR                   = 0x005,
    ID_MAP_OBJECT_PARENT             = 0x006,
    ID_PLAYER_CONTROLLER             = 0x007,
    ID_MAP_SETUP                     = 0x008,
    ID_ENEMY_PARENT                  = 0x009,
    ID_GAMENOTE_DELETE_MGR_CREATOR          = 0x00A,
    ID_GAMENOTE_DELETE                    = 0x00B,
    ID_GAMENOTE_DELETE_MGR                    = 0x00C,
    ID_KONAMI_KCEK_LOGOS_CREATOR                    = 0x00D,
    ID_KONAMI_KCEK_LOGOS             = 0x00E,
    ID_TITLE_SCREEN_TEXT_MGR                    = 0x00F,
    ID_OPENING_CREATOR                    = 0x010,
    ID_OPENING                    = 0x011,
    ID_TITLE_SCREEN_CREATOR                    = 0x012,
    ID_TITLE_SCREEN                    = 0x013,
    ID_FILE_SELECT_CREATOR                    = 0x014,
    ID_FILE_SELECT_MGR                    = 0x015,
    ID_OPTIONS_CREATOR                    = 0x016,
    ID_OPTIONS                    = 0x017,
    ID_TITLE_DEMO_CREATOR                    = 0x018,
    ID_TITLE_DEMO                    = 0x019,
    ID_CREDITSMGR_CREATOR                    = 0x01A,
    ID_CREDITSMGR                    = 0x01B,
    ID_OBJECT_01C                    = 0x01C,
    ID_GAME_OVER_CREATOR                    = 0x01D,
    ID_GAME_OVER                    = 0x01E,
    ID_OBJECT_01F                    = 0x01F,
    ID_OBJECT_020                    = 0x020,
    ID_OBJECT_021                    = 0x021,
    ID_OBJECT_022                    = 0x022,
    ID_OBJECT_023                    = 0x023,
    ID_OBJECT_024                    = 0x024,
    ID_OBJECT_025                    = 0x025,
    ID_OBJECT_026                    = 0x026,
    ID_OBJECT_027                    = 0x027,
    ID_OBJECT_028                    = 0x028,
    ID_OBJECT_029                    = 0x029,
    ID_CUTSCENEMGR                   = 0x02A,
    ID_OBJECT_02B                    = 0x02B,
    ID_OBJECT_02C                    = 0x02C,
    ID_OBJECT_02D                    = 0x02D,
    ID_OBJECT_02E                    = 0x02E,
    ID_OBJECT_02F                    = 0x02F,
    ID_OBJECT_030                    = 0x030,
    ID_OBJECT_031                    = 0x031,
    ID_OBJECT_032                    = 0x032,
    ID_OBJECT_033                    = 0x033,
    ID_OBJECT_034                    = 0x034,
    ID_OBJECT_035                    = 0x035,
    ID_OBJECT_036                    = 0x036,
    ID_OBJECT_037                    = 0x037,
    ID_OBJECT_038                    = 0x038,
    ID_OBJECT_039                    = 0x039,
    ID_OBJECT_03A                    = 0x03A,
    ID_OBJECT_03B                    = 0x03B,
    ID_OBJECT_03C                    = 0x03C,
    ID_OBJECT_03D                    = 0x03D,
    ID_OBJECT_03E                    = 0x03E,
    ID_OBJECT_03F                    = 0x03F,
    ID_OBJECT_040                    = 0x040,
    ID_OBJECT_041                    = 0x041,
    ID_OBJECT_042                    = 0x042,
    ID_OBJECT_043                    = 0x043,
    ID_OBJECT_044                    = 0x044,
    ID_OBJECT_045                    = 0x045,
    ID_OBJECT_046                    = 0x046,
    ID_OBJECT_047                    = 0x047,
    ID_OBJECT_048                    = 0x048,
    ID_OBJECT_049                    = 0x049,
    ID_OBJECT_04A                    = 0x04A,
    ID_OBJECT_04B                    = 0x04B,
    ID_OBJECT_04C                    = 0x04C,
    ID_OBJECT_04D                    = 0x04D,
    ID_OBJECT_04E                    = 0x04E,
    ID_OBJECT_04F                    = 0x04F,
    ID_OBJECT_050                    = 0x050,
    ID_OBJECT_051                    = 0x051,
    ID_OBJECT_052                    = 0x052,
    ID_OBJECT_053                    = 0x053,
    ID_OBJECT_054                    = 0x054,
    ID_OBJECT_055                    = 0x055,
    ID_OBJECT_056                    = 0x056,
    ID_OBJECT_057                    = 0x057,
    ID_OBJECT_058                    = 0x058,
    ID_OBJECT_059                    = 0x059,
    ID_OBJECT_05A                    = 0x05A,
    ID_OBJECT_05B                    = 0x05B,
    ID_OBJECT_05C                    = 0x05C,
    ID_CUTSCENE_FOREST_BLESSING      = 0x05D,
    ID_OBJECT_05E                    = 0x05E,
    ID_OBJECT_05F                    = 0x05F,
    ID_OBJECT_060                    = 0x060,
    ID_OBJECT_061                    = 0x061,
    ID_OBJECT_062                    = 0x062,
    ID_OBJECT_063                    = 0x063,
    ID_OBJECT_064                    = 0x064,
    ID_OBJECT_065                    = 0x065,
    ID_OBJECT_066                    = 0x066,
    ID_OBJECT_067                    = 0x067,
    ID_CUTSCENE_CREDITS              = 0x068,
    ID_OBJECT_069                    = 0x069,
    ID_CAMERAMGR                    = 0x06A,
    ID_OBJECT_06B                    = 0x06B,
    ID_PLAYER_CAMERA_CONTROLLER                    = 0x06C,
    ID_OBJECT_06D                    = 0x06D,
    ID_OBJECT_06E                       = 0x06E,
    ID_POINT_LIGHT                    = 0x06F,
    ID_REINHARDT                     = 0x070,
    ID_REINHARDT_ALT                 = 0x071,
    ID_REINHARDT_ATTACKMGR           = 0x072,
    ID_REINHARDT_DYNAMIC_SCARF       = 0x073,
    ID_CARRIE                        = 0x074,
    ID_CARRIE_ALT                    = 0x075,
    ID_CARRIE_ATTACKMGR              = 0x076,
    ID_CARRIE_DYNAMIC_SKIRT          = 0x077,
    ID_CARRIE_DYNAMIC_RIGHT_STRIP    = 0x078,
    ID_CARRIE_DYNAMIC_LEFT_STRIP     = 0x079,
    ID_OBJECT_07A                    = 0x07A,
    ID_OBJECT_07B                    = 0x07B,
    ID_OBJECT_07C                    = 0x07C,
    ID_OBJECT_07D                    = 0x07D,
    ID_OBJECT_07E                    = 0x07E,
    ID_OBJECT_07F                    = 0x07F,
    ID_OBJECT_080                    = 0x080,
    ID_OBJECT_081                    = 0x081,
    ID_OBJECT_082                    = 0x082,
    ID_OBJECT_083                    = 0x083,
    ID_OBJECT_084                    = 0x084,
    ID_OBJECT_085                    = 0x085,
    ID_OBJECT_086                    = 0x086,
    ID_OBJECT_087                    = 0x087,
    ID_OBJECT_088                    = 0x088,
    ID_OBJECT_089                    = 0x089,
    ID_OBJECT_08A                    = 0x08A,
    ID_OBJECT_08B                    = 0x08B,
    ID_OBJECT_08C                    = 0x08C,
    ID_OBJECT_08D                    = 0x08D,
    ID_OBJECT_08E                    = 0x08E,
    ID_OBJECT_08F                    = 0x08F,
    ID_GARDENER                      = 0x090,
    ID_OBJECT_091                    = 0x091,
    ID_OBJECT_092                    = 0x092,
    ID_OBJECT_093                    = 0x093,
    ID_OBJECT_094                    = 0x094,
    ID_OBJECT_095                    = 0x095,
    ID_OBJECT_096                    = 0x096,
    ID_OBJECT_097                    = 0x097,
    ID_OBJECT_098                    = 0x098,
    ID_OBJECT_099                    = 0x099,
    ID_OBJECT_09A                    = 0x09A,
    ID_OBJECT_09B                    = 0x09B,
    ID_OBJECT_09C                    = 0x09C,
    ID_OBJECT_09D                    = 0x09D,
    ID_OBJECT_09E                    = 0x09E,
    ID_OBJECT_09F                    = 0x09F,
    ID_OBJECT_0A0                    = 0x0A0,
    ID_OBJECT_0A1                    = 0x0A1,
    ID_OBJECT_0A2                    = 0x0A2,
    ID_OBJECT_0A3                    = 0x0A3,
    ID_OBJECT_0A4                    = 0x0A4,
    ID_OBJECT_0A5                    = 0x0A5,
    ID_OBJECT_0A6                    = 0x0A6,
    ID_OBJECT_0A7                    = 0x0A7,
    ID_OBJECT_0A8                    = 0x0A8,
    ID_OBJECT_0A9                    = 0x0A9,
    ID_OBJECT_0AA                    = 0x0AA,
    ID_OBJECT_0AB                    = 0x0AB,
    ID_OBJECT_0AC                    = 0x0AC,
    ID_OBJECT_0AD                    = 0x0AD,
    ID_OBJECT_0AE                    = 0x0AE,
    ID_OBJECT_0AF                    = 0x0AF,
    ID_OBJECT_0B0                    = 0x0B0,
    ID_OBJECT_0B1                    = 0x0B1,
    ID_OBJECT_0B2                    = 0x0B2,
    ID_OBJECT_0B3                    = 0x0B3,
    ID_OBJECT_0B4                    = 0x0B4,
    ID_OBJECT_0B5                    = 0x0B5,
    ID_OBJECT_0B6                    = 0x0B6,
    ID_OBJECT_0B7                    = 0x0B7,
    ID_OBJECT_0B8                    = 0x0B8,
    ID_OBJECT_0B9                    = 0x0B9,
    ID_OBJECT_0BA                    = 0x0BA,
    ID_OBJECT_0BB                    = 0x0BB,
    ID_OBJECT_0BC                    = 0x0BC,
    ID_OBJECT_0BD                    = 0x0BD,
    ID_OBJECT_0BE                    = 0x0BE,
    ID_OBJECT_0BF                    = 0x0BF,
    ID_OBJECT_0C0                    = 0x0C0,
    ID_OBJECT_0C1                    = 0x0C1,
    ID_OBJECT_0C2                    = 0x0C2,
    ID_OBJECT_0C3                    = 0x0C3,
    ID_OBJECT_0C4                    = 0x0C4,
    ID_OBJECT_0C5                    = 0x0C5,
    ID_OBJECT_0C6                    = 0x0C6,
    ID_OBJECT_0C7                    = 0x0C7,
    ID_OBJECT_0C8                    = 0x0C8,
    ID_OBJECT_0C9                    = 0x0C9,
    ID_OBJECT_0CA                    = 0x0CA,
    ID_OBJECT_0CB                    = 0x0CB,
    ID_OBJECT_0CC                    = 0x0CC,
    ID_OBJECT_0CD                    = 0x0CD,
    ID_OBJECT_0CE                    = 0x0CE,
    ID_OBJECT_0CF                    = 0x0CF,
    ID_OBJECT_0D0                    = 0x0D0,
    ID_OBJECT_0D1                    = 0x0D1,
    ID_OBJECT_0D2                    = 0x0D2,
    ID_OBJECT_0D3                    = 0x0D3,
    ID_OBJECT_0D4                    = 0x0D4,
    ID_OBJECT_0D5                    = 0x0D5,
    ID_OBJECT_0D6                    = 0x0D6,
    ID_OBJECT_0D7                    = 0x0D7,
    ID_OBJECT_0D8                    = 0x0D8,
    ID_OBJECT_0D9                    = 0x0D9,
    ID_OBJECT_0DA                    = 0x0DA,
    ID_OBJECT_0DB                    = 0x0DB,
    ID_OBJECT_0DC                    = 0x0DC,
    ID_OBJECT_0DD                    = 0x0DD,
    ID_OBJECT_0DE                    = 0x0DE,
    ID_OBJECT_0DF                    = 0x0DF,
    ID_OBJECT_0E0                    = 0x0E0,
    ID_OBJECT_0E1                    = 0x0E1,
    ID_OBJECT_0E2                    = 0x0E2,
    ID_OBJECT_0E3                    = 0x0E3,
    ID_OBJECT_0E4                    = 0x0E4,
    ID_OBJECT_0E5                    = 0x0E5,
    ID_OBJECT_0E6                    = 0x0E6,
    ID_OBJECT_0E7                    = 0x0E7,
    ID_OBJECT_0E8                    = 0x0E8,
    ID_OBJECT_0E9                    = 0x0E9,
    ID_OBJECT_0EA                    = 0x0EA,
    ID_OBJECT_0EB                    = 0x0EB,
    ID_OBJECT_0EC                    = 0x0EC,
    ID_OBJECT_0ED                    = 0x0ED,
    ID_OBJECT_0EE                    = 0x0EE,
    ID_OBJECT_0EF                    = 0x0EF,
    ID_OBJECT_0F0                    = 0x0F0,
    ID_OBJECT_0F1                    = 0x0F1,
    ID_OBJECT_0F2                    = 0x0F2,
    ID_OBJECT_0F3                    = 0x0F3,
    ID_OBJECT_0F4                    = 0x0F4,
    ID_OBJECT_0F5                    = 0x0F5,
    ID_OBJECT_0F6                    = 0x0F6,
    ID_OBJECT_0F7                    = 0x0F7,
    ID_OBJECT_0F8                    = 0x0F8,
    ID_OBJECT_0F9                    = 0x0F9,
    ID_OBJECT_0FA                    = 0x0FA,
    ID_OBJECT_0FB                    = 0x0FB,
    ID_OBJECT_0FC                    = 0x0FC,
    ID_OBJECT_0FD                    = 0x0FD,
    ID_OBJECT_0FE                    = 0x0FE,
    ID_OBJECT_0FF                    = 0x0FF,
    ID_OBJECT_100                    = 0x100,
    ID_OBJECT_101                    = 0x101,
    ID_OBJECT_102                    = 0x102,
    ID_OBJECT_103                    = 0x103,
    ID_OBJECT_104                    = 0x104,
    ID_OBJECT_105                    = 0x105,
    ID_OBJECT_106                    = 0x106,
    ID_OBJECT_107                    = 0x107,
    ID_OBJECT_108                    = 0x108,
    ID_OBJECT_109                    = 0x109,
    ID_OBJECT_10A                    = 0x10A,
    ID_OBJECT_10B                    = 0x10B,
    ID_OBJECT_10C                    = 0x10C,
    ID_OBJECT_10D                    = 0x10D,
    ID_OBJECT_10E                    = 0x10E,
    ID_OBJECT_10F                    = 0x10F,
    ID_OBJECT_110                    = 0x110,
    ID_OBJECT_111                    = 0x111,
    ID_OBJECT_112                    = 0x112,
    ID_OBJECT_113                    = 0x113,
    ID_OBJECT_114                    = 0x114,
    ID_OBJECT_115                    = 0x115,
    ID_OBJECT_116                    = 0x116,
    ID_OBJECT_117                    = 0x117,
    ID_OBJECT_118                    = 0x118,
    ID_OBJECT_119                    = 0x119,
    ID_OBJECT_11A                    = 0x11A,
    ID_OBJECT_11B                    = 0x11B,
    ID_OBJECT_11C                    = 0x11C,
    ID_OBJECT_11D                    = 0x11D,
    ID_OBJECT_11E                    = 0x11E,
    ID_OBJECT_11F                    = 0x11F,
    ID_OBJECT_120                    = 0x120,
    ID_OBJECT_121                    = 0x121,
    ID_OBJECT_122                    = 0x122,
    ID_OBJECT_123                    = 0x123,
    ID_OBJECT_124                    = 0x124,
    ID_OBJECT_125                    = 0x125,
    ID_GAMEPLAY_MENUMGR              = 0x126,
    ID_OBJECT_127                    = 0x127,
    ID_OBJECT_128                    = 0x128,
    ID_OBJECT_129                    = 0x129,
    ID_OBJECT_12A                    = 0x12A,
    ID_OBJECT_12B                    = 0x12B,
    ID_OBJECT_12C                    = 0x12C,
    ID_OBJECT_12D                    = 0x12D,
    ID_OBJECT_12E                    = 0x12E,
    ID_OBJECT_12F                    = 0x12F,
    ID_OBJECT_130                    = 0x130,
    ID_OBJECT_131                    = 0x131,
    ID_OBJECT_132                    = 0x132,
    ID_OBJECT_133                    = 0x133,
    ID_OBJECT_134                    = 0x134,
    ID_OBJECT_135                    = 0x135,
    ID_OBJECT_136                    = 0x136,
    ID_OBJECT_137                    = 0x137,
    ID_OBJECT_138                    = 0x138,
    ID_OBJECT_139                    = 0x139,
    ID_OBJECT_13A                    = 0x13A,
    ID_OBJECT_13B                    = 0x13B,
    ID_OBJECT_13C                    = 0x13C,
    ID_OBJECT_13D                    = 0x13D,
    ID_OBJECT_13E                    = 0x13E,
    ID_OBJECT_13F                    = 0x13F,
    ID_OBJECT_140                    = 0x140,
    ID_STAGE_SELECT                  = 0x141,
    ID_OBJECT_142                    = 0x142,
    ID_OBJECT_143                    = 0x143,
    ID_OBJECT_144                    = 0x144,
    ID_OBJECT_145                    = 0x145,
    ID_OBJECT_146                    = 0x146,
    ID_OBJECT_147                    = 0x147,
    ID_OBJECT_148                    = 0x148,
    ID_OBJECT_149                    = 0x149,
    ID_OBJECT_14A                    = 0x14A,
    ID_OBJECT_14B                    = 0x14B,
    ID_OBJECT_14C                    = 0x14C,
    ID_OBJECT_14D                    = 0x14D,
    ID_OBJECT_14E                    = 0x14E,
    ID_OBJECT_14F                    = 0x14F,
    ID_OBJECT_150                    = 0x150,
    ID_OBJECT_151                    = 0x151,
    ID_OBJECT_152                    = 0x152,
    ID_OBJECT_153                    = 0x153,
    ID_OBJECT_154                    = 0x154,
    ID_OBJECT_155                    = 0x155,
    ID_OBJECT_156                    = 0x156,
    ID_OBJECT_157                    = 0x157,
    ID_OBJECT_158                    = 0x158,
    ID_OBJECT_159                    = 0x159,
    ID_OBJECT_15A                    = 0x15A,
    ID_OBJECT_15B                    = 0x15B,
    ID_OBJECT_15C                    = 0x15C,
    ID_OBJECT_15D                    = 0x15D,
    ID_OBJECT_15E                    = 0x15E,
    ID_OBJECT_15F                    = 0x15F,
    ID_OBJECT_160                    = 0x160,
    ID_OBJECT_161                    = 0x161,
    ID_OBJECT_162                    = 0x162,
    ID_OBJECT_163                    = 0x163,
    ID_OBJECT_164                    = 0x164,
    ID_OBJECT_165                    = 0x165,
    ID_OBJECT_166                    = 0x166,
    ID_OBJECT_167                    = 0x167,
    ID_OBJECT_168                    = 0x168,
    ID_OBJECT_169                    = 0x169,
    ID_OBJECT_16A                    = 0x16A,
    ID_OBJECT_16B                    = 0x16B,
    ID_OBJECT_16C                    = 0x16C,
    ID_OBJECT_16D                    = 0x16D,
    ID_OBJECT_16E                    = 0x16E,
    ID_OBJECT_16F                    = 0x16F,
    ID_OBJECT_170                    = 0x170,
    ID_OBJECT_171                    = 0x171,
    ID_OBJECT_172                    = 0x172,
    ID_OBJECT_173                    = 0x173,
    ID_OBJECT_174                    = 0x174,
    ID_OBJECT_175                    = 0x175,
    ID_OBJECT_176                    = 0x176,
    ID_OBJECT_177                    = 0x177,
    ID_OBJECT_178                    = 0x178,
    ID_OBJECT_179                    = 0x179,
    ID_OBJECT_17A                    = 0x17A,
    ID_OBJECT_17B                    = 0x17B,
    ID_OBJECT_17C                    = 0x17C,
    ID_OBJECT_17D                    = 0x17D,
    ID_OBJECT_17E                    = 0x17E,
    ID_OBJECT_17F                    = 0x17F,
    ID_OBJECT_180                    = 0x180,
    ID_OBJECT_181                    = 0x181,
    ID_OBJECT_182                    = 0x182,
    ID_OBJECT_183                    = 0x183,
    ID_OBJECT_184                    = 0x184,
    ID_OBJECT_185                    = 0x185,
    ID_OBJECT_186                    = 0x186,
    ID_OBJECT_187                    = 0x187,
    ID_OBJECT_188                    = 0x188,
    ID_OBJECT_189                    = 0x189,
    ID_OBJECT_18A                    = 0x18A,
    ID_OBJECT_18B                    = 0x18B,
    ID_OBJECT_18C                    = 0x18C,
    ID_OBJECT_18D                    = 0x18D,
    ID_OBJECT_18E                    = 0x18E,
    ID_OBJECT_18F                    = 0x18F,
    ID_OBJECT_190                    = 0x190,
    ID_OBJECT_191                    = 0x191,
    ID_OBJECT_192                    = 0x192,
    ID_OBJECT_193                    = 0x193,
    ID_OBJECT_194                    = 0x194,
    ID_OBJECT_195                    = 0x195,
    ID_OBJECT_196                    = 0x196,
    ID_OBJECT_197                    = 0x197,
    ID_OBJECT_198                    = 0x198,
    ID_OBJECT_199                    = 0x199,
    ID_OBJECT_19A                    = 0x19A,
    ID_OBJECT_19B                    = 0x19B,
    ID_OBJECT_19C                    = 0x19C,
    ID_OBJECT_19D                    = 0x19D,
    ID_OBJECT_19E                    = 0x19E,
    ID_OBJECT_19F                    = 0x19F,
    ID_OBJECT_1A0                    = 0x1A0,
    ID_OBJECT_1A1                    = 0x1A1,
    ID_OBJECT_1A2                    = 0x1A2,
    ID_OBJECT_1A3                    = 0x1A3,
    ID_OBJECT_1A4                    = 0x1A4,
    ID_OBJECT_1A5                    = 0x1A5,
    ID_OBJECT_1A6                    = 0x1A6,
    ID_OBJECT_1A7                    = 0x1A7,
    ID_OBJECT_1A8                    = 0x1A8,
    ID_OBJECT_1A9                    = 0x1A9,
    ID_OBJECT_1AA                    = 0x1AA,
    ID_OBJECT_1AB                    = 0x1AB,
    ID_OBJECT_1AC                    = 0x1AC,
    ID_OBJECT_1AD                    = 0x1AD,
    ID_OBJECT_1AE                    = 0x1AE,
    ID_OBJECT_1AF                    = 0x1AF,
    ID_OBJECT_1B0                    = 0x1B0,
    ID_OBJECT_1B1                    = 0x1B1,
    ID_OBJECT_1B2                    = 0x1B2,
    ID_OBJECT_1B3                    = 0x1B3,
    ID_OBJECT_1B4                    = 0x1B4,
    ID_MEIRO_TEIEN_OBJ_01B5          = 0x1B5,
    ID_OBJECT_1B6                    = 0x1B6,
    ID_OBJECT_1B7                    = 0x1B7,
    ID_OBJECT_1B8                    = 0x1B8,
    ID_OBJECT_1B9                    = 0x1B9,
    ID_OBJECT_1BA                    = 0x1BA,
    ID_OBJECT_1BB                    = 0x1BB,
    ID_OBJECT_1BC                    = 0x1BC,
    ID_OBJECT_1BD                    = 0x1BD,
    ID_OBJECT_1BE                    = 0x1BE,
    ID_OBJECT_1BF                    = 0x1BF,
    ID_OBJECT_1C0                    = 0x1C0,
    ID_OBJECT_1C1                    = 0x1C1,
    ID_OBJECT_1C2                    = 0x1C2,
    ID_OBJECT_1C3                    = 0x1C3,
    ID_OBJECT_1C4                    = 0x1C4,
    ID_OBJECT_1C5                    = 0x1C5,
    ID_OBJECT_1C6                    = 0x1C6,
    ID_OBJECT_1C7                    = 0x1C7,
    ID_OBJECT_1C8                    = 0x1C8,
    ID_OBJECT_1C9                    = 0x1C9,
    ID_OBJECT_1CA                    = 0x1CA,
    ID_OBJECT_1CB                    = 0x1CB,
    ID_OBJECT_1CC                    = 0x1CC,
    ID_OBJECT_1CD                    = 0x1CD,
    ID_OBJECT_1CE                    = 0x1CE,
    ID_OBJECT_1CF                    = 0x1CF,
    ID_OBJECT_1D0                    = 0x1D0,
    ID_OBJECT_1D1                    = 0x1D1,
    ID_OBJECT_1D2                    = 0x1D2,
    ID_OBJECT_1D3                    = 0x1D3,
    ID_OBJECT_1D4                    = 0x1D4,
    ID_OBJECT_1D5                    = 0x1D5,
    ID_OBJECT_1D6                    = 0x1D6,
    ID_OBJECT_1D7                    = 0x1D7,
    ID_OBJECT_1D8                    = 0x1D8,
    ID_OBJECT_1D9                    = 0x1D9,
    ID_OBJECT_1DA                    = 0x1DA,
    ID_OBJECT_1DB                    = 0x1DB,
    ID_OBJECT_1DC                    = 0x1DC,
    ID_OBJECT_1DD                    = 0x1DD,
    ID_OBJECT_1DE                    = 0x1DE,
    ID_OBJECT_1DF                    = 0x1DF,
    ID_OBJECT_1E0                    = 0x1E0,
    ID_OBJECT_1E1                    = 0x1E1,
    ID_OBJECT_1E2                    = 0x1E2,
    ID_OBJECT_1E3                    = 0x1E3,
    ID_OBJECT_1E4                    = 0x1E4,
    ID_OBJECT_1E5                    = 0x1E5,
    ID_OBJECT_1E6                    = 0x1E6,
    ID_OBJECT_1E7                    = 0x1E7,
    ID_OBJECT_1E8                    = 0x1E8,
    ID_OBJECT_1E9                    = 0x1E9,
    ID_OBJECT_1EA                    = 0x1EA,
    ID_OBJECT_1EB                    = 0x1EB,
    ID_OBJECT_1EC                    = 0x1EC,
    ID_OBJECT_1ED                    = 0x1ED,
    ID_OBJECT_1EE                    = 0x1EE,
    ID_OBJECT_1EF                    = 0x1EF,
    ID_OBJECT_1F0                    = 0x1F0,
    ID_OBJECT_1F1                    = 0x1F1,
    ID_OBJECT_1F2                    = 0x1F2,
    ID_OBJECT_1F3                    = 0x1F3,
    ID_OBJECT_1F4                    = 0x1F4,
    ID_OBJECT_1F5                    = 0x1F5,
    ID_OBJECT_1F6                    = 0x1F6,
    ID_OBJECT_1F7                    = 0x1F7,
    ID_OBJECT_1F8                    = 0x1F8,
    ID_OBJECT_1F9                    = 0x1F9,
    ID_OBJECT_1FA                    = 0x1FA,
    ID_OBJECT_1FB                    = 0x1FB,
    ID_OBJECT_1FC                    = 0x1FC,
    ID_OBJECT_1FD                    = 0x1FD,
    ID_OBJECT_1FE                    = 0x1FE,
    ID_OBJECT_1FF                    = 0x1FF,
    ID_OBJECT_200                    = 0x200,
    ID_OBJECT_201                    = 0x201,
    ID_OBJECT_202                    = 0x202,
    ID_OBJECT_203                    = 0x203,
    ID_OBJECT_204                    = 0x204,
    ID_OBJECT_205                    = 0x205,
    ID_OBJECT_206                    = 0x206,
    ID_OBJECT_207                    = 0x207,
    ID_OBJECT_208                    = 0x208,
    ID_OBJECT_209                    = 0x209,
    ID_OBJECT_20A                    = 0x20A,
    ID_OBJECT_20B                    = 0x20B,
    ID_OBJECT_20C                    = 0x20C,
    ID_OBJECT_20D                    = 0x20D,
    ID_OBJECT_20E                    = 0x20E,
    ID_OBJECT_20F                    = 0x20F,
    ID_OBJECT_210                    = 0x210,
    ID_OBJECT_211                    = 0x211,
    ID_OBJECT_212                    = 0x212,
    ID_OBJECT_213                    = 0x213,
    ID_OBJECT_214                    = 0x214,
    ID_OBJECT_215                    = 0x215,
    ID_OBJECT_216                    = 0x216,
    ID_OBJECT_217                    = 0x217,
    ID_OBJECT_218                    = 0x218,
    ID_OBJECT_219                    = 0x219,
    ID_OBJECT_21A                    = 0x21A,
    ID_OBJECT_21B                    = 0x21B,
    ID_OBJECT_21C                    = 0x21C,
    ID_OBJECT_21D                    = 0x21D,
    ID_OBJECT_21E                    = 0x21E,
    ID_OBJECT_21F                    = 0x21F,
    ID_ROSE_VENTILATOR               = 0x220,
    ID_ROSE_DOOR                     = 0x221,
    ID_OBJECT_222                    = 0x222,
    ID_OBJECT_223                    = 0x223,
    ID_OBJECT_224                    = 0x224,
    ID_OBJECT_225                    = 0x225,
    ID_OBJECT_226                    = 0x226,
    ID_OBJECT_227                    = 0x227,
    ID_OBJECT_228                    = 0x228,
    ID_OBJECT_229                    = 0x229,
    ID_OBJECT_22A                    = 0x22A
} cv64_object_id_raw_t;

typedef enum cv64_object_id {
    ENGINE_GAMESTATEMGR               = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMESTATEMGR),
    ENGINE_OBJ_002                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_002),
    ENGINE_OBJ_003                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_003),
    ENGINE_DMAMGR                     = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_DMAMGR),
    ENGINE_GAMEPLAYMGR                = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMEPLAYMGR),
    ENGINE_MAP_OBJECT_PARENT          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_MAP_OBJECT_PARENT),
    ENGINE_PLAYER_CONTROLLER          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_PLAYER_CONTROLLER),
    ENGINE_MAP_SETUP                  = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_MAP_SETUP),
    ENGINE_ENEMY_PARENT               = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_ENEMY_PARENT),
    ENGINE_GAMENOTE_DELETE_MGR_CREATOR    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMENOTE_DELETE_MGR_CREATOR),
    ENGINE_GAMENOTE_DELETE    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMENOTE_DELETE),
    ENGINE_GAMENOTE_DELETE_MGR    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMENOTE_DELETE_MGR),
    ENGINE_KONAMI_KCEK_LOGOS_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_KONAMI_KCEK_LOGOS_CREATOR),
    ENGINE_KONAMI_KCEK_LOGOS          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_KONAMI_KCEK_LOGOS),
    ENGINE_TITLE_SCREEN_TEXT_MGR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_TITLE_SCREEN_TEXT_MGR),
    ENGINE_OPENING_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OPENING_CREATOR),
    ENGINE_OPENING          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OPENING),
    ENGINE_TITLE_SCREEN_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_TITLE_SCREEN_CREATOR),
    ENGINE_TITLE_SCREEN          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_TITLE_SCREEN),
    ENGINE_FILE_SELECT_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_FILE_SELECT_CREATOR),
    ENGINE_FILE_SELECT_MGR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_FILE_SELECT_MGR),
    ENGINE_OPTIONS_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OPTIONS_CREATOR),
    ENGINE_OPTIONS          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OPTIONS),
    ENGINE_TITLE_DEMO_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_TITLE_DEMO_CREATOR),
    ENGINE_TITLE_DEMO          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_TITLE_DEMO),
    ENGINE_CREDITSMGR_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CREDITSMGR_CREATOR),
    ENGINE_CREDITSMGR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CREDITSMGR),
    ENGINE_OBJ_01C          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_01C),
    ENGINE_GAME_OVER_CREATOR          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAME_OVER_CREATOR),
    ENGINE_GAME_OVER          = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAME_OVER),

    CUTSCENE_CUTSCENEMGR              = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CUTSCENEMGR),
    CUTSCENE_CUTSCENE_FOREST_BLESSING = CV64_OBJECT_ID(OBJ_KIND_MAP_OVERLAY, ID_CUTSCENE_FOREST_BLESSING),
    CUTSCENE_CUTSCENE_CREDITS         = CV64_OBJECT_ID(OBJ_KIND_MAP_OVERLAY, ID_CUTSCENE_CREDITS),

    CAMERA_CAMERAMGR                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CAMERAMGR),
    CAMERA_OBJ_06B                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_06B),
    CAMERA_PLAYER_CAMERA_CONTROLLER                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_PLAYER_CAMERA_CONTROLLER),
    CAMERA_OBJ_06D                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_06D),
    CAMERA_OBJ_06E                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_OBJECT_06E),
    CAMERA_POINT_LIGHT                    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_POINT_LIGHT),

    PLAYER_REINHARDT                  = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_REINHARDT),
    PLAYER_REINHARDT_ALT              = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_REINHARDT_ALT),
    PLAYER_REINHARDT_ATTACKMGR        = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_REINHARDT_ATTACKMGR),
    PLAYER_REINHARDT_DYNAMIC_SCARF    = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_REINHARDT_DYNAMIC_SCARF),
    PLAYER_CARRIE                     = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE),
    PLAYER_CARRIE_ALT                 = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE_ALT),
    PLAYER_CARRIE_ATTACKMGR           = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE_ATTACKMGR),
    PLAYER_CARRIE_DYNAMIC_SKIRT       = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE_DYNAMIC_SKIRT),
    PLAYER_CARRIE_DYNAMIC_RIGHT_STRIP = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE_DYNAMIC_RIGHT_STRIP),
    PLAYER_CARRIE_DYNAMIC_LEFT_STRIP  = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_CARRIE_DYNAMIC_LEFT_STRIP),

    ENEMY_GARDENER                    = CV64_OBJECT_ID(OBJ_KIND_MAP_OVERLAY, ID_GARDENER),

    MENU_GAMEPLAY_MENUMGR             = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_GAMEPLAY_MENUMGR),
    MENU_STAGE_SELECT                 = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_STAGE_SELECT),

    STAGE_OBJECT_MEIRO_TEIEN_OBJ_01B5 = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_MEIRO_TEIEN_OBJ_01B5),
    STAGE_OBJECT_ROSE_VENTILATOR      = CV64_OBJECT_ID(OBJ_KIND_NONE, ID_ROSE_VENTILATOR),
    STAGE_OBJECT_ROSE_DOOR            = CV64_OBJECT_ID(OBJ_KIND_STAGE_OBJECT, ID_ROSE_DOOR)
} cv64_object_id_t;

// clang-format on

#endif // OBJECT_ID_H
