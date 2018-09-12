#include <stdio.h>
#include <stdlib.h>

int main() {
	
	printf("3 repetitions\n");

	for (int x=0; x<3; x++){
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;
}