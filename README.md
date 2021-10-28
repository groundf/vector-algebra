# Vector library

The vector math header-only C++ library.

## Execute

    cmake -B build

    cmake --build build

    ctest -C debug --test-dir build
or
    ctest -C release --test-dir build --verbose

## Roadmap

- Implement basic algeabric/geometric types such as
  - [ ] The `Vector<N, T>` template class and its specialized versions (aliases) e.g
    - [ ] `Vector2f = Vector<2, float>`,
    - [ ] `Vector3f = Vector<3, float>`,
    - [ ] `Vector4f = Vector<4, float>` etc.
    -  `+`
    -  `-`
    -  `*`

  - [ ] The `Matrix<N, M, T>` template class and its specialized versions (aliases) e.g
    - [ ] `Matrix2f = Matrix<2, 2, float>`,
    - [ ] `Matrix3f = Matrix<3, 3, float>`,
    - [ ] `Matrix4f = Matrix<4, 4, float>` etc.
  - [ ] The `Point<N, T>`
  - [ ] The `Line`
  - [ ] `Ray`
  - [ ] `Color`
  - [ ] `Rotation`


## Notes
  - Konstruktor inicilizuje vektor jednou hodnotou.
  - Konstruktor s jednou hodnoutou musí být označen jako `explicit`.

## Rererences

- https://mariusbancila.ro/blog/2019/10/04/concepts-versus-sfinae-based-constraints/
- https://github.com/VecPP/vecpp/blob/master/include/vecpp/vec/vec.h
- C++ templates: conditionally enabled member function
- http://coddingbuddy.com/article/57490558/c-templates-conditionally-enabled-member-function
- https://akrzemi1.wordpress.com/2020/01/29/requires-expression/
- https://stackoverflow.com/questions/41667905/enable-if-minimal-example-for-void-member-function-with-no-arguments
- https://github.com/smrfeld/cmake_cpp_pybind11_tutorial
- https://developer.lsst.io/cpp/api-docs.html#cpp-doxygen-tparameters