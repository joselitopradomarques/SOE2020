#include<stdio.h>

int main(){
    
   FILE *fp;
   char str[] = "Ola mundo!\n";
   fp = fopen( "ola_mundo.txt" , "w" );
   fwrite(str , 1 , sizeof(str) , fp );
   fclose(fp);
   return(0);s
}
