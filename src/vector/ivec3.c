/**
 * ivec3.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ivec2.h"
#include "ivec3.h"

void cgm_ivec3_set(cgm_ivec3* v, int32_t x, int32_t y, int32_t z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void cgm_ivec3_fill(cgm_ivec3* v, int32_t val) {
    cgm_ivec3_set(v, val, val, val);
}

void cgm_ivec3_set_v2(cgm_ivec3* v, const cgm_ivec2* xy, int32_t z) {
    memcpy(v, xy, sizeof(cgm_ivec2));
    v->z = z;
}

cgm_ivec3* cgm_ivec3_cpy(cgm_ivec3* dest, const cgm_ivec3* src) {
    return memcpy(dest, src, sizeof(cgm_ivec3));
}

bool cgm_ivec3_equals(const cgm_ivec3* u, const cgm_ivec3* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z;
}

void cgm_ivec3_nadd(cgm_ivec3* v, int32_t n) {
    v->x += n;
    v->y += n;
    v->z += n;
}

void cgm_ivec3_add(cgm_ivec3* u, const cgm_ivec3* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
}

void cgm_ivec3_sub(cgm_ivec3* u, const cgm_ivec3* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
}

int cgm_ivec3_dot(const cgm_ivec3* u, const cgm_ivec3* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

void cgm_ivec3_scal(cgm_ivec3* v, int32_t val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
}

void cgm_ivec3_cross(cgm_ivec3* out, const cgm_ivec3* u, const cgm_ivec3* v) {
    cgm_ivec3_set(out,
            u->y * v->z - v->y * u->z,
            u->z * v->x - v->z * u->x,
            u->x * v->y - v->x * u->y);
}

int cgm_ivec3_fprintf(FILE* stream, const cgm_ivec3* v) {
    return fprintf(stream, "(%d, %d, %d)\n", v->x, v->y, v->z);
}

int cgm_ivec3_printf(const cgm_ivec3* v) {
    return cgm_ivec3_fprintf(stdout, v);
}

/* vim: set ft=c: */
