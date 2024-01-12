// Problem: https://open.kattis.com/problems/musicaltrees

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int n, m;
int people[100];
int trees[100];
bool trees_taken[100];

int cmp(void const* a, void const* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    memset(trees_taken, 0, sizeof(trees_taken));

    scanf("%i %i", &n, &m);

    for (int i = 0; i < n; ++i) {
	scanf("%i", &people[i]);
    }

    for (int i = 0; i < m; ++i) {
	scanf("%i", &trees[i]);
    }

    qsort(people, n, sizeof(int), cmp);
    qsort(trees, m, sizeof(int), cmp);

    int curr = 0;
    for (int i = 0; i < n; ++i)
    {
	while (trees[curr] < people[i] && curr < m-1 && trees[curr+1] < people[i])
	{
	    curr += 1;
	}
	if (curr == m-1)
	{
	    trees_taken[curr] = true;
	    continue;
	}

	int left = people[i] - trees[curr];
	int right = trees[curr+1] - people[i];
	if (left <= right) {
	    trees_taken[curr] = true;
	} else {
	    trees_taken[curr+1] = true;
	}
    }

    int count = 0;
    for (int i = 0; i < m; ++i)
    {
	if (trees_taken[i]) {
	    count += 1;
	}
    }

    printf("%i\n", n - count);
}
