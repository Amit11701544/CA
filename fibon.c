#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
int a[100];

int main()
{
 pthread_t th;
 pthread_create(&th,NULL,parent,NULL);
 pthread_join(th,NULL);
}
