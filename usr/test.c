#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <lib.h>
#include <minix/type.h>
int forkowanie(int i)
{
	message mes;
	pid_t pidT = getpid();
	
	mes.m1_i1 = pidT;
	mes.m1_i2 = 1;
	
	if(i>0)
	{
		pidT = fork();
	}
	if(pidT == 0 && i>0)
	{
		forkowanie(--i);
		if(i%2==0)
		{
		mes.m1_i1 = pidT;
	 	mes.m1_i2 = 2;
		}
		if(i%2==1)
		{
		mes.m1_i1 = pidT;
	 	mes.m1_i2 = 1;
		}
	}
	if(pidT !=0 && i==0)
	{
		mes.m1_i1 = pidT;
	 	mes.m1_i2 = 3;
	}
	_syscall(MM,78,&mes);
	return 0;
}

int myOwnSleep(int iRange, int jRange)
{
	int i, j;
	for(i=0;i<iRange;i++)
    	  for(j=1;j<jRange;j++);
    	return 0;
}
int main(int argc, char* atgv[])
{
  int temp = 2;
  
  forkowanie(temp);
  
  myOwnSleep(1,999999999);
  	    
  return 0;
}
