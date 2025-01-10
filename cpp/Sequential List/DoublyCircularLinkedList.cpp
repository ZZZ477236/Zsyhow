#include<bits/stdc++.h>

using namespace std;
enum returninfo{ success,fail,range,overflow,underflow};
const int MAXSIZEE=5;
int example[5]={11,22,33,44,55};
struct dlnode
{
    int data ;
    dlnode* prior;
    dlnode* next;

};
class DLLinkList
{
    private:
    dlnode* headp;
    protected:
    int count;
    public:
    DLLinkList();
    ~DLLinkList();
    returninfo create();
    void clearlist();
    bool empty() const;
    int length() const;
    returninfo traverse();
    returninfo  retrieve(int position,int&item);
    returninfo replace(int position,const int& item);
    returninfo insert(int position,const int &item);
    returninfo remove(int position);
    returninfo invertlist();//所有数据反转
    returninfo k_invertlist(); // 没k个数据反转一次

};


DLLinkList::DLLinkList()
{
    headp=new dlnode;
    headp->next=NULL;
    count=0;
}
DLLinkList ::~DLLinkList()
{
    clearlist();
    delete headp;
}
returninfo DLLinkList::create()
{
    dlnode* searchp=headp;
    dlnode* newdlnodep;
    if(!empty()) return fail;
    for(int i=0;i<MAXSIZEE;i++)
    {
        newdlnodep=new dlnode;
        if(newdlnodep==NULL) return fail;
        newdlnodep->data=example[i];
        newdlnodep->next=NULL;
        newdlnodep->prior=NULL;
        searchp->next=newdlnodep;
        newdlnodep->next=headp;
        newdlnodep->prior=searchp;
        headp->prior=newdlnodep;
        searchp=searchp->next;
        count++;
    }
    //traverse();
    return success;
}

void DLLinkList::clearlist()
{
    dlnode* searchp=headp,*newdlp;
    while(searchp!=NULL)
    {
        newdlp=searchp;
        searchp=searchp->next;
        delete newdlp;
    }
    headp->next=NULL;headp->prior=NULL;
    count=0;
}

bool DLLinkList::empty() const{if(count==0) return true; return false;}

int DLLinkList :: length() const{ return count}

returninfo DLLinkList::

int main()
{
    system("chcp 65001");
    
}