#include <gtest/gtest.h>

#include "xla/pjrt/c/pjrt_c_api_wrapper_impl.h"
#include "myplugin_c_pjrt.h"
#include "tsl/platform/test.h"

namespace {

TEST(MypluginCPjRtTest, CreatesPjRtAPI) {
  const PJRT_Api* myplugin = GetPjrtApi();
  EXPECT_THAT(myplugin, ::testing::NotNull());
}

} // namespace
