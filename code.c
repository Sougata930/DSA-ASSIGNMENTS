#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    // TAKING INPUT OF THE ARRAY.
    int *a;
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // SORTING THE ARRAY.
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }

        }
    }
    int count=1;
    int max=0,max1;
    int flag=0;
    // FINDING THE MAJORITY ELEMENT.
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]){
            if(max<count){
                max=count;
                if(max>(n/2)){
                    max1=a[i];
                    flag++;
                    break;
                    
                }
                count=1;
            }
        }
        else{
            count++;
        }
    }
    
    if (flag!=0){
        printf("MAJORITY ELEMENT FOUND : %d",max1);
    }
    else{
        printf("NO MAJORITY ELEMENT FOUND");
    }
    return 0;
}
            
            
            

        
        
        
        
        
            





