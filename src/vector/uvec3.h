/**
 * uvec3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef UVEC3_H_
#define UVEC3_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "uvec2.h"

/**
 * A 3-dimensional vector with unsigned integer components.
 */
typedef union cgm_uvec3 {
    /**
     * Unsigned integer component representation of the vector.
     */
    struct {
        union {
            /**
             * x and y components.
             */
            struct {
                uint32_t x, y;
            };

            /**
             * x and y components as a cgm_uvec2.
             */
            cgm_uvec2 xy;
        };

        /**
         * z component.
         */
        uint32_t z;
    };

    /**
     * RGB color representation of the vector.
     */
    struct {
        uint32_t r, g, b;
    };

    /**
     * Unsigned integer texture coordinate representation of the vector.
     */
    struct {
        uint32_t s, t, p;
    };

    /**
     * Unsigned integer array representation of the vector.
     */
    uint32_t v[3];
} cgm_uvec3;

/**
 * Returns a pointer to a compound literal cgm_uvec3.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_uvec3, cgm_uvec3_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @return Pointer to the vector.
 */
#define CGM_UVEC3(X, Y, Z)  ((const cgm_uvec3*) &((cgm_uvec3) {{(X), (Y), (Z)}}))

/**
 * Sets the components of a cgm_uvec3.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 */
void cgm_uvec3_set(cgm_uvec3* v, uint32_t x, uint32_t y, uint32_t z);

/**
 * Sets the components of a cgm_uvec3 from a cgm_uvec2 and a z-coordinate.
 * @param v - Vector to set.
 * @param xy - cgm_uvec2 with x and y coordinates.
 * @param z - z coordinate.
 */
void cgm_uvec3_set_v2(cgm_uvec3* v, const cgm_uvec2* xy, uint32_t z);

/**
 * Fills all components of a cgm_uvec3 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_uvec3_fill(cgm_uvec3* v, uint32_t val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Srouce vector.
 * @return dest.
 */
cgm_uvec3* cgm_uvec3_cpy(cgm_uvec3* dest, const cgm_uvec3* src);

/**
 * Tests if two cgm_uvec3's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_uvec3_equals(const cgm_uvec3* u, const cgm_uvec3* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_uvec3_nadd(cgm_uvec3* v, uint32_t n);

/**
 * Adds two cgm_uvec3's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_uvec3_add(cgm_uvec3* u, const cgm_uvec3* v);

/**
 * Subtracts two cgm_uvec3's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_uvec3_sub(cgm_uvec3* u, const cgm_uvec3* v);

/**
 * Calculates the dot product of two cgm_uvec3's.
 * @param u - First vector.
 * @param v - Second vector.
 * @return The dot product u . v.
 */
uint32_t cgm_uvec3_dot(const cgm_uvec3* u, const cgm_uvec3* v);

/**
 * Multiplies a cgm_uvec3 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_uvec3_scal(cgm_uvec3* v, uint32_t val);

/**
 * Prints a cgm_uvec3 to a stream.
 * The vector is printed as "(x, y, z)\n" to the stream in "%d" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_uvec3_fprintf(FILE* stream, const cgm_uvec3* v);

/**
 * Prints a cgm_uvec3 to stdout.
 * The vector is printed as in cgm_uvec3_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_uvec3_printf(const cgm_uvec3* v);

#endif /* UVEC3_H_ */

/* vim: set ft=c: */
