/**
 * bvec3.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "bvec3.h"
#include "bvec3.h"

void cgm_bvec3_set(cgm_bvec3* v, bool x, bool y, bool z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void cgm_bvec3_fill(cgm_bvec3* v, bool val) {
    cgm_bvec3_set(v, val, val, val);
}

void cgm_bvec3_set_v2(cgm_bvec3* v, const cgm_bvec2* xy, bool z) {
    memcpy(v, xy, sizeof(cgm_bvec2));
    v->z = z;
}

cgm_bvec3* cgm_bvec3_cpy(cgm_bvec3* dest, const cgm_bvec3* src) {
    return memcpy(dest, src, sizeof(cgm_bvec3));
}

bool cgm_bvec3_equals(const cgm_bvec3* u, const cgm_bvec3* v) {
    return !u->x == !v->x && !u->y == !v->y && !u->z == !v->z;
}

bool cgm_bvec3_any(const cgm_bvec3* v) {
    return v->x || v->y || v->z;
}

bool cgm_bvec3_all(const cgm_bvec3* v) {
    return v->x && v->y && v->z;
}

void cgm_bvec3_not(cgm_bvec3* v) {
    v->x = !v->x;
    v->y = !v->y;
    v->z = !v->z;
}

int cgm_bvec3_fprintf(FILE* stream, const cgm_bvec3* v) {
    return fprintf(stream, "(%s, %s, %s)\n",
            v->x ? "true" : "false",
            v->y ? "true" : "false",
            v->z ? "true" : "false");
}

int cgm_bvec3_printf(const cgm_bvec3* v) {
    return cgm_bvec3_fprintf(stdout, v);
}

/* vim: set ft=c: */
