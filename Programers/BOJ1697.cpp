#include<iostream>
#include<vector>
#include<queue>

const int MAX = 100000+1;
using namespace std;
bool visited[MAX];


int BFS(int N, int K) {
	queue<pair<int, int>> loc;
	loc.push({ N, 0 });
	visited[N] == 1;
	while (!loc.empty()) {
		
		int cloc = loc.front().first;
		int csec = loc.front().second;
		loc.pop();
		
		if (cloc == K) return csec;
		if (cloc - 1 >= 0 && !visited[cloc - 1]) {
			loc.push({ cloc - 1, csec + 1 });
			visited[cloc - 1] = true;
		}
		if (cloc + 1 < MAX && !visited[cloc + 1]) {
			loc.push({ cloc + 1, csec + 1 });
			visited[cloc + 1] = true;
		}
		if (cloc * 2 < MAX && !visited[cloc * 2 ]) {
			loc.push({ cloc * 2 , csec + 1 });
			visited[cloc *2 ] = true;
		}

	
	}

}


int main() {
	int N, K;
	cin >> N >> K;
	cout<<BFS(N, K);
	return 0;
}