#ifndef XLA_MYPLUGIN_C_API_INTERNAL_H
#define XLA_MYPLUGIN_C_API_INTERNAL_H

#include "xla/pjrt/c/pjrt_c_api.h"

extern "C" {

// Does not pass ownership of returned PJRT_Api* to caller.
const PJRT_Api* GetPjrtApi();

}

#endif // XLA_MYPLUGIN_C_API_INTERNAL_H

