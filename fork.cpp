#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int  main (int argc, char **argv)
{
	int n = atol(argv[1]);
	int m = n-1;
	for (int i = 0; i < n-1; i++)
	{
		if(fork()){
			wait(NULL);
			break;
		}
		m--;
	}

	if (m == n-1){
		printf("%d\n", m);
		fflush(0);
	}
	else{
		printf("%d ", m);
                fflush(0);

	}
	return 0;
}
