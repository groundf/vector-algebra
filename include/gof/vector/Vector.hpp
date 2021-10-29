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

#include <gof/common.hpp>

namespace gof {

/**
 * The vector template class.
 *
 *  $\vec{u} + \vec{v}$
 *
 * This type represents the vector embeded in Euclidean vector space.
 *
 * No more then four elements should be allowed.
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
     * Construct a new vector.
     *
     * Missing values will be filled with zeros.
     */
    template <typename... Ts>
    constexpr Vector(const Ts &... xs) : _v({{xs...}}) { }

    /**
     * Return the value of component #1.
     *
     * The method will be compiled only for N >= 1.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 1>>
    constexpr T x() const noexcept { return _v[0]; }

    /**
     * Return the value of component #2.
     *
     * The method will be compiled only for N >= 2.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 2>>
    constexpr T y() const noexcept { return _v[1]; }

    /**
     * Return the value of component #3.
     *
     * The method will be compiled only for N >= 3.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 3>>
    constexpr T z() const noexcept { return _v[2]; }

    /**
     * Return the value of component #4.
     *
     * The method will be compiled only for N >= 4.
     */
    template <std::size_t Q = N, typename = std::enable_if_t<Q == 4>>
    constexpr T w() const noexcept { return _v[3]; }

    constexpr std::array<T, N> values() const noexcept {
        return _v;
    }

    /**
     *  Check if this is a zero vector.
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
     *  $|x| = \sum_{i=1}^n \sqrt{x_i^2}$
     *
     * Also known as _length_ or _magnitude_.
     */
    constexpr T norm() const noexcept {
        auto result = T{0};
        for(const auto &e : *this->values()) {
            result += (e * e);
        }
        return std::sqrt(result);
    }

    // flip

    // rotate90

    // rotate45

    // is_opposite()

    // is_perpendicular()

    // is_unit() { return norm(self) == T{1}; }

    //-- factory methods

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

/*----------------------------------------------------------------------------*/

/**
 * The binary operator `*`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator *(T const& factor, Vector<N, T> const& self) {
    // Conditional compilation with `constexpr if`.
    if constexpr(N == 1) {
        return {factor * self.x()};
    }
    if constexpr(N == 2) {
        return {factor * self.x(), factor * self.y()};
    }
    if constexpr(N == 3) {
        return {factor * self.x(), factor * self.y(), factor * self.z()};
    }
    if constexpr(N == 4) {
        return {factor * self.x(), factor * self.y(), factor * self.z(), factor * self.w()};
    }
}


/**
 * The binary operator `==`.
 */
template <std::size_t N, Number T>
constexpr bool operator ==(const Vector<N, T>& self, const Vector<N, T>& that) noexcept {
    if constexpr(N == 1) {
        return self.x() == that.x();
    }
    if constexpr(N == 2) {
        return self.x() == that.x() && self.y() == that.y();
    }
    if constexpr(N == 3) {
        return self.x() == that.x() && self.y() == that.y() && self.z() == that.z();
    }
    if constexpr(N == 4) {
        return self.x() == that.x() && self.y() == that.y() && self.z() == that.z() && self.w() == that.w();
    }
}

/**
 * The binary operator `!=`.
 */
template <std::size_t N, Number T>
constexpr  bool operator !=(const Vector<N, T>& self, const Vector<N, T>& that) noexcept {
  return ! (self == that);
}


/**
 * The unary operator `-`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self) {
    return (-T{1}) * self;
}


/**
 * The binary operator `+`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator +(Vector<N, T> const& self, Vector<N, T> const& that) {
    if constexpr(N == 1) {
        return {self.x() + that.x()};
    }
    if constexpr(N == 2) {
        return {self.x() + that.x(), self.y() + that.y()};
    }
    if constexpr(N == 3) {
        return {self.x() + that.x(), self.y() + that.y(), self.z() + that.z()};
    }
    if constexpr(N == 4) {
        return {self.x() + that.x(), self.y() + that.y(), self.z() + that.z(), self.w() + that.w()};
    }
}


/**
 * The binary operator `-`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self, Vector<N, T> const& that) {
    return self + ( (-T{1}) * that );
}


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

#endif
