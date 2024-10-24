#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
int eval(int a,int b,char op){
    switch (op)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    
    
    }
}
void popstack(){
    top--;
}
void pushstack(char val){
    
    if(val=='+' || val=='-' || val=='*' || val=='/'){
        int result=eval(stack[top],stack[top-1],val);
        popstack();
        popstack();
        stack[++top]=result;

    }
    else{
        stack[++top]=(int)val-48;
    }
}
int solution(){
    return stack[top];
}



int main(int argc, char const *argv[])
{
    
    char *postfix;
    int n;
    puts("enter the number of elements you want to enter:");
    scanf("%d",&n);
    postfix=(char*)malloc(sizeof(char)*n);
    for(int i=0;i<n;i++){
        scanf(" %c",&postfix[i]);
    }
    for(int i=0;i<n;i++){
        pushstack(postfix[i]);
    }
    printf("%d",solution());

    return 0;
}



   
    
    
