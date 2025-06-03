#ifndef FAKES_MBUF_COMMON_H
#define FAKES_MBUF_COMMON_H

#include <kern_include/vm/uma.h> 

#ifdef __cplusplus
extern "C" {
#endif

extern uma_zone_t zone_mbuf;
extern uma_zone_t zone_pack;

#ifdef __cplusplus
}
#endif

#endif
