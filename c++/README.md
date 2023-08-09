# Cooking with C++

## Quick Start

Here's how to build the scripts used here:

```
mkdir build
cd build
cmake ..
make
```

Then, all the scripts can are built in the created build folder.

## General notes about this language and ecosystem

### Syntax of Datatypes

One thing about C/C++ that might be a bit confusing is the way we have to parse
data types, where we have to think about the order in which the types are written.

```C++
int num; # integer
int *num; # pointer to integer
int * const num; # const pointer to integer
int const * num; # pointer to a const integer
```

[This post of stack overflow](https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const/1143272#1143272) is quite helpful in understanding how to read these
types. This syntax works well in general for simple types, but for things like
a function pointer, you have to write this:

```C++
int (*fp)(int a, int b); # fp is a function pointer that takes two ints as argument and returns an integer
```

In other languages, there other ways to define a syntax for types like these, see
this [post about Go's syntax](https://go.dev/blog/declaration-syntax) which is quite interesting.

### Packaging / Package Manager

There is not really a "main" package/dependency manager with package index for C++, like [pip/PyPi for python](https://pypi.org/), [Cargo for rust](https://crates.io/), [npm for javascript](), [gem for ruby](https://rubygems.org/), ....

However, there are many tools out there that try to do the same thing for C++, like [conan](https://conan.io/), [vcpkg](https://github.com/Microsoft/vcpkg), or [others](https://stackoverflow.com/questions/27866965/does-c-have-a-package-manager-like-npm-pip-gem-etc). Another way to easily manage third-party projects and use them in your project is [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) which is a CMake script that adds dependency management capabilities to CMake. In this Cookbook, we use `CPM.cmake`.

### Folder Structure Conventions

There is no set folder convention for C++ projects, it kinda depends on how you set up
your build system. For me, this structure works, which is partly adapted from Jason Tuerner's [cmake_template](https://github.com/cpp-best-practices/cmake_template):

```
.
├── cmake
│   └── CPM.cmake
├── CMakeLists.txt
├── Dependencies.cmake
├── README.md
└── src
    ├── basic_adder.cpp
    ├── hello_world.cpp
    ├── ...
    └── CMakeLists.txt
```

To extend new targets to compile, you can create a new file and
define new targets in `src/CMakeLists.txt`.

### Build Systems

The are many ways to build a C/C++ application.

Build system combinations. For this Cookbook repository, I decided to use [cmake](https://cmake.org/)
and make, since this is the one that most people are using _(don't quote me)_,
but there also many projects using [meson](https://mesonbuild.com/).

The underlying compiler can be GCC, clang, or any other compiler, make sure the
compiler supports the [C++ standard](https://en.cppreference.com/w/cpp/language/history)
you are using.

### Formatter + Linter

For formatting and linter, we can use clang, which is defined in `.clang-format`
and `.clang-tidy` respectively. The formatter parses the code and looks on a
syntax level and enforces common formatting rules. The linter looks deeper
and tries to flag things that might be considered bad practice.

Your IDE, like vscode or your vim extension, can use the rules defined in
`.clang-format` or `.clang-tidy` and give you, the developer, warnings or
errors if the rules are violated.

### Learning Resources

As C++ is a very widely used language, there are many projects using C++ and 
conversely also many learning resources. Here is a collection of nice learning
tools to learn C++:

* [The Cherno's youtube playlist of C++ tutorials](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&ab_channel=TheCherno)
* There are many C++ book, so here's a [repository](https://github.com/yuchdev/CppBooks) with a great overview on what kind of books to read
