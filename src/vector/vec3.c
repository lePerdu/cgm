/**
 * vec3.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "vec2.h"
#include "vec3.h"

void cgm_vec3_set(cgm_vec3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void cgm_vec3_fill(cgm_vec3* v, float val) {
    cgm_vec3_set(v, val, val, val);
}

void cgm_vec3_set_v2(cgm_vec3* v, const cgm_vec2* xy, float z) {
    memcpy(v, xy, sizeof(cgm_vec2));
    v->z = z;
}

cgm_vec3* cgm_vec3_cpy(cgm_vec3* dest, const cgm_vec3* src) {
    return memcpy(dest, src, sizeof(cgm_vec3));
}

bool cgm_vec3_equals(const cgm_vec3* u, const cgm_vec3* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z;
}

void cgm_vec3_nadd(cgm_vec3* v, float n) {
    v->x += n;
    v->y += n;
    v->z += n;
}

void cgm_vec3_add(cgm_vec3* u, const cgm_vec3* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
}

void cgm_vec3_sub(cgm_vec3* u, const cgm_vec3* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
}

float cgm_vec3_dot(const cgm_vec3* u, const cgm_vec3* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z;
}

void cgm_vec3_scal(cgm_vec3* v, float val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
}

float cgm_vec3_mag(const cgm_vec3* v) {
    return sqrtf(cgm_vec3_dot(v, v));
}

void cgm_vec3_norm(cgm_vec3* v) {
    float mag = cgm_vec3_mag(v);
    if (mag != 0) {
        cgm_vec3_scal(v, 1 / mag);
    }
}

void cgm_vec3_cross(cgm_vec3* out, const cgm_vec3* u, const cgm_vec3* v) {
    cgm_vec3_set(out,
            u->y * v->z - v->y * u->z,
            u->z * v->x - v->z * u->x,
            u->x * v->y - v->x * u->y);
}

int cgm_vec3_fprintf(FILE* stream, const cgm_vec3* v) {
    return fprintf(stream, "(%g, %g, %g)\n", v->x, v->y, v->z);
}

int cgm_vec3_printf(const cgm_vec3* v) {
    return cgm_vec3_fprintf(stdout, v);
}

/* vim: set ft=c: */
