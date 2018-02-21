#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int n, m;
int start, dest;
vector<pair<int, int> > graph[100001];
int visit[100001];
queue<int> que;
 
int bfs(int limit) {
 
    que.push(start);
    visit[start] = 1;
 
    while (!que.empty()) {
        int current = que.front();
        que.pop();
 
        if (current == dest)    return 1;
 
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int w = graph[current][i].second;
 
            if (visit[next] == 0 && limit <= w) {
                visit[next] = 1;
                que.push(next);
            }
        }
    }
 
    return 0;
}
 
int solve(int e)
{
    int s = 0, middle;
 
    while (s <= e) {
        middle = (s + e) / 2;
 
        if (bfs(middle))        s = middle + 1;
        else                    e = middle - 1; 
    }
 
    return e;
}
 
int main()
{
    int one, two, weight;
    int mx = 0;
 
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &one, &two, &weight);
 
        graph[one].push_back(make_pair(two, weight));
        graph[two].push_back(make_pair(one, weight));
 
        if (weight > mx)    mx = weight;
    }
    scanf("%d %d", &start, &dest);
 
    printf("%d\n", solve(mx));
 
    return 0;
}