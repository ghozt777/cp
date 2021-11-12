// TC :O(n!)
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<bool>> vvb;

void Run();
int queens(vvb);
int util(vvb, int);
void printMaze(vvb);
bool isValid(vvb, int, int);
void test(vvb m)
{
	cout << "size of m : " << size(m) << " size of m[0] :  " << size(m[0]);
}

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	Run();

	return 0;
}

void Run()
{
	// run your code here
	int n = 4;
	vvb m(n, vector<bool>(n, false));
	int c = queens(m);
	cout << "Possible Number of combinations: " << c;
	// test(m) ;
	return;
}

int queens(vvb m)
{
	return util(m, 0);
}

int util(vvb m, int r)
{
	if (r == size(m))
	{
		printMaze(m);
		return 1;
	}
	int count = 0;
	for (int i = 0; i < size(m[0]); i++)
	{
		if (isValid(m, r, i))
		{
			m[r][i] = true;
			count += util(m, r + 1);
			m[r][i] = false;
		}
	}
	return count;
}

bool isValid(vvb m, int r, int c)
{
	for (int i = 0; i < size(m); i++)
		if (m[i][c])
			return false;
	int i = 1;
	while (1)
	{
		int nr = r - i;
		int nc = c + i;
		if (nr >= size(m) || nc >= size(m[0]) || nr < 0 || nc < 0)
			break;
		if (m[nr][nc])
			return false;
		++i;
	}
	i = 1;
	while (1)
	{
		int nr = r - i;
		int nc = c - i;
		if (nr >= size(m) || nc >= size(m[0]) || nr < 0 || nc < 0)
			break;
		if (m[nr][nc])
			return false;
		++i;
	}

	return true;
}

void printMaze(vvb m)
{
	for (auto x : m)
	{
		for (auto y : x)
			y ? cout << "Q " : cout << "X ";
		cout << "\n";
	}
	for (int i = 0; i < size(m); i++)
		i == size(m) - 1 ? cout << "-\n" : cout << "--";
	return;
}
