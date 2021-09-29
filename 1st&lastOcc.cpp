// #include <bits/stdc++.h>
// using namespace std;


// void findFirstAndLast(int arr[], int n, int x)
// {
// 	int first = -1, last = -1;
// 	for (int i = 0; i < n; i++) {
// 		if (x != arr[i])
// 			continue;
// 		if (first == -1)
// 			first = i;
// 		last = i;
// 	}
// 	if (first != -1)
// 		cout << "First Occurrence = " << first<<endl<< "Last Occurrence = " << last<<endl;
// 	else
// 		cout << "Not Found";
// }

// int main()
// {
// 	int n,x;
//         cin>>n>>x;
//         int arr[n];
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//         }
// 	findFirstAndLast(arr, n, x);
// 	return 0;
// }


/* Binary searching (optimized) */

#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int x, int n)
{
	int low = 0, high = n - 1, res = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		else {
			res = mid;
			high = mid - 1;
		}
	}
	return res;
}

int last(int arr[], int x, int n)
{
	int low = 0, high = n - 1, res = -1;
	while (low <= high) {

		int mid = (low + high) / 2;
		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;
		else {
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}

int main()
{
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
 
    int x = 8;
	printf("First Occurrence = %d\t",
           first(arr, x, n));
    printf("\nLast Occurrence = %d\n",
           last(arr, x, n));
	return 0;
}
