# Vector algebra library

_The header-only C++ vector algebra library used in computer graphics._

## Usage

The library currently live under 𝖌 ∘ 𝖋 namespace.

```cpp
#include <gof/Types>

using namespace gof;
```

```cpp
Vector2f v(1.0f, 3.0f);

std::cout << v.x() << std::endl; // => 1.0f
std::cout << v.y() << std::endl; // => 2.0f
```

```cpp
Vector3f v(1.0f, 2.0f, 3.0f);

std::cout << v.x() << std::endl; // => 1.0f
std::cout << v.y() << std::endl; // => 2.0f
std::cout << v.z() << std::endl; // => 3.0f
```

## Roadmap

- Implement basic algeabric types:
  - [ ] The `Vector<N, T>` template class and its specialized versions (aliases) e.g
    - [x] `Vector2f = Vector<2, float>`,
    - [x] `Vector3f = Vector<3, float>`,
    - [x] `Vector4f = Vector<4, float>` etc.
    - [x] `s * v` v ∈ V, s is scalar
    - [x] `u + v` u, v ∈ V
    - [x] `u - v` u, v ∈ V
    - [x] `ones()` factory method
    - [x] `zero()` factory method
    - [x] `unit_x()` factory method
    - [x] `unit_y()` factory method
    - [x] `unit_z()` factory method
    - [x] `unit_w()` factory method
    - [ ] `flip()`
    - [ ] `scale(factor)` aka `s * v`
    - [ ] `is_opposite(to)`
    - [ ] `rotate(angle, axis)` rotate vector by `angle` around `axis`
    - [ ] `rotate_90_cw(axis)` clock-wise
    - [ ] `rotate_90_ccw(axis)` counter-clock-wise
    - [ ] `project(vector)`
    - [ ] Let vector be iterable with range based loop.
  - [ ] The `Matrix<N, M, T>` template class and its specialized versions (aliases) e.g
    - [ ] `Matrix2f = Matrix<2, 2, float>`,
    - [ ] `Matrix3f = Matrix<3, 3, float>`,
    - [ ] `Matrix4f = Matrix<4, 4, float>` etc.
- Implement basic geometric types:
  - [ ] The `Point<N, T>`
  - [ ] The `Line`
  - [ ] `Ray`
  - [ ] `Color`
  - [ ] `Rotation`

## Compilation

This project uses CMake.

```
cmake -B build

cmake --build build

ctest -C debug --test-dir build

or

ctest -C release --test-dir build --verbose
```

## Development

- Compilation via [CMake](https://cmake.org/).
- Documentation via [Doxygen](https://www.doxygen.nl/).
- Formatting via clang-format
- Linting via ???
