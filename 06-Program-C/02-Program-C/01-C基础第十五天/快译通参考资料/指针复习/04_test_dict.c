#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3

struct dict
{
	char *key;
	char *content;
};

void read_file(struct dict **p)
{
	*p = (struct dict *)malloc( MAX * sizeof(struct dict) );
	
	//(*p)[0]
	// *(*p + 0)
	
	//(*p)[0].
	//( (*p) + 0 )->
	(*p)[0].key = (char *)malloc(strlen("a")+1);
	strcpy((*p)[0].key, "a");
	
	(*p)[0].content = (char *)malloc(strlen("art. 一;字母A")+1);
	strcpy((*p)[0].content, "art. 一;字母A");
	
	( *p+1 )->key = (char *)malloc(strlen("a.m.")+1);
	strcpy( (*p+1)->key, "a.m.");
	
	(*p+1)->content = (char *)malloc(strlen("n. 上午")+1);
	strcpy((*p+1)->content, "n. 上午");
	
	( *(*p+2) ).key = (char *)malloc(strlen("a/c")+1);
	strcpy(( *(*p+2) ).key, "a/c");
	
	( *(*p+2) ).content = (char *)malloc(strlen("n. 往来帐户@往来:come - and - go; contact; intercourse@n. 往来帐户")+1);
	strcpy(( *(*p+2) ).content, "n. 往来帐户@往来:come - and - go; contact; intercourse@n. 往来帐户");
}

void search(struct dict *p, char *key, char *content)
{
	int i = 0;
	int flag = 0;
	for(i = 0; i < MAX; i++)
	{
		flag = 0;
		//printf("test = %s\n", p[i].key);
		if( strcmp( p[i].key, key ) == 0)
		{
			//printf("%s的翻译为：%s\n", key, p[i].content);
			strcpy(content, p[i].content);
			flag = 1;
			break;
		}
	}
	
	if(0 == flag)
	{
		printf("没有此词汇\n");
	}
}

void free_buf(struct dict *p)
{
	int i = 0;
	for(i = 0; i < MAX; i++)
	{
		if(p[i].key != NULL)
		{
			free(p[i].key );
			p[i].key  = NULL;
		}
		
		if(p[i].content != NULL)
		{
			free(p[i].content );
			p[i].content  = NULL;
		}
	}
	
	free(p);
	p = NULL;
}

int main()
{
	//定义一个结构体指针变量
	struct dict *p = NULL;
	read_file(&p); //地址传递
	
	char content[1024] = {0};
	search(p, "a.m.", content);
	if( strlen(content) > 0 )
	{
		printf("翻译为：%s\n", content);
	}
	
	free_buf(p);
	
	return 0;
}