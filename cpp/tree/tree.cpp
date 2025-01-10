#include<windows.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<stack>
using namespace std;
#define MAXSIZE 100
char defaultbtree1[] = "a(b,c(,d))";
char defaultbtree2[] = "a(b(c(d,e),f(g)),h(i,j))";


enum returninfo
{
    success, fail, overflow, underflow, nolchild, norchild, nofather, hsonr, hsonl, ones, twos, rewrong, quit
};

void f ( returninfo key)
{
    switch (key)
    {
    case 0:
        

        break;
    case 1:

        break;
    case 2:

        break;
    }

}

class node
{
    friend class btree;
public:
    node(char a = '0', int b = 0, node* c = NULL, node* d = NULL, node* e = NULL, node* f = NULL);
    ~node() {}
protected:
    char data;
    int deep;
    node* lson; node* rson; node* father; node* next;
};

node::node(char a, int b, node* c, node* d, node* e, node* f) :
    data(a), deep(b), lson(c), rson(d), father(e), next(f)
{}

class stackdata
{
    friend class btree;
private:
    node* list;
    int flag;
public:
    stackdata() {};
    ~stackdata() {};
};

class btree
{
private:
    char btreedata[MAXSIZE];
    char answer;
    node* root; node* workinp; node* linkrear;
    int btreecount;
    bool  firstbracket;
    int countnow;
    int leafcout;
    int countall;
    int sondeep;
public:
    btree(node* initrootp)
    {
        root = initrootp;
        firstbracket = true;
        countall = 0;
        btreecount = 0;
    }

    ~btree();
    //


    void initfistbracket();
    //把第一个括号标志位恢复成1
    returninfo createbtree(int choice);
    //广义表生成二叉树
    returninfo creatroot(char data);
    //创建根

    void visit(node* searchp);
    //访问值域
    void destroy(node* leaf);
    //递归删除结点
    void showbtreedata();//在主界面中显示当前工作数组

    int rgetcount(node* searchp);//递归统计二叉树中的结点个数

    int getcount();//记录二叉树中的节点个数

    node* getroot()
    {
        return root;
    }
    returninfo changeworkinpp();//工作指针改指

    returninfo findnode();//查找结点

    returninfo addchild();//增加左儿子或右儿子

    returninfo deletenode();//删除结点

    returninfo getinformation();//获取二叉树结点和叶子的信息

    returninfo gliststravel(node* searchp);
    //以广义表glists表示法输出二叉树
    returninfo indenttravel(node* searchp);
    //缩进表示

    returninfo preorder(node* searchp);//先序遍历

    returninfo inorder(node* searchp);

    returninfo postorder(node* searchp);//

    returninfo nrpreorder(node* searchp);//

    returninfo nrinorder(node* searchp);//

    returninfo nrpostorder(node* searchp);//

    returninfo levelorder(node* searchp);//


};
returninfo btree::creatroot(char data)

{
    if (root != NULL)
    {
        return fail; // 如果根节点已经存在，返回失败
    }

    root = new node(data, 1); // 创建根节点，深度为1
    if (root == NULL)
    {
        return fail; // 如果内存分配失败，返回失败
    }

    workinp = root;
    linkrear = root;
    return success;

}
void btree::destroy(node* leaf)
{
    if (leaf != NULL)
    {
        destroy(leaf->lson); // 递归删除左子树
        destroy(leaf->rson); // 递归删除右子树
        delete leaf;         // 删除当前节点
    }
}
btree::~btree()
{
    destroy(root); // 调用递归删除函数
}
void btree::initfistbracket()
{
    firstbracket = 1;
}

