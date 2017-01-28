/**
 * dvec4.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "dvec2.h"
#include "dvec3.h"
#include "dvec4.h"

void cgm_dvec4_set(cgm_dvec4* v, double x, double y, double z, double w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void cgm_dvec4_set_v2(cgm_dvec4* v, const cgm_dvec2* xy, double z, double w) {
    memcpy(v, xy, sizeof(cgm_dvec2));
    v->z = z;
    v->w = w;
}

void cgm_dvec4_set_v3(cgm_dvec4* v, const cgm_dvec3* xyz, double w) {
    memcpy(v, xyz, sizeof(cgm_dvec3));
    v->w = w;
}

void cgm_dvec4_fill(cgm_dvec4* v, double val) {
    v->x = val;
    v->y = val;
    v->z = val;
    v->w = val;
}

cgm_dvec4* cgm_dvec4_cpy(cgm_dvec4* dest, const cgm_dvec4* src) {
    return memcpy(dest, src, sizeof(cgm_dvec4));
}

bool cgm_dvec4_equals(const cgm_dvec4* u, const cgm_dvec4* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z && u->w == v->w;
}

void cgm_dvec4_nadd(cgm_dvec4* v, double n) {
    v->x += n;
    v->y += n;
    v->z += n;
    v->w += n;
}

void cgm_dvec4_add(cgm_dvec4* u, const cgm_dvec4* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    u->w += v->w;
}

void cgm_dvec4_sub(cgm_dvec4* u, const cgm_dvec4* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    u->w -= v->w;
}

double cgm_dvec4_dot(const cgm_dvec4* u, const cgm_dvec4* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z + u->w * v->w;
}

void cgm_dvec4_scal(cgm_dvec4* v, double val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
    v->w *= val;
}

double cgm_dvec4_mag(const cgm_dvec4* v) {
    return sqrtf(cgm_dvec4_dot(v, v));
}

void cgm_dvec4_norm(cgm_dvec4* v) {
    double mag = cgm_dvec4_mag(v);
    if (mag != 0) {
        cgm_dvec4_scal(v, 1 / mag);
    }
}

int cgm_dvec4_fprintf(FILE* stream, const cgm_dvec4* v) {
    return fprintf(stream, "(%g, %g, %g, %g)\n", v->x, v->y, v->z, v->w);
}

int cgm_dvec4_printf(const cgm_dvec4* v) {
    return cgm_dvec4_fprintf(stdout, v);
}

/* vim: set ft=c: */
