#ifndef _defaultlib_

    #define _defaultlib_

    #include<string.h>
    #include<time.h>
    #include<pthread.h>
    #include <unistd.h>
    #include <sys/types.h>


    #ifdef _WIN32
        #include<conio.h>
        #include<stdio.h>
        #include<stdlib.h>
    #endif

    #ifdef linux
        #include"linuxconio.h"
    #endif

#endif
