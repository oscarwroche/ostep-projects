#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	for (int i = 2; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
		        printf("wgrep: cannot open file\n");
		        exit(1);
		}
		char *line = NULL;
		size_t linecap = 0;
		ssize_t linelen;
		while ((linelen = getline(&line, &linecap, fp)) > 0) {
			if(strstr(line, argv[1]) != NULL) {
				printf("%s", line);
			}
		} 
	}
	return 0;		
}
