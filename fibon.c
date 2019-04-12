#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>>
int a[100];
void *child(void *n)
{ 
 int i;
 int *d=(int*)n;
 int e=*d;
 a[0]=0;
 a[1]=1;
 for(i=2;i<e;i++)
 { 
   a[i]=a[i-1]+a[i-2];
 }
}
void *parent()
{ int n;
int i;
printf("Enter the number of terms in the Fibonacci series :");
scanf("%d",&n);
pthread_t th1;
 pthread_create(&th1,NULL,child,&n);
 pthread_join(th1,NULL);
  wait(NULL);  
  printf("\n Fibonacci Series generated is:");
  for(i=0;i<n;i++)
  {
   printf("%d  ",a[i]);
  }

}
int main()
{
 pthread_t th;
 pthread_create(&th,NULL,parent,NULL);
 pthread_join(th,NULL);
}
