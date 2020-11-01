#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getStreamLength(FILE* fp);

int main (int argc, char** argv) {
	if (argc == 1) {
		fprintf(stderr, "only one arg");
		exit(1);
	} else if (argc == 2) {
		FILE *fp;
		fp = fopen(argv[1], "r");
		int lineCount = getStreamLength(fp);
		fp = fopen(argv[1], "r");
		char *line = NULL;
		size_t linecap = 0;
		ssize_t linelen;
		char* linesArray[lineCount];
		for (int i = 0; i < lineCount; i++) {
			if ((linelen = getline(&line, &linecap, fp)) > 0) {
				linesArray[i] = malloc(strlen(line) * sizeof(char));
				strcpy(linesArray[i], line);
			} else {
				exit(1);
			}
		}
		for (int i = 0; i < lineCount; i++) {
			char* currentLine = linesArray[lineCount - i - 1];
			free(linesArray[lineCount - i - 1]);
			fwrite(currentLine, strlen(currentLine), 1, stdout);
		}
		return 0;
	} else if (argc == 3) {
		exit(1);
	} else {
		exit(1);
	}
}

int getStreamLength(FILE* fp) {
		char *line = NULL;
		size_t linecap = 0;
		ssize_t linelen;
		int lineCount = 0;
		while ((linelen = getline(&line, &linecap, fp)) > 0) {
			lineCount++;
		}
		return lineCount;
}
