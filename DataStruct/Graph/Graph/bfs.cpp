#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int visited[100] = { 0 };

void bfs(map<char, vector<char>> graph, char start)
{
	queue<char> bfsQ;
	visited[start - 'A'] = 1;
	bfsQ.push(start);

	while (!bfsQ.empty())
	{
		char target = bfsQ.front();
		cout << target << " -> ";
			
		for (char c : graph[target])
		{
			if (visited[c - 'A'] == 0)
			{
				bfsQ.push(c);
				visited[c - 'A'] = 1;
			}
		}

		bfsQ.pop();
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

	bfs(graphList, 'A');

	return 0;
}