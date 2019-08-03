#include <stdio.h>
#include <sys/stat.h>

void create_folder(char* folder_name)
{
    printf("Initializing work space %s \n",folder_name);
    mkdir(folder_name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

int main(int args, char ** argv)
{
    char* folder_name = argv[1];

    create_folder(folder_name);

}