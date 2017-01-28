/**
 * dvec2.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "dvec2.h"

void cgm_dvec2_set(cgm_dvec2* v, double x, double y) {
    v->x = x;
    v->y = y;
}

void cgm_dvec2_fill(cgm_dvec2* v, double val) {
    cgm_dvec2_set(v, val, val);
}

cgm_dvec2* cgm_dvec2_cpy(cgm_dvec2* dest, const cgm_dvec2* src) {
    return memcpy(dest, src, sizeof(cgm_dvec2));
}

bool cgm_dvec2_equals(const cgm_dvec2* u, const cgm_dvec2* v) {
    return u->x == v->x && u->y == v->y;
}

void cgm_dvec2_nadd(cgm_dvec2* v, double n) {
    v->x += n;
    v->y += n;
}

void cgm_dvec2_add(cgm_dvec2* u, const cgm_dvec2* v) {
    u->x += v->x;
    u->y += v->y;
}

void cgm_dvec2_sub(cgm_dvec2* u, const cgm_dvec2* v) {
    u->x -= v->x;
    u->y -= v->y;
}

double cgm_dvec2_dot(const cgm_dvec2* u, const cgm_dvec2* v) {
    return u->x * v->x + u->y * v->y;
}

void cgm_dvec2_scal(cgm_dvec2* v, double val) {
    v->x *= val;
    v->y *= val;
}

double cgm_dvec2_mag(const cgm_dvec2* v) {
    return sqrtf(cgm_dvec2_dot(v, v));
}

void cgm_dvec2_norm(cgm_dvec2* v) {
    cgm_dvec2_scal(v, 1 / cgm_dvec2_mag(v));
}

int cgm_dvec2_fprintf(FILE* stream, const cgm_dvec2* v) {
    return fprintf(stream, "(%g, %g)\n", v->x, v->y);
}

int cgm_dvec2_printf(const cgm_dvec2* v) {
    return cgm_dvec2_fprintf(stdout, v);
}

/* vim: set ft=c: */
