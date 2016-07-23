/**
 * transform.inl
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 *
 * Inline definitions for transform.h.
 */

#include <math.h>

#include "mat4.h"
#include "vec3.h"

inline void cgm_set_ortho(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far) {
    if (right <= left ||
            top   <= bottom ||
            far   <= near) {
        return;
    }

    cgm_mat4_set_identity(m);

    m->m[0][0] = 2 / (right - left);
    m->m[1][1] = 2 / (top - bottom);
    m->m[2][2] = - 2 / (far - near);

    m->m[3][0] = - (right + left) / (right - left);
    m->m[3][1] = - (top + bottom) / (top - bottom);
    m->m[3][2] = - (far + near)   / (far - near);
}

inline void cgm_ortho(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far) {
    if (right <= left ||
            top   <= bottom ||
            far   <= near) {
        return;
    }

    cgm_mat4 ortho;
    cgm_set_ortho(&ortho, left, right, bottom, top, near, far);
    cgm_mat4_mul_l(m, &ortho);
}

inline void cgm_set_frustum(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far) {
    if (right <= left ||
            top   <= bottom ||
            far   <= near) {
        return;
    }

    cgm_mat4_fill(m, 0);

    m->m[0][0] = 2 * near / (right - left);
    m->m[1][1] = 2 * near / (top - bottom);
    m->m[3][2] = - 2 * far * near / (far - near);
    m->m[2][3] = -1;

    m->m[0][2] = (right + left) / (right - left);
    m->m[1][2] = (top + bottom) / (top - bottom);
    m->m[2][2] = - (far + near) / (far - near);
}

inline void cgm_frustum(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far) {
    if (right <= left ||
            top   <= bottom ||
            far   <= near) {
        return;
    }

    cgm_mat4 frustum;
    cgm_set_frustum(&frustum, left, right, bottom, top, near, far);
    cgm_mat4_mul_l(m, &frustum);
}

inline void cgm_set_perspective(
        cgm_mat4* m,
        float fov_y, float aspect,
        float near, float far) {
    if (fov_y < 0 || fov_y > M_PI ||
            aspect < 0 ||
            far <= near) {
        return;
    }

    float height = tanf(fov_y / 2) * near;
    float width = height * aspect;
    cgm_set_frustum(m, -width, width, -height, height, near, far);
}

inline void cgm_perspective(
        cgm_mat4* m,
        float fov_y, float aspect,
        float near, float far) {
    if (fov_y < 0 || fov_y > M_PI ||
            aspect < 0 ||
            far <= near) {
        return;
    }

    cgm_mat4 perspective;
    cgm_set_perspective(&perspective, fov_y, aspect, near, far);
    cgm_mat4_mul_l(m, &perspective);
}

inline void cgm_set_lookat(
        cgm_mat4* m,
        const cgm_vec3* eye,
        const cgm_vec3* center,
        const cgm_vec3* up) {
    cgm_vec3 f, u, s;

    cgm_vec3_cpy(&f, center);
    cgm_vec3_sub(&f, eye);
    cgm_vec3_norm(&f);

    cgm_vec3_cross(&s, &f, up);
    cgm_vec3_norm(&s);

    cgm_vec3_cross(&u, &s, &f);

    cgm_mat4_set_identity(m);

    m->m[0][0] =  s.x;
    m->m[1][0] =  s.y;
    m->m[2][0] =  s.z;
    m->m[0][1] =  u.x;
    m->m[1][1] =  u.y;
    m->m[2][1] =  u.z;
    m->m[0][2] = -f.x;
    m->m[1][2] = -f.y;
    m->m[2][2] = -f.z;
    cgm_translate(m, -eye->x, -eye->y, -eye->z);
}

inline void cgm_lookat(
        cgm_mat4* m,
        const cgm_vec3* eye,
        const cgm_vec3* center,
        const cgm_vec3* up) {
    cgm_mat4 lookat;
    cgm_set_lookat(&lookat, eye, center, up);
    cgm_mat4_mul_l(m, &lookat);
}

inline void cgm_set_translate(cgm_mat4* m, float x, float y, float z) {
    cgm_mat4_set_identity(m);

    m->m[3][0] = x;
    m->m[3][1] = y;
    m->m[3][2] = z;
}

inline void cgm_translate(cgm_mat4* m, float x, float y, float z) {
    cgm_mat4 translate;
    cgm_set_translate(&translate, x, y, z);
    cgm_mat4_mul_l(m, &translate);
}

inline void cgm_set_scale(cgm_mat4* m, float x, float y, float z) {
    cgm_mat4_set_identity(m);

    m->m[0][0] = x;
    m->m[1][1] = y;
    m->m[2][2] = z;
}

inline void cgm_scale(cgm_mat4* m, float x, float y, float z) {
    cgm_mat4 scale;
    cgm_set_scale(&scale, x, y, z);
    cgm_mat4_mul_l(m, &scale);
}

inline void cgm_set_rotate_x(cgm_mat4* m, float ang) {
    float s = sinf(ang);
    float c = cosf(ang);

    cgm_mat4_set_identity(m);
    m->m[1][1] = c;
    m->m[1][2] = -s;
    m->m[2][1] = s;
    m->m[2][2] = c;
}

inline void cgm_rotate_x(cgm_mat4* m, float ang) {
    cgm_mat4 rotate;
    cgm_rotate_x(&rotate, ang);
    cgm_mat4_mul_l(m, &rotate);
}

inline void cgm_set_rotate_y(cgm_mat4* m, float ang) {
    float s = sinf(ang);
    float c = cosf(ang);

    cgm_mat4_set_identity(m);
    m->m[0][0] = c;
    m->m[0][2] = s;
    m->m[2][0] = -s;
    m->m[2][2] = c;
}

inline void cgm_rotate_y(cgm_mat4* m, float ang) {
    cgm_mat4 rotate;
    cgm_rotate_y(&rotate, ang);
    cgm_mat4_mul_l(m, &rotate);
}

inline void cgm_set_rotate_z(cgm_mat4* m, float ang) {
    float s = sinf(ang);
    float c = cosf(ang);

    cgm_mat4_set_identity(m);
    m->m[0][0] = c;
    m->m[0][1] = -s;
    m->m[1][0] = s;
    m->m[1][1] = c;
}

inline void cgm_rotate_z(cgm_mat4* m, float ang) {
    cgm_mat4 rotate;
    cgm_rotate_z(&rotate, ang);
    cgm_mat4_mul_l(m, &rotate);
}

inline void cgm_set_rotate(cgm_mat4* m, const cgm_vec3* axis, float ang) {
    float mag = cgm_vec3_mag(axis);
    if (mag == 0) {
        return;
    }

    float x = axis->x / mag;
    float y = axis->y / mag;
    float z = axis->z / mag;

    float s = sinf(ang);
    float c = cosf(ang);
    float p = 1 - c;

    cgm_mat4_set_identity(m);

    m->m[0][0] = c + x*x * p;
    m->m[0][1] =     x*y * p + z * s;
    m->m[0][2] =     x*z * p - y * s;
    m->m[1][0] =     y*x * p - z * s;
    m->m[1][1] = c + y*y * p;
    m->m[1][2] =     y*z * p + x * s;
    m->m[2][0] =     z*x * p + y * s;
    m->m[2][1] =     z*y * p - x * s;
    m->m[2][2] = c + z*z * p;
}

inline void cgm_rotate(cgm_mat4* m, const cgm_vec3* axis, float ang) {
    cgm_mat4 rotate;
    cgm_set_rotate(&rotate, axis, ang);
    cgm_mat4_mul_l(m, &rotate);
}

/* vim: set ft=c: */
