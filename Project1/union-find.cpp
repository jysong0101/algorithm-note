int graph[100001];

int findRoot(int idx) {
	if (idx == graph[idx]) return idx;

	return graph[idx] = findRoot(graph[idx]);
}

void uni(int x, int y) {
	x = findRoot(x);
	y = findRoot(y);

	if (x == y) return;

	graph[x] = y;
}