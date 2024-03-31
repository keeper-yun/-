
//中值表达式的计算

#include<iostream>
#include<string>
#include<malloc.h>

using namespace std;

#define N 100

typedef struct {
    int *base;
    int *top;
    int stacksize;
} SeqStack;



typedef struct {
    char *base;
    char *top;
    int stacksize;
} SeqStack2;



void init(SeqStack *L) {
    L->base = (int *)malloc(sizeof(int) * N);
    L->top = L->base;
    L->stacksize = N;
}



void init2(SeqStack2 *L) {
    L->base = (char *)malloc(sizeof(char) * N);
    L->top = L->base;
    L->stacksize = N;
}



int push(SeqStack *L, int x) {
	
    if (L->top - L->base >= L->stacksize) {
        cout << "栈满，入栈失败!" << endl;
        return 0;
    }

    *(L->top) = x;
    L->top++;
    
    return 1;
}



void pushstr(SeqStack2 *L, char x) {
    if (L->top - L->base >= L->stacksize) {
        cout << "error" << endl;
        exit(0);
    }

    *(L->top) = x;
    L->top++;
}



int pop(SeqStack *L) {
	
    if (L->base == L->top) {
        cout << "栈顶为空，没有元素!" << endl;
        return 0;
    }

    L->top--;
    int x = *(L->top);
    return x;
}



char popstr(SeqStack2 *L) {
	
    if (L->base == L->top) {
        cout << "栈顶为空，没有元素!" << endl;
        exit(0);
    }

    L->top--;
    char x = *(L->top);
    
    return x;
}



int GetTop(SeqStack *L) {
    int x = *(L->top - 1);
    return x;
}



char GetTopstr(SeqStack2 *L) {
    char x = *(L->top - 1);
    return x;
}



char judge(char a, char b) {
    if (((a == '(') && (b == ')')) || ((a == '#') && (b == '#')))
        return '=';
    else if (a == '#' || a == '(' || b == '(' || ((a == '+' || a == '-') && (b == '*' || b == '/')))
        return '<';
    else
        return '>';
}



int Calculation(char str, int num1, int num2) {
    if (str == '+') return num2 + num1;
    else if (str == '*') return num2 * num1;
    else if (str == '-') return num2 - num1;
    else if (str == '/') return num2 / num1;
}



int main() {
	
	//1+3*(4+1)-5 -> 11
    
	char ch;

    char outstr;
    int out1, out2;

    SeqStack num;
    init(&num);

    SeqStack2 str;
    init2(&str);

    pushstr(&str, '#');

    cout << "请输入字符串，并在字符串后加上#号!" << endl;

    ch = getchar();
    
    while (ch == '\n') ch = getchar();

    while (ch != '#' || GetTopstr(&str) != '#') {
    	
        if (isdigit(ch)) {
            push(&num, ch - '0');
            ch = getchar();
        } else {
        	
            switch (judge(GetTopstr(&str), ch)) {
            	
                case '>':
                    outstr = popstr(&str);
                    out1 = pop(&num);
                    out2 = pop(&num);
                    int result;
                    result = Calculation(outstr, out1, out2);
                    push(&num, result);
                    break;
                    
                case '<':
                    pushstr(&str, ch);
                    ch = getchar();
                    break;
                    
                case '=':
                    popstr(&str);
                    ch = getchar();
                    break;
            }
        }
    }

    cout << GetTop(&num) << endl;

    return 0;
}

