// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if the length of the rod is 8 and the values of different pieces are given as the following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 


// A Dynamic Programming solution for Rod cutting problem
#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}

/* Returns the best obtainable price for a rod of length n and
price[] as prices of different pieces */
int cutRod(int price[], int n)
{
int val[n+1];
val[0] = 0;
int i, j;

// Build the table val[] in bottom up manner and return the last entry
// from the table
for (i = 1; i<=n; i++)
{
	int max_val = INT_MIN;
	for (j = 0; j < i; j++)
		max_val = max(max_val, price[j] + val[i-j-1]);
	val[i] = max_val;
}

return val[n];
}

/* Driver program to test above functions */
int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout <<"Maximum Obtainable Value is "<<cutRod(arr, size);
	getchar();
	return 0;
}