/*
file: main.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: Initializes XenoThread, only changes were name of the header file to be included.
*/

#include <iostream>
#include <string>
#include <sys/types.h>
#include <pthread.h>
#include <fstream>

#include "sdfr_ppd.hpp"

volatile bool exitBool = false;

static void *XenoThread(void *arg)
{
    sdfr_ppd example_rt(1,1);
    evl_printf("starting the loop!!!\n");
    example_rt.loop();
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t th;
    
    if(evl_init())
        error(1, errno, "evl_init()");

    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);
    CPU_SET(1, &cpu_set);

    pthread_attr_t my_attr;
    sched_param my_param;
    mlockall(MCL_CURRENT | MCL_FUTURE);

    pthread_attr_init(&my_attr);
    my_param.sched_priority = 1;
    pthread_attr_setaffinity_np(&my_attr, sizeof(cpu_set), &cpu_set);
    pthread_attr_setinheritsched(&my_attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&my_attr, SCHED_FIFO);
    pthread_attr_setschedparam(&my_attr, &my_param);

    int ret = pthread_create(&th, &my_attr, XenoThread, NULL);
    if (ret < 0)
        error(1, errno, "pthread_create(): %d", ret);

    pthread_join(th, NULL);
    return 0;
}
