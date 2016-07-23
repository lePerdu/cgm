/**
 * vec4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef VEC4_H_
#define VEC4_H_

#include <stdio.h>

#include "vec2.h"
#include "vec3.h"

/**
 * Returns a pointer to a compound literal cgm_vec4.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_vec4, cgm_vec4_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @param W - w coordinate.
 * @return Pointer to the vector.
 */
#define VEC4(X, Y, Z, W)  ((const cgm_vec4*) &((cgm_vec4) {{(X), (Y), (Z), (W)}}))

/**
 * A 4-dimensional vector with float components.
 * (Do you think there might be too many unions here? Nah...)
 */
typedef union cgm_vec4 {
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
             * x, y, and z components as a cgm_vec3.
             */
            cgm_vec3 xyz;
        };

        /**
         * w component.
         */
        float w;
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
                float r, g, b;
            };

            /**
             * r, g, and b components as a cgm_vec3.
             */
            cgm_vec3 rgb;
        };

        /**
         * a (alpha) component.
         */
        float a;
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
                    float s, t;

                    /**
                     * s and t coordinates as a cgm_vec2.
                     */
                    cgm_vec2 st;
                };

                /**
                 * p coordinate.
                 */
                float p;
            };

            /**
             * s, t, and p coordinates as a cgm_vec3.
             */
            cgm_vec3 stp;
        };

        /**
         * q coordinate.
         */
        float q;
    };

    /**
     * Float array representation of the vector.
     */
    float v[4];
} cgm_vec4;

/**
 * Sets the components of a cgm_vec4.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
inline void cgm_vec4_set(cgm_vec4* v, float x, float y, float z, float w);

/**
 * Sets the components of a cgm_vec4 from a cgm_vec2 and z and w coordinates
 * @param v - Vector to set.
 * @param xy - Vector with x and y coordinates.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
inline void cgm_vec4_set_v2(cgm_vec4* v, const cgm_vec2* xy, float z, float w);

/**
 * Sets the components of a cgm_vec4 from a cgm_vec3 and a w coordinate
 * @param v - Vector to set.
 * @param xyz - Vector with x, y, and z coordinates.
 * @param w - w coordinate.
 */
inline void cgm_vec4_set_v3(cgm_vec4* v, const cgm_vec3* xyz, float w);

/**
 * Fills all components of a cgm_vec4 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
inline inline void cgm_vec4_fill(cgm_vec4* v, float val);

/**
 * Copies a vector into another.
 * @parm dest - Destinatoin vector.
 * @parm src - Source vector.
 * @return dest.
 */
inline cgm_vec4* cgm_vec4_cpy(cgm_vec4* dest, const cgm_vec4* src);

/**
 * Tests if two cgm_vec4's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
inline int cgm_vec4_equals(const cgm_vec4* u, const cgm_vec4* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
inline void cgm_vec4_nadd(cgm_vec4* v, float n);

/**
 * Adds two cgm_vec4's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
inline void cgm_vec4_add(cgm_vec4* u, const cgm_vec4* v);

/**
 * Subtracts two cgm_vec4's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
inline void cgm_vec4_sub(cgm_vec4* u, const cgm_vec4* v);

/**
 * Calculates the dot product of two cgm_vec4's.
 * @param u - Frist vector.
 * @param v - Second vector.
 * @return Dot product u . v.
 */
inline float cgm_vec4_dot(const cgm_vec4* u, const cgm_vec4* v);

/**
 * Multiplies a cgm_vec4 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
inline void cgm_vec4_scal(cgm_vec4* v, float val);

/**
 * Returns the magnitude of a cgm_vec4.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
inline float cgm_vec4_mag(const cgm_vec4* v);

/**
 * Normalizes a cgm_vec4.
 * The vector v is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * @param v - Vector to normalize.
 */
inline void cgm_vec4_norm(cgm_vec4* v);

/**
 * Prints a cgm_vec4 to a stream.
 * The vector is printed as "(x, y, z, w)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
inline int cgm_vec4_fprintf(FILE* stream, const cgm_vec4* v);

/**
 * Prints a cgm_vec4 to stdout.
 * The vector is printed in the format of cgm_vec4_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
inline inline int cgm_vec4_printf(const cgm_vec4* v);


/* INLINE DECLARATIONS */


inline void cgm_vec4_set(cgm_vec4* v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

inline void cgm_vec4_set_v2(cgm_vec4* v, const cgm_vec2* xy, float z, float w) {
    memcpy(v, xy, sizeof(cgm_vec2));
    v->z = z;
    v->w = w;
}

inline void cgm_vec4_set_v3(cgm_vec4* v, const cgm_vec3* xyz, float w) {
    memcpy(v, xyz, sizeof(cgm_vec3));
    v->w = w;
}

inline void cgm_vec4_fill(cgm_vec4* v, float val) {
    cgm_vec4_set(v, val, val, val, val);
}

inline cgm_vec4* cgm_vec4_cpy(cgm_vec4* dest, const cgm_vec4* src) {
    return memcpy(dest, src, sizeof(cgm_vec4));
}

inline int cgm_vec4_equals(const cgm_vec4* u, const cgm_vec4* v) {
    /*
     * memcmp() is not sufficient because floating point values are not
     * one-to-one.
     */
    return u->x == v->x && u->y == v->y && u->z == v->z && u->w == v->w;
}

inline void cgm_vec4_nadd(cgm_vec4* v, float n) {
    v->x += n;
    v->y += n;
    v->z += n;
    v->w += n;
}

inline void cgm_vec4_add(cgm_vec4* u, const cgm_vec4* v) {
    u->x += v->x;
    u->y += v->y;
    u->z += v->z;
    u->w += v->w;
}

inline void cgm_vec4_sub(cgm_vec4* u, const cgm_vec4* v) {
    u->x -= v->x;
    u->y -= v->y;
    u->z -= v->z;
    u->w -= v->w;
}

inline float cgm_vec4_dot(const cgm_vec4* u, const cgm_vec4* v) {
    return u->x * v->x + u->y * v->y + u->z * v->z + u->w * v->w;
}

inline void cgm_vec4_scal(cgm_vec4* v, float val) {
    v->x *= val;
    v->y *= val;
    v->z *= val;
    v->w *= val;
}

inline float cgm_vec4_mag(const cgm_vec4* v) {
    return sqrtf(cgm_vec4_dot(v, v));
}

inline void cgm_vec4_norm(cgm_vec4* v) {
    float mag = cgm_vec4_mag(v);
    if (mag != 0) {
        cgm_vec4_scal(v, 1 / mag);
    }
}

inline int cgm_vec4_fprintf(FILE* stream, const cgm_vec4* v) {
    return fprintf(stream, "(%g, %g, %g, %g)\n", v->x, v->y, v->z, v->w);
}

inline int cgm_vec4_printf(const cgm_vec4* v) {
    return cgm_vec4_fprintf(stdout, v);
}

#endif /* VEC4_H_ */
