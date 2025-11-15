cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [],
)

cc_library(
    name = "my_vector",
    srcs = ["my_vector.h"],
    deps = [],
)

cc_library(
    name = "my_stack",
    srcs = ["my_stack.h"],
    deps = [":my_vector"],
)

cc_test(
    name = "test_my_vector",
    srcs = ["test_my_vector.cpp"],
    deps = [
        ":my_vector",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test_my_stack",
    srcs = ["test_my_stack.cpp"],
    deps = [
        ":my_stack",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)