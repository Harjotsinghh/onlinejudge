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
	ll x, y;
	cin >> x >> y;

	if (y == 0 || (y == 1 && x != 0))
	{
		cout << "NO" << endl;
		return 0;
	}
	//i need to apply y-1 time to orignal toy
	//after applying y on orignal toy we get copy y-1 copy toys:
	ll ct = y - 1;
	if (x < ct || ((x - ct) % 2 != 0))
		cout << "No" << endl;
	else
	{

		cout << "Yes" << endl;
	}




	return 0;
}
