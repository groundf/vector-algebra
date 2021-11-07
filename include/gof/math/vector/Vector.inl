/*----------------------------------------------------------------------------*/
/*                                 OPERATORS                                  */
/*----------------------------------------------------------------------------*/

/**
 * The binary operator `scalar * vrctor`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator *(T const& scalar, Vector<N, T> const& self) {
   // Conditional compilation with `constexpr if`.
    if constexpr(N == 1) {
        return {scalar * self.x()};
    }
    if constexpr(N == 2) {
        return {scalar * self.x(), scalar * self.y()};
    }
    if constexpr(N == 3) {
        return {scalar * self.x(), scalar * self.y(), scalar * self.z()};
    }
    if constexpr(N == 4) {
        return {scalar * self.x(), scalar * self.y(), scalar * self.z(), scalar * self.w()};
    }
}

/**
 * The binary operator `vector == vector`.
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
 * The binary operator `vector != vector`.
 */
template <std::size_t N, Number T>
constexpr  bool operator !=(const Vector<N, T>& self, const Vector<N, T>& that) noexcept {
  return ! (self == that);
}

/**
 * The unary operator `- vector`.
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
 * The binary operator `vector - vector`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self, Vector<N, T> const& that) {
    return self + ( (-T{1}) * that );
}

/**
 * The binary operator `vector - scalar`.
 */
template <std::size_t N, Number T>
constexpr Vector<N, T> operator -(Vector<N, T> const& self, T const& bias) {
    return self - (bias * Vector<N, T>::ones());
}

// TODO std::hash<>
