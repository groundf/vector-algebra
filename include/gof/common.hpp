#include <concepts>


namespace gof {

//------ CONCEPTS ------//

// Complex number guard.
template <typename T>
struct is_complex : std::false_type {};

template <std::floating_point T>
struct is_complex<std::complex<T>> : std::true_type {};

/// Helper variable template
template< class T >
inline constexpr bool is_complex_v = is_complex<T>::value;

/**
 * The concept for numeric types.
 *
 * This is useful for algebraic types such as vector and matrices.
 */
template <typename T>
concept Number = std::is_arithmetic_v<T> || is_complex_v<T>;


//------ EQUALITY ------//

/**
 * Equality of floating point numbers. It is better to dedicate a strategy how to compare
 * the number to the standalone class.
 */
// template <typename NumericType>
// struct equalizer {
//     /**
//      * Test whenever two floating point numbers are equal.
//      */
//     constexpr bool is_equal() {
//         return
//     }

//     constexpr bool is_near_equal() {

//     }
// }

}
