#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

DIR *opendir(const char *name);

int nodes[100][100];

const char* nodes_[100][100];

int nodes_inserted = 0;

int links_inserted[100];

int find(int i_node)
{
	for (int i = 0; i < 100; i++)
	{
		if (nodes[i][0] == i_node) 
		{
			return i;
		}
	}
	return 100;
}

void print() 
{
	for (int i = 0; i < nodes_inserted; i++)
	{
		printf("%s - ", nodes_[i][1]);
		for (int j = 0 ; j < links_inserted[i] + 2; j++)
		{
			printf("%s ", nodes_[i][j + 2]);
		}
		printf("\n");
	}
}

int main() 
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			nodes[i][j] = 0;
		}
		links_inserted[0] = 0;
	}
	DIR* dirp = opendir("tmp");
	if (dirp == NULL) {return 11;}
	struct dirent *dp;
 	while ((dp = readdir(dirp)) != NULL) 
	{

		
		struct stat* b = malloc(sizeof(struct stat));

		char asd[256];
		strcat(asd, "tmp/");
		strcat(asd, dp->d_name);
		stat(asd, b);
		if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {continue;}
		printf("%s %ld %ld\n", dp->d_name, b->st_dev, b->st_nlink);

		int pos = find(b->st_ino);

		if (pos == 100) 
		{
			nodes[nodes_inserted++][0] = b->st_dev;
		} 

		if (b->st_nlink != 0)
		{
			nodes_[pos][2+links_inserted[pos]] = calloc(100, sizeof(char));
			nodes_[pos][2 + links_inserted[pos]] = dp->d_name;
			links_inserted[pos]++;
		}
		else 
		{
			nodes_[pos][1] = calloc(100, sizeof(char));
			nodes_[pos][1] = dp->d_name;
		}
	}
	print();
}
