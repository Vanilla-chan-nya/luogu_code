#include <iostream>
#include <cstdio>
using namespace std;
int n, ans, goal, plan[15], tot;
void dfs(int i, int col, int ld, int rd) {
	if (col == goal) {
		if (++ans <= 3) {
			for (int i = 1; i < n; i++) printf("%d ", plan[i]);
		printf("%d\n", plan[n]);
		}
		return;
	}
	
	int mask = goal & ~(ld | rd | col);
	while (mask) {
		int p = mask & (-mask);
		mask -= p;
		plan[i] = __builtin_ffs(p);
		dfs(i + 1, col | p, (ld | p) << 1, (rd | p) >> 1);
	}
}

int main() {
	scanf("%d", &n);
	goal = (1 << n) - 1;
	ans = 0;
	dfs(1, 0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
