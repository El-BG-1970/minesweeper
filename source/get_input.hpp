#include <cstdlib>
#include <vector>
#include <cstring>
#include <sstream>

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
	i = 0;
	for (i = 0; i < 3; i++){
		if (out[i] < 10)
			out[i] = 10;
	}

    return(out);
}

int *get_coords(std::string str)
{
    std::vector<std::string> temp;
    std::istringstream iss(str);
    
    for(std::string str; iss >> str; )
        temp.push_back(str);

    int *out = (int *)malloc(temp.size() * sizeof(int)); 
    unsigned i = 0;

    for (i = 0; i < temp.size(); i++)
    {
        try{
            out[i] = std::stoi(temp[i]);
        }
        catch(std::invalid_argument) {
            printf("bad argument");    
            int *zero = (int *)malloc(3 * sizeof(int));
            zero = NULL;
            return(zero);
        }
    }
    return(out);
}
