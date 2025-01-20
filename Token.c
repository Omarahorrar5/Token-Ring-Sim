#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int N; 

int main() {
    int pipes[N][2]; 
    int pid;
    int token = 1; 
    
    for (int i = 0; i < N; i++) {
        if (pipe(pipes[i]) == -1) {
            return -1;
        }
    }
    
    for (int i = 0; i < N; i++) {
        pid = fork();
        if (pid == -1) {
            return -1;
        }
        
        if (pid == 0) {
            int buff;
            
            for (int j = 0; j < N; j++) {
                if (j != i) close(pipes[j][0]);
                if (j != (i + N - 1) % N) close(pipes[j][1]);
            }
            
            while (1) {
                read(pipes[i][0], &buff, sizeof(int));
                printf("Noeud %d a reçu le jeton %d\n", i + 1, buff);
                
                sleep(1);
                
                buff = (buff + 1) % N; 
                write(pipes[(i + 1) % N][1], &buff, sizeof(int));
                
                if (buff == 0) break; 
            }
            
            exit(0); 
        }
    }
    
    for (int i = 0; i < N; i++) {
        close(pipes[i][0]);
        if (i != 0) close(pipes[i][1]);
    }
    
    write(pipes[0][1], &token, sizeof(int));
    
    for (int i = 0; i < N; i++) {
        wait(NULL);
    }
    
    return 0;
}
