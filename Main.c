#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *to_str[] = {"1", "2", "3", "4", "5","6","7"};

void create_folders(char *folder_name, short n)
{
    char *name = folder_name;

    printf("[+] Initializing work space %s \n\n", name);
    mkdir(name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

    strcat(name, "/");

    for (int i = 0; i < n; ++i)
    {
        strcat(name, "/");
        printf("[+] Creating %s \n", to_str[i]);
        mkdir(strcat(name, to_str[i]), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

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
        strcat(name, to_str[i]);
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

int main(int args, char **argv)
{
    char *folder_name = argv[1];
    short sub_folders = atoi(argv[2]);
    char *user_name = getlogin();
    printf("[+] Hi %s!\n\n", user_name);
    create_folders(folder_name, sub_folders);
    make_files(folder_name, sub_folders, user_name);
}