/* Very importent --storing unique elements ---- ordred/unordred set, map that one

no push pop, 
just insert erase find count

ordered stores data in sorted way,



*/

#include <iostream>
#include <utility>
#include <functional>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    set<int> st;
    multiset<int> ms; // stores even duplicates, erase(1) erases all 1's, count gives number of 1's 
    unordered_set<int> us; //random order
    map<int, int> m; //key value 
    multimap<int, int> mm;
    unordered_map<int, int> um;

    st.insert(1);
    st.emplace(2);
    st.insert(3);
    st.insert(4);
    st.insert(3);
    st.insert(5);

    auto it = st.find(2); // returns address where 2 is ( after 2)
    int cnt = st.count(4); // check if it exist -- used in conditions mostly
    st.erase(5);

    //auto it = st.upper_bound(2); // RESEARCH
    //auto it = st.lower_bound(3);

    ms.insert(1);
    ms.insert(2);
    ms.insert(1);
    ms.insert(1);

    //ms.erase(ms.find(1), ms.find(1)+2); // find 1's and erase the first & second occurance

    m[1] = 2;
    m.insert({3,4});
    //m.emplace({5,6});

    for(auto it: m)
    {
        cout<<it.first << " "<<it.second<<endl;
    }

}  