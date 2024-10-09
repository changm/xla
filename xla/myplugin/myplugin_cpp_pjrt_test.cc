#include <gtest/gtest.h>

#include "myplugin_cpp_pjrt.h"
#include "tsl/platform/test.h"
#include "tsl/platform/status_matchers.h"

namespace {

using ::myplugin_pjrt::MypluginPjrtClient;

TEST(MyPluginCPPTest, HasDeviceCount) {
  MypluginPjrtClient client;
  EXPECT_EQ(client.device_count(), 42);
}

TEST(MyPluginCPPTest, GetHloCostAnalysis) {
  MypluginPjrtClient client;
  EXPECT_THAT(client.GetHloCostAnalysis(), testing::Not(::tsl::testing::IsOk()));
}

} // namespace
