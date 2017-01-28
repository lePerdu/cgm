/**
 * dmat4.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../vector/dvec3.h"
#include "../vector/dvec4.h"
#include "../quaternion/dquaternion.h"
#include "dmat4.h"

void cgm_dmat4_fill(cgm_dmat4* m, double val) {
    for (int i = 0; i < 16; i++) {
        m->arr[i] = val;
    }
}

void cgm_dmat4_set_m3(cgm_dmat4* m, const cgm_dmat3* m3) {
    cgm_dvec4_set_v3(&m->vec[0], &m3->vec[0], 0.0F);
    cgm_dvec4_set_v3(&m->vec[1], &m3->vec[1], 0.0F);
    cgm_dvec4_set_v3(&m->vec[2], &m3->vec[2], 0.0F);
    cgm_dvec4_set(&m->vec[3], 0.0F, 0.0F, 0.0F, 1.0F);
}

void cgm_dmat4_set_dquat(cgm_dmat4* m, const cgm_dquat* q) {
    double xx = q->x * q->x;
    double yy = q->y * q->y;
    double zz = q->z * q->z;
    double xz = q->x * q->z;
    double xy = q->x * q->y;
    double yz = q->y * q->z;
    double wx = q->w * q->x;
    double wy = q->w * q->y;
    double wz = q->w * q->z;

    m->m[0][0] = 1.0F - 2.0F * (yy +  zz);
    m->m[0][1] = 2.0F * (xy + wz);
    m->m[0][2] = 2.0F * (xz - wy);
    m->m[0][3] = 0.0F;

    m->m[1][0] = 2.0F * (xy - wz);
    m->m[1][1] = 1.0F - 2.0F * (xx +  zz);
    m->m[1][2] = 2.0F * (yz + wx);
    m->m[1][3] = 0.0F;

    m->m[2][0] = 2.0F * (xz + wy);
    m->m[2][1] = 2.0F * (yz - wx);
    m->m[2][2] = 1.0F - 2.0F * (xx +  yy);
    m->m[2][3] = 0.0F;

    m->m[3][0] = 0.0F;
    m->m[3][1] = 0.0F;
    m->m[3][2] = 0.0F;
    m->m[3][3] = 1.0F;
}

void cgm_dmat4_set_identity(cgm_dmat4* m) {
    for (int i = 0; i < 16; i++) {
        if (i % 5 == 0) {
            m->arr[i] = 1;
        } else {
            m->arr[i] = 0;
        }
    }
}

cgm_dmat4* cgm_dmat4_cpy(cgm_dmat4* dest, const cgm_dmat4* src) {
    return memcpy(dest, src, sizeof(cgm_dmat4));
}

bool cgm_dmat4_equals(const cgm_dmat4* a, const cgm_dmat4* b) {
    for (int i = 0; i < 16; i++) {
        if (a->arr[i] != b->arr[i]) {
            return false;
        }
    }

    return true;
}

void cgm_dmat4_add(cgm_dmat4* a, const cgm_dmat4* b) {
    for (int i = 0; i < 16; i++) {
        a->arr[i] += b->arr[i];
    }
}

void cgm_dmat4_sub(cgm_dmat4* a, const cgm_dmat4* b) {
    for (int i = 0; i < 16; i++) {
        a->arr[i] -= b->arr[i];
    }
}

void cgm_dmat4_scal(cgm_dmat4* m, double val) {
    for (int i = 0; i < 16; i++) {
        m->arr[i] *= val;
    }
}

void cgm_dmat4_mul(cgm_dmat4* out, const cgm_dmat4* a, const cgm_dmat4* b) {
    cgm_dmat4_fill(out, 0);
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            double tmp = b->m[i][k];
            for (int j = 0; j < 4; j++) {
                out->m[i][j] += tmp * a->m[k][j];
            }
        }
    }
}

void cgm_dmat4_mul_l(cgm_dmat4* a, const cgm_dmat4* b) {
    cgm_dmat4 out;
    cgm_dmat4_mul(&out, a, b);
    cgm_dmat4_cpy(a, &out);
}

void cgm_dmat4_mul_r(const cgm_dmat4* a, cgm_dmat4* b) {
    cgm_dmat4 out;
    cgm_dmat4_mul(&out, a, b);
    cgm_dmat4_cpy(b, &out);
}

void cgm_dmat4_mul_v3(const cgm_dmat4* m, cgm_dvec3* v) {
    double x = v->x, y = v->y, z = v->z;
    v->x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z + m->m[3][0];
    v->y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z + m->m[3][1];
    v->z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z + m->m[3][2];
}

void cgm_dmat4_mul_v4(const cgm_dmat4* m, cgm_dvec4* v) {
    double x = v->x, y = v->y, z = v->z, w = v->w;
    v->x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z + m->m[3][0] * w;
    v->y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z + m->m[3][1] * w;
    v->z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z + m->m[3][2] * w;
    v->w = m->m[0][3] * x + m->m[1][3] * y + m->m[2][3] * z + m->m[3][3] * w;
}

void cgm_dmat4_mul_dquat(cgm_dmat4* m, const cgm_dquat* q) {
    cgm_dmat4 tmp;
    cgm_dmat4_set_dquat(&tmp, q);
    cgm_dmat4_mul_l(m, &tmp);
}

double cgm_dmat4_det(const cgm_dmat4* m) {
    double sf0 = m->m[2][2] * m->m[3][3] - m->m[3][2] * m->m[2][3];
    double sf1 = m->m[2][1] * m->m[3][3] - m->m[3][1] * m->m[2][3];
    double sf2 = m->m[2][1] * m->m[3][2] - m->m[3][1] * m->m[2][2];
    double sf3 = m->m[2][0] * m->m[3][3] - m->m[3][0] * m->m[2][3];
    double sf4 = m->m[2][0] * m->m[3][2] - m->m[3][0] * m->m[2][2];
    double sf5 = m->m[2][0] * m->m[3][1] - m->m[3][0] * m->m[2][1];

    double df0 = + (m->m[1][1] * sf0 - m->m[1][2] * sf1 + m->m[1][3] * sf2);
    double df1 = - (m->m[1][0] * sf0 - m->m[1][2] * sf3 + m->m[1][3] * sf4);
    double df2 = + (m->m[1][0] * sf1 - m->m[1][1] * sf3 + m->m[1][3] * sf5);
    double df3 = - (m->m[1][0] * sf2 - m->m[1][1] * sf4 + m->m[1][2] * sf5);

    return m->m[0][0] * df0
        + m->m[0][1] * df1
        + m->m[0][2] * df2
        + m->m[0][3] * df3;
}

void cgm_dmat4_transpose(cgm_dmat4* m) {
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            double tmp = m->m[i][j];
            m->m[i][j] = m->m[j][i];
            m->m[j][i] = tmp;
        }
    }
}

int cgm_dmat4_invert(cgm_dmat4* m) {
    double d_23_01 = m->m[2][0] * m->m[3][1] - m->m[3][0] * m->m[2][1];
    double d_23_02 = m->m[2][0] * m->m[3][2] - m->m[3][0] * m->m[2][2];
    double d_23_03 = m->m[2][0] * m->m[3][3] - m->m[3][0] * m->m[2][3];
    double d_23_12 = m->m[2][1] * m->m[3][2] - m->m[3][1] * m->m[2][2];
    double d_23_13 = m->m[2][1] * m->m[3][3] - m->m[3][1] * m->m[2][3];
    double d_23_23 = m->m[2][2] * m->m[3][3] - m->m[3][2] * m->m[2][3];

    double d_01_01 = m->m[0][0] * m->m[1][1] - m->m[1][0] * m->m[0][1];
    double d_01_02 = m->m[0][0] * m->m[1][2] - m->m[1][0] * m->m[0][2];
    double d_01_03 = m->m[0][0] * m->m[1][3] - m->m[1][0] * m->m[0][3];
    double d_01_12 = m->m[0][1] * m->m[1][2] - m->m[1][1] * m->m[0][2];
    double d_01_13 = m->m[0][1] * m->m[1][3] - m->m[1][1] * m->m[0][3];
    double d_01_23 = m->m[0][2] * m->m[1][3] - m->m[1][2] * m->m[0][3];

    cgm_dmat4 inv;
    inv.m[0][0] = + (m->m[1][1] * d_23_23 - m->m[1][2] * d_23_13 + m->m[1][3] * d_23_12);
    inv.m[0][1] = - (m->m[0][1] * d_23_23 - m->m[0][2] * d_23_13 + m->m[0][3] * d_23_12);
    inv.m[0][2] = + (m->m[3][1] * d_01_23 - m->m[3][2] * d_01_13 + m->m[3][3] * d_01_12);
    inv.m[0][3] = - (m->m[2][1] * d_01_23 - m->m[2][2] * d_01_13 + m->m[2][3] * d_01_12);

    double det = m->m[0][0] * inv.m[0][0] + m->m[1][0] * inv.m[0][1] +
        m->m[2][0] * inv.m[0][2] + m->m[3][0] * inv.m[0][3];
    if (det == 0) {
        return false;
    }

    inv.m[1][0] = - (m->m[1][0] * d_23_23 - m->m[1][2] * d_23_03 + m->m[1][3] * d_23_02);
    inv.m[1][1] = + (m->m[0][0] * d_23_23 - m->m[0][2] * d_23_03 + m->m[0][3] * d_23_02);
    inv.m[1][2] = - (m->m[3][0] * d_01_23 - m->m[3][2] * d_01_03 + m->m[3][3] * d_01_02);
    inv.m[1][3] = + (m->m[2][0] * d_01_23 - m->m[2][2] * d_01_03 + m->m[2][3] * d_01_02);

    inv.m[2][0] = + (m->m[1][0] * d_23_13 - m->m[1][1] * d_23_03 + m->m[1][3] * d_23_01);
    inv.m[2][1] = - (m->m[0][0] * d_23_13 - m->m[0][1] * d_23_03 + m->m[0][3] * d_23_01);
    inv.m[2][2] = + (m->m[3][0] * d_01_13 - m->m[3][1] * d_01_03 + m->m[3][3] * d_01_01);
    inv.m[2][3] = - (m->m[2][0] * d_01_13 - m->m[2][1] * d_01_03 + m->m[2][3] * d_01_01);

    inv.m[3][0] = - (m->m[1][0] * d_23_12 - m->m[1][1] * d_23_02 + m->m[1][2] * d_23_01);
    inv.m[3][1] = + (m->m[0][0] * d_23_12 - m->m[0][1] * d_23_02 + m->m[0][2] * d_23_01);
    inv.m[3][2] = - (m->m[3][0] * d_01_12 - m->m[3][1] * d_01_02 + m->m[3][2] * d_01_01);
    inv.m[3][3] = + (m->m[2][0] * d_01_12 - m->m[2][1] * d_01_02 + m->m[2][2] * d_01_01);

    cgm_dmat4_scal(&inv, 1 / det);
    cgm_dmat4_cpy(m, &inv);
}

int cgm_dmat4_fprintf(FILE* stream, const cgm_dmat4* m) {
    int len = 0;
    for (int i = 0; i < 4; i++) {
        len += fprintf(stream, "%g\t%g\t%g\t%g\n", m->m[i][0], m->m[i][1], m->m[i][2], m->m[i][3]);
    }

    return len;
}

int cgm_dmat4_printf(const cgm_dmat4* m) {
    return cgm_dmat4_fprintf(stdout, m);
}

/* vim: set ft=c: */
