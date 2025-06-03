// sysunit/fakes/gve/gve_common_fakes.c
#include <sys/types.h>
#include <kern_include/dev/gve/gve.h>
#include "fakes/gve/gve_common_fakes.h"

int gve_allow_4k_rx_buffers = 0;
int gve_disable_hw_lro = 0;

void SysUnit::gve_common_fakes::set_gve_allow_4k_rx_buffers(bool val) {
	    gve_allow_4k_rx_buffers = val;
}
void SysUnit::gve_common_fakes::set_gve_disable_hw_lro(bool val) {
	    gve_disable_hw_lro = val;
}

void SysUnit::gve_common_fakes::reset_fakes() {
	    gve_allow_4k_rx_buffers = 0;
	        gve_disable_hw_lro = 0;
}

