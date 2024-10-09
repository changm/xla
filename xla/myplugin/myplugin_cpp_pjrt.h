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

      absl::StatusOr<PjRtDevice*> LookupAddressableDevice(
              PjRtLocalDeviceId local_device_id) const override {
        return Unimplemented("LookupAddressabldEvice is not supported");
      }

      absl::StatusOr<PjRtDevice*> LookupDevice(
               PjRtGlobalDeviceId global_device) const override {
        return Unimplemented("LookupDevice is not supported");
      }

      absl::Span<PjRtMemorySpace* const> memory_spaces() const override { return memory_spaces_; }

      // Return an ID that identifies the platform (CPU/GPU/TPU).
      PjRtPlatformId platform_id() const override { return 9001; }

      // Returns a string containing human-readable, platform-specific version info
      // (e.g. the CUDA version on GPU or libtpu version on Cloud TPU).
      absl::string_view platform_version() const override { return "myplugin platform version"; }

      PjRtRuntimeType runtime_type() const override { return kTfrt; }

      // Return a device-specific default device assignment, e.g., GPU and TPU may
      // be different.
      absl::StatusOr<DeviceAssignment> GetDefaultDeviceAssignment(
        int num_replicas, int num_partitions) const override {
        return Unimplemented("GetDefaultDeviceAssignment");
      }

      // Returns the default device layout for a buffer with `element_type` and
      // `dims`. The default layout is a platform-specific layout used when no other
      // layout is specified, e.g. for host-to-device transfers. When compiling, the
      // default layout is used for program arguments and outputs unless
      // user-specified or compiler-chosen layouts are requested via the
      // "mhlo.layout_mode" attribute.
      absl::StatusOr<Layout> GetDefaultLayout(
        PrimitiveType element_type, absl::Span<const int64_t> dims) override {
        return Unimplemented("GetDefaultLayout");
      }

      // Returns a backend-specific HLO cost analysis visitor.
      absl::StatusOr<std::unique_ptr<HloCostAnalysis>> GetHloCostAnalysis() const override {
        return Unimplemented("GetHloCostAnalysis");
      }

      absl::StatusOr<std::unique_ptr<PjRtLoadedExecutable>> Compile(
        const XlaComputation& computation, CompileOptions options) override {
        return Unimplemented("Compile with XlaComputation");
      }

      absl::StatusOr<std::unique_ptr<PjRtLoadedExecutable>> Compile(
        mlir::ModuleOp module, CompileOptions options) override {
        return Unimplemented("Compile with MLIR");
      }

      absl::StatusOr<std::unique_ptr<PjRtLoadedExecutable>>
        DeserializeExecutable(absl::string_view serialized,
                            std::optional<CompileOptions> options) override {
        return Unimplemented("DeserializeExecutable");
      }

      // Creates a buffer on the device without initializing or copying any data.
      absl::StatusOr<std::unique_ptr<PjRtBuffer>> CreateUninitializedBuffer(
        const Shape& shape, PjRtDevice* device) override {
        return Unimplemented("CreateUnitializedBuffer");
      }

      absl::StatusOr<std::unique_ptr<AsyncHostToDeviceTransferManager>>
      CreateBuffersForAsyncHostToDevice(absl::Span<const Shape> shapes,
                                      PjRtDevice* device) override {
        return Unimplemented("CreateBuffersForAsyncHostToDevice");
      }

      absl::StatusOr<std::unique_ptr<AsyncHostToDeviceTransferManager>>
      CreateBuffersForAsyncHostToDevice(absl::Span<const Shape> shapes,
                                      PjRtMemorySpace* memory_space) override {
        return Unimplemented("CreateBuffersForAsyncHostToDevice");
      }

      absl::StatusOr<std::unique_ptr<PjRtBuffer>> BufferFromHostBuffer(
        const void* data, PrimitiveType type, absl::Span<int64_t const> dims,
        std::optional<absl::Span<int64_t const>> byte_strides,
        HostBufferSemantics host_buffer_semantics,
        absl::AnyInvocable<void() &&> on_done_with_host_buffer,
        PjRtDevice* device) override {
        return Unimplemented("BufferFromHostBuffer");
      }

      absl::StatusOr<std::unique_ptr<PjRtBuffer>> BufferFromHostLiteral(
        const LiteralSlice& literal, PjRtDevice* device) override {
        return Unimplemented("BufferFromHostLiteral");
      }

      absl::StatusOr<std::unique_ptr<PjRtBuffer>> CreateViewOfDeviceBuffer(
        void* device_ptr, const Shape& shape, PjRtDevice* device,
        std::function<void()> on_delete_callback,
        std::optional<std::intptr_t> stream = std::nullopt) override {
        return Unimplemented("CreateViewOfDeviceBuffer");
      }

      absl::StatusOr<std::uintptr_t> UnsafeBufferPointer(
        PjRtBuffer* buffer) override {
        return Unimplemented("UnsafeBufferPointer");
      }

      absl::StatusOr<std::vector<std::unique_ptr<PjRtBuffer>>>
        MakeCrossHostReceiveBuffers(absl::Span<const Shape> shapes,
                                PjRtDevice* device,
                                PjRtCrossHostRecvNotifier notifier) override {
        return Unimplemented("MakeCrossHostReceiveBuffers");
      }

      absl::StatusOr<std::vector<std::unique_ptr<PjRtBuffer>>>
        MakeCrossHostReceiveBuffersForGather(
        absl::Span<const Shape> shapes, std::vector<GatherDetails> gather_details,
        PjRtDevice* device, PjRtCrossHostRecvNotifier notifier) override {
        return Unimplemented("MakeCrossHostReceiveBuffersForGather");
      }

      absl::StatusOr<ChannelHandle> CreateChannelHandle() override {
        return Unimplemented("CreateChannelHandle");
      }

      absl::StatusOr<ChannelHandle> CreateDeviceToHostChannelHandle() override {
        return Unimplemented("CreateDeviceToHostChannelHandle");
      }

      absl::Status Defragment() override {
        return Unimplemented("Defragment");
      }

    private:
      std::vector<xla::PjRtDevice*> devices_;
      std::vector<PjRtMemorySpace*> memory_spaces_;
  };  // end class

} // namespace

#endif // MYPLUGIN_PJRT_CPP_H
