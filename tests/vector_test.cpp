#include <catch2/catch_test_macros.hpp>

#include <gof/Types>


using namespace gof;


SCENARIO("Vector accessors are well defined",  "[vector]")
{
    GIVEN("A vector class with N = 2 components")
    {
        Vector2f v(1.0f);

        WHEN("A vector is created")
        {
            THEN("it has set a `x` and `y` property") {
                REQUIRE(v.x() == 1.0);
                REQUIRE(v.y() == 0.0);
            }
        }
    }
}

SCENARIO("Vector is created with factory method", "[vector]")
{
    GIVEN("A vector class with N = 2 components")
    {
        WHEN("the unit `x` vector is created")
        {
            auto v = Vector3f::unit_x();
            THEN("the `x` component is one and others are zero")
            {
                REQUIRE(v.x() == 1.0f);
                REQUIRE(v.y() == 0.0f);
            }
        }
        WHEN("the unit `y` vector is created")
        {
            auto v = Vector3f::unit_y();
            THEN("the `y` component is one and others are zero")
            {
                REQUIRE(v.x() == 0.0f);
                REQUIRE(v.y() == 1.0f);
            }
        }
        WHEN("the zero vector is created")
        {
            auto v = Vector3f::zero();
            THEN("all components are zero")
            {
                REQUIRE(v.x() == 0.0f);
                REQUIRE(v.y() == 0.0f);
            }
        }
    }
    GIVEN("A vector class with N = 3 components")
    {
        WHEN("the unit `x` vector is created")
        {
            auto v = Vector3f::unit_x();
            THEN("the `x` component is one and others are zero")
            {
                REQUIRE(v.x() == 1.0f);
                REQUIRE(v.y() == 0.0f);
                REQUIRE(v.z() == 0.0f);
            }
        }
        WHEN("the unit `y` vector is created")
        {
            auto v = Vector3f::unit_y();
            THEN("the `y` component is one and others are zero")
            {
                REQUIRE(v.x() == 0.0f);
                REQUIRE(v.y() == 1.0f);
                REQUIRE(v.z() == 0.0f);
            }
        }
        WHEN("the unit `z` vector is created")
        {
            auto v = Vector3f::unit_z();
            THEN("the `z` component is one and others are zero")
            {
                REQUIRE(v.x() == 0.0f);
                REQUIRE(v.y() == 0.0f);
                REQUIRE(v.z() == 1.0f);
            }
        }
        WHEN("the zero vector is created")
        {
            auto v = Vector3f::zero();
            THEN("all components are zero")
            {
                REQUIRE(v.x() == 0.0f);
                REQUIRE(v.y() == 0.0f);
                REQUIRE(v.z() == 0.0f);
            }
        }
    }
}

SCENARIO("Vector equality operators are well defined", "[vector]")
{
    GIVEN("A vectors with N = 2 components")
    {
        Vector3f x(1.0f, 0.0f);
        Vector3f y(2.0f, 1.0f);

        WHEN("vectors has the same components")
        {
            THEN("they are considered equal")
            {
                REQUIRE(x == x);
            }
        }
        WHEN("vectors differ in any component")
        {
            THEN("they are considered not equal")
            {
                REQUIRE(x != y);
            }
        }
    }
    GIVEN("A vectors with N = 3 components")
    {
        Vector3f x(1.0f, 0.0f, 0.0f);
        Vector3f z(0.0f, 0.0f, 1.0f);

        WHEN("vectors has same components")
        {
            THEN("they are considered equal")
            {
                REQUIRE(x == x);
            }
        }
        WHEN("vectors differ in any component")
        {
            THEN("they are considered not equal")
            {
                REQUIRE(x != z);
            }
        }
    }
}


// REQUIRE( (1.0f * v) == v);


TEST_CASE("Vector N", "[vector2d]")
{
    Vector2f u(1.0f);


    SECTION("2") {
        Vector2f u(1.0f, 1.0f);
        REQUIRE(u.x() == 1.0f);
        REQUIRE(u.y() == 1.0f);
    }

    SECTION("3") {
        Vector2f u(1.0f);
        REQUIRE(u.size == 2);         // object access
        REQUIRE(Vector2f::size == 2); // class access
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
}


TEST_CASE("vector operators N = 2", "[vectors 2]")
{
    Vector2f u(1.0f, 2.0f);
    Vector2f v(3.0f, 2.0f);

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
        Vector2f w(1.0f);
        REQUIRE(w.x() == 1.0f);
        REQUIRE(w.y() == 0.0f);
    }
}
