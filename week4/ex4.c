#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <string.h>

int main()
{
    char* args[256];
    int counter = 0;
    char a[256];
    int len = 0;
    while (1)
    {
        char c;
        c = fgetc(stdin);
        if (c == '\n')
        {
            a[len] = '\0';
			if (strcmp(a, "exit\0") == 0)
			{
				return 0;
			}
            args[counter] = (char*)malloc(sizeof(char) * strlen(a));
            strcpy(args[counter++], a);
            args[counter] = NULL;
            int pid = fork();
            if (pid == 0)
            {
                execvp(args[0], args);
            }
            counter = 0;
            a[0] = '\0';
            len = 0;
        }
        else if (c == ' ')
        {
            a[len] = '\0';
            args[counter] = (char*)malloc(sizeof(char) * strlen(a));
            strcpy(args[counter++], a);
            a[0] = '\0';
            len = 0;
        }
        else
        {
            a[len++] = c;
        }
    }
}

