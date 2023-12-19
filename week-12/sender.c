#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

int main()
{
    int i;
 
    // to print where the shared segment gets attach to the process address space
    void *shared_memory;
 
    // buffer it is used to write the data into shared memory by the user
    char buff[100];
     
    int shmid;
 
    // creates shared memory segment with key 2345 (any number that you want to assign to 
    // the shared segment), having size 1024 bytes. 
    // IPC_CREAT is used to create the shared segment if it does not exist. 
    // 0666 (read and write to user,group and other) are the permissions on the shared segment
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT); 
    printf("Key of shared memory is %d\n",shmid);
     
    //process attached to shared memory segment
    shared_memory=shmat(shmid,NULL,0); 
     
    //this prints the address where the segment is attached with this process
    printf("Process attached at %p\n",shared_memory); 
 
    printf("Enter some data to write to shared memory\n");
    read(0,buff,100); //get some input from user
 
    //data written to shared memory
    strcpy(shared_memory,buff);
     
    printf("You wrote : %s\n",(char *)shared_memory);
}
