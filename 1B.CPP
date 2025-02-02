// LABSET-1(B)

/*
	W.A.P TO OBTAIN THE MINIMUM COST SPANNING TREE OF A GIVEN UNDIRECTED
	CONNECTED GRAPH USING PRIM'S ALGORITHM
*/

#include <iostream>

using namespace std;

class prim
{
private:
	int **a, *b, n;
	int total;

public:
	prim(); // Constructor
	void getdata();
	void insert();
	int scanrow();
	~prim(); // destructor
};

prim::prim()
{
	n = total = 0;
}

void prim::getdata()
{
	int w;
	char ch;
	cout << endl
		 << "ENTER THE NO. OF VERTICES:";
	cin >> n;
	cout << n;
	b = new int[n];
	for (int i = 0; i < n; i++)
		b[i] = 0;
	a = new int *[n + 1];
	for (int i = 1; i <= n; i++)
		a[i] = new int[n + 1];
	cout << endl
		 << "NOTE:The Graph should be a connected undirected graph";
	cout << endl
		 << "\nEnter the edges and the weights between them" << endl;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 0;
	cout << "If there are edges,then press 'y' to input:";
	cin >> ch;
	int i, j;

	while (ch == 'y')
	{
		cout << endl
			 << "1stvertex	2ndvertex    weight" << endl;
		cin >> i >> j >> w;

		a[i][j] = a[j][i] = w;
		cout << "If there are edges,then press 'y' to input:";
		cin >> ch;
	}
}

void prim::insert()
{
	int index = 0, x;
	b[index++] = 1;
	for (int i = 1; i <= n; i++)
		a[i][1] = 0;

	while (index < n)
	{
		x = scanrow();
		for (int i = 1; i <= n; i++)
			a[i][x] = 0;

		b[index++] = x;
	}
	cout << endl
		 << "The weight of the minimal spanning tree is:" << total;
}

int prim::scanrow()
{
	int xi, yj, i = 0, min = 100;
	for (int row = b[i]; row != 0; row = b[i++])
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[row][j] < min && a[row][j] != 0)
			{
				xi = row;
				yj = j;
				min = a[row][j];
			}
		}
	}
	cout << endl
		 << "Edge: " << xi << "-----" << yj << "    weight:   " << min;
	total += min;
	return (yj);
}

prim::~prim()
{
	for (int i = 1; i <= n; i++)
		delete a[i];
	delete[] a;
	delete[] b;
}

int main()
{struct timespec begin, end,gbegin,gend;
	prim p;
	p.getdata();
	clock_gettime(CLOCK_REALTIME, &begin);
	p.insert();
	clock_gettime(CLOCK_REALTIME, &end);
	long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds+nanoseconds*1e-9;
	cout << endl
		 << "THE TIME TAKEN FOR THE SEARCH IS : " <<seconds<< " seconds\n" ;
	cout <<nanoseconds<< " nanoseconds" << endl;
	return 0;
}

/*
	   //output

ENTER THE NO. OF VERTICES:5
NOTE:The Graph should be a connected undirected graph

Enter the edges and the weights between them
If there are edges,then press 'y' to input:
1stvertex	2ndvertex    weight
1		2		6
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
1		4		8
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
2		3		4
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
2		5		5
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
3		5		3
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
3		4		2
If there are edges,then press 'y' to input:n

Edge: 1-----2    weight:   6
Edge: 2-----3    weight:   4
Edge: 3-----4    weight:   2
Edge: 3-----5    weight:   3
The weight of the minimal spanning tree is:15

---------------------------------------------------------------------

ENTER THE NO. OF VERTICES:5
NOTE:The Graph should be a connected undirected graph

Enter the edges and the weights between them
If there are edges,then press 'y' to input:
1stvertex	2ndvertex    weight
1		2		6
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
1		4		6
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
2		3		2
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
2		5		3
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
3		5		4
If there are edges,then press 'y' to input:y

1stvertex	2ndvertex    weight
3		4		2
If there are edges,then press 'y' to input:n

Edge: 1-----2    weight:   6
Edge: 2-----3    weight:   2
Edge: 3-----4    weight:   2
Edge: 2-----5    weight:   3
The weight of the minimal spanning tree is:13

*/
