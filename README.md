# learn-programming

A collection of programming projects for learning and practicing various concepts and best practices.

## Projects

### C++ Projects

- **[Smart Pointers](./cpp/smart_pointers/)** — Learn about unique_ptr, shared_ptr, and other smart pointer concepts
- **[Template Demo](./cpp/template_demo/)** — Explore C++ templates and generic programming
- **[Demo Move Constructor](./cpp/demo_move_constructor/)** — Understand move semantics and rvalue references
- **[Library & Tests](./cpp/lib/)** — Common library code with unit tests
- **[Main](./cpp/)** — Core C++ examples and demonstrations

### [Unit Testing Practice](./Unit-testing-practice/README.md)

- **[Unit Testing Practice](./Unit-testing-practice/)** — Learn unit testing with GoogleTest
  - [C++ Testing Examples](./Unit-testing-practice/c++/) — CMake-based C++ unit testing with GoogleTest
  - [C Testing Examples](./Unit-testing-practice/C-project/) — C unit testing examples

### Python Projects

- **[Python](./python/)** — Python learning projects (content available)

## Quick Start

To run the smart pointers example with Bazel:

```bash
bazel run //cpp/smart_pointers:main --ui_event_filters=-info,-stdout,-stderr --noshow_progress
```

For C++ unit testing, see [Unit-testing-practice/README.md](./Unit-testing-practice/README.md) for build and test instructions.
