#include "xla/pjrt/c/pjrt_c_api_wrapper_impl.h"
#include "myplugin_c_pjrt.h"
#include "myplugin_cpp_pjrt.h"

namespace myplugin_pjrt {

std::unique_ptr<xla::PjRtClient> GetPluginPjRtClient() {
  return std::make_unique<myplugin_pjrt::MypluginPjrtClient>();
}

// Create my client
PJRT_Error* PJRT_MypluginClient_Create(PJRT_Client_Create_Args* args) {
  std::unique_ptr<xla::PjRtClient> client = GetPluginPjRtClient();
  args->client = pjrt::CreateWrapperClient(std::move(client));
  printf("Creating PJRT Client from myplugin_pjrt.cc\n");
  return nullptr;
}

PJRT_Error* PJRT_MypluginExecuteContext_Create(PJRT_ExecuteContext_Create_Args* args) {
  return new PJRT_Error{absl::UnimplementedError(
      "ExecuteContext not supported for MyPlugin execution.")};
}

PJRT_Error* PJRT_MypluginDeviceTopology_Create(
    PJRT_TopologyDescription_Create_Args* args) {
  return new PJRT_Error{
      absl::UnimplementedError("Topology not supported for MyPlugin compilation.")};
}

} // namespace myplugin_pjrt

const PJRT_Api* GetPjrtApi() {
  printf("C++ Calling GetPjrtApi");
  static PJRT_Layouts_Extension layouts_extension =
      pjrt::CreateLayoutsExtension(nullptr);

  static const PJRT_Api pjrt_api = pjrt::CreatePjrtApi(
      myplugin_pjrt::PJRT_MypluginClient_Create,
      myplugin_pjrt::PJRT_MypluginExecuteContext_Create,
      myplugin_pjrt::PJRT_MypluginDeviceTopology_Create,
      pjrt::PJRT_Plugin_Initialize_NoOp,
      reinterpret_cast<PJRT_Extension_Base*>(&layouts_extension));

  printf("MyPlugin called GetPjrtApi\n");
  return &pjrt_api;
}
