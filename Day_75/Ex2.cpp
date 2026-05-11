#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define bitscount 32
// Function to find the prefix XOR array
vector<int>prefix_xor(vector<int>&arr)
{
  int n = arr.size();
  vector<int>prexor(n);
  prexor[0]=arr[0];
  for(int i=1;i<n;i++)
  {
      prexor[i]= prexor[i-1]^arr[i];
  }
  return prexor;
}
//Function to find the xor in the range of [l,r]
int findxor(vector<int>prexor,int l, int r)
{
   if(l==0)
      return prexor[r];
    else
      return prexor[r]^prexor[l-1];
}

int or_prefix[bitscount][MAX];

// Function to find the prefix Or array
void prefix_or(vector<int>arr)
{
    int n=arr.size();
    for (int i = 0; i < bitscount; i++) {
        or_prefix[i][0] = ((arr[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            or_prefix[i][j] = ((arr[j] >> i) & 1);
            or_prefix[i][j] += or_prefix[i][j - 1];
        }
    }
}
//Function to find the or in the range of [l,r]
int rangeOr(int l, int r)
{
    int ans = 0;
    for (int i = 0; i < bitscount; i++) {
        int x;
        if (l == 0)
            x = or_prefix[i][r];
        else
            x = or_prefix[i][r]
                - or_prefix[i][l - 1];
        if (x != 0)
            ans = (ans | (1 << i));
    }
    return ans;
}


//prefix and
int prefix_count[bitscount][MAX];
// Function to find the prefix and array
void prefix_and(vector<int> arr)
{
  int n =arr.size();
	for (int i = 0; i < bitscount; i++) {
		prefix_count[i][0] = ((arr[0] >> i) & 1);
		for (int j = 1; j < n; j++) {
			prefix_count[i][j] = ((arr[j] >> i) & 1);
			prefix_count[i][j] += prefix_count[i][j - 1];
		}
	}
}
//Function to find the and in the range of [l,r]
int rangeAnd(int l, int r)
{
	int ans = 0;
	for (int i = 0; i < bitscount; i++) {
		int x;
		if (l == 0)
			x = prefix_count[i][r];
		else
			x = prefix_count[i][r]
				- prefix_count[i][l - 1];
		if (x == r - l + 1)
			ans = (ans | (1 << i));
	}

	return ans;
}
vector<int>WeirdBitwsieQuery(vector<int>arr,vector<vector<int>>&query)
{
   vector<int>xorprefix = prefix_xor(arr); //storing the prefix xor of the array.
   prefix_and(arr); //initializing the prefix_and of the array.
   prefix_or(arr); //initializing the prefix_or of the array.
   vector<int>res;  //initializing the result vector to store the result of query
   for(auto &i:query) //iterating over each query.
   {
     int xorr = findxor(xorprefix,i[0]-1,i[1]-1); //finding xor for the range of current query.
     int andd = rangeAnd(i[0]-1,i[1]-1);//finding and for the range of current query.
     int orr = rangeOr(i[0]-1,i[1]-1);//finding or for the range of current query.
     res.push_back(xorr+andd+orr); //appending the sum of bitwise operations.
   }
   return res; //returning the result vector.
  
}
int main() 
{
    int N,Q;
    cin>>N>>Q;
    vector<int>arr(N);
    for(auto &i:arr)
    cin>>i;
    vector<vector<int>>q(Q,vector<int>(2));
    for(auto &i:q)
    {
      cin>>i[0]>>i[1];
    }
    vector<int>res = WeirdBitwsieQuery(arr,q);
    for(auto &i:res)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}