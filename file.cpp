#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int p = 5;

int main(int argc, char* argv[])
{	
    int i = 0;
    //for(int j = 0; j <= argc -2; j ++){
    //char* arguments[] = {"superabundantes.py", };
    
    int my_pipe[2];
    if(pipe(my_pipe) == -1)
    {
        fprintf(stderr, "Error creating pipe\n");
    }

    pid_t child_id;
    child_id = fork();
    if(child_id == -1)
    {
        fprintf(stderr, "Fork error\n");
    }
    if(child_id == 0) // child process
    {
	printf("This is child. ID=%d\n", child_id);
        close(my_pipe[0]); // child doesn't read
        dup2(my_pipe[1], 1); // redirect stdout
	//printf("Cild say!");
        execve(argv[1], argv+1/*arguments*/, NULL); 

        perror("Exec failed");
	return -1;
        //fprintf(stderr, "Exec failed\n");
    }
    else
    {
	printf("This is parent. ID=%d\n", child_id);
        close(my_pipe[1]); // parent doesn't write
	
	wait(NULL);
	printf("%d", p);
        char reading_buf[1];
	printf("%d", 5);
	while(read(my_pipe[0], reading_buf, 1) > 0)        
	{
            //write(1, reading_buf, 1); // 1 -> stdout
	    i++;
        }
	printf("%d\n", i);
        close(my_pipe[0]);
      //  wait(NULL);
    }
}
