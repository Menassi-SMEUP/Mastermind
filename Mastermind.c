#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{int n,x,a,b,c,d,a1,b1,c1,d1,flag=1,count=0,countpos=0,i=0;

// printf("inserire n:\n");
// scanf("%d",&n);

do{
    srand(time(NULL));
    n=rand()%10000;

    d=n%10;
    c=((n-d)%100)/10;
    b=((n-(c*10+d))%1000)/100;
    a=(n-(b*100+c*10+d))/1000;
    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
        flag=0;
}while(flag==1);

double time_spent = 0.0;
clock_t begin = clock();

do{
    do {
        printf("inserire un numero di 4 cifre differenti tra loro:\n");
        scanf("%d",&x);

        if(x>9999){
            flag=2;
            printf("numero troppo grande\n");}


        if (x==9999){
            printf("\n%d\n",n);
            x=n;}

        d1=x%10;
        c1=((x-d1)%100)/10;
        b1=((x-(c1*10+d1))%1000)/100;
        a1=(x-(b1*100+c1*10+d1))/1000;
        if(a1!=b1 && a1!=c1 && a1!=d1 && b1!=c1 && b1!=d1 && c1!=d1)
            flag=1;
        else
            printf("cifre non diverse tra loro\n");
    }while (flag!=1);

    if(a==a1)
        countpos++;
    if(b==b1)
        countpos++;
    if(c==c1)
        countpos++;
    if(d==d1)
        countpos++;
    if(a==b1 || a==c1 || a==d1)
        count++;
    if(b==a1 || b==c1 || b==d1)
        count++;
    if(c==a1 || c==b1 || c==d1)
        count++;
    if(d==a1 || d==b1 || d==c1)
        count++;

    if(countpos!=4)
        printf("numeri uguali in posizioni differenti: %d \nnumeri uguali nella stessa posizione:%d \n",count,countpos);

    count=0;
    countpos=0;
    i++;

}while(n!=x );

sleep(3);
clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("Il tempo trascorso e' %f secondi", time_spent);

printf("numero di tentativi: %d",i);

return 0;
}
