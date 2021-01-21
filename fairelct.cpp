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
		int  n, m;
		cin >> n >> m;
		int arr1[n];
		int arr2[m];
		int sum1 = 0, sum2 = 0;

		loop(i, 1, n)
		{
			cin >> arr1[i - 1];
			sum1 += arr1[i - 1];
		}
		loop(i, 1, m)
		{
			cin >> arr2[i - 1];
			sum2 += arr2[i - 1];
		}
		if (sum1 > sum2) {
			cout << 0 << endl;
			continue;
		}

		sort(arr1, arr1 + n);
		sort(arr2, arr2 + m);
		int i = 0, j = m - 1, count = 0;

		while (i < n && j >= 0 && sum1 <= sum2) {
			if (arr1[i] < arr2[j]) {
				sum1 += (arr2[j] - arr1[i]);
				sum2 -= (arr2[j] - arr1[i]);
				i++; j--;
				count += 1;

			}
			else {
				break;
			}

		}
		if (sum1 <= sum2)
			cout << -1 << endl;
		else
			cout << count << endl;



	}

	return 0;
}
