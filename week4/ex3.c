#include <stdio.h>
#include <stdlib.h>


int main() {

	printf("If you want to exit this program print \"exit()\"\n");
	char sys_command[20];

	while (1){
		printf ("> ");
		scanf ("%s", sys_command);
		if (strcmp (sys_command, "exit()") != 0) {
			system(sys_command);		
		} else {
			return 0;
		}

	}
}