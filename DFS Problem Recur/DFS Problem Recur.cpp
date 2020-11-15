#define _CRT_SECURE_NO_WARNINGS //put in first line
# include <stdio.h>
# include <stdlib.h>
# include <memory.h>
typedef struct node
{
	int vertex;
	struct node*next;
} Node;
Node*head[100];
int visited[100];
void DFS(int t);
void add_to_head(Node*head, int v);
int main()
{
	int i, n, m, k, v1, v2;
	Node*p;
	for (i = 0; i < 100; i++)
	{
		head[i] = (Node*)malloc(sizeof(Node));
		head[i]->next = NULL;
	}

	scanf("%d", &n);//n组数据
	while (n--)
	{
		memset(visited, 0, sizeof(visited));
		scanf("%d%d", &k, &m);
		for (i = 0; i < k; i++)
		{
			head[i]->next = NULL;
		}
		while (m--)
		{
			scanf("%d%d", &v1, &v2);
			/*无向图*/
			add_to_head(head[v1], v2);
			add_to_head(head[v2], v1);
		}
		/*检测建的邻接表
		for(i=0;i<k;i++)
		{
			printf("vertex%d::",i);
			p = head[i]->next;
			while(p)
			{
				printf("%d ",p->vertex);
				p = p->next;
			}
			printf("\n");
		}
		*/
		DFS(0);
		printf("\n");
	}
	return 0;
}

void add_to_head(Node*head, int v)
{
	Node*p, *q, *r;
	p = (Node*)malloc(sizeof(Node));
	p->vertex = v;
	p->next = NULL;
	q = head;
	r = head->next;
	while (r && r->vertex < v)
	{
		q = r;
		r = r->next;
	}
	q->next = p;
	p->next = r;
}

void DFS(int t)
{
	Node *p;
	int j;
	visited[t] = 1;
	if (t == 0)
		printf("%d", t);
	else
		printf(" %d", t);
	p = head[t]->next;
	while (p)
	{
		j = p->vertex;
		if (!visited[j])
		{
			DFS(j);
		}
		p = p->next;
	}
}
