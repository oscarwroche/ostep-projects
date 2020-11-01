#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
		    printf("wcat: cannot open file\n");
		    exit(1);
		}
		char* str = malloc(sizeof(char) * 256);
		while (fgets(str, 256, fp)) {
		       printf("%s", str);
		}
		free(str);
	}
	return 0;		
}
