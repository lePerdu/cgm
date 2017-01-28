/**
 * ivec2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef IVEC2_H_
#define IVEC2_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * A 2-dimensional vector with integer components.
 */
typedef union cgm_ivec2 {
    /**
     * Integer component representation of the vector.
     */
    struct {
        int32_t x, y;
    };

    /**
     * Integer texture coordinate representaion of the vector.
     */
    struct {
        int32_t s, t;
    };

    /**
     * Integer array representation of the vector.
     */
    int32_t v[2];
} cgm_ivec2;

/**
 * Returns a pointer to a compound literal cgm_ivec2.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_ivec2, cgm_ivec2_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @return Constant pointer to cgm_ivec2.
 */
#define CGM_IVEC2(X, Y)  ((const cgm_ivec2*) &((cgm_ivec2) {{(X), (Y)}}))

/**
 * Sets the components of a cgm_ivec2.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 */
void cgm_ivec2_set(cgm_ivec2* v, int32_t x, int32_t y);

/**
 * Fills both components of a cgm_ivec2 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_ivec2_fill(cgm_ivec2* v, int32_t val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Source vector.
 * @return dest.
 */
cgm_ivec2* cgm_ivec2_cpy(cgm_ivec2* dest, const cgm_ivec2* src);

/**
 * Tests if two cgm_ivec2's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true(1) if u = v, false(0) otherwise.
 */
bool cgm_ivec2_equals(const cgm_ivec2* u, const cgm_ivec2* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_ivec2_nadd(cgm_ivec2* v, int32_t n);

/**
 * Adds two cgm_ivec2's component-wise.
 * The result u + v is stored in u.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_ivec2_add(cgm_ivec2* u, const cgm_ivec2* v);

/**
 * Subtracts two cgm_ivec2's component-wise.
 * The result u - v is stored in u
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_ivec2_sub(cgm_ivec2* u, const cgm_ivec2* v);

/**
 * Returns the dot product of two cgm_ivec2's.
 * @param u - First vector.
 * @param v - Secont vector.
 * @return Dot product u . v.
 */
int32_t cgm_ivec2_dot(const cgm_ivec2* u, const cgm_ivec2* v);

/**
 * Multiplies a cgm_ivec2 by a scalar.
 * The result val * v is stored in v.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_ivec2_scal(cgm_ivec2* v, int32_t val);

/**
 * Prints a cgm_ivec2 to a stream.
 * The vector is printed as "(x, y)\n" to the stream in "%d" format.
 * @param stream - Filesteam to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_ivec2_fprintf(FILE* stream, const cgm_ivec2* v);

/**
 * Prints a cmg_ivec2 to stdout.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_ivec2_printf(const cgm_ivec2* v);

#endif /* IVEC2_H_ */

/* vim: set ft=c: */
