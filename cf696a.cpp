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
	while (t--) {
		int n;
		string b;
		cin >> n >> b;

		string a = "";
		loop(i, 0, n - 1) {

			if (b[i] == '1')
			{
				if (i == 0)
					a += '1';
				else {
					if (a[i - 1] == '1' && b[i - 1] == '1')
						a += '0';
					else if (a[i - 1] == '0' && b[i - 1] == '0')
						a += '1';
					else
						a += '1';
				}
			}
			else {
				if (i == 0)
					a += '1';
				else {
					if (a[i - 1] == '1' && b[i - 1] == '1')
						a += '1';
					else if (a[i - 1] == '0' && b[i - 1] == '0')
						a += '1';
					else

						a += '0';
				}



			}
		}
		cout << a << endl;




	}
	return 0;
}
