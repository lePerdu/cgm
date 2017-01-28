/**
 * dquaternion.c
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "../vector/dvec3.h"
#include "dquaternion.h"

void cgm_dquat_set(cgm_dquat* q,
        double w, double x, double y, double z) {
    q->w = w;
    q->x = x;
    q->y = y;
    q->z = z;
}

void cgm_dquat_set_v3(cgm_dquat* q, double w, const cgm_dvec3* xyz) {
    q->w = w;
    cgm_dvec3_cpy(&q->xyz, xyz);
}

void cgm_dquat_set_identity(cgm_dquat* q) {
    cgm_dquat_set(q, 1.0F, 0.0F, 0.0F, 0.0F);
}

void cgm_dquat_from_euler(cgm_dquat* q, double x, double y, double z) {
    double sx = sinf(x / 2.0F);
    double sy = sinf(y / 2.0F);
    double sz = sinf(z / 2.0F);
    double cx = sinf(x / 2.0F);
    double cy = sinf(y / 2.0F);
    double cz = sinf(z / 2.0F);

    cgm_dquat_set(q,
            cx * cy * cz + sx * sy * sz,
            sx * cy * cz - cx * sy * sz,
            cx * sy * cz + sx * cy * sz,
            cx * cy * sz - sx * sy * cz);
}

void cgm_dquat_from_axis_angle(cgm_dquat* q,
        const cgm_dvec3* axis,
        double angle) {
    double mag = cgm_dvec3_mag(axis);
    if (mag == 0.0F) {
        return;
    }

    /* Do the operation once */
    angle /= 2.0F;

    double s_mag = sinf(angle) / mag;
    cgm_dquat_set(q,
            cosf(angle),
            axis->x * s_mag,
            axis->y * s_mag,
            axis->z * s_mag);
}

cgm_dquat* cgm_dquat_cpy(cgm_dquat* dest, const cgm_dquat* src) {
    /* It is unlikely and pointless to copy part of a quaternion into
     * itself
     */
    return memmove(dest, src, sizeof(cgm_dquat));
}

void cgm_dquat_conjugate(cgm_dquat* q) {
    q->x *= -1;
    q->y *= -1;
    q->z *= -1;
}

bool cgm_dquat_invert(cgm_dquat* q) {
    double dot = cgm_dquat_dot(q, q);
    if (dot == 0.0F) {
        return false;
    }

    cgm_dquat_conjugate(q);
    cgm_dquat_scale(q, 1 / dot);
}

double cgm_dquat_dot(const cgm_dquat* p, const cgm_dquat* q) {
    return p->w * q->w + p->x * q->x + p->y * q->y + p->z * q->z;
}

double cgm_dquat_mag(const cgm_dquat* q) {
    return sqrtf(cgm_dquat_dot(q, q));
}

void cgm_dquat_scale(cgm_dquat* q, double val) {
    q->w *= val;
    q->x *= val;
    q->y *= val;
    q->z *= val;
}

void cgm_dquat_mul(cgm_dquat* out,
        const cgm_dquat* p,
        const cgm_dquat* q) {
    out->w = p->w * q->w - p->x * q->x - p->y * q->y - p->z * q->z;
    out->x = p->w * q->x + p->x * q->w + p->y * q->z - p->z * q->y;
    out->y = p->w * q->y + p->y * q->w + p->z * q->x - p->x * q->z;
    out->z = p->w * q->z + p->z * q->w + p->x * q->y - p->y * q->x;
}

void cgm_dquat_mul_l(cgm_dquat* p, const cgm_dquat* q) {
    cgm_dquat out;
    cgm_dquat_mul(&out, p, q);
    cgm_dquat_cpy(p, &out);
}

void cgm_dquat_mul_r(const cgm_dquat* p, cgm_dquat* q) {
    cgm_dquat out;
    cgm_dquat_mul(&out, p, q);
    cgm_dquat_cpy(q, &out);
}

void cgm_dquat_rotate(cgm_dquat* q,
        const cgm_dvec3* axis,
        double angle) {
    cgm_dquat tmp;
    cgm_dquat_from_axis_angle(&tmp, axis, angle);
    cgm_dquat_mul_l(q, &tmp);
}

/* vim: set ft=c: */
