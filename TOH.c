TOH
#include <stdio.h>
#include <stdlib.h>
void toh(int n,char source,char aux,char dest){
if(n>0){
    toh(n-1,source,dest,aux);
    printf("move the %d from %c to %c \n",n,source ,dest);
    toh (n-1,aux,source,dest);

}
}
int main()
{
    int n;

    printf("enter the number of disk\n");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}
