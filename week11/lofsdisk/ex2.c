#include <dirent.h>
#include <stdio.h>

int main()
{
	DIR* dir;
	struct dirent *d;
	dir = opendir("/");
	if (dir != NULL) 
	{
		while ((d = readdir(dir)) != NULL)
		{
			printf("%s\n", d->d_name);
		}
		closedir(dir);
	}
}
