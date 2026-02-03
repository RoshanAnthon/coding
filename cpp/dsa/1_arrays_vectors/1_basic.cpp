#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a[]={1,2,3,4};
    int len=sizeof(a)/sizeof(a[0]);

    cout<<"printing the array\n";
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
}