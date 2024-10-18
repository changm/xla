#ifndef MYPLUGIN_PJRT_CPP_H
#define MYPLUGIN_PJRT_CPP_H

#include <vector>

#include "xla/pjrt/pjrt_client.h"

namespace myplugin_pjrt {
  using namespace xla;

  class MypluginPjrtClient : public xla::PjRtClient {
    public:
      MypluginPjrtClient() {};
      ~MypluginPjrtClient() override {};
      absl::string_view platform_name() const override;
      int process_index() const override;
      int device_count() const override { return 42; }
      int addressable_device_count() const override { return 43; }
      absl::Span<xla::PjRtDevice* const> devices() const override { return devices_; }
      absl::Span<xla::PjRtDevice* const> addressable_devices() const override { return devices_; }
      absl::Span<PjRtMemorySpace* const> memory_spaces() const override { return memory_spaces_; }

      // Return an ID that identifies the platform (CPU/GPU/TPU).
      PjRtPlatformId platform_id() const override { return 9001; }

      // Returns a string containing human-readable, platform-specific version info
      // (e.g. the CUDA version on GPU or libtpu version on Cloud TPU).
      absl::string_view platform_version() const override { return "myplugin platform version"; }

      PjRtRuntimeType runtime_type() const override { return kTfrt; }

    private:
      std::vector<xla::PjRtDevice*> devices_;
      std::vector<PjRtMemorySpace*> memory_spaces_;
  };  // end class

} // namespace

#endif // MYPLUGIN_PJRT_CPP_H
