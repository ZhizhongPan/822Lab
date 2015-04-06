#include <stdio.h>

#define deepsleep() syscall(323)

int main(){
	printf("Deep Sleep.......\n");
	deepsleep();
	printf("Woke Up!!!! \n");
	return 0;
}