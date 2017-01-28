/**
 * uvec2.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "uvec2.h"

void cgm_uvec2_set(cgm_uvec2* v, uint32_t x, uint32_t y) {
    v->x = x;
    v->y = y;
}

void cgm_uvec2_fill(cgm_uvec2* v, uint32_t val) {
    cgm_uvec2_set(v, val, val);
}

cgm_uvec2* cgm_uvec2_cpy(cgm_uvec2* dest, const cgm_uvec2* src) {
    return memcpy(dest, src, sizeof(cgm_uvec2));
}

bool cgm_uvec2_equals(const cgm_uvec2* u, const cgm_uvec2* v) {
    return u->x == v->x && u->y == v->y;
}

void cgm_uvec2_nadd(cgm_uvec2* v, uint32_t n) {
    v->x += n;
    v->y += n;
}

void cgm_uvec2_add(cgm_uvec2* u, const cgm_uvec2* v) {
    u->x += v->x;
    u->y += v->y;
}

void cgm_uvec2_sub(cgm_uvec2* u, const cgm_uvec2* v) {
    u->x -= v->x;
    u->y -= v->y;
}

uint32_t cgm_uvec2_dot(const cgm_uvec2* u, const cgm_uvec2* v) {
    return u->x * v->x + u->y * v->y;
}

void cgm_uvec2_scal(cgm_uvec2* v, uint32_t val) {
    v->x *= val;
    v->y *= val;
}

int cgm_uvec2_fprintf(FILE* stream, const cgm_uvec2* v) {
    return fprintf(stream, "(%u, %u)\n", v->x, v->y);
}

int cgm_uvec2_printf(const cgm_uvec2* v) {
    return cgm_uvec2_fprintf(stdout, v);
}

/* vim: set ft=c: */
