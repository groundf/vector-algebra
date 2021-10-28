#include <catch2/catch_test_macros.hpp>

#include <vector/Types.hpp>
#include <vector/Vector.hpp>

#include <vector/simple/Vector2.hpp>
#include <vector/simple/Vector3.hpp>


using namespace gof;


TEST_CASE("Vector N", "[vector_n]") {

    SECTION("1") {
        Vector<2, float> u(1.0f);
        REQUIRE(u.x() == 1.0f);
        REQUIRE(u.y() == 0.0f);
    }

    SECTION("2") {
        Vector<2, float> u(1.0f, 1.0f);
        REQUIRE(u.x() == 1.0f);
        REQUIRE(u.y() == 1.0f);
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

    SECTION("unary operator -") {
        Vector2f u(1.0f, 2.0f);
        auto v = -u;
        REQUIRE(v.x() == -1.0f);
        REQUIRE(v.y() == -2.0f);
    };

    SECTION("binary operator +") {
        Vector2f u(1.0f, 2.0f);
        Vector2f v(2.0f, 1.0f);
        auto w = u + v;
        REQUIRE(w.x() == 3.0f);
        REQUIRE(w.y() == 3.0f);
    };

    SECTION("binary operator -") {
        Vector2f u(1.0f, 2.0f);
        Vector2f v(1.0f, 2.0f);
        auto w = u - v;
        REQUIRE(w.x() == 0.0f);
        REQUIRE(w.y() == 0.0f);
    };

    // This should not compile.
    // SECTION("wrong type") {
    //     #include <string>
    //     Vector<2, std::string> v("a", "b");
    // }
}

// TEST_CASE("Scalar product", "[vectors]") {

//     Vector3<float> u(1.0f);
//     Vector3<float> v(1.0f);

//     auto s = scalar_product(u, v);

// }


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
