/**
 * ivec2.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ivec2.h"

void cgm_ivec2_set(cgm_ivec2* v, int32_t x, int32_t y) {
    v->x = x;
    v->y = y;
}

void cgm_ivec2_fill(cgm_ivec2* v, int32_t val) {
    cgm_ivec2_set(v, val, val);
}

cgm_ivec2* cgm_ivec2_cpy(cgm_ivec2* dest, const cgm_ivec2* src) {
    return memcpy(dest, src, sizeof(cgm_ivec2));
}

bool cgm_ivec2_equals(const cgm_ivec2* u, const cgm_ivec2* v) {
    return u->x == v->x && u->y == v->y;
}

void cgm_ivec2_nadd(cgm_ivec2* v, int32_t n) {
    v->x += n;
    v->y += n;
}

void cgm_ivec2_add(cgm_ivec2* u, const cgm_ivec2* v) {
    u->x += v->x;
    u->y += v->y;
}

void cgm_ivec2_sub(cgm_ivec2* u, const cgm_ivec2* v) {
    u->x -= v->x;
    u->y -= v->y;
}

int cgm_ivec2_dot(const cgm_ivec2* u, const cgm_ivec2* v) {
    return u->x * v->x + u->y * v->y;
}

void cgm_ivec2_scal(cgm_ivec2* v, int32_t val) {
    v->x *= val;
    v->y *= val;
}

int cgm_ivec2_fprintf(FILE* stream, const cgm_ivec2* v) {
    return fprintf(stream, "(%d, %d)\n", v->x, v->y);
}

int cgm_ivec2_printf(const cgm_ivec2* v) {
    return cgm_ivec2_fprintf(stdout, v);
}

/* vim: set ft=c: */
