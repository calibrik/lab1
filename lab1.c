#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Vector
{
        int count;
        int *obj;
};

struct Matrix
{
	int lines;
	struct Vector *line;
};

int right_input()
{
        char input[128];
	while (1)
	{	
		fgets(input,128,stdin);
		if (strlen(input)>8)
		{
			printf("Too much\nEnter again:");
			continue;
		}
		int i=0;
		int flag=1;
		if (input[i]=='-') ++i;
		for (;input[i]!='\n' && input[i]!='\0';++i)
		{
			if (input[i]<'0'||input[i]>'9')
			{
				flag=0;
				printf("Incorrect input. Enter again: ");
				break;
			}
		}
		if (flag==1) break;
	}
        return atoi(input);
}
int right_size()     
{       
	int a=right_input();
        while (a<=0)
        {      
                printf("Incorrect input. Enter again: ");
		a=right_input();
        }
	return a;
                
} 
struct Matrix* vvod()
{
	struct Matrix *matrix=malloc(sizeof(struct Matrix));
	printf("Enter lines in matrix:");
	matrix->lines=right_size();
	matrix->line=malloc(sizeof(struct Vector)*matrix->lines);
	for (int i=0;i<matrix->lines;++i)
	{
		printf("Number of symbols in %d line:",i+1);
		matrix->line[i].count=right_size();
		matrix->line[i].obj=malloc(sizeof(int)*matrix->line[i].count);
		for (int j=0;j<matrix->line[i].count;++j)
		{
			printf("[%d]:[%d]:",i+1,j+1);
			matrix->line[i].obj[j]=right_input();
		}
	}
	return matrix;	
}
void vivod(struct Vector *vector)
{
	for (int i=0;i<vector->count;++i)
        {
		printf("%d ",vector->obj[i]);
	}
	printf("\n");
}
void dellocate(struct Vector *vector,struct Matrix *matrix)
{
	for (int i=0;i<matrix->lines;++i)        
        {
		free(matrix->line[i].obj);
	}
	free(matrix->line);
	free(matrix);
	free(vector->obj);
	free(vector);
}
struct Vector* sum(struct Matrix *matrix)
{
	struct Vector *vector=malloc(sizeof(struct Vector));
	vector->count=matrix->lines;
	vector->obj=calloc(matrix->lines,sizeof(int));
	for (int i=0;i<matrix->lines;++i)
	{
		for (int j=0;j<matrix->line[i].count;++j)
                {
			vector->obj[i]+=matrix->line[i].obj[j];
		}
	}
	return vector;
}
int main()
{
	struct Matrix *matrix=vvod();
	struct Vector *vector=sum(matrix);
	printf("Source:\n");
	for (int i=0;i<matrix->lines;++i)
	{
		vivod(matrix->line+i);
	
	}
	printf("Result:\n");
	vivod(vector);
	dellocate(vector,matrix);
	return 0;
}
