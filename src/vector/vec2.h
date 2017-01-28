/**
 * vec2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <stdbool.h>
#include <stdio.h>

/**
 * A 2-dimensional vector with float components.
 */
typedef union cgm_vec2 {
    /**
     * Float component representation of the vector.
     */
    struct {
        float x, y;
    };

    /**
     * Float texture coordinate representaion of the vector.
     */
    struct {
        float s, t;
    };

    /**
     * Float array representation of the vector.
     */
    float v[2];
} cgm_vec2;

/**
 * Returns a pointer to a compound literal cgm_vec2.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_vec2, cgm_vec2_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @return Constant pointer to cgm_vec2.
 */
#define CGM_VEC2(X, Y)  ((const cgm_vec2*) &((cgm_vec2) {{(X), (Y)}}))

/**
 * Sets the components of a cgm_vec2.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 */
void cgm_vec2_set(cgm_vec2* v, float x, float y);

/**
 * Fills both components of a cgm_vec2 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_vec2_fill(cgm_vec2* v, float val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Source vector.
 * @return dest.
 */
cgm_vec2* cgm_vec2_cpy(cgm_vec2* dest, const cgm_vec2* src);

/**
 * Tests if two cgm_vec2's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true(1) if u = v, false(0) otherwise.
 */
bool cgm_vec2_equals(const cgm_vec2* u, const cgm_vec2* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_vec2_nadd(cgm_vec2* v, float n);

/**
 * Adds two cgm_vec2's component-wise.
 * The result u + v is stored in u.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_vec2_add(cgm_vec2* u, const cgm_vec2* v);

/**
 * Subtracts two cgm_vec2's component-wise.
 * The result u - v is stored in u
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_vec2_sub(cgm_vec2* u, const cgm_vec2* v);

/**
 * Returns the dot product of two cgm_vec2's.
 * If either of the vectors is NULL, then NaN is returned.
 * @param u - First vector.
 * @param v - Secont vector.
 * @return Dot product u . v.
 */
float cgm_vec2_dot(const cgm_vec2* u, const cgm_vec2* v);

/**
 * Multiplies a cgm_vec2 by a scalar.
 * The result val * v is stored in v.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_vec2_scal(cgm_vec2* v, float val);

/**
 * Returns the magnitude of a cgm_vec2.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
float cgm_vec2_mag(const cgm_vec2* v);

/**
 * Normalizes a cgm_vec2.
 * The vector v is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * If the vector has a magnitude of 0, no operation is performed.
 * @param v - Vector to normalize.
 */
void cgm_vec2_norm(cgm_vec2* v);

/**
 * Prints a cgm_vec2 to a stream.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param stream - Filesteam to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_vec2_fprintf(FILE* stream, const cgm_vec2* v);

/**
 * Prints a cmg_vec2 to stdout.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_vec2_printf(const cgm_vec2* v);

#endif /* VEC2_H_ */

/* vim: set ft=c: */
