# Vector library

The vector math header-only C++ library.

## Execute

    cmake -B build

    cmake --build build

    ctest -C debug --test-dir build
or
    ctest -C release --test-dir build --verbose

## Roadmap

- Implement basic algeabric types:
  - [ ] The `Vector<N, T>` template class and its specialized versions (aliases) e.g
    - [x] `Vector2f = Vector<2, float>`,
    - [x] `Vector3f = Vector<3, float>`,
    - [x] `Vector4f = Vector<4, float>` etc.
    - [x] `s * v` v ∈ V, s is scalar
    - [x] `u + v` u, v ∈ V
    - [x] `u - v` u, v ∈ V
    - [ ] `one` factory method
    - [ ] `zero` factory method
    - [ ] `unit_x` factory method
    - [ ] `unit_y` factory method
    - [ ] `unit_z` factory method
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

## Questions

- Should we implement expression templates?
- How to effectively use C++ concepts?

## Notes & Guide

- Vector SHOULD implement the constructor which populates vector with the same value.

  ```
  Vector2f v(1.0) -> v(1.0, 1.0)
  ```

- Constructor with one value MUST be marked as `explicit`.
- Documenatation commenst MUST follow https://developer.lsst.io/cpp/api-docs.html


## Rererences

- https://mariusbancila.ro/blog/2019/10/04/concepts-versus-sfinae-based-constraints/
- https://github.com/VecPP/vecpp/blob/master/include/vecpp/vec/vec.h
- C++ templates: conditionally enabled member function
- http://coddingbuddy.com/article/57490558/c-templates-conditionally-enabled-member-function
- https://akrzemi1.wordpress.com/2020/01/29/requires-expression/
- https://stackoverflow.com/questions/41667905/enable-if-minimal-example-for-void-member-function-with-no-arguments
- https://github.com/smrfeld/cmake_cpp_pybind11_tutorial
- https://developer.lsst.io/cpp/api-docs.html#cpp-doxygen-tparameters
- https://www.gamedev.net/blogs/entry/2265481-oop-is-dead-long-live-oop/
- https://www.sandordargo.com/blog/2021/02/24/cpp-concepts-with-classes
- https://subscription.packtpub.com/book/programming/9781786465184/1/ch01lvl1sec13/enabling-range-based-for-loops-for-custom-types