/**
 * dvec3.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "dvec2.h"
#include "dvec3.h"

void cgm_dvec3_set(cgm_dvec3* v, double x, double y, double z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void cgm_dvec3_fill(cgm_dvec3* v, double val) {
    cgm_dvec3_set(v, val, val, val);
}

void cgm_dvec3_set_v2(cgm_dvec3* v, const cgm_dvec2* xy, double z) {
    memcpy(v, xy, sizeof(cgm_dvec2));
    v->z = z;
}

cgm_dvec3* cgm_dvec3_cpy(cgm_dvec3* dest, const cgm_dvec3* src) {
    return memcpy(dest, src, sizeof(cgm_dvec3));
}

bool cgm_dvec3_equals(const cgm_dvec3* u, const cgm_dvec3* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z;
}

void cgm_dvec3_nadd(cgm_dvec3* v, double n) {
    v->x += n;
    v->y += n;
    v->z += n;
}

void cgm_dvec3_add(cgm_dvec3* u, const cgm_dvec3* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
}

void cgm_dvec3_sub(cgm_dvec3* u, const cgm_dvec3* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
}

double cgm_dvec3_dot(const cgm_dvec3* u, const cgm_dvec3* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

void cgm_dvec3_scal(cgm_dvec3* v, double val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
}

double cgm_dvec3_mag(const cgm_dvec3* v) {
    return sqrtf(cgm_dvec3_dot(v, v));
}

void cgm_dvec3_norm(cgm_dvec3* v) {
    double mag = cgm_dvec3_mag(v);
    if (mag != 0) {
        cgm_dvec3_scal(v, 1 / mag);
    }
}

void cgm_dvec3_cross(cgm_dvec3* out, const cgm_dvec3* u, const cgm_dvec3* v) {
    cgm_dvec3_set(out,
            u->y * v->z - v->y * u->z,
            u->z * v->x - v->z * u->x,
            u->x * v->y - v->x * u->y);
}

int cgm_dvec3_fprintf(FILE* stream, const cgm_dvec3* v) {
    return fprintf(stream, "(%g, %g, %g)\n", v->x, v->y, v->z);
}

int cgm_dvec3_printf(const cgm_dvec3* v) {
    return cgm_dvec3_fprintf(stdout, v);
}

/* vim: set ft=c: */
