#ifndef __greedy_snake_H__
#define __greedy_snake_H__
#include "iostream"
#include "pthread.h"
#include "unistd.h"
#include "sys/select.h"
#include "xcb/xcb.h"
#include "vector"

static bool complete = false;

/* thread main work */
void *pthread_work(void);

/* sleep million seconds */
void sleep_ms(uint64_t time);

std::vector<uint64_t> screen_ctl();

#endif
