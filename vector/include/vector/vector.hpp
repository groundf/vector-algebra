#pragma once

#ifndef VECTOR_HEADER_LIBRARY
#define VECTOR_HEADER_LIBRARY

#include <array>
#include <cstddef>
#include <type_traits>

namespace gof {

///
/// Vector class compile-time (constexpr).
///
template <std::size_t N, typename T>
class Vector {

  public:

    static constexpr std::size_t size = N;

    Vector() = default;

    /// Missing values will be filled with zeros.
    template <typename... Ts>
    constexpr Vector(const Ts &... xs) : _v({{xs...}}) { }

    const std::array<T, N> _v;

    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 1>>
    inline constexpr T x() const noexcept { return _v[0]; }

    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 2>>
    inline constexpr T y() const noexcept { return _v[1]; }

    template <std::size_t Q = N, typename = std::enable_if_t<Q >= 3>>
    inline constexpr T z() const noexcept { return _v[2]; }

    template <std::size_t Q = N, typename = std::enable_if_t<Q == 4>>
    inline constexpr T w() const noexcept { return _v[3]; }
};

} // namespace

#endif
