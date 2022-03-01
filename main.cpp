#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<fstream>
using namespace std;
using namespace std::chrono;
bool arraySortedOrNot(float a[], int n)
{if (n == 1 || n == 0)
	    {
	        return true;
	    }
	    return a[n - 1] >= a[n - 2] &&
	 		arraySortedOrNot(a, n - 1);
}
void swap(float* a, float* b)
{
	float t = *a;
	*a = *b;
	*b = t;
}
int partition(float arr[], int low, int high)
{
	float pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void merge(float arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	vector<float> L(n1);
	vector<float> R(n2);
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	int i = 0,j = 0,k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void heapify(float arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void mergeSort(float arr[], int l, int r) {
	if (l >= r) {
		return;
	}
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}
void quickSort(float arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void bubbleSort(float arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void insertionSort(float arr[], int n)
{
	int i, j;
	float key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void heapSort(float arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
int main(){
	ifstream f("extralarge_similar_list.txt");
	using std::chrono::high_resolution_clock;
  using std::chrono::duration_cast;
  using std::chrono::duration;
	float x;
	static float arr[20001001];
	int i=0;
	while (f>>x){
				arr[i]=x;
				i++;
							}
	auto t1 = high_resolution_clock::now();
	heapSort(arr,i-1);
	auto t2 = high_resolution_clock::now();
	// if (arraySortedOrNot(arr,i-1))
	// 	cout<<"the array was sorted in\t";
	// else
	// 	cout<<"the array was sorted in\t";
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << ms_int.count() << "ms\n";
	return 0;
}
