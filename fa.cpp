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
		if (n == 1)
		{
			cout << 1 << endl;
		}
		else {

			int k = 1 + (n - 1) * 2;
			int sp = 0;
			int offset = 0;
			int no = n;
			loop(i, 1, n) {
				int oo = n;
				loop(k, 1, sp)
				cout << oo--;
				loop(j, 1, k)
				cout << no;

				offset += 1;
				k -= 2;
				oo = no + 1;
				loop(k, 1, sp)
				cout << oo++;
				cout << endl;
				no--;
				sp += 1;

			}

			k = 3 ;
			sp = n - 2;
			offset = n - 2;
			no = 2;
			loop(i, 1, n - 1) {
				int oo = n;
				loop(k, 1, sp)
				cout << oo--;
				loop(j, 1, k)
				cout << no;

				offset -= 1;
				oo = i + 2;
				loop(k, 1, sp)
				cout << oo++;
				sp -= 1;
				k += 2;
				no++;
				cout << endl;

			}


		}

	}


	return 0;
}
