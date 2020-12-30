
#include<iostream>
using namespace std; 
  
void findElements(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if (arr[j] > arr[i]) 
                count++; 
  
        if (count >= 2) 
        
            cout << arr[i] << " "; 
    } 
} 
  
int main() 
{ 
    int arr[1000],n;
    cout<<"Program to print all the elements except the 2 greater elements"<<endl;
    cout << "Enter the total number of elements to be inserted" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++)
    {
    	cin >> arr[i];
	}
		cout<<"Elements except 2 greater elements:\t";
    findElements(arr, n); 
    return 0; 
} 
