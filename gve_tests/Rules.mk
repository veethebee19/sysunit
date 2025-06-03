LIB := gve_test

TESTS := \
	gve_sample \
#       tcp_lro_sample \

TEST_GVE_SRCS := \
	gve_sample.gtest.cpp \

TEST_GVE_LIBS := \
	gve \
	fake_csum \
	fake_malloc \
	fake_mbuf \
	fake_atomic \
	fake_mib \
	fake_panic \
	fake_uma \
	fake_phash \
	mock_ifnet \
	mock_time \
	pktgen \
	sysunit_init \
	fake_gve \

TEST_GVE_STDLIBS := \
	gmock \

TEST_GVE_SAMPLE_SRCS := \
	$(TEST_GVE_SRCS) \

TEST_GVE_SAMPLE_LIBS := \
	$(TEST_GVE_LIBS) \

TEST_GVE_SAMPLE_STDLIBS := \
	$(TEST_GVE_STDLIBS) \
