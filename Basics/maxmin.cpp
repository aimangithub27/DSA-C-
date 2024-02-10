#include<bits/stdc++.h>
using namespace std;
class Solution
{
   public:
    int findSum(int A[], int N)
    {
        int maxi=A[0];
        int mini=A[0];
    	for(int i=0;i<N-1;i++){
    	     maxi = max(maxi,A[i+1]);
    	     mini = min(mini,A[i+1]);
    	     
    	}
    	int sum =maxi+mini;
        return sum;
    }

};

int main(){
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	Solution ob;  
	int ans=ob.findSum(arr, n);
	cout<<ans;
	cout<<"\n";
    return 0;

}