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
		cin >> n;
		int s1 = 0;
		int s2 = 0;
		loop(i, 1, n)
		{
			int x; cin >> x;
			if (x == 1)
				s1 += 1;
			else
				s2 += 2;

		}



		if (((s1 + s2) % 2 != 0) || s1 % 2 != 0)
			cout << "NO" << endl;
		else {

			if (s2 > s1) {
				int diff = s2 - s1;
				int tot = diff / 2;
				if (tot % 2 == 0)
					cout << "YES" << endl;
				else if (s1 != 0)
					cout << "YES" << endl;
				else
					cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;


			}

		}




	}
	return 0;
}
