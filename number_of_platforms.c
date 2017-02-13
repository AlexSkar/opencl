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
        printf("Platform: %d\n", i+1);

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
    }
    free(platforms);

    return EXIT_SUCCESS;
}