/**
 * ivec3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef IVEC3_H_
#define IVEC3_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "ivec2.h"

/**
 * A 3-dimensional vector with integer components.
 */
typedef union cgm_ivec3 {
    /**
     * Float component representation of the vector.
     */
    struct {
        union {
            /**
             * x and y components.
             */
            struct {
                int32_t x, y;
            };

            /**
             * x and y components as a cgm_ivec2.
             */
            cgm_ivec2 xy;
        };

        /**
         * z component.
         */
        int32_t z;
    };

    /**
     * RGB color representation of the vector.
     */
    struct {
        int32_t r, g, b;
    };

    /**
     * Float texture coordinate representation of the vector.
     */
    struct {
        int32_t s, t, p;
    };

    /**
     * Float array representation of the vector.
     */
    int32_t v[3];
} cgm_ivec3;

/**
 * Returns a pointer to a compound literal cgm_ivec3.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_ivec3, cgm_ivec3_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @return Pointer to the vector.
 */
#define CGM_IVEC3(X, Y, Z)  ((const cgm_ivec3*) &((cgm_ivec3) {{(X), (Y), (Z)}}))

/**
 * Sets the components of a cgm_ivec3.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 */
void cgm_ivec3_set(cgm_ivec3* v, int32_t x, int32_t y, int32_t z);

/**
 * Sets the components of a cgm_ivec3 from a cgm_ivec2 and a z-coordinate.
 * @param v - Vector to set.
 * @param xy - cgm_ivec2 with x and y coordinates.
 * @param z - z coordinate.
 */
void cgm_ivec3_set_v2(cgm_ivec3* v, const cgm_ivec2* xy, int32_t z);

/**
 * Fills all components of a cgm_ivec3 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_ivec3_fill(cgm_ivec3* v, int32_t val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Srouce vector.
 * @return dest.
 */
cgm_ivec3* cgm_ivec3_cpy(cgm_ivec3* dest, const cgm_ivec3* src);

/**
 * Tests if two cgm_ivec3's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_ivec3_equals(const cgm_ivec3* u, const cgm_ivec3* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_ivec3_nadd(cgm_ivec3* v, int32_t n);

/**
 * Adds two cgm_ivec3's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_ivec3_add(cgm_ivec3* u, const cgm_ivec3* v);

/**
 * Subtracts two cgm_ivec3's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_ivec3_sub(cgm_ivec3* u, const cgm_ivec3* v);

/**
 * Calculates the dot product of two cgm_ivec3's.
 * @param u - First vector.
 * @param v - Second vector.
 * @return The dot product u . v.
 */
int cgm_ivec3_dot(const cgm_ivec3* u, const cgm_ivec3* v);

/**
 * Multiplies a cgm_ivec3 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_ivec3_scal(cgm_ivec3* v, int32_t val);

/**
 * Calculates the cross product of two cgm_ivec3's.
 * The cross product of two vectors is a vector which is perpendicular
 * to both of them.
 * @param out - Vector to store u x v.
 * @param u - First vector to cross.
 * @param v - Second vector to cross.
 */
void cgm_ivec3_cross(cgm_ivec3* out, const cgm_ivec3* u, const cgm_ivec3* v);

/**
 * Prints a cgm_ivec3 to a stream.
 * The vector is printed as "(x, y, z)\n" to the stream in "%d" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_ivec3_fprintf(FILE* stream, const cgm_ivec3* v);

/**
 * Prints a cgm_ivec3 to stdout.
 * The vector is printed as in cgm_ivec3_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_ivec3_printf(const cgm_ivec3* v);

#endif /* IVEC3_H_ */

/* vim: set ft=c: */
