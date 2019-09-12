#include <bits/stdc++.h>
using namespace std;

struct node {
	node* a[2];
	int sub;
	node () {
		a[0] = a[1] = NULL;
		sub = 0;
	}
} *root;

void insert(int x) {
	node *cur = root;
	for(int i = 5; i >= 0; i--) {
		int b = (x >> i) & 1;
		if(cur -> a[b] == NULL) {
			cur -> a[b] = new node();
		}
		cur = cur -> a[b];
		cur -> sub += 1;
	}
}
int getMex(int x) {
	int ans = 0;
	node* cur = root;
	for(int i = 5; i >= 0; i--) {
		int b = (x >> i) & 1;
		if(cur == NULL) return ans;
		if(cur -> a[b] == NULL) return ans;
		if(cur -> a[b] -> sub < (1 << i)) {
			cur = cur -> a[b];
		} else {
			cur = cur -> a[b ^ 1];
			ans |= 1 << i;
		}
 	}
 	return ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	set <int> s;
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		s.insert(x);
	}

	root = new node();
	for(auto i : s) {
		insert(i);
	}

	int xoer = 0;
	while(m--) {
		int x;
		scanf("%d", &x);
		xoer ^= x;
		printf("%d\n", getMex(xoer));
	}
	return 0;
}

