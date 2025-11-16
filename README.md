# learn-programming

A collection of programming projects for learning and practicing various concepts and best practices.

## Projects

### C++ Projects

- **[Smart Pointers](./cpp/smart_pointers/)** — Learn about unique_ptr, shared_ptr, and other smart pointer concepts
- **[Template Demo](./cpp/template_demo/)** — Explore C++ templates and generic programming
- **[Demo Move Constructor](./cpp/demo_move_constructor/)** — Understand move semantics and rvalue references
- **[Library & Tests](./cpp/lib/)** — Common library code with unit tests
- **[Main](./cpp/)** — Core C++ examples and demonstrations

### [Unit Testing Project](./unit_testing_project/README.md)

- **[Unit Testing Project](./unit_testing_project/)** — Learn unit testing with GoogleTest
  - [C++ Testing Examples](./unit_testing_project/c++/) — CMake-based C++ unit testing with GoogleTest
  - [C Testing Examples](./unit_testing_project/C-project/) — C unit testing examples

### Python Projects

- **[Python](./python/)** — Python learning projects (content available)

## Quick Start

To run the smart pointers example with Bazel:

```bash
bazel run //cpp/smart_pointers:main --ui_event_filters=-info,-stdout,-stderr --noshow_progress
```

For C++ unit testing, see [unit_testing_project/README.md](./unit_testing_project/README.md) for build and test instructions.
