#include<iostream>
using namespace std;

class node
{
  public:
    int data;
    node *next;
    node(int element)
    {
      data=element;
      next=NULL;
    }
};

class linkedqueue
{
  private:
    node *head,*tail;
  public:
    linkedqueue()
    {
      head=NULL;
      tail=NULL;
    }
    void enqueue(int data)
    {
      if(!tail)
      {
        tail=new node(data);
        head=tail;
      }
      else
      {
        tail->next=new node(data);
        tail=tail->next;
      }
    }
    int dequeue()
    {
      if(isempty())
      {
        return -1;
      }
      int temp=head->data;
      head=head->next;
      if(head==NULL)
      {
        tail=NULL;
      }
      return temp;
    }
    bool isempty()
    {
      if(!head)
      {
        return true;
      }
      return false;
    }
};
class arrayqueue
{
  int *a;
  int head;
  int last;
  int size;
  public:
    arrayqueue(int element)
    {
      size=element;
      a=new int(element);
      head=-1;
      last=-1;
    }
    void enqueue(int element)
    {
      if(empty())
      {
        head=0;
        last=0;
        a[head]=element;
        return;
      }
      if(full())
      {
        cout<<"The queue is full";
        return;
      }
      if(head==-1)
      head++;
      a[++last]=element;
    }
    int dequeue()
    {
      if(empty())
      {
        return -1;
      }
      else
      {
        int temp=a[head];
        head++;
        return temp;
      }
    }
    bool empty()
    {
      if(head==last+1)
      {
        return true;
      }
      return false;
    }
    bool full()
    {
      if(head==size-1)
      {
        return true;
      }
      return false;
    }
};
int main()
{
  arrayqueue aq(2);
  aq.enqueue(1);
  aq.enqueue(2);
  aq.enqueue(3);
  cout<<aq.dequeue();
  cout<<aq.dequeue();
  cout<<aq.dequeue();
}
