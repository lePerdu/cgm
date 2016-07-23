/**
 * vec2.inl
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

inline void cgm_vec2_set(cgm_vec2* v, float x, float y) {
    v->x = x;
    v->y = y;
}

inline cgm_vec2* cgm_vec2_cpy(cgm_vec2* dest, const cgm_vec2* src) {
    return memcpy(dest, src, sizeof(cgm_vec2));
}

inline int cgm_vec2_equals(const cgm_vec2* u, const cgm_vec2* v) {
    return u->x == v->x && u->y == v->y;
}

inline void cgm_vec2_nadd(cgm_vec2* v, float n) {
    v->x += n;
    v->y += n;
}

inline void cgm_vec2_add(cgm_vec2* u, const cgm_vec2* v) {
    u->x += v->x;
    u->y += v->y;
}

inline void cgm_vec2_sub(cgm_vec2* u, const cgm_vec2* v) {
    u->x -= v->x;
    u->y -= v->y;
}

inline float cgm_vec2_dot(const cgm_vec2* u, const cgm_vec2* v) {
    return u->x * v->x + u->y * v->y;
}

inline void cgm_vec2_scal(cgm_vec2* v, float val) {
    v->x *= val;
    v->y *= val;
}

inline float cgm_vec2_mag(const cgm_vec2* v) {
    return sqrtf(cgm_vec2_dot(v, v));
}

inline void cgm_vec2_norm(cgm_vec2* v) {
    cgm_vec2_scal(v, 1 / cgm_vec2_mag(v));
}

inline int cgm_vec2_fprintf(FILE* stream, const cgm_vec2* v) {
    return fprintf(stream, "(%g, %g)\n", v->x, v->y);
}

/* vim: set ft=c: */
