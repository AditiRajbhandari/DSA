#include <stdio.h>  
#define MAXSIZE 10

int stack[MAXSIZE];  
int top = -1;
int isempty()
{
if(top == -1)
return 1;
else
return 0;
}
int isfull()
{
if(top == MAXSIZE - 1)
return 1;
else
return 0;
}
void peek()
{
	if(isempty())
		 printf("Stack is empty.\n");
	else
		printf("Element at top: %d. \n",stack[top]);
		
}
void pop()
{
int data;  if(isempty())
	printf("Stack is empty");
else
{
	data = stack[top]; 
	 top = top - 1;
	printf("Popped element: %d. \n",data);
}

}
void push(int data)
{
if(isfull())
	printf("Stack is full.\n");
else
{
	top = top + 1;  
	stack[top] = data;
}
}
void display()
{
	if(isempty()) 
		printf("Stack is empty");

	else
	{
		for(int i = top; i>=0;i--)
        {

			printf("%d\n",stack[i]);
        }
	}

}
int main()
{
push(3);
push(5);
push(9);
push(1);
push(12);
push(15);
peek();
		  pop();
pop();
peek();
display();

}
