/**
 * mat4.inl
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "vec3.h"
#include "vec4.h"

inline void cgm_mat4_fill(cgm_mat4* m, float val) {
    for (int i = 0; i < 16; i++) {
        m->arr[i] = val;
    }
}

inline void cgm_mat4_set_identity(cgm_mat4* m) {
    for (int i = 0; i < 16; i++) {
        if (i % 5 == 0) {
            m->arr[i] = 1;
        } else {
            m->arr[i] = 0;
        }
    }
}

inline cgm_mat4* cgm_mat4_cpy(cgm_mat4* dest, const cgm_mat4* src) {
    return memcpy(dest, src, sizeof(cgm_mat4));
}

inline int cgm_mat4_equals(const cgm_mat4* a, const cgm_mat4* b) {
    for (int i = 0; i < 16; i++) {
        if (a->arr[i] != b->arr[i]) {
            return false;
        }
    }

    return true;
}

inline void cgm_mat4_add(cgm_mat4* a, const cgm_mat4* b) {
    for (int i = 0; i < 16; i++) {
        a->arr[i] += b->arr[i];
    }
}

inline void cgm_mat4_sub(cgm_mat4* a, const cgm_mat4* b) {
    for (int i = 0; i < 16; i++) {
        a->arr[i] -= b->arr[i];
    }
}

inline void cgm_mat4_scal(cgm_mat4* m, float val) {
    for (int i = 0; i < 16; i++) {
        m->arr[i] *= val;
    }
}

inline void cgm_mat4_mul(cgm_mat4* out, const cgm_mat4* a, const cgm_mat4* b) {
    cgm_mat4_fill(out, 0);
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            float tmp = b->m[i][k];
            for (int j = 0; j < 4; j++) {
                out->m[i][j] += tmp * a->m[k][j];
            }
        }
    }
}

inline void cgm_mat4_mul_l(cgm_mat4* a, const cgm_mat4* b) {
    cgm_mat4 out;
    cgm_mat4_mul(&out, a, b);
    cgm_mat4_cpy(a, &out);
}

inline void cgm_mat4_mul_r(const cgm_mat4* a, cgm_mat4* b) {
    cgm_mat4 out;
    cgm_mat4_mul(&out, a, b);
    cgm_mat4_cpy(b, &out);
}

inline void cgm_mat4_mul_v3(const cgm_mat4* m, cgm_vec3* v) {
    float x = v->x, y = v->y, z = v->z;
    v->x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z + m->m[3][0];
    v->y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z + m->m[3][1];
    v->z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z + m->m[3][2];
}

inline void cgm_mat4_mul_v4(const cgm_mat4* m, cgm_vec4* v) {
    float x = v->x, y = v->y, z = v->z, w = v->w;
    v->x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z + m->m[3][0] * w;
    v->y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z + m->m[3][1] * w;
    v->z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z + m->m[3][2] * w;
    v->w = m->m[0][3] * x + m->m[1][3] * y + m->m[2][3] * z + m->m[3][3] * w;
}

inline float cgm_mat4_det(const cgm_mat4* m) {
    float sf0 = m->m[2][2] * m->m[3][3] - m->m[3][2] * m->m[2][3];
    float sf1 = m->m[2][1] * m->m[3][3] - m->m[3][1] * m->m[2][3];
    float sf2 = m->m[2][1] * m->m[3][2] - m->m[3][1] * m->m[2][2];
    float sf3 = m->m[2][0] * m->m[3][3] - m->m[3][0] * m->m[2][3];
    float sf4 = m->m[2][0] * m->m[3][2] - m->m[3][0] * m->m[2][2];
    float sf5 = m->m[2][0] * m->m[3][1] - m->m[3][0] * m->m[2][1];

    float df0 = + (m->m[1][1] * sf0 - m->m[1][2] * sf1 + m->m[1][3] * sf2);
    float df1 = - (m->m[1][0] * sf0 - m->m[1][2] * sf3 + m->m[1][3] * sf4);
    float df2 = + (m->m[1][0] * sf1 - m->m[1][1] * sf3 + m->m[1][3] * sf5);
    float df3 = - (m->m[1][0] * sf2 - m->m[1][1] * sf4 + m->m[1][2] * sf5);
   
    return m->m[0][0] * df0
         + m->m[0][1] * df1
         + m->m[0][2] * df2
         + m->m[0][3] * df3;
}

inline void cgm_mat4_transpose(cgm_mat4* m) {
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            float tmp = m->m[i][j];
            m->m[i][j] = m->m[j][i];
            m->m[j][i] = tmp;
        }
    }
}

inline int cgm_mat4_invert(cgm_mat4* m) {
    float d_23_01 = m->m[2][0] * m->m[3][1] - m->m[3][0] * m->m[2][1];
    float d_23_02 = m->m[2][0] * m->m[3][2] - m->m[3][0] * m->m[2][2];
    float d_23_03 = m->m[2][0] * m->m[3][3] - m->m[3][0] * m->m[2][3];
    float d_23_12 = m->m[2][1] * m->m[3][2] - m->m[3][1] * m->m[2][2];
    float d_23_13 = m->m[2][1] * m->m[3][3] - m->m[3][1] * m->m[2][3];
    float d_23_23 = m->m[2][2] * m->m[3][3] - m->m[3][2] * m->m[2][3];

    float d_01_01 = m->m[0][0] * m->m[1][1] - m->m[1][0] * m->m[0][1];
    float d_01_02 = m->m[0][0] * m->m[1][2] - m->m[1][0] * m->m[0][2];
    float d_01_03 = m->m[0][0] * m->m[1][3] - m->m[1][0] * m->m[0][3];
    float d_01_12 = m->m[0][1] * m->m[1][2] - m->m[1][1] * m->m[0][2];
    float d_01_13 = m->m[0][1] * m->m[1][3] - m->m[1][1] * m->m[0][3];
    float d_01_23 = m->m[0][2] * m->m[1][3] - m->m[1][2] * m->m[0][3];

    cgm_mat4 inv;
    inv.m[0][0] = + (m->m[1][1] * d_23_23 - m->m[1][2] * d_23_13 + m->m[1][3] * d_23_12);
    inv.m[0][1] = - (m->m[0][1] * d_23_23 - m->m[0][2] * d_23_13 + m->m[0][3] * d_23_12);
    inv.m[0][2] = + (m->m[3][1] * d_01_23 - m->m[3][2] * d_01_13 + m->m[3][3] * d_01_12);
    inv.m[0][3] = - (m->m[2][1] * d_01_23 - m->m[2][2] * d_01_13 + m->m[2][3] * d_01_12);

    float det = m->m[0][0] * inv.m[0][0] + m->m[1][0] * inv.m[0][1] +
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

    cgm_mat4_scal(&inv, 1 / det);
    cgm_mat4_cpy(m, &inv);
}

inline int cgm_mat4_fprintf(FILE* stream, const cgm_mat4* m) {
    int len = 0;
    for (int i = 0; i < 4; i++) {
        len += fprintf(stream, "%g\t%g\t%g\t%g\n", m->m[i][0], m->m[i][1], m->m[i][2], m->m[i][3]);
    }

    return len;
}

inline int cgm_mat4_printf(const cgm_mat4* m) {
    return cgm_mat4_fprintf(stdout, m);
}

/* vim: set ft=c: */
