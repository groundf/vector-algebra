#include <catch2/catch_test_macros.hpp>

#include <vector/Vector.hpp>
#include <vector/Vector2.hpp>
#include <vector/Vector3.hpp>


using namespace gof;


TEST_CASE("Vector N", "[vector_n]") {

    using Vector2f = Vector<2, float>;

    SECTION("1") {
        Vector<2, float> u(1.0f);
        REQUIRE(u._v[0] == 1.0f);
        REQUIRE(u._v[1] == 0.0f);
    }

    SECTION("2") {
        Vector<2, float> u(1.0f, 1.0f);
        REQUIRE(u._v[0] == 1.0f);
        REQUIRE(u._v[1] == 1.0f);
    }

    SECTION("3") {
        Vector<2, float> u(1.0f);
        REQUIRE(u.size == 2);                 // object access
        REQUIRE(Vector<2, float>::size == 2); // class access
    }

    SECTION("4") {
        Vector2f v(1.0f, 2.0f);
        REQUIRE(v.x() == 1.0f);
        REQUIRE(v.y() == 2.0f);
    };
}


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

    SECTION("constructor") {
        Vector2<float> w(1.0f);
        REQUIRE(w.x() == 1.0f);
        REQUIRE(w.y() == 1.0f);
    }
}
