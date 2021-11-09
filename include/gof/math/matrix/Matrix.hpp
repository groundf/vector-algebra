#pragma once

#ifndef MATRIX_HEADER_GUARD
#define MATRIX_HEADER_GUARD


#include <valarray>
#include <gof/math/vector/Vector.hpp>

namespace gof {

/**
 * The matrix template class.
 *
 * @tparam N The number of rows.
 * @tparam M The number of columns.
 * @tparam T The scalar type.
 */
template <std::size_t N, std::size_t M, typename T>
class Matrix
{

  const std::array<T, M * N> _values;

  Matrix() = delete;

  public:
    /**
     * Constructor: The row order.
     */
    template <typename... Ts>
    constexpr Matrix(const Ts&... values) : _values({values...}) { }

    /**
     * Destructor
     */
    virtual ~Matrix() { }

    // GETTERS

    constexpr auto values() const noexcept -> decltype(_values) {
      return _values;
    }

    /**
     * Get the row with specified index.
     */
    inline constexpr auto row(std::size_t index) const -> Vector<M, T> {
        // TODO Check the index.
        return Vector<M, T>::zero(); // TODO
    }

    /**
     *  Get the column with specified index.
     */
    inline constexpr auto column(std::size_t index) const -> Vector<N, T> {
        // TODO Check the index.
        return Vector<N, T>::zero(); // TODO
    }

    // FACTORIES

    /**
     * Constructor
     */
    // static Matrix from_columns() { }
};

} // namespace

#endif // guard
