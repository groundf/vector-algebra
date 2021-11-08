#include <catch2/catch_test_macros.hpp>

#include <gof/math/types>
// #include <gof/math/vector/Vector.hpp>


using namespace gof;


SCENARIO("Vector constructors works", "[vector]")
{
    GIVEN("A vector with N = 2 components")
    {
        Vector2f u(1.0f);
        WHEN("A we make vector from this") {
            auto v = Vector2f(u);
            THEN("a new vector has a same values") {
                REQUIRE(v.x() == 1.0f);
                REQUIRE(v.y() == 0.0f);
            }
        }
    }

    GIVEN("A vector with N = 3 components")
    {
        Vector3f u(1.0f);
        WHEN("A we make vector from this") {
            auto v = Vector3f(u);
            THEN("a new vector has a same values") {
                REQUIRE(v.x() == 1.0f);
                REQUIRE(v.y() == 0.0f);
                REQUIRE(v.z() == 0.0f);
            }
        }
    }

    GIVEN("A vector with N = 4 components")
    {
        Vector4f u(1.0f);
        WHEN("A we make vector from this") {
            auto v = Vector4f(u);
            THEN("a new vector has a same values") {
                REQUIRE(v.x() == 1.0f);
                REQUIRE(v.y() == 0.0f);
                REQUIRE(v.z() == 0.0f);
                REQUIRE(v.w() == 0.0f);
            }
        }
    }
}

SCENARIO("Vector accessors works", "[vector]")
{
    GIVEN("A vectors with N = 2 components")
    {
        Vector2f v(1.0f);

        WHEN("A vector is created")
        {
            THEN("we can access `x` and `y` component") {
                REQUIRE(v.x() == 1.0);
                REQUIRE(v.y() == 0.0);
            }
            THEN("the size is correct") {
                REQUIRE(v.size == 2);         // object access
                REQUIRE(Vector2f::size == 2); // class access
            }
        }
    }

    GIVEN("A vectors with N = 3 components")
    {
        Vector3f v(1.0f);

        WHEN("A vector is created")
        {
            THEN("we can access `x`, `y` and `z` component") {
                REQUIRE(v.x() == 1.0);
                REQUIRE(v.y() == 0.0);
                REQUIRE(v.z() == 0.0);
            }
            THEN("the size is correct") {
                REQUIRE(v.size == 3);         // object access
                REQUIRE(Vector3f::size == 3); // class access
            }
        }
    }

    GIVEN("A vectors with N = 4 components")
    {
        Vector4f v(1.0f);

        WHEN("A vector is created")
        {
            THEN("we can access `x`, `y`, `z` and `w` component") {
                REQUIRE(v.x() == 1.0);
                REQUIRE(v.y() == 0.0);
                REQUIRE(v.z() == 0.0);
                REQUIRE(v.w() == 0.0);
            }
            THEN("the size is correct") {
                REQUIRE(v.size == 4);         // object access
                REQUIRE(Vector4f::size == 4); // class access
            }
        }
    }
}

SCENARIO("Vector factories works", "[vector]")
{
    GIVEN("A vectors with N = 2 components")
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

    GIVEN("A vectors with N = 3 components")
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

SCENARIO("Vector equality works", "[vector]")
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

SCENARIO("Vector arithmetic works", "[vector]")
{
    GIVEN("A vectors with N = 2 components")
    {
        Vector2f u(1.0f, 2.0f);
        Vector2f v(-1.0f, -2.0f);

        WHEN("we add two opposite vectors") {
            THEN("we get the zero vector") {
                REQUIRE((u + v) == Vector2f::zero());
            }
        }

        WHEN("we subtract two equal vectors") {
            THEN("we get the zero vector") {
                REQUIRE((v - v) == Vector2f::zero());
            }
        }

        WHEN("we multiply vector with one") {
            THEN("we get the same vector") {
                REQUIRE( (1.0f * v) == v);
            }
        }

        WHEN("we multiply vector with zero") {
            THEN("we get the zero vector") {
                REQUIRE( (0.0f * v) == Vector2f::zero());
                REQUIRE(u.scale(0.0f) == Vector2f::zero());
            }
        }

        WHEN("we negate vector with unary operator") {
            THEN("we get an opposite vector") {
                REQUIRE(-u == v);
            }
        }
    }

    GIVEN("A vectors with N = 3 components")
    {
        Vector3f u(1.0f, 2.0f, 3.0f);
        Vector3f v(-1.0f, -2.0f, -3.0f);

        WHEN("we add two opposite vectors") {
            THEN("we get the zero vector") {
                REQUIRE((u + v) == Vector3f::zero());
            }
        }

        WHEN("we subtract two equal vectors") {
            THEN("we get the zero vector") {
                REQUIRE((u - u) == Vector3f::zero());
            }
        }

        WHEN("we multiply vector with one") {
            THEN("we get the same vector") {
                REQUIRE( (1.0f * u) == u);
            }
        }

        WHEN("we multiply vector with zero") {
            THEN("we get the zero vector") {
                REQUIRE( (0.0f * u) == Vector3f::zero());
                REQUIRE(u.scale(0.0f) == Vector3f::zero());
            }
        }

        WHEN("we negate vector with unary operator") {
            THEN("we get an opposite vector") {
                REQUIRE(-u == v);
            }
        }
    }
}


TEST_CASE("`is_unit()` works") {
    auto u = Vector2f(1.0f, 0.0f);
    auto v = Vector2f(1.0f, 1.0f);
    REQUIRE(u.is_unit());
}


TEST_CASE("is_zero() works") {
    auto u = Vector2f(0.0f, 0.0f);
    auto v = Vector2f(1.0f, 0.0f);

    REQUIRE(u.is_zero());
    REQUIRE_FALSE(v.is_zero());
}


TEST_CASE("is_opposite() works") {
    auto u = Vector2f(1.0f, 2.0f);
    auto v = Vector2f(-1.0f, -2.0f);
    REQUIRE(u.is_opposite(v));
}

// is_parallel_to()

// is_perpendicular_to()

// TODO Vector hash function works
