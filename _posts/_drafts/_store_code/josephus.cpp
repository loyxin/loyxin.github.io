#include<iostream>
using namespace std;

class JosephusNode{
public:
    JosephusNode(){
        this->alive =1; //1 为活着
        this->next=NULL;
    }
    ~JosephusNode(){}
    bool isAlive(){
        if(this->alive==1)
            return true;
        else 
            return false;
    }
    void killman(){       //自杀
        this->alive=0;
    }
    JosephusNode* getNext(){
        return this->next;
    }
    void setNext(JosephusNode* node){
        this->next=node;
    }
private:
    int alive;
    JosephusNode* next;
};

//定义约瑟夫环
class JosephusCircle{
public:
//n 为参加的人数, m 表示需要自杀的报数
JosephusCircle(int n,int m)
{
    if(n<=0||n<m||m<=0)
    {
        cout<<"无效的人数"<<endl;
        return;
    }
    this->length=0;
    first = new JosephusNode();
    this->length++;
    JosephusNode* p=first;
    for(int i=1;i<n;i++)
    {
        JosephusNode* node = new JosephusNode();
        p->setNext(node);
        p=node;
        this->length++;
    }
    p->setNext(first);
}

~JosephusCircle(){
    JosephusNode* p=this->first;
    while(p->getNext()!=first){
        JosephusNode* temp=p;
        p=p->getNext();
        delete temp;
    }
    delete p;
    delete first;
}

JosephusNode* getFirst(){
    return first;
}
private:
int length;
JosephusNode* first;
};
//number is alive people  number
void josephus(int n, int m, int number,JosephusCircle* jose){
    int josecount = 0;
    int i=0;
    JosephusNode* p= jose->getFirst();
   while(josecount<(n-number))
   {
       do{
           if(p->isAlive())
               i++;
           if(i==m)
           {
               i=0;
               p->killman();
               break;
           }
           p=p->getNext();
       }while(1);
       josecount++;
   }
   int* alivePos = new int[number];
   for(int index = 0;index<number;index++)
       alivePos[index]=0;
   p=jose->getFirst();
   int pos=0;
   int j=0;
   while(p->getNext()!=jose->getFirst())
   {
       if(j<number)
       {
           pos++;
               if(p->isAlive())
               {
                   alivePos[j]=pos;
                   j++;
               }
               p=p->getNext();
           }else{
               break;
           }
       }
   if(p->isAlive()||j<number)
     alivePos[j]=pos+1;
   cout<<"能够活着的位置:"<<endl;
   for(int k=0;k<number;k++)
       cout<<alivePos[k]<<" ";
   cout<<endl;
}

int main()
{
    cout<<"input total number, dead number,and the alive number:"<<endl;
    int n, m, number;
    cin>>n>>m>>number;
    JosephusCircle* jose= new JosephusCircle(n,m);
    josephus(n,m,number,jose);
    return 0;
}

