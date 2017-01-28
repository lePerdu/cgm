/**
 * uvec4.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "uvec2.h"
#include "uvec3.h"
#include "uvec4.h"

void cgm_uvec4_set(cgm_uvec4* v, uint32_t x, uint32_t y, uint32_t z, uint32_t w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void cgm_uvec4_set_v2(cgm_uvec4* v, const cgm_uvec2* xy, uint32_t z, uint32_t w) {
    memcpy(v, xy, sizeof(cgm_uvec2));
    v->z = z;
    v->w = w;
}

void cgm_uvec4_set_v3(cgm_uvec4* v, const cgm_uvec3* xyz, uint32_t w) {
    memcpy(v, xyz, sizeof(cgm_uvec3));
    v->w = w;
}

void cgm_uvec4_fill(cgm_uvec4* v, uint32_t val) {
    v->x = val;
    v->y = val;
    v->z = val;
    v->w = val;
}

cgm_uvec4* cgm_uvec4_cpy(cgm_uvec4* dest, const cgm_uvec4* src) {
    return memcpy(dest, src, sizeof(cgm_uvec4));
}

bool cgm_uvec4_equals(const cgm_uvec4* u, const cgm_uvec4* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z && u->w == v->w;
}

void cgm_uvec4_nadd(cgm_uvec4* v, uint32_t n) {
    v->x += n;
    v->y += n;
    v->z += n;
    v->w += n;
}

void cgm_uvec4_add(cgm_uvec4* u, const cgm_uvec4* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    u->w += v->w;
}

void cgm_uvec4_sub(cgm_uvec4* u, const cgm_uvec4* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    u->w -= v->w;
}

uint32_t cgm_uvec4_dot(const cgm_uvec4* u, const cgm_uvec4* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z + u->w * v->w;
}

void cgm_uvec4_scal(cgm_uvec4* v, uint32_t val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
    v->w *= val;
}

int cgm_uvec4_fprintf(FILE* stream, const cgm_uvec4* v) {
    return fprintf(stream, "(%u, %u, %u, %u)\n", v->x, v->y, v->z, v->w);
}

int cgm_uvec4_printf(const cgm_uvec4* v) {
    return cgm_uvec4_fprintf(stdout, v);
}

/* vim: set ft=c: */
