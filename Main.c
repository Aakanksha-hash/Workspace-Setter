#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char num[3];

void create_folders(char *folder_name, short n)
{
    char *name = folder_name;

    printf("[+] Initializing work space %s \n\n", name);
    mkdir(name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    strcat(name, "/");
    for (int i = 0; i < n; ++i)
    {
        strcat(name, "/");
        sprintf(num, "%d", i+1);
        printf("[+] Creating %s \n", num);
        mkdir(strcat(name, num), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        name = strtok(name, "/");
    }
    printf("\n");
}

void make_files(char *name, short n, char *username)
{
    FILE *source, *target;
    char ch, tem_folder[50], template_address[100] = "/home/";
    strcat(template_address, username);
    strcat(template_address, "/Templates/cp");
        
    for (int i = 0; i < n; ++i)
    {
        // printf("%s\n",template_address);
        source = fopen(template_address, "r");
        strcat(name, "/");
        sprintf(num, "%d", i+1);
        strcat(name, num);
        strcat(name, "/");
        strcpy(tem_folder, name);
        strcat(name, "Main.cpp");
        printf("[+] Copying template ... \n");
        target = fopen(name, "w");
        while ((ch = fgetc(source)) != EOF)
        {
            fputc(ch, target);
        }
        fclose(source);
        fclose(target);
        strcat(tem_folder, "in");
        printf("[+] Creating in ... \n");
        target = fopen(tem_folder, "w");
        fclose(target);
        name = strtok(name, "/");
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    // Declarations
    char* folder_name;
    char* user_name;
    int sub_folder_count;
    int opt;

    // Assignments (Defults)
    strcpy(folder_name,"Contest");
    sub_folder_count = 1;

    // Parsing the command line input
    while ((opt = getopt(argc, argv, "n:c:h")) != -1)
    {
        switch (opt)
        {
        case 'n':
            printf("Creating workspace : %s\n", optarg);
            strcpy(folder_name,optarg);
            break;
        
        case 'c':
            sub_folder_count = atoi(optarg);
            printf("%d\n",atoi(optarg));
            break;
        
        case 'h':
            printf("Welcome to setws by Mithil\n");
            printf("Pass the name of the workspace as -n \"name\". By default \"Contest\"\n");
            printf("Pass the number of sub-folder count as -c \"value\". By default 1.\n");
            exit(0);
            break;
        
        default:
            printf("Incorrect usage! Check help by passing -h\n");
            exit(1);
            break;
        }
    }

    // Assignment
    user_name = getlogin();

    // Greeting the user
    printf("[+] Hi %s!\n\n", user_name);

    // Creates the main folder and the sub-folders
    create_folders(folder_name, sub_folder_count);

    // Creates the files
    make_files(folder_name, sub_folder_count, user_name);

    return 0;
}