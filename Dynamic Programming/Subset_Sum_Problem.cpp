#include <bits/stdc++.h>
using namespace std;

#define superfast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define endl "\n"

#define f1 for(ll i=0;i<n;i++)cin>>a[i]
#define f2 for(ll i=0;i<n;i++)for(ll j=0;j<m;j++)cin>>ar[i][j]
#define MOD 1000000007
#define INF 9e18

// Start ----------------------------------------------------

bool equalPartition(int N, int arr[])
{
	int sum = 0;
	int i,j;
	for(i=0;i<N;i++)
	{
		sum+=arr[i];
	}

	if(sum%2!=0)
	{
		return false;
	}

	int W = sum/2;
	bool dp[N+1][W+1];

	for(i=0;i<N+1;i++)
	{
		dp[i][0]=true;
	}

	for(j=1;j<W+1;j++)
	{
		dp[0][j]=false;
	}

	for(i=1;i<N+1;i++)
	{
		for(j=1;j<W+1;j++)
		{
			if(arr[i]<=j)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[N][W];
}

void solve(){
	int N;
    cin>>N;
    int arr[N];

    for(int i = 0;i < N;i++)
    	cin>>arr[i];

    if(equalPartition(N, arr))
    	cout<<"YES\n";
    else
        cout<<"NO\n";

}

int main() {

	superfast;

	int tc,t;
	tc=1;
	//cin>>tc;
	while(tc--)
	{
	solve();
	}
	return 0;
}

// end ----------------------------------------------
