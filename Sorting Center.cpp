#include <iostream>
#include <conio.h>
 
using namespace std;
 

void MaxHeapify(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && a[j+1] > a[j])
		j = j+1;

		if (temp > a[j])
			break;

		else if (temp <= a[j])
		{
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = temp;
	return;
}
void HeapSort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{

		temp = a[i];
		a[i] = a[1];
		a[1] = temp;

		MaxHeapify(a, 1, i - 1);
	}
	
	
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		MaxHeapify(a, i, n);
}
void BubbleSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
	
	}	
}	

void SelectionSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = i+1; j < n; ++j)
		{
		
			if (arr[i] > arr[j])
			{
				arr[i] = arr[i]+arr[j];
				arr[j] = arr[i]-arr[j];
				arr[i] = arr[i]-arr[j];
			}	
		}

	}	
}
int BinarySearch(int a[], int start, int end, int item, int iter)
{                                        
	int i, mid;
	iter++;

	mid = start + (end-start+1)/2;

	if(item > a[end] || item < a[start] || mid == end)
	{
		cout<<"\nNot found";
		return -1;
	}

	else if(item == a[mid])
	{
		return mid;
	}
	
	else if(item == a[start])
	{
		return start;
	}

	else if(item == a[end])
	{
		return end;
	}

	else if(item > a[mid])
		BinarySearch(a, mid, 19, item, iter);
	else
		BinarySearch(a, start, mid, item, iter);
}	

void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
 

int Partition(int a[], int low, int high)
{
	int pivot, index, i;
	index = low;
	pivot = high;
 

	for(i=low; i < high; i++)
	{
		if(a[i] < a[pivot])
		{
			swap(&a[i], &a[index]);
			index++;
		}
	}

	swap(&a[pivot], &a[index]);
 
	return index;
}
 
	

int RandomPivotPartition(int a[], int low, int high)
{
	int pvt, n,rand,temp;
	n = rand;

	pvt = low + n%(high-low+1);
 

	swap(&a[high], &a[pvt]);
 
	return Partition(a, low, high);
}
 
int QuickSort(int a[], int low, int high)
{
	int pindex;
	if(low < high)
	{

		pindex = RandomPivotPartition(a, low, high);

		QuickSort(a, low, pindex-1);
		QuickSort(a, pindex+1, high);
	}
	return 0;
}
void Merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		MergeSort(a, low, mid);
		MergeSort(a, mid+1, high);
 
		Merge(a, low, high, mid);
	}
}

int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
void countSort(int arr[], int n, int exp)
{
	int output[n], i, count[10] = {0};
 
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);
 
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
const int MAX_SIZE = 20; 

void fillArray(int a[], int size, int& numberUsed)
{
    int next = 0;
    int index = 0;

    cin >> next;

    while ((next >= 0) && (index < size)) 
    {
        a[index] = next; 
        index++;
        cin >> next;    
    }
    numberUsed = index; 
}

void sort(int a[], int numberUsed)
{
    int j, temp;

    for (int i = i; i < numberUsed; i++)
    {
        temp = a[i];

        j = i -1;

        while (temp < a[j] && j >= 0)
        {
            a[j+1] = a[j];
            --j;
        }
        a[j+1] = temp;

    }
}

void displayArray(const int a[], int numberUsed)
{
    for (int index = 0; index < numberUsed; index++)
        cout << a[index] << " ";
    cout << endl;
}
int main()
{
		int number,n,i,arr;
		int found,first,last,loc,a[10];
cout<<"    _______________________________________________________________________________________________________________\n";
cout<<"    _______________________________________________________________________________________________________________\n";
cout<<"    |||                                                 WELCOME                                                 |||\n  ";
cout<<"  |||                                                   TO                                                    |||\n   ";
cout<<" |||                                              C++ SORTING CENTER                                            |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      HEAP SORT ENTER NUMBER      (  1  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      BUBLE SORT ENTER NUMBER     (  2  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      SELCTION SORT ENTER NUMBER  (  3  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      QUICK SORT ENTER NUMBER     (  4  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      MERGE SORT ENTER NUMBER     (  5  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  |||                                      RADIX SORT ENTER NUMBER     (  6  )                                |||\n  ";
cout<<"  |||                                                                                                         |||\n  ";
cout<<"  _______________________________________________________________________________________________________________\n";             
cout<<"    _______________________________________________________________________________________________________________\n";
   
     cout<< " \n\n  ENTER The Number ";
    cin >> number;

    if ( number == 1)
    {
      	int n, i;
      	
      	cout<<"  |||                                        HEAP SORT                                   |||\n  ";
      	
      	
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}

	Build_MaxHeap(arr, n-1);
	HeapSort(arr, n-1);
 
	
	cout<<"\nSorted Data ";
 
	for (i = 1; i < n; i++)
		cout<<"===("<<arr[i]<<")===";
		
		cout<<"\n("<<arr[i]<<")\n"<<"||";
	
    }
    if (number==2)

{
	
int n, i;
      	cout<<"  |||                                        BUBLE SORT                                   |||\n  ";
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	BubbleSort(arr, n);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
 


}

if(number==3) 
{
	
int n, i;
      	cout<<"  |||                                       SIMPLE SELCTION SORT                                   |||\n  ";
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	SelectionSort(arr, n);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];
 
}
if(number==4)
{
	
	
cout<<"  |||                                          QUICK SORT                                    |||\n  ";	
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	QuickSort(arr, 0, n-1);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        	cout<<"->"<<arr[i];
 
	return 0;
}

if(number==5)
{
cout<<"  |||                                              MERGE SORT                                  |||\n  ";	
int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	MergeSort(arr, 0, n-1);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
 
	return 0;
}
if(number==6)

{
cout<<"  |||                                                 RADIX SORT                                  |||\n  ";	
int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	radixsort(arr, n);
 

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<"->"<<arr[i];
	return 0;
}

else

 {
	
	
cout<<"...";	
	
}


 
 
	return 0;
}
