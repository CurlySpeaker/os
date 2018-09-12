#include <stdio.h>


int main() {

	int n = 68;
	int pid = fork();
	
	if (pid < 0) {
		return 1;
	}
	else if (pid > 0) {
		printf("Hello from parent[%d-%d]\n", getpid(), n);
	}
	else {
		printf("Hello from child[%d-%d]\n", getpid(), n);
	}
	return 0;
}