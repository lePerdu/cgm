/**
 * ivec4.c
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
#include "ivec4.h"

void cgm_ivec4_set(cgm_ivec4* v, int x, int y, int z, int w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void cgm_ivec4_set_v2(cgm_ivec4* v, const cgm_ivec2* xy, int z, int w) {
    memcpy(v, xy, sizeof(cgm_ivec2));
    v->z = z;
    v->w = w;
}

void cgm_ivec4_set_v3(cgm_ivec4* v, const cgm_ivec3* xyz, int w) {
    memcpy(v, xyz, sizeof(cgm_ivec3));
    v->w = w;
}

void cgm_ivec4_fill(cgm_ivec4* v, int32_t val) {
    v->x = val;
    v->y = val;
    v->z = val;
    v->w = val;
}

cgm_ivec4* cgm_ivec4_cpy(cgm_ivec4* dest, const cgm_ivec4* src) {
    return memcpy(dest, src, sizeof(cgm_ivec4));
}

bool cgm_ivec4_equals(const cgm_ivec4* u, const cgm_ivec4* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z && u->w == v->w;
}

void cgm_ivec4_nadd(cgm_ivec4* v, int n) {
    v->x += n;
    v->y += n;
    v->z += n;
    v->w += n;
}

void cgm_ivec4_add(cgm_ivec4* u, const cgm_ivec4* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    u->w += v->w;
}

void cgm_ivec4_sub(cgm_ivec4* u, const cgm_ivec4* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    u->w -= v->w;
}

int cgm_ivec4_dot(const cgm_ivec4* u, const cgm_ivec4* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z + u->w * v->w;
}

void cgm_ivec4_scal(cgm_ivec4* v, int val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
    v->w *= val;
}

int cgm_ivec4_fprintf(FILE* stream, const cgm_ivec4* v) {
    return fprintf(stream, "(%d, %d, %d, %d)\n", v->x, v->y, v->z, v->w);
}

int cgm_ivec4_printf(const cgm_ivec4* v) {
    return cgm_ivec4_fprintf(stdout, v);
}

/* vim: set ft=c: */
