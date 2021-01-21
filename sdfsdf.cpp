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
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int no = 1;
		int sp = (n - 1) / 2;
		int cc = sp;
		int count = cc - 1;
		loop(i, 1, cc + 1) {
			loop(j, 1, sp)
			cout << " ";
			loop(k, 1, count)
			cout << no++;

			sp--;
			cout << endl;
		}
		sp = 1;
		loop(i, 1, cc) {
			loop(k, 1, sp)
			cout << " ";
			loop(k, 1, count)
			cout << no++;

			sp++;
			cout << endl;

		}
		sp = 1;

	}
	return 0;
}
