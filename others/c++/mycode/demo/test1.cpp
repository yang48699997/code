#include<iostream>
#include<cstdlib>
struct stack
{
    int* top;
    int* base;
    int num;
    int maxSize=20;
};
void initStack(stack*s){
    s->base=(int*)malloc(s->maxSize*sizeof(int));
    s->top=s->base;
}
void push(struct stack* s,int num){
    if(s->top-s->base>=s->maxSize){
        s->base=(int*)realloc(s->base,(s->maxSize*2)*sizeof(int));
        s->maxSize*=2;
    }
    *(s->top)=num;
    s->top+=1;
}
int* pop(struct stack*s){
    if(s->top==s->base){
        return NULL;
    }else{
        s->top--;
        return s->top;
    }
}
void transfer(stack*s,int num){
    std::cout<<std::endl;
    while(num!=0){
        push(s,num%8);
        num/=8;
    }
    while(s->top!=s->base){
        std::cout<<*pop(s);
    }
}
int main(){
    int num;
    stack* s=new stack;
    initStack(s);
    std::cout<<"请输入:";
    std::cin>>num;
    transfer(s,num);
    free(s->base);
    return 0;
}