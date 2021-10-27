

# Vector library

The vector math header-only C++ library.


## Execute

    cmake -B build

    cmake --build build

    ctest -C debug --test-dir build
or

    ctest -C release --test-dir build --verbose


## Roadmap

Implementace základních geomterických matematických objektů

- [ ] Implement `Vector<N, T> template class` and specialized `Vector<2, T>`, `Vector<3, T>`, `Vector<4, T>` versions.

-
- Konstruktor inicilizuje vektor jednou hodnotou.
- Konstruktor s jednou hodnoutou musí být označen jako `explicit`.
-

## Rererences

- https://mariusbancila.ro/blog/2019/10/04/concepts-versus-sfinae-based-constraints/
- https://github.com/VecPP/vecpp/blob/master/include/vecpp/vec/vec.h
-
- C++ templates: conditionally enabled member function
- http://coddingbuddy.com/article/57490558/c-templates-conditionally-enabled-member-function
- https://akrzemi1.wordpress.com/2020/01/29/requires-expression/
- https://stackoverflow.com/questions/41667905/enable-if-minimal-example-for-void-member-function-with-no-arguments
- https://github.com/smrfeld/cmake_cpp_pybind11_tutorial