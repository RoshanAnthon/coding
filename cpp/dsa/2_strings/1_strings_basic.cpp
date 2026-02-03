#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    printf("enter your name\n");
    cin>>s1;
    cout<<"your name is "<<s1<<endl;
    printf("enter your full name\n");
    cin.ignore(); // to ignore the newline character left in the buffer
    getline(cin,s2);
    cout<<"your full name is "<<s2<<endl;
    
    cout<<"full name length is "<<s2.length()<<endl;
    cout<<"enter the middle name\n";
    string s3;
    cin>>s3;

    cout<<"find the index after first name\n";
    int i=s2.find(" ");

    cout<<"your full name with middle name is "<<s2.insert(i+1, s3+" ")<<endl;
    //s1.push_back(' A P');
    s1.push_back('A');
    s1.push_back('P');
    cout<<s1<<endl;
    s1.pop_back();
    cout<<s1<<endl;
    s1.erase(2,3);
    cout<<s1<<endl;

    for(char j : s1)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    for(i=0;i<s2.size();i++)
    {
        cout<<s2[i]<<" ";
    }
    return 0;
}

// many string functions are available like append, clear, compare, copy, c_str, empty, erase, find, insert, length, replace, substr etc.