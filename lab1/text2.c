#include<stdio.h>
#include <stdlib.h>

struct node
{
	double real;
    double fake;
};

int main(void){
    int a, b, c, d;
    printf("请输入第一个复数的实部与虚部:\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("请输入第二个复数的实部与虚部:\n");
    scanf("%d", &c);
    scanf("%d", &d);

    printf("这两个复数分别是:\n");
    printf("%d + %di\n", a, b);
    printf("%d + %di\n", c, d);
    printf("\n");

    printf("这两个复数的和,差,积分别是:\n");
    if(b+d>=0){
        printf("%d + %di\n",a+c,b+d);
    }else{
        printf("%d  %di\n",a+c,b+d);
    }

    if(b-d>=0){
        printf("%d + %di\n",a-c,b-d);
    }else{
        printf("%d  %di\n",a-c,b-d);
    }

    if((a*d+b*c)>=0){
        printf("%d + %di\n",(a*c-b*d),(a*d+b*c));
    }else{
        printf("%d  %di\n",(a*c-b*d),(a*d+b*c));
    }
}