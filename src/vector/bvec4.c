/**
 * bvec4.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "bvec2.h"
#include "bvec3.h"
#include "bvec4.h"

void cgm_bvec4_set(cgm_bvec4* v, bool x, bool y, bool z, bool w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void cgm_bvec4_set_v2(cgm_bvec4* v, const cgm_bvec2* xy, bool z, bool w) {
    memcpy(v, xy, sizeof(cgm_bvec2));
    v->z = z;
    v->w = w;
}

void cgm_bvec4_set_v3(cgm_bvec4* v, const cgm_bvec3* xyz, bool w) {
    memcpy(v, xyz, sizeof(cgm_bvec3));
    v->w = w;
}

void cgm_bvec4_fill(cgm_bvec4* v, bool val) {
    v->x = val;
    v->y = val;
    v->z = val;
    v->w = val;
}

cgm_bvec4* cgm_bvec4_cpy(cgm_bvec4* dest, const cgm_bvec4* src) {
    return memcpy(dest, src, sizeof(cgm_bvec4));
}

bool cgm_bvec4_equals(const cgm_bvec4* u, const cgm_bvec4* v) {
    return !u->x == !v->x && !u->y == !v->y && !u->z == !v->z && !u->w == !v->w;
}

bool cgm_bvec4_any(const cgm_bvec4* v) {
    return v->x || v->y || v->z || v->w;
}

bool cgm_bvec4_all(const cgm_bvec4* v) {
    return v->x && v->y && v->z && v->w;
}

void cgm_bvec4_not(cgm_bvec4* v) {
    v->x = !v->x;
    v->y = !v->y;
    v->z = !v->z;
    v->w = !v->w;
}

int cgm_bvec4_fprintf(FILE* stream, const cgm_bvec4* v) {
    return fprintf(stream, "(%g, %g, %g, %g)\n", v->x, v->y, v->z, v->w);
}

int cgm_bvec4_printf(const cgm_bvec4* v) {
    return cgm_bvec4_fprintf(stdout, v);
}

/* vim: set ft=c: */
