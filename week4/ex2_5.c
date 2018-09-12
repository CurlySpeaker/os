#include <stdio.h>
#include <stdlib.h>

int main() {
	
	printf("5 repetitions\n");

	for (int x=0; x<5; x++){
		fork();
		sleep(5);
	}

	return EXIT_SUCCESS;
}