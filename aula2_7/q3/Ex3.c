#include<stdio.h>
#include<unistd.h>

int main() {
    /*
    Pai: 1
    Filho 1: 2
    Filho 2: 3
    Pai e filho 1: 12
    Pai e filho 2: 13
     
    - PID1: Filho 1
    - PID2: Filho 2
    */
    
    int pipefds1[2], pipefds2[2], pipefds3[2];
    int returnstatus1, returnstatus2, returnstatus3;
    int pid1, pid2;
    char pipe1writemessage[100] = "FILHO1: Quando o vento passa, é a bandeira que se move.";
    char pipe2writemessage[100] = "FILHO2: Não, é o vento que se move.";
    char pipe3writemessage[100] = "PAI: Os dois se enganam. É a mente dos senhores que se move.";
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
    
   returnstatus3 = pipe(pipefds3);
   if (returnstatus3 == -1) {
      printf("Não foi possível criar pipe 3 \n");
      return 1;
   }
    
   // Filho 1
   pid1 = fork();
   
   if (pid1 == 0) // Processo filho 1
   {
      close(pipefds1[0]);
      close(pipefds2[1]);
      close(pipefds3[0]);
      close(pipefds3[1]);
      read(pipefds2[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
      write(pipefds1[1], pipe3writemessage, sizeof(pipe3writemessage));
   } else {
       
       pid2 = fork();
       // Processo filho 2
       if (pid2 == 0)
       {
           close(pipefds1[0]);
           close(pipefds1[1]);
           close(pipefds2[0]);
           close(pipefds2[1]);
           close(pipefds3[1]);
           
           read(pipefds3[0], readmessage, sizeof(readmessage));
           printf("%s\n", readmessage);
       }
       else {
       // Processo pai
       
      close(pipefds1[1]);
      close(pipefds2[0]);
      close(pipefds3[0]);
           
      write(pipefds2[1], pipe1writemessage, sizeof(pipe1writemessage));
      write(pipefds3[1], pipe2writemessage, sizeof(pipe2writemessage));
      wait(NULL);
      read(pipefds1[0], readmessage, sizeof(readmessage));
      printf("%s\n", readmessage);
   }
   return 0;
}
}
