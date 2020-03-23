#include<iostream>
using namespace std;
class node
{
  public:
    int data;
    node *next;
    node(int value)
    {
      data=value;
      next=NULL;
    }
};
class list
{
  private:
    node *head;
    int current;
  public:
    list()
    {
      head=NULL;
      current=0;
    }
    int size()
    {
      return current;
    }
    bool empty()
    {
      if(current==0)
        return true;
      return false;
    }
    int value_at(int index)
    {
      index--;
      node *temp=head;
      int tempindex=0;
      while(temp!=NULL&&tempindex<index)
      {
        temp=temp->next;
        tempindex++;
      }
      if(temp!=NULL)
      {
        return temp->data;
      }
      else
      {
        return -1;
      }
    }
    void push_front(int value)
    {
      if(head==NULL)
      {
        head=new node(value);
      }
      else
      {
        node *temp=new node(head->data);
        head->next=temp;
        head->data=value;
      }
      current++;
    }
    int pop_front()
    {
      if(head==NULL)
      {
        return -1;
      }
      int value=head->data;
      head=head->next;
      return value;
      current--;
    }
    void push_back(int element)
    {
      if(head==NULL)
      {
        head=new node(element);
        return;
      }
      node *temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=new node(element);
    }
    int pop_back()
    {
      if(head==NULL)
      {
        return -1;
      }
      else
      {
        node* parent=head;
        node *temp=head;
        while(temp->next!=NULL)
        {
          parent=temp;
          temp=temp->next;
        }
        if(parent==temp)
        {
          head=NULL;
          return temp->data;
        }
        parent->next=NULL;
        return temp->data;
      }
    }
    int front()
    {
      return head?head->data:-1;
    }
    int back()
    {
      if(head==NULL)
      return -1;
      node *temp=head;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      return temp->data;
    }
    void insert(int index,int value)
    {
      index--;
      int count=0;
      if(head==NULL)
      {
        head=new node(value);
      }
      if(index==0)
      {
        node *temp=new node(value);
        temp->next=head;
        head=temp;
        return;
      }
      node *temp=head;
      while(temp->next!=NULL&&count<index-1)
      {
        temp=temp->next;
        count++;
      }
      node *temp1=new node(value);
      temp1->next=temp->next;
      temp->next=temp1;
    }
    void display()
    {
      node *temp=head;
      while(temp!=NULL)
      {
        cout<<temp->data<<" ";
        temp=temp->next;
      }
    }
    void erase(int index)
    {
      index--;
      int count=0;
      if(head==NULL)
      {
        return;
      }
      if(index==0)
      {
        head=head->next;
        return;
      }
      node *temp=head;
      while(temp->next!=NULL&&count<index-1)
      {
        temp=temp->next;
        count++;
      }
      if(temp->next!=NULL)
      temp->next=temp->next->next;
    }
    int value_n_from_end(int index)
    {
      node *parent=head;
      node *temp=head;
      int count=0;
      while(temp!=NULL&&count<index)
      {
        temp=temp->next;
        count++;
      }
      while(temp!=NULL)
      {
        parent=parent->next;
        temp=temp->next;
      }
      return parent->data;
    }
    void reverse()
    {
      node *current=head,*next=current,*prev=NULL;
      while(current!=NULL)
      {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
      }
      head=prev;
    }
    void remove_value(int value)
    {
      node *temp=head;
      node *parent=head;
      while(temp->next!=NULL&&temp->data!=value)
      {
        parent=temp->next;
        temp=temp->next;
      }
    }
};
int main()
{
  list newlist;
  newlist.push_back(1);
  newlist.push_back(2);
  newlist.push_back(3);
  newlist.push_back(4);
  newlist.insert(3,100);
  newlist.display();
  cout<<endl;
  newlist.reverse();
  newlist.display();
}
