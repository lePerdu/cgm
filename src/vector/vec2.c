/**
 * vec2.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "vec2.h"

void cgm_vec2_set(cgm_vec2* v, float x, float y) {
    v->x = x;
    v->y = y;
}

void cgm_vec2_fill(cgm_vec2* v, float val) {
    cgm_vec2_set(v, val, val);
}

cgm_vec2* cgm_vec2_cpy(cgm_vec2* dest, const cgm_vec2* src) {
    return memcpy(dest, src, sizeof(cgm_vec2));
}

bool cgm_vec2_equals(const cgm_vec2* u, const cgm_vec2* v) {
    return u->x == v->x && u->y == v->y;
}

void cgm_vec2_nadd(cgm_vec2* v, float n) {
    v->x += n;
    v->y += n;
}

void cgm_vec2_add(cgm_vec2* u, const cgm_vec2* v) {
    u->x += v->x;
    u->y += v->y;
}

void cgm_vec2_sub(cgm_vec2* u, const cgm_vec2* v) {
    u->x -= v->x;
    u->y -= v->y;
}

float cgm_vec2_dot(const cgm_vec2* u, const cgm_vec2* v) {
    return u->x * v->x + u->y * v->y;
}

void cgm_vec2_scal(cgm_vec2* v, float val) {
    v->x *= val;
    v->y *= val;
}

float cgm_vec2_mag(const cgm_vec2* v) {
    return sqrtf(cgm_vec2_dot(v, v));
}

void cgm_vec2_norm(cgm_vec2* v) {
    cgm_vec2_scal(v, 1 / cgm_vec2_mag(v));
}

int cgm_vec2_fprintf(FILE* stream, const cgm_vec2* v) {
    return fprintf(stream, "(%g, %g)\n", v->x, v->y);
}

int cgm_vec2_printf(const cgm_vec2* v) {
    return cgm_vec2_fprintf(stdout, v);
}

/* vim: set ft=c: */
