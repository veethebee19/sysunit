#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "sysunit/TestSuite.h" 
//#include "fakes/gve/gve_common_fakes.h"
#include <cstring> 

extern "C" {
#include <kern_include/sys/types.h>
#include "gve.h"
#include "gve_main.c"
}

class GveMainTestSuite : public SysUnit::TestSuite {
protected:
	struct gve_priv priv_instance;

	void TestCaseSetUp() override {
		        SysUnit::TestSuite::TestCaseSetUp();
			SysUnit::gve_common_fakes::reset_fakes();
			std::memset(&priv_instance, 0, sizeof(struct gve_priv));
	}

	void TestCaseTearDown() override {
		SysUnit::TestSuite::TestCaseTearDown();
	}
};

TEST_F(GveMainTestSuite, GetDqoRxBufSizeTest) {
	uint16_t mtu;
	int result;

	priv_instance.queue_format = GVE_GQI_QPL_FORMAT;
	mtu = 1500;
	result = gve_get_dqo_rx_buf_size(&priv_instance, mtu);
	EXPECT_EQ(result, GVE_DEFAULT_RX_BUFFER_SIZE) << "Should return default size in GQI mode";
}
