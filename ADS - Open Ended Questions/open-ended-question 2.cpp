#include<iostream> 
using namespace std; 
  
void printUnique(int l, int r) 
{ 

    for (int i=l ; i<=r ; i++) 
    { 
        int num = i; 
        bool visited[10] = {false}; 
  
        while (num) 
        { 
            if (visited[num % 10]) 
                break; 
  
            visited[num%10] = true; 
  
            num = num/10; 
        } 
        
        if (num == 0) 
            cout << i << " "; 
    } 
} 
  

int main() 
{ 
    int l,r;
    cout<<"printing all unique elements between range"<<endl;
	cout << "Enter the value of l" <<endl;
	cin >>l;
	cout << "Enter the value of r" <<endl;
	cin >>r; 
    printUnique(l, r); 
    return 0;
}
