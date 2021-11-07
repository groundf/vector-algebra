# Vector algebra library

__The header-only C++ vector algebra library useful for computer graphics.__

## Usage

The library currently live under 𝖌 ∘ 𝖋 namespace.

```cpp
#include <gof/types>

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

## Compilation

This project uses CMake.

```
cmake -B build
cmake --build build
ctest -C debug --test-dir build
```
or
```
ctest -C release --test-dir build --verbose
```

## Development

- Compilation via [CMake](https://cmake.org/).
- Documentation via [Doxygen](https://www.doxygen.nl/).
- Formatting via `clang-format`
- Linting via `clang-tidy`

## Overview

All the library types are value objects i.e. that they are immutable and they equality is defined by their attributes.
In other words, when they have same attributes the are considered equal. because they are immutable we can also define
hashing functions for them which means they can be stored in maps (`std::map`). The term value object comes from
Domain Driven Design and you can learn about thsi term [here](https://en.wikipedia.org/wiki/Value_object).

__Here are some general design-notes/style-guide and roadmap.__

- [ ] Should we implement expression templates https://en.wikipedia.org/wiki/Expression_templates?
- [ ] How to effectively use C++ concepts?
- [ ] Use header files without extension for interface see https://stackoverflow.com/questions/40624930/c-header-files-with-no-extension
  e.g `Types` header is without suffix and it imports `Vector.hpp` and `Matrix.hpp` headers. This is similar to Haskell lib approach.

- [x] Vector SHOULD implement the constructor populating the vector with the same value.
  `Vector2f v(1.0) -> v(1.0, 1.0)`

- [x] Constructor with one value MUST be marked as `explicit` e.g see [](https://github.com/ConfettiFX/The-Forge/blob/2665761184b3dfdbc307fa5e19b03b4e3944b578/Common_3/ThirdParty/OpenSource/ModifiedSonyMath/sse/vectormath.hpp#L2946)
- Documenatation commenst MUST follow https://developer.lsst.io/cpp/api-docs.html

- Algeabric/Geometric types:
  - [ ] The `Vector<N, T>` template class and its specialized versions (aliases) e.g
    - [x] `Vector2f = Vector<2, float>`,
    - [x] `Vector3f = Vector<3, float>`,
    - [x] `Vector4f = Vector<4, float>` etc.
    - [x] `s * v` v ∈ V, s is scalar
    - [x] `u + v` u, v ∈ V
    - [x] `u - v` u, v ∈ V

    - [ ] `x()` cartesian coordinate getter for N >= 1
    - [ ] `y()` cartesian coordinate getter for N >= 2
    - [ ] `z()` cartesian coordinate getter for N >= 3
    - [ ] `w()` cartesian coordinate getter for N == 4

    - [ ] `swizzle`
    - [ ] `xy`, `xyz`, `xyzw` ...

    - [ ] `rho()` polar coordinate
    - [ ] `phi()` cylindrical coordinate

    - [x] `ones()` factory method
    - [x] `zero()` factory method
    - [ ] `axis_x(T length = 1.0f)` factory method
    - [ ] `axis_y(T length = 1.0f)` factory method
    - [ ] `axis_z(T length = 1.0f)` factory method
    - [x] `unit_x() = axis_x()` factory method
    - [x] `unit_y() = axis_y()` factory method
    - [x] `unit_z() = axis_z()` factory method
    - [x] `unit_w()` factory method
    - [ ] `from_angle(angle, length = 1.0)`: Vytvoří (jednotkový) vektor směřujíci do daneho uhlu.

    - [ ] `flip()`
    - [x] `scale(factor)` aka `s * v`
    - [ ] `is_opposite(to)`
    - [ ] `rotate(angle, axis)` rotate vector by `angle` around `axis`
    - [ ] `rotate_90_cw(axis)` clock-wise
    - [ ] `rotate_90_ccw(axis)` counter-clock-wise
    - [ ] `project(vector)`
    - [ ] `reflect(normal: Vector)`: Provede reflexi vektoru podle zadané normály.
    - [ ] `reverse` or `negate` or `opposite`: Otočí vektor do opačného směru
    - [ ] `bounce(normal: Vector)`: Provede reflexi vektoru podle zadané normály a zárověň změní směr na opačný. Hodí se to např. pokud se předmět odrazí od stěny viz zákon dopadu a odrazu.
    - [ ] Let vector be iterable with range based loop.
    - [ ] `distance_to`
    - [ ] `angle_between`

  - [ ] The `Matrix<N, M, T>` template class and its specialized versions (aliases) e.g
    - [ ] `Matrix2f = Matrix<2, 2, float>`,
    - [ ] `Matrix3f = Matrix<3, 3, float>`,
    - [ ] `Matrix4f = Matrix<4, 4, float>` etc.

  - `Position2`/`Position3` is a vector representing the position of some object. This is alias for vector.
  - `Direction2`/`Direction3` is vector with of unit length pointing to some direction. This is mostly alias for vector.

  - `Basis`: The cartesian base of vectors (orthogonal or orthonormal).

  - [ ] The `Point<N, T>`
    - [ ] `from_polar()`
    - [ ] `along()`
    - [ ] `midpoint`
    - [ ] `interpolate`
    - [ ] `interpolate_from`
    - [ ] `distance_to` výpočet vzdálenosti mezi dvěma body
    - [ ] `rotate`, `traslate`, `reflect`, `mirror`, `project`
    - [ ] konverze bodů mezi různými souřadnými soustavami (polární)

  - [ ] `Angle`
  - [ ] `Rectangle`
  - [ ] `Line`
  - [ ] `Ray`: For raytracing
  - [ ] `Color`: Represents the RGB or RGBA color.
  - [ ] `Transformation`: Translation, Rotation and so on...
  - [ ] `Rotation < Transformation`:

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
- https://github.com/opensolid/geometry/blob/master/src/OpenSolid/Point2d.elm

- https://www.youtube.com/watch?v=rK6ulQaOpso&t=1658s&ab_channel=Gamefromscratch
- https://www.youtube.com/playlist?list=PLS9MbmO_ssyBfq4jdnzR5NQZV6j_JkWGZ


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

### Notes on vector math library design in C++

The various implementations of vetor and matrix classes

- https://github.com/knightcrawler25/GLSL-PathTracer/blob/master/src/math/Vec3.h
- https://github.com/RomkoSI/G3D/blob/master/G3D.lib/include/G3D/Vector3.h

- https://github.com/godotengine/godot/blob/master/core/math/vector3.h


- https://github.com/godotengine/godot-cpp/blob/master/src/variant/vector2.cpp

- https://docs.unity3d.com/ScriptReference/Vector2.html
- https://docs.unity3d.com/ScriptReference/Vector3.html

- https://github.com/aws/lumberyard/blob/414466d63520443fafd8c27c4735fee099914384/dev/Code/Framework/AzCore/AzCore/Math/Vector2.h

- https://github.com/aws/lumberyard/blob/414466d63520443fafd8c27c4735fee099914384/dev/Code/Framework/AzCore/AzCore/Math/Vector4.h

- https://docs.unrealengine.com/4.27/en-US/API/Runtime/Core/Math/FVector/

- https://github.com/stride3d/stride/blob/6b020703bfd8ff1e42325930a5e1a547b021d324/sources/core/Stride.Core.Mathematics/Vector3.cs
- https://doc.stride3d.net/latest/en/api/Stride.Core.Mathematics.Vector2.html
https://cppdepend.com/blog/?p=13

- https://github.com/ConfettiFX/The-Forge/blob/2665761184b3dfdbc307fa5e19b03b4e3944b578/Common_3/ThirdParty/OpenSource/ModifiedSonyMath/sse/vectormath.hpp
