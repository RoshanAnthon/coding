
#include <iostream>
#include <utility>
//#include<bits/stdc++>  // this provides access to all math, string header files but not available in MAC clang
// good for gcc

using namespace std;

int main()
{
    pair<int, int> p = {2,3};
    pair<int, string> p2 = {1, "Roshan"};
    vector<pair<int,int>> v= {{1,2}, {3,4}}; //same with array
    pair<int, pair<char,string>> p3 = {1,{'R', "Roshan"}};
    cout<<p.first<<" and "<<p.second<<endl;
    cout<<p2.first<<" and "<<p2.second<<endl;
    cout<<v[0].first<<" and "<<v[0].second<<endl;
    cout<<p3.second.second<<endl;

    return 0;
}