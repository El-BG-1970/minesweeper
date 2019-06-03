#include <cstring>
#include <cstdlib>

int *get_input(int argc, char **argv)
{
    int *out;
    out = (int *)malloc(3 * sizeof(int));
    out[0] = 10; //h
    out[1] = 10; //w
    out[2] = 10; //m
    
    int i = 1;
    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-h")){      
            if (argv[i+1])
                out[0] = atoi(argv[i+1]);
        }
        if (!strcmp(argv[i], "-w")){
            if(argv[i+1])
                out[1] = atoi(argv[i+1]);
        }
        if (!strcmp(argv[i], "-m")){
            if (argv[i+1])
                out[2] = atoi(argv[i+1]);    
        }
    } 

    return(out);
}
