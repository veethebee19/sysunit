// sysunit/fakes/gve/gve_common_fakes.h
#ifndef SYSUNIT_FAKES_GVE_COMMON_FAKES_H
#define SYSUNIT_FAKES_GVE_COMMON_FAKES_H

#include "gve.h" // For struct gve_priv, constants (your fake gve.h)

//extern "C" { // For global variables and functions defined in .c file
// Global variables from gve_main.c that are accessed by gve_get_dqo_rx_buf_size
//extern int gve_allow_4k_rx_buffers;
//extern int gve_disable_hw_lro;

// Add more externs as needed (e.g., for device_printf, malloc, free, etc.)
// // For now, these are the only ones for gve_get_dqo_rx_buf_size.
//}

namespace SysUnit {
namespace gve_common_fakes {

// Static variables to control the behavior of the fakes
// (These variables will be defined in gve_common_fakes.c)

// Public API for tests to control the fakes
void set_gve_allow_4k_rx_buffers(bool val);
void set_gve_disable_hw_lro(bool val);

// Reset all fake states for a new test
void reset_fakes();

} // namespace gve_common_fakes
} // namespace SysUnit

#endif // SYSUNIT_FAKES_GVE_COMMON_FAKES_H
