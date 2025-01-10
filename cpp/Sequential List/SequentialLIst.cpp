#include<bits/stdc++.h>
using namespace std;
const int Maxsize=20;
enum returninfo{success,fail,overflow,underflow,rangeerror};

class seqlist
{
    protected:
        int dataarray[Maxsize];
        int Cnt;
    public:
    seqlist():Cnt(0){}
    ~seqlist(){}
    returninfo create(int number);
    bool empty() const;
    int length() const;
    returninfo taverse();
    returninfo get(int position ,int &item)const;
    returninfo replace(int position, const int &item);
    returninfo insert(int position ,const int &item);
    returninfo remove(int position);
    returninfo invertlist();//全部反转
    
};
returninfo seqlist:: create(int number)
{
    Cnt=number;
    for(int i=0;i<number;i++)
    {
        cin>>dataarray[i];
    }
    return success;

}

 bool seqlist:: empty()const
{
    if(Cnt==0) return true;
    else return false;
} 

int seqlist::length()const{
    return Cnt;
}

returninfo seqlist::taverse()//顺序访问所有
{
    if(empty())
    {
        return underflow;
    }
    cout<<"顺序表中的所有元素为";
    for(int i=0;i<Cnt;i++)
    {
        cout<<dataarray[i]<<" ";
    }
    return success;
}

returninfo seqlist::get(int position ,int &item)const
{
        if(empty())
        {
            return underflow;
        }
        if(position<1||position>Cnt)
        {
            return rangeerror;
        }
        item=dataarray[position-1];
        return success;

}

 returninfo seqlist:: replace(int position, const int &item)
 {  
if(empty())
        {
            return underflow;
        }
        if(position<1||position>Cnt)
        {
            return rangeerror;
        }
        dataarray[position-1]=item;
        return success;
 }
    returninfo seqlist::insert(int position ,const int &item)
    {
        if(empty())
        {
            return underflow;
        }
        if(position<1||position>Cnt+1)
        {
            return rangeerror;
        }
        Cnt++;
        if(position==Cnt)
        {
            dataarray[position-1]=item;
        }
        for(int i=position;i<Cnt;i++)
        {
            dataarray[i]=dataarray[i-1];
        }dataarray[position-1]=item;
        return success;
    }

    returninfo seqlist:: remove(int position)
    {
        if(empty())
        {
            return underflow;
        }
        if(position<1||position>Cnt)
        {
            return rangeerror;
        }
        for(int i=Cnt-1;i>position-1;i--)
        {
            dataarray[i-1]=dataarray[i];
        }
        Cnt--;
        return success;
    }
    returninfo seqlist:: invertlist()
    {
        int halfpos;
        if(empty())
        {
            return underflow;
        }
        halfpos=Cnt/2;
        for(int i=0;i<halfpos;i++)
        {
            dataarray[i]=dataarray[i]^dataarray[Cnt-1-i];
            dataarray[Cnt-1-i]=dataarray[i]^dataarray[Cnt-1-i];
            dataarray[i]=dataarray[i]^dataarray[Cnt-1-i];
        }
        return success;
    }
//界面处理

int main()
{
    system("chcp 65001");
    seqlist seqlistnow;
    int t;cin>>t;
    seqlistnow.create(t);
    seqlistnow.taverse();
    seqlistnow.invertlist();
    seqlistnow.taverse();
    return 0;

}
