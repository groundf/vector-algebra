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

  public:

    static constexpr std::size_t size = N;

    /**
     * Constructor
     */
    Vector() = default;

    /**
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
     *  Check if it is a zero vector.
     */
    template <typename Vector>
    constexpr bool is_zero() {
        for (const auto &e : *this->values()) {
            if (e != 0.0f) {
                return false;
            }
        }
        return true;
    }

    // flip

    // rotate90

    // rotate45

    //-- factory methods

    /**
     * Return the zero vector.
     */
    constexpr static auto zero() -> Vector<N, T> {
        return {T{0}};
    }

    /**
     * Return the unit vector in direction `x`.
     *
     * This will compile only for N >= 1.
     */
    constexpr static auto unit_x() -> Vector<N, T> {
        return {T{1}};
    }

    /**
     * Return the unit vector in direction `y`.
     *
     * This will compile only for N >= 2.
     */
    constexpr static auto unit_y() -> Vector<N, T> {
        return {T{0}, T{1}};
    }

    /**
     * Return the unit vector in direction `z`.
     *
     * This will compile only for N >= 3.
     */
    constexpr static auto unit_z() -> Vector<N, T> {
        return {T{0}, T{0}, T{1}};
    }

    constexpr static auto ones() -> Vector<N, T> {
        if constexpr(N == 1) { return {T{1}}; }
        if constexpr(N == 2) { return {T{1}, T{1}}; }
        if constexpr(N == 3) { return {T{1}, T{1}, T{1}}; }
    }

  private:

    const std::array<T, N> _v;
};

/*----------------------------------------------------------------------------*/

/**
 * Binary operator `*`.
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
 * == operator
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
 *  != operator
 */
template <std::size_t N, Number T>
constexpr  bool operator !=(const Vector<N, T>& self, const Vector<N, T>& that) noexcept {
  return ! (self == that);
}


/**
 * Unary operator `-`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self) {
    return (-T{1}) * self;
}


/**
 * Binary operator `+`.
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
 * Binary operator `-`.
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
