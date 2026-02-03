#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // write it myself in C programming way
    vector<int> v={1,3,5,2,7,9,4,3};
    int n=v.size();

    // Bubble sort algorithm
    /* whole logic here is, compare adjustant element, and greater one keep pushing( swapping) till the last,
    then repeat the same till you reach end
    remember - keep bursting small small bubbles of swap by comparing them till the array is sorted-- so bubble
    worst time complexity after linear*/
    cout<<"Bubble sort algorithm\n";
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                //swap(v[j],v[j+1]); --> great function in c++
                /*
                int x=v[j];
                v[j]=v[j+1];
                v[j+1]=x;
                */
                v[j]=v[j]^v[j+1];
                v[j+1]=v[j]^v[j+1];
                v[j]=v[j]^v[j+1];
                // many other ways to swap without using 3rd variable
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // Selection sort algorithm
    /* logic here is, for each element i, find minimum in its right array elements, and swap that to ith place, 
    remember - select min in subarray and keep pushing it to first so selection*/
    cout<<"\nSelection sort algorithm\n";
    v={1,3,5,2,7,9,4,3};
    for (int i=0;i<n-1;i++)
    {
        int min=i;
        for (int j=i+1;j<n;j++)
        {
            if(v[j]<v[min])
                min=j;
        }
        swap(v[i],v[min]);
    }

    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // insertion sort algorithm
    /* logic here is, start from 1, for every element of i, maintain its left side elements sorted, 
    then compare each element with i by moving left, and as soon as you find lesser number, place next to it...
    remember - keep serching element perfect place in already sorted part and insert it there- so insertion sort*/
    cout<<"\nInsertion sort algorithm\n";
    v={1,3,5,2,7,9,4,3};
    for (int i=1;i<n;i++)
    {   
        int key=v[i];
        int j=i-1;
        while(j>=0 && v[j]>key)
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }

    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // quick sort algorithm
    cout<<"\nQuick sort algorithm\n";
    v={1,3,5,2,7,9,4,3};
    //function for partition
    function<int(int,int)> partition=[&v,&n,&partition](int low,int high)->int
    {
        int pivot=v[high];
        int i=low-1;
        for (int j=low;j<high;j++)
        {
            if(v[j]<pivot)
            {
                i++;
                swap(v[i],v[j]);
            }
        }
        swap(v[i+1],v[high]);
        return i+1;
    };
    //function for quicksort
    function<void(int,int)> quicksort=[&v,&n,&quicksort,&partition](int low,int high)->void
    {
        if(low<high)
        {
            int pi=partition(low,high);
            quicksort(low,pi-1);
            quicksort(pi+1,high);
        }
    };
    quicksort(0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // merge sort algorithm
    /* messy one, but compare it to binary search kind of, device and concure--- its like keep adding two sorted arrays
    best is with recursion. find a mid, then call in below sequence
    mergesort(a, L, R) {
        while(L<R)
        {
            mid = l+(r-l)/2
            mergesort(array, left, mid). // sort left array
            mergesort(array, mid+1, right) // sort right array
            merge(array, left, mid, right) // merge both
        }       
    }

    break/base condition for mergesort is l>R -- till last element 

    merge function is simple, but important, maintain 2 pointer on 2 arrays from start, keep coparing each,
    keep storing in another array & return array... 
    
    */
    cout<<"\nMerge sort algorithm\n";
    v={1,3,5,2,7,9,4,3};
    //function for merging two halves
    function<void(int,int,int)> merge=[&v,&n,&merge](int left,int mid,int right)->void
    {
        int n1=mid-left+1;
        int n2=right-mid;
        vector<int> L(n1);
        vector<int> R(n2);
        for (int i=0;i<n1;i++)
            L[i]=v[left+i];
        for (int j=0;j<n2;j++)  
            R[j]=v[mid+1+j];
        int i=0,j=0,k=left;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                v[k]=L[i];
                i++;
            }
            else
            {
                v[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            v[k]=L[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            v[k]=R[j];
            j++;
            k++;
        }
    };
    //function for mergesort
    function<void(int,int)> mergesort=[&v,&n,&mergesort,&merge](int left,int right)->void
    {
        if(left<right)
        {
            int mid=left+(right-left)/2;
            mergesort(left,mid);
            mergesort(mid+1,right);
            merge(left,mid,right);
        }
    };
    mergesort(0,n-1);
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // heap sort algorithm
    cout<<"\nHeap sort algorithm\n";
    v={1,3,5,2,7,9,4,3};
    //function to heapify a subtree rooted with node i
    //function<void(int,int)> heapify=[&v,&n,&heapify](int n,int i)->void
    function<void(int,int)> heapify=[&v,&n,&heapify](int m,int i)->void
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<m && v[left]>v[largest])
            largest=left;
        if(right<m && v[right]>v[largest])
            largest=right;
        if(largest!=i)
        {
            swap(v[i],v[largest]);
            heapify(m,largest);
        }
    };
    //building heap
    for (int i=n/2-1;i>=0;i--)
    {
        heapify(n,i);
    }
    //one by one extract elements from heap
    for (int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        heapify(i,0);
    }
    for (int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }

    // remaining are couting, radix and bucket sort algorithms
    // if more then bitonic, pontic, shell sort algorithms
    // many more which are not importent

    
    //Lets do it using the inbuilt sort function
    // inbuilt sort function uses intro sort algorithm, 
    // which is a hybrid sorting algorithm derived from quicksort and heapsort
    // average time complexity O(n log n)
    
    vector<int> v2={1,3,5,2,7,9,4,3};
    cout<<"\nUsing inbuilt sort function\n";

    sort(v2.begin(),v2.end());
    for (int i=0;i<n;i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<"\n";
    return 0;
   


    
}
