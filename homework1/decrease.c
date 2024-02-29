#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
	int bcode;
	struct node* next;
};

bool isDecrease(int n){
    int a[10]; 
    int i = 0,count=0;
    struct node * head=NULL,*p;

    if(n<=0)
        return false;

    while (n > 0){
        int r = n % 10;
        n = n / 10;
        if(n==0){
            return true;
        }

        p = (struct node *)malloc(sizeof(struct node));
        p->bcode = r;
        p->next = head;
        head = p;
        count++;
    }

    p = head;
    while (p != NULL && p->next != NULL )
    {
        a[i] = p->bcode;
        p = p->next;
        i++;
        if (a[i-1] <= p->bcode) { 
            return false; 
        }
    }
    
    free(head); 

    return true; 
}

int main(void){
    int n;
    // printf("请输入一个整数:\n");
    scanf("%d",&n);
    if(isDecrease(n))
        printf("1\n");
    else
        printf("0\n");
    return 0;
}


// #include<stdio.h>
// #include<stdbool.h>

// bool isDecrease(int n){
//     if(n < 0){
//         return false;
//     }else if(n<=10){
//         return true;
//     }

//     int old = n%10;
//     n=n/10;
    
//     while(n>0){
//         int now = n%10;
//         if(old>=now){
//             return false;
//         }
//         old=now;
//         n=n/10;
//     }

//     return true;
// }

// int main(void){
//     int n;
//     // printf("请输入一个整数:\n");
//     scanf("%d", &n);
//     if(isDecrease(n))
//         printf("1\n");
//     else
//         printf("0\n");
//     return 0;
// }
