#include<iostream>
using namespace std;

class vector
{
	private:
		int *a;
		int dcapacity;
		int current;
	public:
		vector()
		{
			dcapacity=1;
			a=new int(1);
			current=-1;
		}
		void resize(int multiplicity)
		{
			cout<<"resized at"<<dcapacity<<endl;
			int tempdcapacity=multiplicity*dcapacity;
			int *temp;
			temp=new int(tempdcapacity);
			for(int i=0;i<dcapacity;i++)
			{
				temp[i]=a[i];
			}

			dcapacity=tempdcapacity;
			a=temp;

		}
		void push(int element)
		{
			if(current==dcapacity-1)
			{
				resize(2);
			}
			current++;
			a[current]=element;
		}
		int get()
		{
			if(current>=0)
			{
				return *(a+current);
			}
		}
		int at(int index)
		{
			if(index>current)
			{
				return -1;
			}
			else
			{
				return *(a+index);
			}
		}
		int size()
		{
			return current;
		}
		int capacity()
		{
			return dcapacity;
		}
		bool is_empty()
		{
			if(current==-1)
				return true;
			else
				return false;
		}
		int insert(int index,int item)
		{
			index--;
			if(index<=current+1)
			{
				if(current==dcapacity-1)
				{
					resize(2);
				}
				for(int i=current;i>=index;i--)
				{
					a[i+1]=a[i];
				}
				current++;
				a[index]=item;
			}
			else
			{
				cout<<"index out of bound";
			}
		}
		void prepend(int item)
		{
			insert(1,item);
		}
		void display()
		{
			if(is_empty())
			{
				cout<<"The array is empty";
				return;
			}
			for(int i=0;i<=current;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		int pop()
		{
			if(!is_empty())
			{
				current--;
				if(current==dcapacity/4)
				{
					resize(current/2);
				}
			}
			return -1;
		}
		int fdelete(int index)
		{
			index--;
			for(int i=index;i<current;i++)
			{
				a[i]=a[i+1];
			}
			current--;
		}
		int remove(int item)
		{
			for(int i=0;i<=current;i++)
			{
				if(a[i]==item)
				{
					fdelete(i+1);
					i--;
				}
			}
		}
		int find(int item)
		{
			for(int i=0;i<current;i++)
			{
				if(item==a[i])
				{
					return i+1;
				}
			}
			return -1;
		}
};

int main()
{
	vector v;
	v.push(100);
	v.push(100);
	v.push(100);
	v.push(100);
	v.push(100);
	v.pop();
	v.pop();
	v.pop();
	cout<<v.find(100);
}
