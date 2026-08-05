#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int visited[100] = { 0 };

void dfs_recursive(map<char, vector<char>> graph, char start)
{
	visited[start - 'A'] = 1;

	for (char c : graph[start])
	{
		if (visited[c - 'A'] == 0)
		{
			dfs_recursive(graph, c);
		}
	}

	cout << start << " -> ";
}

void dfs_iterative(map<char, vector<char>> graph, char start)
{
	visited[start - 'A'] = 1;
	stack<char> dfsSt;
	dfsSt.push(start);

	while (!dfsSt.empty())
	{
		char target = dfsSt.top();
		cout << target << " -> ";
		dfsSt.pop();

		for (char c : graph[target])
		{
			if (visited[c - 'A'] == 0)
			{
				dfsSt.push(c);
				visited[c - 'A'] = 1;
			}
		}
	}
}

int main()
{
	map<char, vector<char>> graphList;
	graphList['A'].push_back('B');
	graphList['B'].push_back('D');
	graphList['B'].push_back('F');
	graphList['C'].push_back('B');
	graphList['D'].push_back('H');
	graphList['E'].push_back('C');
	graphList['E'].push_back('H');
	graphList['F'].push_back('G');
	graphList['F'].push_back('H');
	graphList['F'].push_back('D');
	graphList['G'].push_back('E');
	graphList['G'].push_back('F');
	graphList['G'].push_back('H');

	dfs_recursive(graphList, 'A');
	cout << endl;
	dfs_iterative(graphList, 'A');

	return 0;
}