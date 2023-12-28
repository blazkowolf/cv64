#include "cv64.h"
#include "math.h"
#include <ultra64.h>

f32 func_80011310_11F10(f32 src) {
    f32 src_squared;
    f32 sqrt;

    src_squared = src * src;
    sqrt = (src_squared > 1.0f) ? 0.0f : sqrtf(1.0f - src_squared);

    return atan2f(sqrt, src);
}

f32 func_80011370_11F70(f32 src) {
    f32 src_squared;
    f32 sqrt;

    src_squared = src * src;
    sqrt = (src_squared > 1.0f) ? 0.0f : sqrtf(1.0f - src_squared);

    return atan2f(src, sqrt);
}

f32 vec3f_distance(vec3f* src1, vec3f* src2) {
    vec3f dest;

    vec3f_substract(&dest, src1, src2);
    return vec3f_magnitude(&dest);
}

f32 vec3f_magnitude(vec3f* src) {
    f32 x, y, z;

    z = src->z;
    y = src->x;
    x = src->y;
    return sqrtf((z * z) + ((y * y) + (x * x)));
}

f32 vec3f_80011440(vec3f* dest, vec3f* src, f32 scalar) {
    f32 magn;

    magn = vec3f_magnitude(src);
    if (magn != 0.0f) {
        vec3f_multiplyScalar(dest, src, scalar / magn);
    } else {
        vec3f_set(dest, 0.0f, 0.0f, 0.0f);
    }

    return magn;
}

void vec3f_add(vec3f* dest, vec3f* src1, vec3f* src2) {
    dest->x = (f32) (src2->x + src1->x);
    dest->y = (f32) (src2->y + src1->y);
    dest->z = (f32) (src2->z + src1->z);
}

void vec3f_substract(vec3f* dest, vec3f* src1, vec3f* src2) {
    dest->x = (f32) (src1->x - src2->x);
    dest->y = (f32) (src1->y - src2->y);
    dest->z = (f32) (src1->z - src2->z);
}

void vec3f_copy(vec3f* dest, vec3f* src) {
    dest->x = (f32) src->x;
    dest->y = (f32) src->y;
    dest->z = (f32) src->z;
}

void vec3f_swap(vec3f* dest, vec3f* src) {
    vec3f temp;

    vec3f_copy(&temp, dest);
    vec3f_copy(dest, src);
    vec3f_copy(src, &temp);
}

void vec3f_multiplyScalar(vec3f* dest, vec3f* src, f32 scalar) {
    dest->x = (f32) (src->x * scalar);
    dest->y = (f32) (src->y * scalar);
    dest->z = (f32) (src->z * scalar);
}

void vec3f_percentage(vec3f* dest, vec3f* src, f32 percent) {
    percent = 1.0f / percent;
    dest->x = (f32) (src->x * percent);
    dest->y = (f32) (src->y * percent);
    dest->z = (f32) (src->z * percent);
}

void vec3f_complement(vec3f* dest, vec3f* src) {
    dest->x = (f32) -src->x;
    dest->y = (f32) -src->y;
    dest->z = (f32) -src->z;
}

f32 vec3f_80011614(vec3f* dest, vec3f* src) {
    f32 magn;

    magn = vec3f_magnitude(src);
    if (magn != 0.0f) {
        vec3f_percentage(dest, src, magn);
    }

    return magn;
}

f32 vec3f_dotProduct(vec3f* src1, vec3f* src2) {
    return (src2->z * src1->z) + ((src1->x * src2->x) + (src1->y * src2->y));
}

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/vec3f_crossProduct.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/vec3f_80011710.s")

void vec3f_set(vec3f* vec, f32 x, f32 y, f32 z) {
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

void vec3f_multiplyByOne(vec3f* dest) {
    vec3f_multiplyScalar(dest, dest, 1.0f);
}

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/vec3f_800117a4.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/vec3f_80011808.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/matrix_multiplyVec3f.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/func_80011914_12514.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/func_80011984_12584.s")

#pragma GLOBAL_ASM("../asm/nonmatchings/vec3f/func_800119F0_125F0.s")