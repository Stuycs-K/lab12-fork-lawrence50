#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");
    exit(1);
  } else if ( p == 0){
      printf("Hello from Child!\n");
  }else{
      printf("Hello from Parent!\n");
  }
  return 0;
}
