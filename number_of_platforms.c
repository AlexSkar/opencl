//
// Created by regoeco on 13/02/17.
//
#if defined(__APPLE__) || defined(__MACOSX)
#include <OpenCLC/cl.h>
#else
#include <CL/cl.h>
#endif

#include <stdio.h>

int main(){
    cl_platform_id *platforms;
    cl_uint platforms_n;
    clGetPlatformIDs(0, NULL, &platforms_n);
    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id)*platforms_n);
    clGetPlatformIDs(platforms_n, platforms, &platforms_n);
    printf("There are %d platforms\n", platforms_n);

    int i = 0;
    char re[1024];

    for(i=0; i<platforms_n; i++){
        printf("Platform: %d\n", i);

        clGetPlatformInfo(platforms[i], CL_PLATFORM_VENDOR, 1024, re, NULL);
        printf("CL_PLATFORM_VENDOR: %s\n", re);

        clGetPlatformInfo(platforms[i], CL_PLATFORM_NAME, 1024, re, NULL);
        printf("CL_PLATFORM_NAME: %s\n", re);

        clGetPlatformInfo(platforms[i], CL_PLATFORM_VERSION, 1024, re, NULL);
        printf("CL_PLATFORM_VERSION: %s\n", re);

        clGetPlatformInfo(platforms[i], CL_PLATFORM_PROFILE, 1024, re, NULL);
        printf("CL_PLATFORM_PROFILE: %s\n", re);

        clGetPlatformInfo(platforms[i], CL_PLATFORM_EXTENSIONS, 1024, re, NULL);
        printf("CL_PLATFORM_EXTENSIONS: %s\n", re);

        cl_device_id *devices;
        cl_uint devices_n;
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, 0, NULL, &devices_n);
        cl_uint uint;
        cl_ulong ulong;
        devices = (cl_device_id*)malloc(sizeof(cl_device_id)*devices_n);
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_ALL, devices_n, devices, &devices_n);

        for(int j = 0; j < devices_n; j++ ){
            char string[1024];
            printf("\tPlatform: %d, devices: %d\n", i, j);

            clGetDeviceInfo(devices[j], CL_DEVICE_NAME, 1024, string, NULL);
            printf("\tCL_DEVICE_NAME: %s\n", string);

            clGetDeviceInfo(devices[j], CL_DEVICE_VENDOR, 1024, string, NULL);
            printf("\tCL_DEVICE_VENDOR: %s\n", string);

            clGetDeviceInfo(devices[j], CL_DEVICE_EXTENSIONS, 1024, string, NULL);
            printf("\tCL_DEVICE_EXTENSIONS: %s\n", string);

            clGetDeviceInfo(devices[j], CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(uint), &uint, NULL);
            printf("\tCL_DEVICE_MAX_COMPUTE_UNITS: %d\n", uint);

            clGetDeviceInfo(devices[j], CL_DEVICE_MAX_CLOCK_FREQUENCY, sizeof(uint), &uint, NULL);
            printf("\tCL_DEVICE_MAX_CLOCK_FREQUENCY: %d\n", uint);

            clGetDeviceInfo(devices[j], CL_DEVICE_LOCAL_MEM_SIZE, sizeof(ulong), &ulong, NULL);
            printf("\tCL_Device_LOCAL_MEM_SIZE: %lu\n", ulong);

            clGetDeviceInfo(devices[j], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(ulong), &ulong, NULL);
            printf("\tCL_DEVICE_GLOBAL_MEM_SIZE: %lu\n", ulong);
        }
        free(devices);

    }


    free(platforms);

    return EXIT_SUCCESS;
}