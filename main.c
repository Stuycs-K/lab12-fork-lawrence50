#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
  pid_t p1, p2;
  printf("%d about to create 2 child processes\n", getpid());
  p1 = fork();
  if(p1 < 0){
    perror("fork fail");
    exit(1);
  }
  else if ( p1 == 0){
      // printf("Hello from Child 1!\n");
      int pid = getpid();
      srand(pid);
      int time = rand() % 5 + 1;
      printf("%d %d sec\n", pid, time);
      sleep(time);
      printf("%d finished after %d sec\n", pid, time);
  }
  else{
      // printf("Hello from Parent of child 1!\n");
      p2 = fork();
      int *status;
      pid_t child = wait(status);
      printf("child %d\n", child);
	  printf("Main Process %d is done\n", getpid());
      // printf("Main Process %d is done. Child %d slept for %d sec\n", getpid(), *status, -1);
      if(p2 < 0){
        perror("fork fail");
        exit(1);
      }
      else if ( p2 == 0){
         // printf("Hello from Child 2!\n");
          int pid = getpid();
          srand(pid);
	  	  int time = rand() % 5 + 1;
          printf("%d %d sec\n", pid, time);
	  	  sleep(time);
	  	  printf("%d finished after %d sec\n", pid, time);
      }
      else{
          // printf("Hello from Parent of child 2!\n");
      }
  }
  return 0;
}
