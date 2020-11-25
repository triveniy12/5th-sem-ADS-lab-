/****** program to implement functions of Dictionary using hashing*******/
#include<iostream>
#include<string.h>

using namespace std;
class HashFunction
{
	typedef struct hash
	{
		long key;
		char name[10];
	}hash;
	hash h[10];
	public:
		HashFunction();
		void insert();
		void display();
		int search(long);
		void Delete(long);
};

HashFunction::HashFunction()
{
	int i;
	for(i =0; i<10;i++)
	{
		h[i].key == -1;
		strcpy(h[i].name,"NULL");
	}
}

void HashFunction::Delete(long k)
{
	int index = search(k);
	if(index == -1)
	{
		cout<<"\n\tKey Not Found";
	}
	else
	{
		h[index].key == -1;
		strcpy(h[index].name,"NULL");
		cout<<"\n \t  Key is Deleted";
	}
}

int HashFunction::search(long k)
{
	int i;
	for(i =0;i<10;i++)
	{
		if(h[i].key == k)
		{
			cout<<"\n\t"<<h[i].key<<"is Found at"<<i<<"Location with Name" <<h[i].name;
			return i;
		}
		if(i==10){return i;}
	}
}

void HashFunction::display()
{
	int i;
	cout<<"\n\t \t Key\t\t Name";
	for(i=0;i<10;i++)
	{
		cout<<"\n\t h["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].name;
	}
}

void HashFunction::insert()
{
	char ans,n[10],ntemp[10];
	long k,temp;
	int v,hi,cnt=0,flag=0,i;
	
	do
	{
		if(cnt >= 10)
		{
			cout<<"\n\t Hash Table is FULL";
			break;
		}
		cout<<"\n\t Enter Telephone No:";
		cin>>k;
		cout<<"\n\t Enter a clent name:";
		cin>>n;
		hi=k%10;
		if(h[hi].key ==-1)
		{
			h[hi].key=k;
			strcpy(h[hi].name,n);
		}
		else
		{
			if(h[hi].key % 10 !=hi)
			{
				temp = h[hi].key;
				strcpy(ntemp,h[hi].name);
				h[hi].key = k;
				strcpy(h[hi].name,n);
				for(i=hi+1;i<10 ;i++)
				{
					if(h[i].key ==-1)
					{
						h[i].key = temp;
						strcpy(h[i].name,ntemp);
						flag =1;
						break;
					}
				}
				for(i=0; i<hi && flag == 0 ;i++)
				{
					if(h[i].key == -1)
					{
						h[i].key =temp;
						strcpy(h[i].name,ntemp);
						break;
					}
				}
			}
			else
			{
				for(i=hi+1;i<10 ;i++)
				{
					if(h[i].key ==-1)
					{
						h[i].key = k;
						strcpy(h[i].name,n);
						flag =1;
						break;
					}
				
				}
				for(i =0;i<hi && flag ==0 ;i++)
				{
					if(h[i].key ==-1)
					{
						h[i].key = k;
						strcpy(h[i].name,n);
						break;
					}
				}
			}
		}
		flag = 0;
		cnt++;
		cout<<"\n\t....Do you want to insert More key:Y/N";
		cin>>ans;
	}while(ans == 'y' || ans == 'Y');
}

int main()
{
	long k;
	int ch,index;
	char ans;
	HashFunction obj;
	do
	{
		cout<<"\n\t *****Dictionary Functions Using Hashing**********";
		cout<<"\n\t 1.Insert \n\t 2.Display\n\t 3.Search \n\t 4.Delete\n\t 5.Exit";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:obj.insert();
					break;
			case 2:obj.display();
					break;
			case 3: cout<<"Enter the key that you want to search:";
					cin>>k;
					index = obj.search(k);
					if(index == -1)
					{
						cout<<"\n\t Key Not Found";
					}
					break;
			case 4:cout<<"Enter the key which you want to delete:";
					cin>>k;
					obj.Delete(k);
					break;
			case 5:break;
		}
			cout<<"\n\t Do you want to continue in main menu:Y/N";
			cin>>ans;
	}while(ans == 'y' || ans == 'Y');
}

