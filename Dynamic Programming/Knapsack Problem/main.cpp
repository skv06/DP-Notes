/*
!---- Author  -  Sushil Kumar Verma
                 KIET Group Of Institution  ----!
*/
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

int knapSack(int W, int wt[], int val[], int n)
{
	int dp[n+1][W+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

void solve(){
	int n,W;
	cin>>n>>W;

	int wt[n],val[n];

	for(int i=0;i<n;i++)
		cin>>val[i];

	for(int i=0;i<n;i++)
		cin>>wt[i];

	cout<<knapSack( W, wt, val, n);

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
