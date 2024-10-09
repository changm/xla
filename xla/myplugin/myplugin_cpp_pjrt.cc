#include "myplugin_cpp_pjrt.h"

namespace myplugin_pjrt {

absl::string_view MypluginPjrtClient::platform_name() const {
  return "myplugin_pjrt_client";
}

int MypluginPjrtClient::process_index() const {
  return 0;
}

} // namespace myplugin_pjrt
