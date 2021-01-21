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
int degenerate(int a, int b, int c) {
	return (a + b > c) && (b + c > a) && (a + c > b);
}
int main()
{
	io();
	int n;
	cin >> n;
	int c = 0;
	loop(i, 2, n - 2) {
		loop(j, i + 1, n - 1) {
			int xx = i ^ j;
			if (xx > j && xx <= n) {
				if (degenerate(i, j, xx))
					c++;

			}

		}
	}
	cout << c << endl;

	return 0;
}
