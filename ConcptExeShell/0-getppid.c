#include "shell.h"
#include <sys/types.h>

int main(void)
{
	//variable to store calling functions proccess id
	pid_t process_id;
	//variable to store parent function's proccess id
	pid_t p_process_id;

	//get_pid() - will return process id of calling fucntion
	process_id = getpid();
	//getppid() 0 retunr process if of parent function
	p_process_id = getppid();

	printf("The process id: %d\n",  process_id);
	printf("The process id of parent function is %d\n", p_process_id);

	return(0);
}

