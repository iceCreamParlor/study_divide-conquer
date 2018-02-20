#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
short paper[2200][2200];
int cnt[3] = { 0 };
void solve(int x, int y, int size) {
    if (size == 1) {
        int num = paper[y][x] + 1;
        cnt[num]++;
        return;
    }
    bool same = true;
    short first = paper[y][x];
    for (int sy = y; sy < y + size; sy++) {
        if (!same) break;
        for (int sx = x; sx < x + size; sx++) {
            if (first != paper[sy][sx]) {
                same = false;
                break;
            }
        }
    }
    if (same) {
        int num = paper[y][x] + 1;
        cnt[num]++;
        return;
    }
    int newsize = size / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(x + newsize*i, y + newsize*j, newsize);
        }
    }
}
int main(void) {
		freopen("input.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%hd", &paper[i][j]);
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}