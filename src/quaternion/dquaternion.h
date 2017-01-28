/**
 * dquaternion.h
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef DQUATERNION_H_
#define DQUATERNION_H_

#include <stdbool.h>

#include "../vector/dvec3.h"

/**
 * A quaternion with double point components.
 */
typedef union cgm_dquat {
    /**
     * Component representation of the quaternion.
     */
    struct {
        /**
         * The w component.
         */
        double w;

        union {
            struct {
                /**
                 * The x, y, and z components.
                 */
                double x;
                double y;
                double z;
            };

            /**
             * The x, y, and z components as a cgm_dvec3.
             */
            cgm_dvec3 xyz;
        };
    };

    /**
     * Float array representation of the quaternion.
     */
    double q[4];
} cgm_dquat;

#define CGM_QUAT(W, X, Y, Z) ((const cgm_dquat*) &((cgm_dquat) {{(W), (X), (Y), (Z)}}))

/**
 * Sets the components of a quaternion.
 * @param q - The quaternion to set.
 * @param w - The w component.
 * @param x - The x component.
 * @param y - The y component.
 * @param z - The z component.
 */
void cgm_dquat_set(cgm_dquat* q,
        double w, double x, double y, double z);

/**
 * Sets the components of a quaternion from a w component and a
 * cgm_dvec3.
 * @param q - The quaternion to set.
 * @param w - The w component.
 * @param xyz - The x, y, and z components.
 */
void cgm_dquat_set_v3(cgm_dquat* q, double w, const cgm_dvec3* xyz);

/**
 * Sets a quaternion to the identity, one which has no rotation.
 * @param q - The quaternion to set.
 */
void cgm_dquat_set_identity(cgm_dquat* q);

/**
 * Sets a quaternion from Euler angles (around x, y, and z axes).
 * @param q - The quaternion to set.
 * @param x - The angle around the x axis (in radians).
 * @param y - The angle around the y axis (in radians).
 * @param z - The angle around the z axis (in radians).
 */
void cgm_dquat_from_euler(cgm_dquat* q, double x, double y, double z);

/**
 * Sets a quaternion to a rotation of a specified angle around a
 * specified axis.
 * @param q - The quaternion to set.
 * @param axis - The axis around which to rotate.
 * @param angle - The angle to rotate.
 */
void cgm_dquat_from_axis_angle(cgm_dquat* q,
        const cgm_dvec3* axis,
        double angle);

/**
 * Copies a quaternion into another.
 * @param dest - The quaternion into which to copy.
 * @param src - The quaternion to copy.
 * @return The quaternion into which data was copied.
 */
cgm_dquat* cgm_dquat_cpy(cgm_dquat* dest, const cgm_dquat* src);

/**
 * Conjugates quaternion.
 * The conjugate is analagous to a complex conjugate: the product of a
 * quaternion and its conjugate yields one with a null vector portion.
 * @param q - The quaternion to conjugate.
 */
void cgm_dquat_conjugate(cgm_dquat* q);

/**
 * Inverts a quaternion.
 * The product of a quaternion and its inverse is the identity
 * quaternion.
 * @param q - The quaternion to invert.
 */
bool cgm_dquat_invert(cgm_dquat* q);

/**
 * Calculates the dot product (element-wise multiplication) of two quaternions.
 * @param p - The first quaternion.
 * @param q - The second quaternion.
 * @return The dot product p * q
 */
double cgm_dquat_dot(const cgm_dquat* p, const cgm_dquat* q);

/**
 * Calculates the magnitude of a quaternion.
 * @param q - The quaternion of which to find the magnitude.
 * @param The magnitude of the quaternion.
 */
double cgm_dquat_mag(const cgm_dquat* q);

/**
 * Scales each component of a quaternion by a scalar.
 * @param q - The quaternion to scale.
 * @param val - The scalar.
 */
void cgm_dquat_scale(cgm_dquat* q, double val);

/**
 * Multiplies two quaternions.
 * The operation `out = p * q' is performed.
 * @param out - The quaternion to store the result.
 * @param p - The quaternion multiplied on the left.
 * @param q - The quaternion multiplied on the right.
 */
void cgm_dquat_mul(cgm_dquat* out,
        const cgm_dquat* p,
        const cgm_dquat* q);

/**
 * Multiplies two quaternions and stores the result to the first one.
 * @param p - The quaternion to multiply on the left and store the
 * result.
 * @param q - The quaternion to multiple on the right.
 */
void cgm_dquat_mul_l(cgm_dquat* p, const cgm_dquat* q);

/**
 * Multiplies two quaternions and stores the result to the second one.
 * @param p - The quaternion to multiply on the left.
 * @param q - The quaternion to multiple on the right and store the
 * result.
 */
void cgm_dquat_mul_r(const cgm_dquat* p, cgm_dquat* q);

/**
 * Rotates a quaternion a specified angle about a specified axis.
 * @param q - The quaternion to rotate.
 * @param axis - The axis around which to rotate.
 * @param angle - The angle to rotate.
 */
void cgm_dquat_rotate(cgm_dquat* q,
        const cgm_dvec3* axis,
        double angle);

#endif /* DQUATERNION_H_ */

/* vim: set ft=c: */
