#define deepsleep() syscall(322)

main()
{
	printf("goodnight, Irene\n");
	deepsleep();
	printf("oops ... woke up!\n");
}