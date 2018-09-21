#include <iostream>
using namespace std;
 // A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid) {
	// We have low to mid and mid+1 to high already sorted.
	int temp[high-low+1];
	int	i = low, j = mid + 1, k = 0 ;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}
		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high) {
		temp[k] = a[j];
		k++;
		j++;
	}
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++) 
		a[i] = temp[i-low] ;
}
 
// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high) {
		mid=(low+high)/2;  					// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
		Merge(a, low, high, mid);			// Merge them to get sorted output.
	}
}
 
int main() {
	int n;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
	cout<<"\nSorted Data ";
	for (int i = 0; i < n; i++)
        cout<<"->"<<arr[i];
	return 0;
}