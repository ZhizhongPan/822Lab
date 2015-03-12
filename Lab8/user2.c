#include <stdio.h>

int int main(int argc, char const *argv[])
{
	int pid;

	switch(pid = fork()){
		case 0:
			printf("try to kill pid %d\n", getpid());
			exit(0);
		default;
			printf("without killing %d\n", getpid());
			while(1){
				sleep(20);
			}
	}
	return 0;
}