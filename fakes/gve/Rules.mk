LIB := fake_gve

SRCS := \
	gve_common_fakes.c \

LOCAL_INCLUDE := -I $(TOPDIR)/include/kern_include/ -I$(TOPDIR)/gve_tests/gve/