returninfo btree::createbtree(int choice)
{
    char charnow;
    node* newnode;
    if (choice == 1)
    {
        cout << endl << "1.easyone,2.hardone" << endl;
        cin >> choice;
        if (choice == 1)
        {
            strcpy(btreedata, defaultbtree1);

        }
        else if (choice == 2)
        {
            strcpy(btreedata, defaultbtree2);
        }
        else {
            return fail;
        }
    }
    else
    {
        cout << "输入一串如下广义表" << endl << defaultbtree1 << endl << defaultbtree2 << endl << "其中第一个字符必须为字母"<<endl;
        cin >> btreedata;
    }
    creatroot(btreedata[0]);
    for (int i = 1; btreedata[i] != '\0'; i++)
    {
        charnow = btreedata[i];
        switch (charnow)
        {
        case '(':
        {//a(c(,d),b)
            if (btreedata[i + 1] == ',')
            {
                i = i + 2;
                sondeep = workinp->deep + 1;
                newnode = new node(btreedata[i], sondeep);   //根据构造函数创建新结点
                newnode->lson = NULL;
                newnode->rson = NULL;
                workinp->rson = newnode;                    //逗号右边是右子树
                newnode->father = workinp;
                workinp = workinp->rson;
                linkrear->next = newnode;                  //结点指向下一节点
                linkrear = newnode;                         //指针下移

            }

            else
            {
                i++;
                sondeep = workinp->deep + 1;
                newnode = new node(btreedata[i], sondeep);
                newnode->lson = NULL;
                newnode->rson = NULL;
                workinp->lson = newnode;
                newnode->father = workinp;
                linkrear->next = newnode;
                linkrear = newnode;
                workinp = workinp->lson;
            }
            break;
        }
        //a(b(c(d,e), f(,g)), h(i, j))
        case ',':
        {
            i++;
            workinp = workinp->father;         //先回移，再判断
            if (btreedata[i] != ')') 
            {
                sondeep = workinp->deep + 1;
                newnode = new node(btreedata[i], sondeep);
                newnode->lson = NULL;
                newnode->rson = NULL;
                workinp->rson = newnode;
                newnode->father = workinp;
                linkrear->next = newnode;
                linkrear = newnode;
                workinp = workinp->rson;
                
            }
            break;
        }//a(b(c(d, e), f(, g)), h(i, j))
        case ')':
        {
            workinp = workinp->father;
            break;
        }
        default:
            return fail;
            break;
        }

    }
    return success;
}

void btree::visit(node* searchp)
{
    cout << searchp->data;
}

returninfo btree::gliststravel(node* searchp)
{
    if (firstbracket == 1)
    {
        searchp = root;
        cout << "广义表输出二叉树" << endl;
    }
    if (searchp != NULL)
    {
        firstbracket = 0;
        cout << searchp->data;//a(b(c(d, e), f(, g)), h(i, j))
        if (searchp->lson != NULL || searchp->rson != NULL)
        {
            cout << "(";
            gliststravel(searchp->lson);
            cout << ",";
            gliststravel(searchp->rson);
            cout << ")";
        }
    }


    return success;
}


returninfo btree::indenttravel(node* searchp)
{
    if (firstbracket == 1)
    {
        searchp = root;
    }
    if (searchp != NULL)
    {
        if(firstbracket==1)
        cout << "缩进输出二叉树" << endl;
        firstbracket = 0;
        cout << setw(searchp->deep * 3) << " " << searchp->deep << "->" << searchp->data << endl;

        if (searchp->lson != NULL || searchp->rson != NULL)
        {
            indenttravel(searchp->lson);
            if (searchp->lson == NULL)
                cout << setw(searchp->deep * 3+3) << " " << searchp->deep+1 << "->左子树空" << endl;
            indenttravel(searchp->rson);
            if (searchp->rson == NULL)
                cout << setw(searchp->deep * 3+3) << " " << searchp->deep+1 << "->右子树空" << endl;
        }
    }
    
    return success;
}
returninfo btree:: preorder(node* searchp)
{
    if(firstbracket==1)
        searchp=root;
        if(searchp==NULL)
            return underflow;
        firstbracket=0;
        countnow=getcount();
        cout << "先序遍历二叉树:(" << endl;
        if(searchp!=NULL)
        {
            visit(searchp);
            countnow--;
            if(countnow!=0)
                cout<<',';
            else
                cout<<')';
            preorder(searchp->lson);
            preorder(searchp->rson);
        }
        return success;
}

returninfo btree:: inorder(node* searchp)
{
    if(firstbracket==1)
        searchp=root;
        if(searchp==NULL)
            return underflow;
        firstbracket=0;
        countnow=getcount();
        cout << "中序遍历二叉树:(" << endl;
        if(searchp!=NULL)
        {
            inorder(searchp->lson);
            visit(searchp);
            countnow--;
            if(countnow!=0)
                cout<<',';
            else
                cout<<')';
            inorder(searchp->rson);
        }
        return success;
}

