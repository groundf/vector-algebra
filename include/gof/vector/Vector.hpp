#pragma once

#ifndef VECTOR_HEADER_LIBRARY
#define VECTOR_HEADER_LIBRARY

// import <vector>; Modules doesn't work?!

#include <array>
#include <cstddef>
#include <type_traits>
#include <complex>

namespace gof {

//>> TODO MOve to standalone file

#include <concepts>

// Complex number guard.
template <typename T>
struct is_complex : std::false_type {};

template <std::floating_point T>
struct is_complex<std::complex<T>> : std::true_type {};

/// Helper variable template
template< class T >
inline constexpr bool is_complex_v = is_complex<T>::value;

/**
 * The concept fo numeric types.
 *
 * This is useful for algebraic types such as vector and matrices.
 */
template <typename T>
concept Number = std::is_arithmetic_v<T> || is_complex_v<T>;

//<<


/**
 * The vector template class.
 *
 * This type reprensets the vector embeded in Euclidean vector space.
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

    // factory methods

    // auto zero() -> Vector<N, T>   {  }

    // auto unit_x() -> Vector<N, T> { }

    // auto unit_y() -> Vector<N, T> { }

    // auto unit_z() -> Vector<N, T> { }

  private:

    const std::array<T, N> _v;
};


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
