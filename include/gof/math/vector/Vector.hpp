/**
 * @mainpage CGV Library
 * @section This library deals with basic algebra types often used in computer graphics
 * or simulation in 3D Euclidean space
 *
 * @section install_sec Installation
 *
 * @subsection install_dependencies Installing Dependencies
 * Do somethings ...
 * @subsection install_library Installing Library
 * Do somethings ...
 * @subsection install_example Installing Examples
 * Do somethings ...
 */

#pragma once

#ifndef VECTOR_HEADER_LIBRARY
#define VECTOR_HEADER_LIBRARY

// import <vector>; Modules doesn't work?!

#include <array>
#include <cstddef>
#include <type_traits>
#include <complex>

#include <gof/math/common.hpp>

namespace gof {

/**
 * The vector template class.
 *
 * This type represents the immutable vector type embeded in Euclidean vector space.
 *
 * No more then four elements should be allowed.
 *
 *  $\vec{u} + \vec{v}$
 *
 * @tparam N
 * @tparam T
 *
 */
template <std::size_t N, Number T>
class Vector
{
    using self = Vector<N, T>;

    Vector() = delete;

  public:

    static constexpr std::size_t size = N;

    /**
     * Constructor initializing all components to a single value of type `T`.
     *
     * Missing values will be filled with zeros.
     */
    template <typename... Ts>
    constexpr Vector(const Ts &... xs) : _v({{xs...}}) { }

    /**
     *  Copy constructor.
     */
    constexpr explicit Vector(const Vector<N, T>& that) : _v({that.values()}) { }

    /**
     * Destructor accessible in derived classes.
     */
    virtual ~Vector() { }

    /**
     * Get the value of component #1.
     *
     * The method will be compiled only for N >= 1.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 1>>
    constexpr T x() const noexcept { return _v[0]; }

    /**
     * Get the value of component #2.
     *
     * The method will be compiled only for N >= 2.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 2>>
    constexpr T y() const noexcept { return _v[1]; }

    /**
     * Get the value of component #3.
     *
     * The method will be compiled only for N >= 3.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 3>>
    constexpr T z() const noexcept { return _v[2]; }

    /**
     * Get the value of component #4.
     *
     * The method will be compiled only for N >= 4.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q == 4>>
    constexpr T w() const noexcept { return _v[3]; }

    constexpr std::array<T, N> values() const noexcept {
        return _v;
    }

    /**
     * Check if this is a zero vector.
     */
    template <typename Vector>
    constexpr bool is_zero() {
        for (const auto &e : *this->values()) {
            if (e != 0.0f) {
                return false;
            }
        }
    }

    /**
     * Calculate the Euclidean norm.
     *
     * $|x| = \sum_{i=1}^n \sqrt{x_i^2}$
     *
     * Also known as _length_ or _magnitude_.
     */
    constexpr T length() const noexcept {
        auto result = T{0};
        for(const auto &e : *this->values()) {
            result += (e * e);
        }
        return std::sqrt(result);
    }

    /**
     * An alias for `length()`.
     */
    constexpr T magnitude() const noexcept {
        return length();
    }

    // reject()

    // project()

    // flip

    // rotate(axis, angle) { }

    // rotate_90_cc(axis) {  }

    // rotate_x_90_cc(axis) {  }

    // rotate_y_90_cc(axis) {  }

    // rotate_z_90_cc(axis) {  }

    // rotate_90_ccw(axis) { }

    // rotate_x_90_ccw(axis) { }

    // rotate_y_90_ccw(axis) { }

    // rotate_z_90_ccw(axis) { }

    // auto rotate_45_cc const { }
    // auto rotate_45_ccw const { }

    // constexpr bool is_unit() const noexcept { return norm(self) == T{1}; }

    // constexpr bool is_opposite(Vector<N, T> const& that) { }

    // constexpr bool is_parallel(that) const noexcept { }

    // constexpr bool is_perpendicular(that) const noexcept { }


    /**
     * Whenever has all values equal with specified tolerance.
     */
    // constexpr is_uniform(T tolerance) { }

    // constexpr T max_value() const noexcept { }

    // constexpr T min_value() const noexcept { }

    /**
     * Scale the vector by factor (scalar).
     *
     * This is the same as multiplying vector by scalar with `*` operator.
     */
    Vector<N, T> scale(T const& scalar) {
        return scalar * (*this);
    }

    /*--- STATIC FACTORY METHODS ---*/

    /**
     * Return the zero vector i.e. it has all components set to zero.
     */
    constexpr static auto zero() -> Vector<N, T> {
        return {T{0}};
    }

    /**
     * Return the vector with unit `x` component i.e. the unit vector in direction `x`.
     *
     * This will compile only for N >= 1.
     */
    constexpr static auto unit_x() -> Vector<N, T> {
        return {T{1}};
    }

    /**
     * Return the vector with unit `y` component i.e. the unit vector in direction `y`.
     *
     * This will compile only for N >= 2.
     */
    constexpr static auto unit_y() -> Vector<N, T> {
        return {T{0}, T{1}};
    }

    /**
     * Return the vector with unit `z` component i.e. the unit vector in direction `z`.
     *
     * This will compile only for N >= 3.
     */
    constexpr static auto unit_z() -> Vector<N, T> {
        return {T{0}, T{0}, T{1}};
    }

    /**
     * Return the vector with unit `w` component.
     *
     * This will compile only for N >= 4.
     */
    constexpr static auto unit_w() -> Vector<N, T> {
        return {T{0}, T{0}, T{0}, T{1}};
    }

    /**
     * Return the vector with all components set to one.
     */
    constexpr static auto ones() -> Vector<N, T> {
        if constexpr(N == 1) {
            return {T{1}};
        }
        if constexpr(N == 2) {
            return {T{1}, T{1}};
         }
        if constexpr(N == 3) {
             return {T{1}, T{1}, T{1}};
         }
    }

  private:

    const std::array<T, N> _v;
};

#include "Vector.inl"

/*----------------------------------------------------------------------------*/
/*                                 PRODUCTS                                   */
/*----------------------------------------------------------------------------*/

/**
 * Calculate the scalar product of two vectors.
 *
 * @tparam N
 * @tparam T
 */
template <std::size_t N, Number T = float>
constexpr T scalar_product(const Vector<N, T>& lhs, const Vector<N, T>& rhs) {
    return nullptr;
}

/**
 * Calculate the vector product of two vectors.
 *
 * @tparam N
 * @tparam T
 */
template <std::size_t N, Number T = float>
constexpr Vector<N, T> vector_product(const Vector<N, T>& lhs, const Vector<N, T>& rhs) {
    return nullptr;
}

constexpr auto plus(int a, int b) -> decltype(a) {
    return a + b;
}

} // namespace

#endif // guard
