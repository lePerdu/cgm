/**
 * uvec2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef UVEC2_H_
#define UVEC2_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * A 2-dimensional vector with unsigned integer components.
 */
typedef union cgm_uvec2 {
    /**
     * Unsigned integer component representation of the vector.
     */
    struct {
        uint32_t x, y;
    };

    /**
     * Unsigned integer texture coordinate representaion of the vector.
     */
    struct {
        uint32_t s, t;
    };

    /**
     * Unsigned integer array representation of the vector.
     */
    uint32_t v[2];
} cgm_uvec2;

/**
 * Returns a pointer to a compound literal cgm_uvec2.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_uvec2, cgm_uvec2_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @return Constant pointer to cgm_uvec2.
 */
#define CGM_UVEC2(X, Y)  ((const cgm_uvec2*) &((cgm_uvec2) {{(X), (Y)}}))

/**
 * Sets the components of a cgm_uvec2.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 */
void cgm_uvec2_set(cgm_uvec2* v, uint32_t x, uint32_t y);

/**
 * Fills both components of a cgm_uvec2 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_uvec2_fill(cgm_uvec2* v, uint32_t val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Source vector.
 * @return dest.
 */
cgm_uvec2* cgm_uvec2_cpy(cgm_uvec2* dest, const cgm_uvec2* src);

/**
 * Tests if two cgm_uvec2's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true(1) if u = v, false(0) otherwise.
 */
bool cgm_uvec2_equals(const cgm_uvec2* u, const cgm_uvec2* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_uvec2_nadd(cgm_uvec2* v, uint32_t n);

/**
 * Adds two cgm_uvec2's component-wise.
 * The result u + v is stored in u.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_uvec2_add(cgm_uvec2* u, const cgm_uvec2* v);

/**
 * Subtracts two cgm_uvec2's component-wise.
 * The result u - v is stored in u.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_uvec2_sub(cgm_uvec2* u, const cgm_uvec2* v);

/**
 * Returns the dot product of two cgm_uvec2's.
 * If either of the vectors is NULL, then NaN is returned.
 * @param u - First vector.
 * @param v - Secont vector.
 * @return Dot product u . v.
 */
uint32_t cgm_uvec2_dot(const cgm_uvec2* u, const cgm_uvec2* v);

/**
 * Multiplies a cgm_uvec2 by a scalar.
 * The result val * v is stored in v.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_uvec2_scal(cgm_uvec2* v, uint32_t val);

/**
 * Prints a cgm_uvec2 to a stream.
 * The vector is printed as "(x, y)\n" to the stream in "%d" format.
 * @param stream - Filesteam to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_uvec2_fprintf(FILE* stream, const cgm_uvec2* v);

/**
 * Prints a cmg_uvec2 to stdout.
 * The vector is printed as "(x, y)\n" to the stream in "%d" format.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_uvec2_printf(const cgm_uvec2* v);

#endif /* UVEC2_H_ */

/* vim: set ft=c: */
