#include <cstdio>
// DP�� �̺� Ž�� ��� �̿��Ѵ�.
using namespace std;
int n; int dp[22];
void solve(int n, int x, int y){
	if(n==0 ) return;
	solve(n-1, x, 6-x-y);
	printf("%d %d\n", x, y);
	solve(n-1, 6-x-y, y);
}
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	dp[1] = 1;
	for(int i=2; i<= n; i++){
		dp[i] = 2*dp[i-1] +1; // n-1 ���� 2��ŭ �ű��(n), �� �Ʒ����� 3���� �ű�� (1), 2�� �ִ� ���� �ٽ� 3���� �ű��(n)
	}
	printf("%d\n", dp[n]);
	solve(n, 1, 3);
	return 0;
}