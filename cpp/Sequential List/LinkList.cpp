#include<iostream>
using namespace std;
const int MAXNUM=5;
enum returninfo {success,underflow,fail,overflow,range};
int sourcedata[MAXNUM]={11,22,33,55,66};
class node
{
    public :
    int data;
    node* next;
};

class LinkList
{
    private:
    node* headp;
    protected:
    int count;
    public:
    LinkList();
    ~LinkList();
    returninfo create();
    void clearlist();
    bool empty() const;
    int length () const;
    returninfo traverse();
    returninfo retrieve(int position,int &item) const; //读取一个结点
    returninfo replace(int position,const int &item);
    returninfo insert(int position,const int & item);
    returninfo remove(int position);
    returninfo invertlist(); //所有数据反转
    returninfo K_invertlist(int k); //每k个逆转一次
};
LinkList:: LinkList()
{
    headp=new node;
    headp->next=NULL;
    count=0;
}
LinkList::~LinkList()
{
    clearlist();
 delete headp;
 count=0;

}
returninfo LinkList:: create()
{
    node* searchp=headp,*newnodep;
    int i;
    for(i=0;i<MAXNUM;i++)
    {
        newnodep=new node;
        newnodep->next=NULL;
        //cin>>newnodep->data;
        newnodep->data=sourcedata[i];
        searchp->next=newnodep;
        searchp=searchp->next;
        count++;
    }
    return success;
}

void LinkList::clearlist()
{
    node* searchp=headp,*follow=headp->next;
    while(follow!=NULL)
    {
        searchp=follow;
        follow=follow->next;
        delete searchp;
    }
    headp->next=NULL;
    count=0;
}

bool LinkList::empty() const
{
    if(count==0&&headp->next==NULL)
    {
        return true;
    }
    return false;
}

int LinkList::length() const 
{
    return count;
}

returninfo LinkList:: traverse()
{
    if(empty())
    {
        return underflow;
    }
    node*searchp=headp;
    searchp=searchp->next;
    while(searchp!=NULL)
    {
        cout<<searchp->data<<" ";
        searchp=searchp->next;
    }
    cout<<endl;
    return success;
}

returninfo LinkList::retrieve(int position,int &item) const
{
    node* searchp=headp;
    if(empty()) return underflow;
    if(position<1||position>count) return range;
    for(int i=1;i<position&&searchp!=NULL;i++)
    {
        searchp=searchp->next;
    }
    item= searchp->data;
    return success;
}

returninfo LinkList::replace(int position,const int &item)
{
    node* searchp=headp->next;
    if(empty()) return underflow;
    if(position<1||position>count) return range;
    for(int i=1;i<position&&searchp!=NULL;i++)
    {
        searchp=searchp->next;
    }
    searchp->data=item;
    return success;
}

returninfo LinkList::insert(int position,const int & item)
{
    node* searchp=headp->next;
    if(empty()) return underflow;
    if(position<1||position>count+1) return range;
    for(int i=1;i<position&&searchp!=NULL;i++)
    {
        searchp=searchp->next;
    }
    node* newnodep=new node;
    newnodep->data=item;
    newnodep->next=searchp->next;
    searchp->next=newnodep;
    count++;
    return success;
}

returninfo LinkList:: remove(int position)
{
    node* searchp=headp->next,* lastp=new node;
    if(empty()) return underflow;
    if(position<1||position>count) return range;
    for(int i=1;i<position&&searchp!=NULL;i++)
    {
        lastp=searchp;
        searchp=searchp->next;
    }
    lastp->next=searchp->next;
    delete searchp;
    count--;
    return success;
}

returninfo LinkList:: invertlist() //所有数据反转
{
    node* nowp,*midp,*lastp;
    if(empty()) return underflow;
    nowp=headp->next;
    midp=NULL;
    while(nowp!=NULL)
    {
        lastp=midp;
        midp=nowp;
        nowp=nowp->next;
        midp->next=lastp;
    }
    headp->next=midp;
    return success;
}

returninfo  LinkList:: K_invertlist(int k)
{
    node *now, *last, *mid, *s,*head=headp;
    for (int i = 1; i <= count / k; i++) 
    {    
       now=head->next; s=now;mid=NULL;
        int j=k;
        while(j--)
        {last=mid;
        mid=now;
        now=now->next;
        mid->next=last;
        }//循环结束时now等于下一次循环的开头，mid等于等于这次循环的头节点
        head->next=mid;
        s->next=now;//借用s为head赋值
        head=s;
    }
return success;
}
int main()
{   
    LinkList a,b;
    a.create();
    a.traverse();
    a.insert(3,10);
    a.traverse();
    a.remove(3);
    a.traverse();
    a.replace(4,10);
    a.traverse();
    a.invertlist();
    a.traverse();
    b.create();
    b.K_invertlist(2);
    b.traverse();
}