package(default_visibility = ["//visibility:public"])

cc_library(
    name = "flight_management_system",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/**/*.h"]),
    strip_include_prefix = "include",
    deps = [
        "@nholthaus//:units",
    ],
)
