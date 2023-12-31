#ifndef MEMORY_H
#define MEMORY_H

#include <ultra64.h>

#define ALIGN8(val) ((((u32) val) + 7) & ~7)

#define HEAP_MULTIPURPOSE_SIZE 0xD0000
/*  @bug
        Since the menu data heap is always set to start at 0x801CC000,
        setting it to a size of 0x40000 can theoretically overwrite
   gFramebuffers, causing graphical glitches and crashes with the elements that
   use said heap (such as the Pause menu).

        The correct size should be 0x34000.
*/
#define HEAP_MENU_DATA_SIZE 0x40000

#define HEAP_NUM 8

typedef enum heap_kind {
    HEAP_KIND_MULTIPURPOSE, // Most dynamically-allocated data is allocated on
                            // this heap
    HEAP_KIND_1,
    HEAP_KIND_MENU_DATA, // Assets used on some menus (usually file 0x60 and
                         // 0x61). Some menu-related structs are also allocated
                         // on this heap
    HEAP_KIND_3,
    HEAP_KIND_4,
    HEAP_KIND_5,
    HEAP_KIND_6,
    HEAP_KIND_MAP_DATA // Current map's data (assets file, collision data, etc)
} cv64_heap_kind_t;

// There's also 0x4000, see function 0x80001008
typedef enum cv64_heapblock_flag {
    HEAP_BLOCK_FREE = 0x0000,
    HEAP_BLOCK_ACTIVE = 0x8000
} cv64_heapblock_flag_t;

typedef enum cv64_heap_flag {
    HEAP_INACTIVE = 0x0000,
    HEAP_WRITE_BACK_CACHE_TO_RAM =
        0x4000, // Assumption based on function 0x80000C94
    HEAP_ACTIVE = 0x8000
} cv64_heap_flag_t;

typedef struct cv64_heapblock_hdr {
    u16 flags;
    u8 field_0x02[2];
    u32 size;         // Size of the block
    void* field_0x08; // Display List / GFX related?
    void* data_start;
    void* data_end;   // End of the allocated data, NOT end of the block
    u8 field_0x14[4]; // Related to file decompression?
} cv64_heapblock_hdr_t;

typedef struct cv64_heap_inf {
    s16 flags;
    u8 field_0x02[2];
    u32 size;                         // Size of the heap
    cv64_heapblock_hdr_t* heap_start; // Start of the block array
} cv64_heap_inf_t;

extern cv64_heap_inf_t heaps[HEAP_NUM];
extern void* HEAP_MULTIPURPOSE_START;
extern void* HEAP_MENU_DATA_START;

extern void memory_copy(void* src, void* dest, u32 size);
extern void memory_clear(void* ptr, u32 length);
void heap_init(cv64_heap_kind_t kind, cv64_heapblock_hdr_t* first_block_ptr,
               s32 heap_size, u32 additional_flags);
void heap_free(cv64_heap_kind_t kind);
void heap_writebackDCache(void);
extern void initHeaps(void);
extern void* heap_alloc(s32 kind, u32 data_size); // CV64's malloc()
extern void* heap_allocWithAlignment(s32 kind, u32 data_size, u32 alignment);
extern s32 heapBlock_updateBlockMaxSize(void* data, u32 data_size);
extern void heapBlock_free(u16* ptr); // CV64's free()

#endif
