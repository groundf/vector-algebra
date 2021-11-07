/*
 * Simple implementation of vectors for educational purpose.
 *
 * Uses no template parameters => u have to duplicat ea lot of code, but it
 * is straightforward and easy to follow.
 */
#pragma once

#include <cstddef>

namespace gof {

class Vector2 {

  float _x,  _y;

  public:

    // Constructor.
    Vector(float x, float y) : _x(x), _y(y) { };
};


class Vector2 {

  float _x,  _y, _z;

  public:

    // Constructor.
    Vector(float x, float y, float z) : _x(x), _y(y), _z(z) { };
};

// operators


} // namespace