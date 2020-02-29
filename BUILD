package(default_visibility = ["//visibility:public"])

filegroup(
    name = "testdata",
    srcs = [
        "data/highway_map.csv",
    ],
)

cc_library(
    name = "simulator_communications",
    srcs = glob(
        ["src/**/*.cpp"],
        exclude = ["src/main.cpp"],
    ),
    hdrs = glob([
        "include/**/*.h",
    ]),
    copts = [
        "-std=c++14",
        "-Wall",
        "-Werror",
    ],
    includes = ["include"],
    deps = [
        "//lib:motion_planning",
        "@eigen",
        "@nlohmann//:json",
        "@spline",
        "@uwebsocket",
    ],
)

cc_binary(
    name = "simulator_client",
    srcs = ["src/main.cpp"],
    copts = [
        "-std=c++14",
        "-Wall",
        "-Werror",
    ],
    data = [":testdata"],
    includes = ["include"],
    deps = [
        ":simulator_communications",
    ],
)
