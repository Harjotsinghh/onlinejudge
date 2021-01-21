#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define mk make_pair
#define vll vector<long long >
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define loopr(i,a,b) for(int i=b;i>=a;i--)
#define vii vector<vector<int>>
#define ll long long
void io()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	io();
	int n, x;
	cin >> n;
	int a[n];
	loop(i, 1, n)
	cin >> a[i - 1];
	int ans = 0;
	loop(i, 1, n)
	{
		cin >> x;
		ans += a[i - 1] * x;

	}

	cout << ((ans == 0) ? "Yes" : "No") << endl;



	return 0;
}
