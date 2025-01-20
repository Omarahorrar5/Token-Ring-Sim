#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int n; //nombre de noeuds
	int pid[n];

	for (int i=1; i<=n; i++) {
		int p[2];
		pid[i]=fork();
		int token=1;
		while (token!=0) {
			if (pid==0) { //fils
				int buff;
				read(p[0], &buff, 1*sizeof(int));
			}

			else { //pere
				int buff;
		       		buff = token;
			}
		}
	}

	return 0;
}
