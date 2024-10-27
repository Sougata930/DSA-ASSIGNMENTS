#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>
typedef struct{
    float x;
    float y;
    int id;
}Point;
typedef struct{
    float x;
    float y;
    int id;
}Center;
float eval(float a,float b,float x,float y){
    return sqrt(pow(x-a,2)+pow(y-b,2));
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    int n;
    puts("enter the number of points:");
    scanf("%d",&n);
    Point *arr;
    arr=(Point*)malloc(sizeof(Point)*n); // array containing all the points.
    
    FILE *filepointer;
    filepointer=fopen("clustering.txt","w"); // file.
    for(int i=0;i<n;i++){
        arr[i].x=rand()%(100-0+1);
        arr[i].y=rand()%(100-0+1);
        arr[i].id=i;
        
        
    }
    Center *arr1;
    arr1=(Center*)malloc(sizeof(Center)*5); // center array of size 5.
    int g=0;
    for(int i=0;i<5;i++){
        int d=rand()%(100-0+1);
        arr1[i].x=d;
        int d1=rand()%(100-0+1);
        arr1[i].y=d1;
        arr1[i].id=g;
        g++;
        
    }
    
    int p=0,k;
    while(p<200){
        

        for(int i=0;i<n;i++){
            float min=__FLT_MAX__;
            for(int j=0;j<5;j++){
          
                float result=eval(arr[i].x,arr[i].y,arr1[j].x,arr1[j].y);
                if(result<min){
                    min=result;
                    k=j;
                }

            }
            arr[i].id=arr1[k].id;
        }
        float x1=0,y1=0,count=0;
        for(int i=0;i<5;i++){
            x1=0;
            y1=0;
            count=0;
            for(int j=0;j<n;j++){
                if(arr[j].id==arr1[i].id){
                    x1=x1+arr[j].x;
                    y1=y1+arr[j].y;
                    count++;
                }
            }
            arr1[i].x=x1/count;
            arr1[i].y=y1/count;
        }
        p++;
    }
    for(int i=0;i<n;i++){
        fprintf(filepointer,"%.2f %.2f %d\n",arr[i].x,arr[i].y,arr[i].id);
    }
                



    return 0;
}






    


    
    
