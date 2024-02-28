#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> // 添加头文件

struct node
{
	int bcode;
	struct node* next;
};

bool isDecrease(int n){
    int a[10]; 
    int i = 0;
    struct node * head=NULL,*p;

    while (n > 0){
        int r = n % 10;
        n = n / 10;
        if(n==0)
            return true;
        p = (struct node *)malloc(sizeof(struct node));
        p->bcode = r;
        p->next = head;
        head = p;
    }

    p = head;
    while (p != NULL && p->next != NULL) 
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

