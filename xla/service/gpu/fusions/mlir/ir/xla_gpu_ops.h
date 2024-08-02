/* Copyright 2024 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef XLA_SERVICE_GPU_FUSIONS_MLIR_IR_XLA_GPU_OPS_H_
#define XLA_SERVICE_GPU_FUSIONS_MLIR_IR_XLA_GPU_OPS_H_

#include "mlir/Bytecode/BytecodeOpInterface.h"  // IWYU pragma: keep
#include "mlir/Dialect/Func/IR/FuncOps.h"  // IWYU pragma: keep
#include "mlir/IR/Attributes.h"  // IWYU pragma: keep
#include "mlir/IR/BuiltinTypes.h"  // IWYU pragma: keep
#include "mlir/IR/Dialect.h"  // IWYU pragma: keep
#include "mlir/IR/MLIRContext.h"  // IWYU pragma: keep
#include "mlir/IR/OpDefinition.h"  // IWYU pragma: keep
#include "mlir/IR/OpImplementation.h"  // IWYU pragma: keep
#include "mlir/Interfaces/CallInterfaces.h"  // IWYU pragma: keep
#include "mlir/Interfaces/InferTypeOpInterface.h"  // IWYU pragma: keep
#include "mlir/Interfaces/SideEffectInterfaces.h"  // IWYU pragma: keep
#include "xla/service/gpu/fusions/mlir/ir/xla_gpu_dialect.h.inc"
#include "xla/service/gpu/model/indexing_map.h"  // IWYU pragma: keep
#define GET_ATTRDEF_CLASSES
#include "xla/service/gpu/fusions/mlir/ir/xla_gpu_attrs.h.inc"
#undef GET_ATTRDEF_CLASSES
#define GET_OP_CLASSES
#include "xla/service/gpu/fusions/mlir/ir/xla_gpu_ops.h.inc"
#undef GET_OP_CLASSES

#endif  // XLA_SERVICE_GPU_FUSIONS_MLIR_IR_XLA_GPU_OPS_H_
