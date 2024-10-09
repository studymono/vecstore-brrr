#include "config_manager_impl.h"
#include "../logger/logger.h"
#include <cstring>
#include <string>

int ConfigManagerImpl::GetVSize()
{
    return this->vsize;
}

void ConfigManagerImpl::LoadConfigsFromCommandLineFlags(int argc, char *argv[])
{
    // find the index of the place where we have "--vsize" in argv
    // verify that this is not the last thing in our argument list
    // if it is not, try to convert the next thing into an integer
    // and then store that integer that comes after is as the vsize
    // in our configuration
    for (int i = 0; i < argc; i++)
    {
        // if we are at the last argument, throw an error and exit the application
        if (i == argc - 1)
        {
            logger << "You must specify the dimensions of the vectors with the --vsize flag." << std::endl;
            exit(0);
        }

        if (strcmp(argv[i], "--vsize") == 0)
        {
            // try to see if the thing after this is a number
            int vsize;
            if ((vsize = atoi(argv[i + 1])) <= 0)
            {
                throw std::invalid_argument("The argument to --vsize must be a positive integer.");
            }
            this->vsize = vsize;
            break;
        }
    }
}
