/**
 * ivec4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef IVEC4_H_
#define IVEC4_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "ivec2.h"
#include "ivec3.h"

/**
 * A 4-dimensional vector with integer components.
 * (Do you think there might be too many unions here? Nah...)
 */
typedef union cgm_ivec4 {
    /**
     * Float component representation of the vector.
     */
    struct {
        union {
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
             * x, y, and z components as a cgm_ivec3.
             */
            cgm_ivec3 xyz;
        };

        /**
         * w component.
         */
        int32_t w;
    };

    /**
     * RGBA color representation of the vector.
     */
    struct {
        union {
            /**
             * r, g, and b components.
             */
            struct {
                int32_t r, g, b;
            };

            /**
             * r, g, and b components as a cgm_ivec3.
             */
            cgm_ivec3 rgb;
        };

        /**
         * a (alpha) component.
         */
        int32_t a;
    };

    /**
     * Float texture coordinate representation of the vector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * s and t coordinates.
                     */
                    int32_t s, t;

                    /**
                     * s and t coordinates as a cgm_ivec2.
                     */
                    cgm_ivec2 st;
                };

                /**
                 * p coordinate.
                 */
                int32_t p;
            };

            /**
             * s, t, and p coordinates as a cgm_ivec3.
             */
            cgm_ivec3 stp;
        };

        /**
         * q coordinate.
         */
        int32_t q;
    };

    /**
     * Float array representation of the vector.
     */
    int32_t v[4];
} cgm_ivec4;

/**
 * Returns a pointer to a compound literal cgm_ivec4.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_ivec4, cgm_ivec4_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @param W - w coordinate.
 * @return Pointer to the vector.
 */
#define CGM_IVEC4(X, Y, Z, W)  ((const cgm_ivec4*) &((cgm_ivec4) {{(X), (Y), (Z), (W)}}))

/**
 * Sets the components of a cgm_ivec4.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_ivec4_set(cgm_ivec4* v, int32_t x, int32_t y, int32_t z, int32_t w);

/**
 * Sets the components of a cgm_ivec4 from a cgm_ivec2 and z and w coordinates
 * @param v - Vector to set.
 * @param xy - Vector with x and y coordinates.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_ivec4_set_v2(cgm_ivec4* v, const cgm_ivec2* xy, int32_t z, int32_t w);

/**
 * Sets the components of a cgm_ivec4 from a cgm_ivec3 and a w coordinate
 * @param v - Vector to set.
 * @param xyz - Vector with x, y, and z coordinates.
 * @param w - w coordinate.
 */
void cgm_ivec4_set_v3(cgm_ivec4* v, const cgm_ivec3* xyz, int32_t w);

/**
 * Fills all components of a cgm_ivec4 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_ivec4_fill(cgm_ivec4* v, int32_t val);

/**
 * Copies a vector into another.
 * @parm dest - Destinatoin vector.
 * @parm src - Source vector.
 * @return dest.
 */
cgm_ivec4* cgm_ivec4_cpy(cgm_ivec4* dest, const cgm_ivec4* src);

/**
 * Tests if two cgm_ivec4's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_ivec4_equals(const cgm_ivec4* u, const cgm_ivec4* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_ivec4_nadd(cgm_ivec4* v, int32_t n);

/**
 * Adds two cgm_ivec4's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_ivec4_add(cgm_ivec4* u, const cgm_ivec4* v);

/**
 * Subtracts two cgm_ivec4's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_ivec4_sub(cgm_ivec4* u, const cgm_ivec4* v);

/**
 * Calculates the dot product of two cgm_ivec4's.
 * @param u - Frist vector.
 * @param v - Second vector.
 * @return Dot product u . v.
 */
int cgm_ivec4_dot(const cgm_ivec4* u, const cgm_ivec4* v);

/**
 * Multiplies a cgm_ivec4 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_ivec4_scal(cgm_ivec4* v, int32_t val);

/**
 * Prints a cgm_ivec4 to a stream.
 * The vector is printed as "(x, y, z, w)\n" to the stream in "%d" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_ivec4_fprintf(FILE* stream, const cgm_ivec4* v);

/**
 * Prints a cgm_ivec4 to stdout.
 * The vector is printed in the format of cgm_ivec4_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_ivec4_printf(const cgm_ivec4* v);

#endif /* IVEC4_H_ */

/* vim: set ft=c: */
