/**
 * bvec2.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "bvec2.h"

void cgm_bvec2_set(cgm_bvec2* v, bool x, bool y) {
    v->x = x;
    v->y = y;
}

void cgm_bvec2_fill(cgm_bvec2* v, bool val) {
    cgm_bvec2_set(v, val, val);
}

cgm_bvec2* cgm_bvec2_cpy(cgm_bvec2* dest, const cgm_bvec2* src) {
    return memcpy(dest, src, sizeof(cgm_bvec2));
}

bool cgm_bvec2_equals(const cgm_bvec2* u, const cgm_bvec2* v) {
    return !u->x == !v->x && !u->y == !v->y;
}

bool cgm_bvec2_any(const cgm_bvec2* v) {
    return v->x || v->y;
}

bool cgm_bvec2_all(const cgm_bvec2* v) {
    return v->x && v->y;
}

void cgm_bvec2_not(cgm_bvec2* v) {
    v->x = !v->x;
    v->y = !v->y;
}

int cgm_bvec2_fprintf(FILE* stream, const cgm_bvec2* v) {
    return fprintf(stream, "(%s, %s)\n", v->x ? "true" : "false", v->y ? "true" : "false");
}

int cgm_bvec2_printf(const cgm_bvec2* v) {
    return cgm_bvec2_fprintf(stdout, v);
}

/* vim: set ft=c: */
