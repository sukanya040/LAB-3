#include<stdio.h>
void hanoi_rec(int n,char src,char dest,char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",src,dest);
        return;
    }
    hanoi_rec(n-1,src,aux,dest);
    printf("Move disk %d from %c to %c\n ",n,src,dest);
    hanoi_rec(n-1,aux,dest,src);
}
int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    printf("Recursive solution:\n");
    hanoi_rec(n, 'A', 'C', 'B');
    return 0;
}
