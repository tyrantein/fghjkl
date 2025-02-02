#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

template <class T>
void bubblesort(T a[], int n)
{
	for (int i = n; i > 2; i--)
		for (int j = 0; j < i - 1; j++)
			if (a[j] > a[j + 1])
			{
				T temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
}

template <class T>
int bin(T a[], int low, int high, T key)
{
	int mid;
	if (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key)
			return 1;
		else
		{
			if (a[mid] < key)
				return (bin(a, mid + 1, high, key));
			else
				return (bin(a, low, mid - 1, key));
		}
	}
	return 0;
}

int main()
{
	int a[30];
	int i, n, key, t;
	long int k;
    struct timespec begin,end,gbegin,gend; 
	
	cout << "enter the number of element:";
	cin >> n;
	cout << endl
		 << "THE ELEMENTS ENTERED RANDOMLY:\n ";

	for (i = 0; i < n; i++)
		cin >> a[i];

	a[i] = rand() % 500;

	for (int j = 0; j < n; j++)
		cout << a[j] << endl;

	bubblesort(a, n);
	cout << endl
		 << "ENTER THE KEY ELEMENT TO BE SEARCHED : ";
	cin >> key;
	cout << key;
	clock_gettime(CLOCK_REALTIME, &begin);
	t = bin(a, 0, n - 1, key);
	clock_gettime(CLOCK_REALTIME, &end);
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds+nanoseconds*1e-9;
	if (t == 1)
		cout << endl
			 << "SEARCH WAS A SUCCESS ";
	else
		cout << endl
			 << "SEARCH UNSUCCESSFUL ";
	cout << endl
		 << "THE TIME TAKEN FOR THE SEARCH IS : " << seconds << " sec" << endl;
         cout <<nanoseconds<< " nanoseconds" << endl;
	getch();
}