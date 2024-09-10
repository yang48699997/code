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
void pushString(stack*s,const char*c){
    while(*c!='\0'){
        int insert=0;
        switch (*c){
            case '(':
            insert=1;
            break; 
            case ')':
            insert=-1;
            break; 
            case '[':
            insert=2;
            break; 
            case ']':
            insert=-2;
            break;
        }
        
        if(s->top!=s->base){
            if(insert>0){
                push(s,insert);
            }else{
                int temp=*pop(s);
                if(temp+insert!=0){
                    push(s,0);
                    return;
                }
            }
        }else if(insert<0){
            push(s,insert);
            return;
        }else{
            push(s,insert);
        }
        c++;
    }
    return;
}

int main(){
    stack* s=new stack;
    initStack(s);
    char c[20];
    std::cout<<"请输入："<<std::endl;
    std::cin>>c;
    pushString(s,c);
    if(s->base==s->top){
        std::cout<<"匹配";
    }else{
         std::cout<<"此串括号匹配不合法";
    }
    free(s->base);
}