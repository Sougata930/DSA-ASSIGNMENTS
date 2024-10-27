#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int insertionsort(int *arr,int n){
  int count=0;
  for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j=j-1;
      count++;
    }
    arr[j+1]=key;
  }
  return count;
}
int checksort(int *arr,int n){
  int flag=0;
  for(int i=0;i<n;i++){
    if(arr[i]>arr[i+1]){
      flag++;
      break;
    }
  }
  if(flag!=0){
    return 1;
  }
  else{
    return 0;
  }
}
int main(int argc, char const *argv[])
{
  srand(time(NULL));
  int *arr;
  int n;
  scanf("%d",&n);
  arr=(int *)malloc(sizeof(int)*n);
  for(int i=0;i<n;i++){
    arr[i]=rand();
  }
  if (checksort(arr,n)==0){
    printf("SORTED !");
  }
  else{
    printf("NOT SORTED!\n");
    printf("Number of comparisons during Sorting %d\n",insertionsort(arr,n));
    printf("Now it is Sorted !\n");
  }
  return 0;
}
