/**
 * uvec3.c
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

void cgm_uvec3_set(cgm_uvec3* v, uint32_t x, uint32_t y, uint32_t z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void cgm_uvec3_fill(cgm_uvec3* v, uint32_t val) {
    cgm_uvec3_set(v, val, val, val);
}

void cgm_uvec3_set_v2(cgm_uvec3* v, const cgm_uvec2* xy, uint32_t z) {
    memcpy(v, xy, sizeof(cgm_uvec2));
    v->z = z;
}

cgm_uvec3* cgm_uvec3_cpy(cgm_uvec3* dest, const cgm_uvec3* src) {
    return memcpy(dest, src, sizeof(cgm_uvec3));
}

bool cgm_uvec3_equals(const cgm_uvec3* u, const cgm_uvec3* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z;
}

void cgm_uvec3_nadd(cgm_uvec3* v, uint32_t n) {
    v->x += n;
    v->y += n;
    v->z += n;
}

void cgm_uvec3_add(cgm_uvec3* u, const cgm_uvec3* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
}

void cgm_uvec3_sub(cgm_uvec3* u, const cgm_uvec3* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
}

uint32_t cgm_uvec3_dot(const cgm_uvec3* u, const cgm_uvec3* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

void cgm_uvec3_scal(cgm_uvec3* v, uint32_t val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
}

int cgm_uvec3_fprintf(FILE* stream, const cgm_uvec3* v) {
    return fprintf(stream, "(%u, %u, %u)\n", v->x, v->y, v->z);
}

int cgm_uvec3_printf(const cgm_uvec3* v) {
    return cgm_uvec3_fprintf(stdout, v);
}

/* vim: set ft=c: */
