#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

/*
void manejador(int valor_pid){
    int estado;
    pid_t resultado = waitpid(valor_pid, &estado, WNOHANG);
    printf("Valor devuelto por waitpid(): %d\nValor de &status: %d", resultado, estado);
} */

int main() {
    // Se crea el proceso hijo
    pid_t pid = fork();
    if (pid == -1){
        printf("Se produjo un error al crear al hijo.\n");
        return 1;
    }
    else if (pid == 0) {
        printf("PID hijo: %d\nPID padre: %d\n", getpid(), getppid());
        sleep(2);
        exit(0);
    } 
    else {
        sleep(10);
        //signal(SIGCHLD, manejador(pid));
        int status;
        pid_t resultado = waitpid(pid, &status, WNOHANG);
        printf("Valor devuelto por waitpid(): %d\nValor de &status: %d\n", resultado, status);
    }

    return 0;
}  // ps aux | grep 'Z'
