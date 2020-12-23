#include <bits/stdc++.h>
using namespace std;
string stringWithSecondHighestFrequency(vector<string> &ip)
{
    unordered_map<string, int> hash_table;

    for (int i = 0; i < ip.size(); i++)
    {
        hash_table[ip[i]]++;
    }
  
    int max_freq = 0;
    int second_highest_freq = 0;
    for (auto ele : hash_table)
    {
        max_freq = max(max_freq, ele.second);
        if (second_highest_freq < ele.second && ele.second < max_freq)
        {
            second_highest_freq = ele.second;
        }
    }

    for (auto ele : hash_table)
    {
        if (ele.second == second_highest_freq)
        {
            return ele.first;
        }
    }
}
int main()
{   
    vector<string> ip = {"eeee", "mmm", "ooo", "lllll", "sss"};
    cout << "String with second highest frequency is: " << stringWithSecondHighestFrequency(ip) << endl;
    return 0;
}