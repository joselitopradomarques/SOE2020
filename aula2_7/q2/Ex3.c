#include<stdio.h>
#include<unistd.h>

int main() {
    int pipefds1[2], pipefds2[2];
    int returnstatus1, returnstatus2;
    int pid;
    char pipe1writemessage[100] = "FILHO: Pai, qual é a verdadeira essência da sabedoria?";
    char pipe2writemessage[100] = "PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.";
    char pipe3writemessage[100] = "FILHO: Mas até uma criança de três anos sabe disso!";
    char pipe4writemessage[100] = "PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...";
    char readmessage[100];
    returnstatus1 = pipe(pipefds1);
   
   if (returnstatus1 == -1) {
      printf("Não foi possível criar pipe 2 1 \n");
      return 1;
   }
   returnstatus2 = pipe(pipefds2);
   
   if (returnstatus2 == -1) {
      printf("Não foi possível criar pipe 2 \n");
      return 1;
   }
   pid = fork();
   
   if (pid == 0) // Processo filho
   {
      close(pipefds1[0]);
      close(pipefds2[1]);
      write(pipefds1[1], pipe1writemessage, sizeof(pipe1writemessage));
      read(pipefds2[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
      write(pipefds1[1], pipe3writemessage, sizeof(pipe3writemessage));
      read(pipefds2[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
   } else { // Processo pai
      close(pipefds1[1]);
      close(pipefds2[0]);
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
      write(pipefds2[1], pipe2writemessage, sizeof(pipe2writemessage));
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
      write(pipefds2[1], pipe4writemessage, sizeof(pipe4writemessage));
   }
   return 0;
}
