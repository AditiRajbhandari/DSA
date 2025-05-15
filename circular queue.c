#include <stdio.h>  
#define MAXSIZE 5 
 int queue[MAXSIZE]; 
int rear =  - 1;
int front = -1;
int isempty()
{
if(rear == -1)
return 1;
else
return 0;
}
int isfull()
{
if(front == (rear + 1) % MAXSIZE )
return 1;
else
return 0;
}
void enqueue(int data)
{
if(isfull())
printf("Queue is full.\n");
else
{
		if(isempty())
            {
                rear = front = 0;
                queue[rear] = data;
                printf("Data Enqueued");
            }
            else {
                rear = (rear + 1)%MAXSIZE;
                queue[rear] = data;
                printf("Data Enqueued\n");
            }
}
}
void dequeue()
{
int data;  
if(isempty())
printf("Queue is empty.\n");
else
{
data = queue[front];
                  if(front == rear)
front = rear =  - 1;
else
front = (front + 1) % MAXSIZE;

}
printf("Dequeued element:%d\n" , data);
}
void peek()
{
if(isempty())
printf("Queue is empty.\n");
else
printf("Front element: %d\n" , queue[front]);
}
void display()
{	
		if(isempty())
			printf("Queue is empty.\n");
		else
		{
			while(front != (rear +1)%MAXSIZE)
          		  {
               			 printf("%d\t", queue[front]);
                			front = (front+1)%MAXSIZE;

         		   } 
		}		
}
void main()
{
    enqueue(4);
    enqueue(5);
    enqueue(9);
    enqueue(1);
    enqueue(12);
    peek();
    dequeue();
    dequeue();
    enqueue(15);
    display();
}
