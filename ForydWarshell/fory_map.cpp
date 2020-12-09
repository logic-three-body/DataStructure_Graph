#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, map<string, int>> mp;


int main()
{
    int n,m;
    cin >> n;
    for (int i = 0; i <n; i++)
    {
        string x,y;
        cin >> x >> y;
        mp[x][y] = 1;
        mp[y][x] = 1;
    }
    for (map<string, map<string, int>>::iterator it = mp.begin(); it != mp.end();it++)
    {
        for (map<string,int>::iterator it1 = (it->second).begin(); it1 != (it->second).end() ; it1++)
        {
            cout << "mp[" << it->first << "]"
                 << "[" << it1->first << "]"
                 << "=" << it1->second << endl;
        }
        
    }
    system("pause");
    return 0;
}