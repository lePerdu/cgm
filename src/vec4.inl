/**
 * vec4.inl
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "vec2.h"
#include "vec3.h"

inline void cgm_vec4_set(cgm_vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

inline void cgm_vec4_set_v2(cgm_vec4* v, const cgm_vec2* xy, float z, float w) {
    memcpy(v, xy, sizeof(cgm_vec2));
    v->z = z;
    v->w = w;
}

inline void cgm_vec4_set_v3(cgm_vec4* v, const cgm_vec3* xyz, float w) {
    memcpy(v, xyz, sizeof(cgm_vec3));
    v->w = w;
}

inline cgm_vec4* cgm_vec4_cpy(cgm_vec4* dest, const cgm_vec4* src) {
    return memcpy(dest, src, sizeof(cgm_vec4));
}

inline int cgm_vec4_equals(const cgm_vec4* u, const cgm_vec4* v) {
    return u->x == v->x && u->y == v->y && u->z == v->z && u->w == v->w;
}

inline void cgm_vec4_nadd(cgm_vec4* v, float n) {
    v->x += n;
    v->y += n;
    v->z += n;
    v->w += n;
}

inline void cgm_vec4_add(cgm_vec4* u, const cgm_vec4* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    u->w += v->w;
}

inline void cgm_vec4_sub(cgm_vec4* u, const cgm_vec4* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    u->w -= v->w;
}

inline float cgm_vec4_dot(const cgm_vec4* u, const cgm_vec4* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z + u->w * v->w;
}

inline void cgm_vec4_scal(cgm_vec4* v, float val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
    v->w *= val;
}

inline float cgm_vec4_mag(const cgm_vec4* v) {
    return sqrtf(cgm_vec4_dot(v, v));
}

inline void cgm_vec4_norm(cgm_vec4* v) {
    float mag = cgm_vec4_mag(v);
    if (mag != 0) {
        cgm_vec4_scal(v, 1 / mag);
    }
}

inline int cgm_vec4_fprintf(FILE* stream, const cgm_vec4* v) {
    return fprintf(stream, "(%g, %g, %g, %g)\n", v->x, v->y, v->z, v->w);
}

/* vim: set ft=c: */
