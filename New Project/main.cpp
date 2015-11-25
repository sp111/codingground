#include <string>
#include <stdio.h>
using namespace std;
#include <iostream> 
using namespace std;

#define SIZE 50            /* Size of Stack */
char s[SIZE];
int top=-1;       /* Global declarations */
 
 void push(char elem)
{                       /* Function for PUSH operation */
	top++;
    s[top]=elem;
   // cout<<"pushed"<<elem;
}
 
char pop()
{                      /* Function for POP operation */
	char answer;
	answer = s[top];
	top--;
    return(answer);
}
 
int ctoi( int c )
{
    return c - '0';
}

int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    }
}

int evaluate(char elem, int oprand1, int oprand2)
{                 /* Function for precedence */
//cout<<elem;
//cout<<oprand2;
    switch(elem)
    {
    case '+': return (oprand1) + (oprand2);
    case '-': return (oprand1) - (oprand2);
    case '*': return (oprand1) * (oprand2);
    case '/': return (oprand1) / (oprand2);
    }
}
 
int main()
{                         /* Main Program */
    char ch,zap, infx[50],prfx[50];
    int i=0,k=0,eval=0,j=0;
    bool isNum;
    cout<<"\n\nEnter postfix expression ";
    cin>>prfx;
     /* puts a # to show the end of the stack */
    
   
   int l=0;
   k=0;
   int op1;
   int op2;
   int sum = 0;
   
   while(prfx[k]!='\0')
   {
       if(isalnum(prfx[k]))
	    {
	        		//   cout<<prfx[k];

	        push(prfx[k]);
		}
		else {
		    
		    op2 = ctoi(pop());
		    
		   cout<<prfx[k];
		    op1 = ctoi(pop());
		  //cout<<op1;
		    sum = evaluate(prfx[k], op1, op2);
		    push(sum+48);
		    //cout<<sum;
		    //cout<<s[top];
		}
		//cout<<s;
		k++;
   }
  cout<<"\n\nGiven Infix Expn:"<< infx << "\nPrefix Expn: " << prfx <<"\n";
 
cout<<"\nResult:"<<s;
  return 0;
}