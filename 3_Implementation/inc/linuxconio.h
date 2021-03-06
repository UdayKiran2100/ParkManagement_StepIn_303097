 #ifndef _linux_lib_

    #define _linux_lib_


    #ifdef _WIN32
        #include<conio.h>
    #endif

    #ifdef linux
        
        #include <sys/ioctl.h>
        #include <termios.h>


        int kbhit()
        {
            struct termios term;
            tcgetattr(0, &term);
            term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
            tcsetattr(0, TCSANOW, &term);

            int byteswaiting;
            ioctl(0, FIONREAD, &byteswaiting);
            
            
            term.c_lflag |= ICANON | ECHO;
            tcsetattr(0, TCSANOW, &term);
            
            return byteswaiting;
        }
    #endif

#endif