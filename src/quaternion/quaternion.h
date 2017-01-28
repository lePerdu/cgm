/**
 * quaternion.h
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_

#include <stdbool.h>

#include "../vector/vec3.h"

/**
 * A quaternion with floating point components.
 */
typedef union cgm_quat {
    /**
     * Component representation of the quaternion.
     */
    struct {
        /**
         * The w component.
         */
        float w;

        union {
            struct {
                /**
                 * The x, y, and z components.
                 */
                float x;
                float y;
                float z;
            };

            /**
             * The x, y, and z components as a cgm_vec3.
             */
            cgm_vec3 xyz;
        };
    };

    /**
     * Float array representation of the quaternion.
     */
    float q[4];
} cgm_quat;

#define CGM_QUAT(W, X, Y, Z) ((const cgm_quat*) &((cgm_quat) {{(W), (X), (Y), (Z)}}))

/**
 * Sets the components of a quaternion.
 * @param q - The quaternion to set.
 * @param w - The w component.
 * @param x - The x component.
 * @param y - The y component.
 * @param z - The z component.
 */
void cgm_quat_set(cgm_quat* q,
        float w, float x, float y, float z);

/**
 * Sets the components of a quaternion from a w component and a
 * cgm_vec3.
 * @param q - The quaternion to set.
 * @param w - The w component.
 * @param xyz - The x, y, and z components.
 */
void cgm_quat_set_v3(cgm_quat* q, float w, const cgm_vec3* xyz);

/**
 * Sets a quaternion to the identity, one which has no rotation.
 * @param q - The quaternion to set.
 */
void cgm_quat_set_identity(cgm_quat* q);

/**
 * Sets a quaternion from Euler angles (around x, y, and z axes).
 * @param q - The quaternion to set.
 * @param x - The angle around the x axis (in radians).
 * @param y - The angle around the y axis (in radians).
 * @param z - The angle around the z axis (in radians).
 */
void cgm_quat_from_euler(cgm_quat* q, float x, float y, float z);

/**
 * Sets a quaternion to a rotation of a specified angle around a
 * specified axis.
 * @param q - The quaternion to set.
 * @param axis - The axis around which to rotate.
 * @param angle - The angle to rotate.
 */
void cgm_quat_from_axis_angle(cgm_quat* q,
        const cgm_vec3* axis,
        float angle);

/**
 * Copies a quaternion into another.
 * @param dest - The quaternion into which to copy.
 * @param src - The quaternion to copy.
 * @return The quaternion into which data was copied.
 */
cgm_quat* cgm_quat_cpy(cgm_quat* dest, const cgm_quat* src);

/**
 * Conjugates quaternion.
 * The conjugate is analagous to a complex conjugate: the product of a
 * quaternion and its conjugate yields one with a null vector portion.
 * @param q - The quaternion to conjugate.
 */
void cgm_quat_conjugate(cgm_quat* q);

/**
 * Inverts a quaternion.
 * The product of a quaternion and its inverse is the identity
 * quaternion.
 * @param q - The quaternion to invert.
 */
bool cgm_quat_invert(cgm_quat* q);

/**
 * Calculates the dot product (element-wise multiplication) of two quaternions.
 * @param p - The first quaternion.
 * @param q - The second quaternion.
 * @return The dot product p * q
 */
float cgm_quat_dot(const cgm_quat* p, const cgm_quat* q);

/**
 * Calculates the magnitude of a quaternion.
 * @param q - The quaternion of which to find the magnitude.
 * @param The magnitude of the quaternion.
 */
float cgm_quat_mag(const cgm_quat* q);

/**
 * Scales each component of a quaternion by a scalar.
 * @param q - The quaternion to scale.
 * @param val - The scalar.
 */
void cgm_quat_scale(cgm_quat* q, float val);

/**
 * Multiplies two quaternions.
 * The operation `out = p * q' is performed.
 * @param out - The quaternion to store the result.
 * @param p - The quaternion multiplied on the left.
 * @param q - The quaternion multiplied on the right.
 */
void cgm_quat_mul(cgm_quat* out,
        const cgm_quat* p,
        const cgm_quat* q);

/**
 * Multiplies two quaternions and stores the result to the first one.
 * @param p - The quaternion to multiply on the left and store the
 * result.
 * @param q - The quaternion to multiple on the right.
 */
void cgm_quat_mul_l(cgm_quat* p, const cgm_quat* q);

/**
 * Multiplies two quaternions and stores the result to the second one.
 * @param p - The quaternion to multiply on the left.
 * @param q - The quaternion to multiple on the right and store the
 * result.
 */
void cgm_quat_mul_r(const cgm_quat* p, cgm_quat* q);

/**
 * Rotates a quaternion a specified angle about a specified axis.
 * @param q - The quaternion to rotate.
 * @param axis - The axis around which to rotate.
 * @param angle - The angle to rotate.
 */
void cgm_quat_rotate(cgm_quat* q,
        const cgm_vec3* axis,
        float angle);

/**
 * Prints a cgm_quat to a stream.
 * The quaternion is printed as "(x, y, z, w)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param q - Quaternion to print.
 * @return The number of characters printed.
 */
int cgm_quat_fprintf(FILE* stream, const cgm_quat* q);

/**
 * Prints a cgm_quat to stdout.
 * The quaternion is printed in the format of cgm_quat_fprintf().
 * @param q - Quaternion to print.
 * @return The number of characters printed.
 */
int cgm_quat_printf(const cgm_quat* q);

#endif /* QUATERNION_H_ */

/* vim: set ft=c: */
