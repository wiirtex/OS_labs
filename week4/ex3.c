#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char a[256];
	fgets(a, 256, stdin);
	while (strcmp(a, "exit\n")) {
		system(a);
		fgets(a, 256, stdin);
}
}
