/**
 * vec3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef VEC3_H_
#define VEC3_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vec2.h"

/**
 * A 3-dimensional vector with float components.
 */
typedef union cgm_vec3 {
    /**
     * Float component representation of the vector.
     */
    struct {
        union {
            /**
             * x and y components.
             */
            struct {
                float x, y;
            };

            /**
             * x and y components as a cgm_vec2.
             */
            cgm_vec2 xy;
        };

        /**
         * z component.
         */
        float z;
    };

    /**
     * RGB color representation of the vector.
     */
    struct {
        float r, g, b;
    };

    /**
     * Float texture coordinate representation of the vector.
     */
    struct {
        float s, t, p;
    };

    /**
     * Float array representation of the vector.
     */
    float v[3];
} cgm_vec3;

/**
 * Returns a pointer to a compound literal cgm_vec3.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_vec3, cgm_vec3_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @return Pointer to the vector.
 */
#define CGM_VEC3(X, Y, Z)  ((const cgm_vec3*) &((cgm_vec3) {{(X), (Y), (Z)}}))

/**
 * Sets the components of a cgm_vec3.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 */
void cgm_vec3_set(cgm_vec3* v, float x, float y, float z);

/**
 * Sets the components of a cgm_vec3 from a cgm_vec2 and a z-coordinate.
 * @param v - Vector to set.
 * @param xy - cgm_vec2 with x and y coordinates.
 * @param z - z coordinate.
 */
void cgm_vec3_set_v2(cgm_vec3* v, const cgm_vec2* xy, float z);

/**
 * Fills all components of a cgm_vec3 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_vec3_fill(cgm_vec3* v, float val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Srouce vector.
 * @return dest.
 */
cgm_vec3* cgm_vec3_cpy(cgm_vec3* dest, const cgm_vec3* src);

/**
 * Tests if two cgm_vec3's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_vec3_equals(const cgm_vec3* u, const cgm_vec3* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_vec3_nadd(cgm_vec3* v, float n);

/**
 * Adds two cgm_vec3's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_vec3_add(cgm_vec3* u, const cgm_vec3* v);

/**
 * Subtracts two cgm_vec3's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_vec3_sub(cgm_vec3* u, const cgm_vec3* v);

/**
 * Calculates the dot product of two cgm_vec3's.
 * @param u - First vector.
 * @param v - Second vector.
 * @return The dot product u . v.
 */
float cgm_vec3_dot(const cgm_vec3* u, const cgm_vec3* v);

/**
 * Multiplies a cgm_vec3 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_vec3_scal(cgm_vec3* v, float val);

/**
 * Returns the magnitude of a cgm_vec3.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
float cgm_vec3_mag(const cgm_vec3* v);

/**
 * Normalizes a cgm_vec3.
 * The vector is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * @param v - The vector to normalize.
 */
void cgm_vec3_norm(cgm_vec3* v);

/**
 * Calculates the cross product of two cgm_vec3's.
 * The cross product of two vectors is a vector which is perpendicular
 * to both of them.
 * @param out - Vector to store u x v.
 * @param u - First vector to cross.
 * @param v - Second vector to cross.
 */
void cgm_vec3_cross(cgm_vec3* out, const cgm_vec3* u, const cgm_vec3* v);

/**
 * Prints a cgm_vec3 to a stream.
 * The vector is printed as "(x, y, z)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_vec3_fprintf(FILE* stream, const cgm_vec3* v);

/**
 * Prints a cgm_vec3 to stdout.
 * The vector is printed as in cgm_vec3_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_vec3_printf(const cgm_vec3* v);

#endif /* VEC3_H_ */

/* vim: set ft=c: */
