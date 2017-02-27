    #include<stdio.h>  
    #include<stdlib.h>  
    #include<malloc.h>  
      
    typedef struct Node//定义一个链表结构体  
    {  
        int data;  
        struct Node* pNext;  
    }NODE,*PNODE;  
      
    typedef struct Stack//定义一个栈结构体  
    {  
        PNODE pTop;  
        PNODE pBottom;  
    }STACK,*PSTACK;  
      
    void initStack(PSTACK);  
    void pushStack(PSTACK,int);  
    void travelStack(PSTACK);  
    void popStack(PSTACK,int*);  
    void clear(PSTACK ps);  
    int main()  
    {  
        int val;  
        STACK S;//定义一个S变量，该变量有两个参数。一个pTop,一个pBotton   
        initStack(&S);//初始化栈  
        pushStack(&S,1);//压栈  
        pushStack(&S,2);  
        pushStack(&S,3);  
        pushStack(&S,4);  
        pushStack(&S,5);  
          
        travelStack(&S);//遍历输出  
          
        if(popStack(&S,&val))//判断是否出栈成功  
        {  
            printf("出栈成功，出栈元素是%d\n",val);  
        }  
        else  
        {  
            printf("出栈失败\n");  
        }  
        printf("出栈后遍历输出结果\n");  
        travelStack(&S);//遍历输出  
        clear(&S);  
        printf("再次遍历下面为空白，说明清空成功！\n");  
        travelStack(&S);//遍历输出  
          
        return 0;  
    }  
      
    void initStack(PSTACK ps)//初始化栈，让栈里面的两个元素指向一个节点。  
    {  
        ps->pTop=(PNODE)malloc(sizeof(NODE));  
        if(NULL==ps->pTop)  
        {  
            printf("动态内存分配失败\n");  
            exit(-1);  
        }  
        else  
        {  
            ps->pBottom=ps->pTop;  
            ps->pTop->pNext=NULL;//等价于：ps->pBottom->pNext=NULL;也就是说下一次插入的空间是空的。也就是栈顶元素下一个是空的  
        }  
    }  
      
    void pushStack(PSTACK ps,int val)//压栈函数  
    {  
        PNODE pNew=(PNODE)malloc(sizeof(NODE));  
        pNew->data=val;  
        pNew->pNext=ps->pTop;//每次都把元素压到栈顶  
        ps->pTop=pNew;  
    }  
      
    void travelStack(PSTACK ps)//遍历栈  
    {  
        PNODE p=ps->pTop;  
          
        while(p!=ps->pBottom)  
        {  
            printf("%d ",p->data);  
            p=p->pNext;  
        }  
        printf("\n");  
        return ;  
    }  
      
    void empty(PSTACK ps)//判断栈是否为空  
    {  
        if(ps->pTop==ps->pBottom)  
        return;  
        else  
        return;  
    }  
      
    //把ps所指向的栈出栈一次，并把出栈的元素存入pVal形参所指向的变量中  
    //如果出栈失败，返回false，否则，返回true  
    void popStack(PSTACK ps,int* pVal)  
    {  
        if(empty(ps))  
        {  
            return -1;  
        }  
        else  
        {  
            PNODE r=ps->pTop;  
            *pVal=r->data;  
            ps->pTop=r->pNext;  
            free(r);  
            r=NULL;  
            return 0;  
        }  
    }  
      
      
    //最后把栈清空。  
    void clear(PSTACK ps)  
    {  
        if(empty(ps))  
        {  
            return ;  
        }  
      
        else  
        {  
            PNODE p=ps->pTop;  
            PNODE q=NULL;  
              
            while(p!=ps->pBottom)  
            {  
                q=p->pNext;  
                free(p);  
                p=q;  
            }  
      
            ps->pTop=ps->pBottom;  
        }  
          
    }  


