#include <iostream>
#include <algorithm>
using namespace std;

//two pointer approach// sliding window -- only works for +ve numbers
/* 
int main()
{
    int a[] = {1,2,3,1,1,1,1,4,2,3}; //considering size 10
    int k = 4;

    int l=0, r=0;
    int sum=0, maxc=0;

    for(r=0;r<10;r++)
    {
        sum += a[r];
        while(sum > k && l <= r)
        {
            sum -= a[l];
            l++;
        }
        if(sum == k)
            axc = max(maxc, r-l+1);
    }
    cout<<maxc;

}
*/

#include <map>
// hashmap
int main()
{
    vector<int> v = {1,2,3,1,1,1,1,4,2,3};
    int k = 4;

    map<int, int> m;
    int sum =0;
    int maxc=0;

    for( int i=0; i<v.size(); i++)
    {
        sum += v[i];
        if(sum == k)
        {
            maxc = max(maxc, i+1);
        }
        int rem = sum - k;
        if(m.find(rem) != m.end())
        {
            maxc = max(maxc, i-m[rem]);
        }
        else
        {
            m[sum] = i;
            cout<<rem<<" "<<i<<endl;
        }
    }
    cout<<maxc;
}