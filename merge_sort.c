#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int merge(int*arr1, int*left,int l,int* right,int r){
    
    int n1=l+r; // total size (left+right).
    
    int g=0,h=0,f=0; // g=> will track the left array. h=> will track the right array. f=> will track the arr1 array.
    int count=0;
    while(g<l && h<r){
        
        if(left[g]>right[h]){
            arr1[f]=right[h];
            count++;
            
            h++;
        }
        else{
            arr1[f]=left[g];
            count++;
            g++;
            
        }
        f++;
    
    }
    // inserting the remaining elements.
    while(g<l){
        arr1[f]=left[g];
        g++;
        f++;
    }
    while(h<r){
        arr1[f]=right[h];
        h++;
        f++;
    }
    return count;
}
    


int split(int*arr,int n){
    if (n<2){
        return 0;
        
    }
    int k=n/2;
    int *left=(int *)malloc(sizeof(int)*k);
    int *right=(int *)malloc(sizeof(int)*(n-k));
    for(int i=0;i<k;i++){
        left[i]=arr[i];
        
    }
    int l1=0;
    for(int i=k;i<n;i++){
        right[l1]=arr[i];
        l1++;
    }
    
    int comparison=0;
    comparison+=split(left,k);
    comparison+=split(right,n-k);
    comparison+=merge(arr,left,k,right,n-k);

    free(right);
    free(left);
    return comparison;
}


int main(int argc, char const *argv[])
{
    
    int *arr;
    int num[]={10,100,1000,10000,20000,40000,50000};
    int n;
    FILE *filepointer;
    filepointer=fopen("merge_sort.txt","a");
    for(int i=0;i<7;i++){
        n=num[i];
        arr=(int*)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++){
            arr[j]=rand();
        }
        int m=split(arr,n);
        printf("Number of Elements : %d\n",n);
        printf("the number of comparisons :%d\n",m);
        printf("\n");
        fprintf(filepointer,"%d %d\n",n,m);
        
    }
    free(arr);

    
    return 0;
}








    

    
    
    
    

    
