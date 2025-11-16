# Unit Testing Practice

This project is designed to help you learn and practice unit testing in various programming languages.

## Getting Started

Clone the repository:

```bash
cd c++
```

Add GoogleTest as a submodule (if not already added) and fetch submodules:

```bash
git submodule add <https://github.com/google/googletest.git>
git submodule update --init --recursive
```

## Build (C++)

From the `Unit-testing-practice/C-project/c++` directory, create a build directory and run CMake + make:

```bash
mkdir -p build
cd build
cmake ..
make -j
```

This configures and builds the test binaries. The CMake setup in this project uses the `googletest` submodule.

## Build and run the main target

Build the `MyProject` executable using make:

```bash
make MyProject
```

Or build using CMake:

```bash
cmake --build . --target MyProject
```

Run the `MyProject` executable:

```bash
./MyProject
```

Or build and run in one command:

```bash
make MyProject && ./MyProject
```

Or using CMake to build and then run:

```bash
cmake --build . --target MyProject && ./MyProject
```

## Run tests

Run all tests with CTest (recommended):

```bash
ctest --output-on-failure
```

Or run the test binary directly (example executable name found in the build directory):

```bash
./test_demo
```

For verbose CTest output use:

```bash
ctest -V
```

To run a single test by regex with CTest:

```bash
ctest -R 'test-name-regex' -V
```
