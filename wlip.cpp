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
		int n, k;
		cin >> n >> k;
		int arr[n];
		loop(i, 1, n)
		cin >> arr[i - 1];

		sort(arr, arr + n);
		int i = n - 1;
		int s1 = 0, s2 = 0;
		int count = 0;


		while (i >= 0 ) {
			if (s1 >= k && s2 >= k)
				break;

			if (s1 < k && s2 < k && i > 0) {
				if (i % 2 != 0)
				{
					s1 += arr[i];
					s2 += arr[i - 1];
				}
				else
				{
					s1 += arr[i - 1];
					s2 += arr[i];

				}

				count += 2;
				i -= 2;
			}
			else if (s1 < k)
			{
				s1 += arr[i];
				i--;
				count += 1;
			}
			else if (s2 < k)
			{
				s2 += arr[i];
				i--;
				count += 1;
			}


		}
		int count1 = 0, s3 = 0, s4 = 0;
		i = n - 1;
		while (i >= 0 ) {
			if (s3 >= k && s4 >= k)
				break;

			if (s3 < k && s4 < k && i > 0) {
				if (i % 2 == 0)
				{
					s3 += arr[i];
					s4 += arr[i - 1];
				}
				else
				{
					s3 += arr[i - 1];
					s4 += arr[i];

				}

				count1 += 2;
				i -= 2;
			}
			else if (s3 < k)
			{
				s3 += arr[i];
				i--;
				count1 += 1;
			}
			else if (s4 < k)
			{
				s4 += arr[i];
				i--;
				count1 += 1;
			}


		}

		if ((s1 < k || s2 < k) && (s3 < k || s4 < k))
			cout << -1 << endl;
		else
		{

			cout << min(count1, count) << endl;

		}
	}

	return 0;
}
