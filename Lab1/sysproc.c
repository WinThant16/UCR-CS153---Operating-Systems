#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

/*The exit system call must act as previously 
defined (i.e., terminate the current process) 
but it must also store the exit status of the 
terminated process in the corresponding structure*/
//change exit() signature to void exit(int status)

int
sys_exit(void)
{
  //the default code is commented out
  //exit();
  //return 0; //not reached
  int status = 0; // Initialize a variable 'status' to store the exit status.
  // Use argint to retrieve the exit status argument from the user space.
  // This extracts an integer argument from the user and stores it in 'status'.
  argint(0, &status);

  // Call the exit function with the provided exit status.
  exit(status); // This will terminate the current process with the specified exit status.

  return 0; // This line is not reached because 'exit' will terminate the process.
}



/*The wait system call must prevent the current process 
from execution until any of its child processes is 
terminated (if any exists) and return the terminated 
child exit status through the status argument.
*/
//Return the terminated child proc’s exit status 
//through the status pointer argument; 
int
sys_wait(void)
{
  //default code is commented out
  //return wait();

  int* status; // Declare a pointer to an integer (this will store the exit status of the child process).

  // Use argptr to validate and retrieve the status argument from the user space.
  // argptr is a function that helps ensure that the user-provided argument is valid.
  // if (argptr(0, (void*)&status, sizeof(status))){
  //   return -1; // If the status argument is invalid, return -1 to indicate an error.
  // }
  argptr(0, (void*)&status, sizeof(status));
  // Call the wait function to wait for a child process to exit and return its PID.
  // The exit status of the child process is stored in the 'status' pointer.
  return wait(status);
}


int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_hello(void){
  hello();
  return 0;
}


int 
sys_waitpid(void)
{
  int pid;
  int options;
  int* status;
  // options = 0;
  if (argint(0, &pid) < 0){
    return -1;
  }
  if(argptr(1,(void*)&status, sizeof(status)) < 0){
    return -1;
  }
  if(argint(2, &options) < 0)
    return -1;
  return waitpid(pid, status, options);
}