returninfo btree:: postorder(node* searchp)
{
    if(firstbracket==1)
        searchp=root;
        if(searchp==NULL)
            return underflow;
        firstbracket=0;
        countnow=getcount();
        cout << "后序遍历二叉树:(" << endl;
        if(searchp!=NULL)
        {
            postorder(searchp->lson);
            postorder(searchp->rson);
            visit(searchp);
            countnow--;
            if(countnow!=0)
                cout<<',';
            else
                cout<<')';
        }
        return success;
}
returninfo btree:: nrpreorder(node* searchp)
{
    node* stack[100],*pnow; int top=0;
    searchp=root;
    pnow=searchp;
    if(searchp==NULL)
        return underflow;
    cout<<"非递归先序遍历二叉树:(";
    countnow=getcount();
    while(!(searchp==NULL&&top==0))
    {
        while(pnow!=NULL)
        {   
            visit(pnow);
            countnow--;
            if(countnow!=0)
                cout<<',';
            else
                cout<<')';
            stack[top++]=pnow;
            pnow=pnow->lson;
        }
        pnow=stack[--top];
        pnow=pnow->rson;
    }
    return success;
}
returninfo btree:: nrinorder(node* searchp)
{
    node* stack[100],*pnow; int top=0;
    searchp=root;
    pnow=searchp;
    if(searchp==NULL)
    return underflow;
    cout<<"非递归中序遍历二叉树:(";
    countnow=getcount();
    while(!(searchp==NULL&&top==0))
    {
        while(pnow!=NULL)
        {
            stack[top++]=pnow;
            pnow=pnow->lson;
        }
        pnow=stack[--top];
        visit(pnow);
        countnow--;
        if(countnow!=0)
            cout<<',';
        else
            cout<<')';
        pnow=pnow->rson;
    }
    return success;
}

returninfo btree:: nrpostorder(node* searchp)
{
    node* stack[100],*pnow; int top=0;
    searchp=root;
    pnow=searchp;
    if(searchp==NULL)
        return underflow;
    cout<<"非递归后序遍历二叉树:(";
    countnow=getcount();
    while(!(searchp==NULL&&top==0))
    {
        while(pnow!=NULL)
        {
            stack[top++]=pnow;
            pnow=pnow->lson;
        }
        pnow=stack[--top];  
        if(pnow->rson!=NULL&&pnow->rson!=pnow->father)
        {
            pnow=pnow->rson;
            while(pnow->lson!=NULL)  
            {   
                stack[top++]=pnow;
                pnow=pnow->lson;
            }
        }
        else
        {
            visit(pnow);
            countnow--;
            if(countnow!=0)
                cout<<',';
            else
                cout<<')';
            pnow=NULL;
        }
    }
    return success;
}
            
returninfo btree:: levelorder(node* searchp)
{       
    node* queue[100],*pnow; int front=0,rear=0;
    searchp=root;
    if(searchp==NULL)   
        return underflow;
        cout<<"层序遍历二叉树:(";
    countnow=getcount();
    queue[rear++]=searchp;
    while(front!=rear)
    {
        pnow=queue[front++];
        visit(pnow);
        countnow--;
        if(countnow!=0)
            cout<<',';
        else
            cout<<')';
        if(pnow->lson!=NULL)
            queue[rear++]=pnow->lson;
        if(pnow->rson!=NULL)
            queue[rear++]=pnow->rson;
    }
    return success;
}

int btree::rgetcount(node* searchp)
{
    if (searchp == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + rgetcount(searchp->lson) + rgetcount(searchp->rson);
    }
}

int btree::getcount()
{
    return rgetcount(root);
}

returninfo btree::changeworkinpp()

}
int main()
{
    //system("chcp 6500>nul");
    cout << "输入 1 选择从已有两种广义表生成二叉树" << endl << "输入 2 自行输入广义表生成" << endl;
    while (1)
    {
        int choice;
        cin >> choice;
        node* a = NULL;
        btree b(a);
        b.createbtree(choice);
        b.gliststravel(b.getroot());
       b.initfistbracket();
        cout << endl;
       b.indenttravel(b.getroot());
    }
    return 0;
}
