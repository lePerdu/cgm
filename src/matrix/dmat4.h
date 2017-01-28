/**
 * dmat4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef DMAT4_H_
#define DMAT4_H_

#include <stdio.h>

#include "dmat3.h"
#include "../vector/dvec3.h"
#include "../vector/dvec4.h"
#include "../quaternion/dquaternion.h"

/**
 * A 4x4 matrix with double elements.
 */
typedef union cgm_dmat4 {
    /**
     * Row-major 4x4 2D double array representation of the matrix.
     */
    double m[4][4];

    /**
     * Row-major 1D double array representation of the matrix.
     */
    double arr[16];

    /**
     * 1D Array of row cgm_dvec4's of the matrix.
     */
    cgm_dvec4 vec[4];
} cgm_dmat4;

/**
 * Fills all elements of a cgm_dmat4 with a value.
 * @param m - Matrix to fill.
 * @param val - Value to fill with.
 */
void cgm_dmat4_fill(cgm_dmat4* m, double val);

/**
 * Sets the upper left of a cgm_dmat4 with a cgm_dmat3 and the rest of it
 * as in an identity matrix.
 * @param m - Matrix to set.
 * @param m3 - Matrix from which to set.
 */
void cgm_dmat4_set_m3(cgm_dmat4* m, const cgm_dmat3* m3);

/**
 * Sets a cgm_dmat4 to represent the same rotation as a cgm_dquat.
 * @param m - Matrix to set.
 * @param q - Quaternion from which to set.
 */
void cgm_dmat4_set_dquat(cgm_dmat4* m, const cgm_dquat* q);

/**
 * Sets a cgm_dmat4 to an identity matrix.
 * @param m - Matrix to set.
 */
void cgm_dmat4_set_identity(cgm_dmat4* m);

/**
 * Copies a matrix into another.
 * @param dest - Destination matrix.
 * @param src - Source matrix.
 * @return dest.
 */
cgm_dmat4* cgm_dmat4_cpy(cgm_dmat4* dest, const cgm_dmat4* src);

/**
 * Tests if two cgm_dmat4's are equal.
 * Two matrices are equal if all of their corresponding elements are equal.
 * @param a - First matrix.
 * @param b - Second matrix.
 * @return true (1) if a = b; false (0) otherwise.
 */
bool cgm_dmat4_equals(const cgm_dmat4* a, const cgm_dmat4* b);

/**
 * Adds two cgm_dmat4's element-wise.
 * @param a - Matrix to add to.
 * @param b - Matrix to add.
 */
void cgm_dmat4_add(cgm_dmat4* a, const cgm_dmat4* b);

/**
 * Subtracts two cgm_dmat4's element-wise.
 * @param a - Matrix to subtract from.
 * @param b - Matrix to subtract.
 */
void cgm_dmat4_sub(cgm_dmat4* a, const cgm_dmat4* b);

/**
 * Scales each element of a matrix.
 * @param m - Matrix to scale.
 * @param val - Value to scale each element.
 */
void cgm_dmat4_scal(cgm_dmat4* m, double val);

/**
 * Multiples two cgm_dmat4's.
 * @param out - Matrix to store the result.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right.
 */
void cgm_dmat4_mul(cgm_dmat4* out, const cgm_dmat4* a, const cgm_dmat4* b);

/**
 * Multiplies two cgm_dmat4's.
 * @param a - Matrix to multiply on the left and store the result.
 * @param b - Matrix to multiply on the right.
 */
void cgm_dmat4_mul_l(cgm_dmat4* a, const cgm_dmat4* b);

/**
 * Multiplies two cgm_dmat4's.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right and store the result.
 */
void cgm_dmat4_mul_r(const cgm_dmat4* a, cgm_dmat4* b);

/**
 * Multiples a cgm_dvec3 by a cgm_dmat4 by assigning a w component of 1.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_dmat4_mul_v3(const cgm_dmat4* m, cgm_dvec3* v);

/**
 * Multiplies a cgm_dvec4 by a cgm_dmat4.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_dmat4_mul_v4(const cgm_dmat4* m, cgm_dvec4* v);

/**
 * Applies the rotation from a cgm_dquat to a cgm_dmat4.
 * @param m - Matrix to rotate.
 * @param q - Quaternion by which to rotate by.
 */
void cgm_dmat4_mul_dquat(cgm_dmat4* m, const cgm_dquat* q);

/**
 * Calculates the determinant of a cgm_dmat4.
 * @param m - Matrix to take the determinant of.
 * @return Determinant |m|.
 */
double cgm_dmat4_det(const cgm_dmat4* m);

/**
 * Transposes a cgm_dmat4.
 * @param m - Matrix to transpose.
 */
void cgm_dmat4_transpose(cgm_dmat4* m);

/**
 * Inverts a cgm_dmat4.
 * The (multiplicative) inverse of a matrix m is m' such that
 * m * m' = m' * m = I (identity matrix).
 * @param m - Matrix to invert.
 * @return true (1) if the matrix could be inverted; false (0) otherwise.
 */
int cgm_dmat4_invert(cgm_dmat4* m);

/**
 * Prints a cgm_dmat4 to a stream.
 * The matrix is printed as:
 *      m00 m01 m02 m03
 *      m10 m11 m12 m13
 *      m20 m21 m22 m23
 *      m30 m31 m32 m33
 * with each element printed with %g and separated by tabs and line breaks.
 * @param stream - Filestream to print to.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_dmat4_fprintf(FILE* stream, const cgm_dmat4* m);

/**
 * Prints a cmg_dmat4 to stdout.
 * the matrix is printed as in cgm_dmat4_fprintf().
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_dmat4_printf(const cgm_dmat4* m);

#endif /* DMAT4_H_ */

/* vim: set ft=c: */
