load("//xla:xla.bzl", "xla_cc_binary", "xla_cc_test")

cc_library(
    name = "myplugin_cpp_pjrt",
    srcs = [
      "myplugin_cpp_pjrt.cc",
    ],
    hdrs = ["myplugin_cpp_pjrt.h"],
    deps = [
         "//xla/pjrt:pjrt_client",
    ],
)

xla_cc_test(
  name = "myplugin_cpp_pjrt_test",
  srcs = ["myplugin_cpp_pjrt_test.cc"],
  deps = [
    ":myplugin_cpp_pjrt",
    "@com_google_googletest//:gtest_main",
    "@tsl//tsl/platform:test",
    "@tsl//tsl/platform:status_matchers",
  ]
)

cc_library(
    name = "myplugin_c_pjrt",
    srcs = [
      "myplugin_c_pjrt.cc",
    ],
    hdrs = ["myplugin_c_pjrt.h"],
    deps = [
        ":myplugin_cpp_pjrt",
         "//xla/pjrt/c:pjrt_c_api_hdrs",
         "//xla/pjrt/c:pjrt_c_api_wrapper_impl",
    ],

    alwayslink = 1,
)

xla_cc_test(
  name = "myplugin_c_pjrt_test",
  srcs = ["myplugin_c_pjrt_test.cc"],
  deps = [
    ":myplugin_c_pjrt",
    "@com_google_googletest//:gtest_main",
    "@tsl//tsl/platform:test",
  ]
)

xla_cc_binary(
    name = "pjrt_c_api_myplugin_plugin.so",
    linkshared = True,
    deps = [
        ":myplugin_c_pjrt",
    ]
)
