#pragma once

namespace gof {

//!
//! Vector 3
//!
template <typename T>
class Vector3
{
  public:

    using value_type = T;

    Vector3(const T& x, const T& y, const T& z)
      : _x(x)
      , _y(y)
      , _z(z)
    { }

    inline T x() const noexcept { return _x; };

    inline T y() const noexcept { return _y; };

    inline T z() const noexcept { return _z; };

  private:
    const T _x;
    const T _y;
    const T _z;
};


template <typename T> inline
bool operator ==(const Vector3<T>& self, const Vector3<T>& that) noexcept {
  return self.x() == that.x() && self.y() == that.y() && self.z() == that.z();
}


template <typename T> inline
bool operator !=(const Vector3<T>& self, const Vector3<T>& that) noexcept {
  return ! (self == that);
}


template <typename T> inline
Vector3<T> operator *(const T& scalar, const Vector3<T>& self) noexcept {
  return { scalar * self.x(), scalar * self.y(), scalar * self.z() };
}

} // namespace