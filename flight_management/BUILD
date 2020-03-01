package(default_visibility = ["//visibility:public"])

cc_library(
    name = "flight_management_system",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
)

cc_test(
    name = "unit_tests",
    srcs = ["test/unit_tests.cpp"],
    deps = [
        ":flight_management_system",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "component_test",
    srcs = ["test/component_tests.cpp"],
    deps = [
        ":flight_management_system",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "smoke_test",
    srcs = ["test/smoke_tests.cpp"],
    deps = [
        ":flight_management_system",
        "@googletest//:gtest_main",
    ],
)
