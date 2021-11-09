/*
 * MATRIX TESTS
 */

#include <catch2/catch_test_macros.hpp>

#include <gof/math/types>

#include <array>

using namespace gof;

TEST_CASE("Matrix constructor works", "[matrix]") {
    Matrix<2, 2, float> A(1.0f, 2.0f, 3.0f, 4.0f);
    const std::array<float, 4> b({1.0f, 2.0f, 3.0f, 4.0f});
    REQUIRE( A.values() == b );
}

TEST_CASE("Matrix get row works", "[matrix]") {
    Matrix<2, 2, float> A(1.0f, 2.0f, 3.0f, 4.0f);
    Vector<2, float>  r1{0.0f, 0.0f}; // FIXME Should return 1st row.
    REQUIRE(A.row(1) == r1);
}