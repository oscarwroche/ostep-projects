#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		 char *line = NULL;
                 size_t linecap = 0;
		 ssize_t linelen;
		 printf("wish> ");
		 while ((linelen = getline(&line, &linecap, stdin)) > 0) {
			char *token;
			char **arguments = malloc(0);
			int i = 0;
	         	while((token = strsep(&line, " ")) != NULL) {
				realloc(arguments, (i + 1) * sizeof(char*));
				char *pos;
				if ((pos=strchr(token, '\n')) != NULL)
				  *pos = '\0';
				else
				arguments[i] = token;
				i++;
			}		
			arguments[i+1] = NULL;
			int rc = fork();
			if (rc == 0) {
				execv(arguments[0], arguments);	
			} else if (rc >0) {
				wait(NULL);
			}	
			printf("wish> ");
		 }
		 free(line);
	} else if (argc == 2) {
		exit(1);
	} else {
		exit(1);
	}
}



