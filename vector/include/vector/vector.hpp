#pragma once

#ifndef VECTOR_HEADER_LIBRARY
#define VECTOR_HEADER_LIBRARY

namespace gof {

class Vector
{
public:
  //{ constructors & destructor

  explicit Vector(const float & x, const float & y, const float & z)
    : _x(x)
    , _y(y)
    , _z(z)
  { }

  //}

  //{ getters and setters

  inline float x() const { return _x; };
  inline float y() const { return _y; };
  inline float z() const { return _z; };

  //}

private:
    const float _x;
    const float _y;
    const float _z;
};

} // namespace

#endif