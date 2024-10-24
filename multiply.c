#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
  int m,n;
  int *arr1,*arr2;
  printf("enter length of first number:");
  scanf("%d",&m);
  printf("enter length of second number:");
  scanf("%d",&n);
  arr1=(int*)malloc(sizeof(int)*m);
  arr2=(int*)malloc(sizeof(int)*n);
  printf("enter first number of length %d\n :",m);
  for(int i=0;i<m;i++){
    scanf("%d[^%d]",&arr1[i]);
  }
  printf("enter second number of length %d\n :",n);
  for(int i=0;i<n;i++){
    scanf("%d[^%d]",&arr2[i]);
  }
  int l=m+n;
  
  int *ind = (int*)calloc(l, sizeof(int));
  int carry=0;
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      int pos=i+j+1;
      int r=arr2[i]*arr1[j]+carry+ind[pos];
      ind[pos]=r%10;
      carry=r/10;
      ind[pos-1]=ind[pos-1]+carry;
      carry=0;
    }
  }
  int x=0;
  while (x<l && ind[x]==0){
    x++;
  }

  if (x==l){
      printf("%d",0);
  }
  else{
    for(int i=x;i<l;i++){
      printf("%d",ind[i]);
    }
  }
  return 0;
}
