#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h> 
#include <string.h> 


int main() {
  pid_t p1, p2;
  printf("%d about to create 2 child processes\n", getpid());
  p1 = fork();
  if(p1 < 0){
    perror("fork fail");
    exit(1);
  }
  else if (p1 == 0){
      p2 = fork();
      if (p2 < 0) {
        perror("fork fail");
        exit(1);
      }
      else {
        int pid = getpid();
        srand(pid);
        int time = rand() % 5 + 1;
        printf("%d %d sec\n", pid, time);
        sleep(time);
        printf("%d finished after %d sec\n", pid, time);
        return time;
      }
  }
  else{
      int status;
      pid_t childPid = wait(&status);
      if (childPid == -1) {
        perror("wait");
        exit(1);
      }
      printf("Main Process %d is done. Child %d slept for %d sec.\n", getpid(), childPid, WEXITSTATUS(status));
  }
  return 0;
}
