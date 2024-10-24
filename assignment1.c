#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int fib(int n,int* arr1){
  
  arr1[n]=arr1[n]+1;
  if(n<2){
    return n;
  }
  else{
    return fib(n-1,arr1)+fib(n-2,arr1);
  }
  
}


    
int main(int argc, char const *argv[])
{
  clock_t start,end;
  
  srand(time(0));
  int n1,n,high,low;
  scanf("%d",&high);
  scanf("%d",&low);
  printf("enter 0 if u want to go with iterative , else enter 1 for recursive :");
  scanf("%d",&n1);
  int a,b,sum;
  
  
  int c,i;
  start=clock();
  for(int j=0;j<10;j++){
    a=0,b=1,sum=0;
    
    n=(rand()%(high-low+1))+low;
    int* arr1 = (int*)malloc((n + 1) * sizeof(int));
    for (i = 0; i <= n; i++) {
      arr1[i] = 0;  // Initialize array
    }
    
    c=0;
    i=0;
    
    
    switch(n1){
      case 0:
        
        if(n==1){
          printf("%d",1);
        }
        if(n>=2){
          while(i<=n-2){
            c=a+b;
            a=b;
            b=c;
            i++;
          }
          printf("%d\n",c);

        }
        
        break;
    
    
    

      case 1:
        
    
        printf("%d\n",fib(n,arr1));
        for(int i=0;i<n;i++){
          printf("# of times fib(%d) is called : %d\n",i,arr1[i]);
          sum=sum+arr1[i];
        }
        printf("total call = %d\n",sum);
        break;
    }
  }
  end=clock();
  printf("Total time: %f",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}
    
    
 
  


  
    
  
  

  

  
  








    
    
    


    


      
  



  
  



