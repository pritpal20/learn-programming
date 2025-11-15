# Unit Testing Practice

This project is designed to help you learn and practice unit testing in various programming languages.

## Getting Started

Clone the repository:

cd C-project/c++

Add GoogleTest as a submodule (if not already added) and fetch submodules:

git submodule add <https://github.com/google/googletest.git>
git submodule update --init --recursive

## Build (C++)

From the `Unit-testing-practice/C-project/c++` directory, create a build directory and run CMake + make:

mkdir -p build
cd build
cmake ..
make -j

This configures and builds the test binaries. The CMake setup in this project uses the `googletest` submodule.

## Build and run the main target

Build the `MyProject` executable:

make MyProject

Run the `MyProject` executable:

./MyProject

Or build and run in one command:

make MyProject && ./MyProject

## Run tests

Run all tests with CTest (recommended):

ctest --output-on-failure

Or run the test binary directly (example executable name found in the build directory):

./test_demo

For verbose CTest output use:

ctest -V

To run a single test by regex with CTest:

ctest -R 'test-name-regex' -V
