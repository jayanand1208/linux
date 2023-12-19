#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
 
int main()
{
    int i;
 
    void *shared_memory;
    char buff[100];
    int shmid;
     
    // to get shmid which will be require as parameter to shmat() function
    shmid=shmget((key_t)2345, 1024, 0666);
    printf("Key of shared memory is %d\n",shmid);
 
    //process attached to shared memory segment
    shared_memory=shmat(shmid,NULL,0); 
    printf("Process attached at %p\n",shared_memory);
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}
