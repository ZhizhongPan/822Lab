#include <stdio.h>

#define smunch(pid, bit_pattern) syscall(324, pid, bit_pattern)

int main(int argc, char** argv){
	int ret;
	int pid = atoi(argv[1]);
	unsigned long bit_pattern = 0;
	bit_pattern |= 256; //set kill bit

	ret = smunch(pid, bit_pattern);

	if (ret == 0)
		printf("Smunch Success!!\n");
	else
		printf("Smunch Failure!!\n");	
	
	return 0;
}