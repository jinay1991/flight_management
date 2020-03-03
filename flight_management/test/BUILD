cc_test(
    name = "unit_tests",
    srcs = [
        "logging_test.cpp",
        "unit_tests.cpp",
    ],
    deps = [
        "//flight_management",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "acceptance_tests",
    srcs = ["acceptance_tests.cpp"],
    deps = [
        "//flight_management",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "component_tests",
    srcs = ["component_tests.cpp"],
    deps = [
        "//flight_management",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "smoke_tests",
    srcs = ["smoke_tests.cpp"],
    deps = [
        "//flight_management",
        "@googletest//:gtest_main",
    ],
)
