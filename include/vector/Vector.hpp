#pragma once

#ifndef VECTOR_HEADER_LIBRARY
#define VECTOR_HEADER_LIBRARY

// import <vector>; Modules doesn't work?!

#include <array>
#include <cstddef>
#include <type_traits>

namespace gof {

/**
 * The vector template class.
 *
 * No more then four elements should be allowed.
 *
 * @tparam N
 * @tparam T
 *
 */
template <std::size_t N, typename T>
class Vector
{
    const std::array<T, N> _v;

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
};


/**
 * Binary operator `*`.
 */
template <std::size_t N, typename T>
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
 * Unary operator `-`.
 */
template <std::size_t N, typename T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self) {
    return (-T{1}) * self;
}

/**
 * Binary operator `+`.
 */
template <std::size_t N, typename T>
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
template <std::size_t N, typename T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self, Vector<N, T> const& that) {
    return self + ( (-T{1}) * that );
}

constexpr auto plus(int a, int b) -> decltype(a) {
    return a + b;
}


} // namespace

#endif
