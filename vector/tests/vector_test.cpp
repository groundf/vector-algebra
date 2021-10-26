#include <catch2/catch_test_macros.hpp>

#include <vector/vector.hpp>

using namespace gof;


TEST_CASE("Vectors 3", "[vectors]") {

    Vector3<float> u(1.0f, 2.0f, 3.0f);
    Vector3<float> v(3.0f, 2.0f, 1.0f);

    SECTION("== operator") {
        REQUIRE(v == v);
    }

    SECTION("!= operator") {
        REQUIRE(u != v);
    }

    SECTION("* operator") {
        REQUIRE( (1.0f * v) == v);
    }
}

TEST_CASE("Vector 2", "[vectors]") {

    Vector2<float> u(1.0f, 2.0f);
    Vector2<float> v(3.0f, 2.0f);

    SECTION("== operator") {
        REQUIRE(v == v);
    }

    SECTION("!= operator") {
        REQUIRE(u != v);
    }

    SECTION("* operator") {
        REQUIRE( (1.0f * v) == v);
    }
}
