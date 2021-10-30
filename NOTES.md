# Notes

## Questions

- Should we implement expression templates https://en.wikipedia.org/wiki/Expression_templates?
- How to effectively use C++ concepts?
- Use header files without extension for interface see https://stackoverflow.com/questions/40624930/c-header-files-with-no-extension
  e.g `Types` header is without suffix and it imports `Vector.hpp` and `Matrix.hpp` headers. This is similar to Haskell lib approach.

## Notes & Guide

- Vector SHOULD implement the constructor populating the vector with the same value.

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

- https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/


### Engines

#### The open-source game engines

CryEngine
- https://github.com/CRYTEK/CRYENGINE
- Far Cry, Kingdom Come: Deliverance, and Crysis.

Ureal Engine
- https://www.unrealengine.com/
- https://www.unrealengine.com/en-US/ue4-on-github


#### The close-source game engines

Decima
- https://en.wikipedia.org/wiki/Decima_(game_engine)
- https://www.guerrilla-games.com/read/decima


_Programming in C++ is a true art because it is so subjective._
