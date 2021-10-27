#pragma once

#include <concepts>
#include <type_traits>
#include <cstddef>

namespace gof {


template <class T>
concept integral = std::is_integral_v<T>;

//!
//! Vector 2
//!
template <typename T> // std::size_t N = 2
class Vector2 {
  public:

    // using size_value = N;
    using value_type = T;

    // static size = size_type;
    // static type = value_type;

    Vector2(const T& x, const T& y)
      : _x(x)
      , _y(y)
    { }

    inline T x() const noexcept { return _x; };

    inline T y() const noexcept { return _y; };

  private:
    const T _x;
    const T _y;
};

//-----------------------------------------------------------------------------

template <typename T> inline
bool operator ==(const Vector2<T>& self, const Vector2<T>& that) noexcept {
  return self.x() == that.x() && self.y() == that.y();
}


template <typename T> inline
bool operator !=(const Vector2<T>& self, const Vector2<T>& that) noexcept {
  return ! (self == that);
}


template <typename T> inline
Vector2<T> operator *(const T& scalar, const Vector2<T>& self) noexcept {
  return { scalar * self.x(), scalar * self.y() };
}

}