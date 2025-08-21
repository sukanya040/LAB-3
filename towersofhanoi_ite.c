#include<stdio.h>
#include<math.h>
void movedisk(int disk,char from,char to){
    printf("Move disk %d from %c to %c\n",disk,from,to);
}
void hanoi_ite(int n,char src,char aux,char dest){
    int totalmoves,i,k,disk;
    totalmoves=pow(2,n)-1;
    if(n%2==0){
        char temp;
        temp=dest;
        dest=aux;
        aux=temp;
    }
    for(i=1;i<=totalmoves;i++){
        disk=1;
        k=i;
        while(k%2==1){
            k/=2;
            disk++;
        }
        if(i%3==1){
            movedisk(disk,src,dest);
        }
        else if(i%3==2){
            movedisk(disk,src,aux);
        }
        else{
            movedisk(disk,aux,dest);
        }
    }
}
int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    printf("Iterative solution:\n");
    hanoi_ite(n,'A', 'B', 'C');
    return 0;
}