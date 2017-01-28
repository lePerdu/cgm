/**
 * quaternion.c
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "quaternion.h"

void cgm_quat_set(cgm_quat* q,
        float w, float x, float y, float z) {
    q->w = w;
    q->x = x;
    q->y = y;
    q->z = z;
}

void cgm_quat_set_v3(cgm_quat* q, float w, const cgm_vec3* xyz) {
    q->w = w;
    cgm_vec3_cpy(&q->xyz, xyz);
}

void cgm_quat_set_identity(cgm_quat* q) {
    cgm_quat_set(q, 1.0F, 0.0F, 0.0F, 0.0F);
}

void cgm_quat_from_euler(cgm_quat* q, float x, float y, float z) {
    float sx = sinf(x / 2.0F);
    float sy = sinf(y / 2.0F);
    float sz = sinf(z / 2.0F);
    float cx = cosf(x / 2.0F);
    float cy = cosf(y / 2.0F);
    float cz = cosf(z / 2.0F);

    cgm_quat_set(q,
            cx * cy * cz + sx * sy * sz,
            sx * cy * cz - cx * sy * sz,
            cx * sy * cz + sx * cy * sz,
            cx * cy * sz - sx * sy * cz);
}

void cgm_quat_from_axis_angle(cgm_quat* q,
        const cgm_vec3* axis,
        float angle) {
    float mag = cgm_vec3_mag(axis);
    if (mag == 0.0F) {
        return;
    }

    /* Do the operation once */
    angle /= 2.0F;

    float s_mag = sinf(angle) / mag;
    cgm_quat_set(q,
            cosf(angle),
            axis->x * s_mag,
            axis->y * s_mag,
            axis->z * s_mag);
}

cgm_quat* cgm_quat_cpy(cgm_quat* dest, const cgm_quat* src) {
    /* It is unlikely and pointless to copy part of a quaternion into
     * itself
     */
    return memmove(dest, src, sizeof(cgm_quat));
}

void cgm_quat_conjugate(cgm_quat* q) {
    q->x *= -1;
    q->y *= -1;
    q->z *= -1;
}

bool cgm_quat_invert(cgm_quat* q) {
    float dot = cgm_quat_dot(q, q);
    if (dot == 0.0F) {
        return false;
    }

    cgm_quat_conjugate(q);
    cgm_quat_scale(q, 1 / dot);
}

float cgm_quat_dot(const cgm_quat* p, const cgm_quat* q) {
    return p->w * q->w + p->x * q->x + p->y * q->y + p->z * q->z;
}

float cgm_quat_mag(const cgm_quat* q) {
    return sqrtf(cgm_quat_dot(q, q));
}

void cgm_quat_scale(cgm_quat* q, float val) {
    q->w *= val;
    q->x *= val;
    q->y *= val;
    q->z *= val;
}

void cgm_quat_mul(cgm_quat* out,
        const cgm_quat* p,
        const cgm_quat* q) {
    out->w = p->w * q->w - p->x * q->x - p->y * q->y - p->z * q->z;
    out->x = p->w * q->x + p->x * q->w + p->y * q->z - p->z * q->y;
    out->y = p->w * q->y + p->y * q->w + p->z * q->x - p->x * q->z;
    out->z = p->w * q->z + p->z * q->w + p->x * q->y - p->y * q->x;
}

void cgm_quat_mul_l(cgm_quat* p, const cgm_quat* q) {
    cgm_quat out;
    cgm_quat_mul(&out, p, q);
    cgm_quat_cpy(p, &out);
}

void cgm_quat_mul_r(const cgm_quat* p, cgm_quat* q) {
    cgm_quat out;
    cgm_quat_mul(&out, p, q);
    cgm_quat_cpy(q, &out);
}

void cgm_quat_rotate(cgm_quat* q,
        const cgm_vec3* axis,
        float angle) {
    cgm_quat tmp;
    cgm_quat_from_axis_angle(&tmp, axis, angle);
    cgm_quat_mul_l(q, &tmp);
}

int cgm_quat_fprintf(FILE* stream, const cgm_quat* q) {
    return fprintf(stream, "(%g, %g, %g, %g)\n", q->x, q->y, q->z, q->w);
}

int cgm_quat_printf(const cgm_quat* q) {
    return cgm_quat_fprintf(stdout, q);
}

/* vim: set ft=c: */
