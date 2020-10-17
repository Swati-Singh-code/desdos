#include<stdio.h>

int add(int,int);

int add(int a,int b){
    return a+b;

}
int main(int argc, char const *argv[])
{
    printf("addition:%d\n",add(10,20));
    return 0;
}
