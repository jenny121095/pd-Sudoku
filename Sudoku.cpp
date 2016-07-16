#include "Sudoku.h"
Sudoku::Sudoku()
{
        int i,j;
        for(i=0;i<sudokusize;i++)
        {
                for(j=0;j<sudokusize;j++)
                {
                        map[i][j]=0;
                        res[i][j]=0;
                }
        }
        for(i=0;i<81;i++)
        {
            record[i].x=0;
            record[i].y=0;
        }
}
void Sudoku::ReadIn()
{
	Answer=0;
        depth=0;
        zero=0;
        int i,j;
        for(i=0;i<sudokusize;i++)
        {
                for(j=0;j<sudokusize;j++)
                {
                        scanf("%d",&map[i][j]);
                        if(map[i][j]==0)
                        {
                                zero++;
                        }
                }
        }
}

int Sudoku::Solve()
{
	if(zero>64){printf("2\n");return 0;}
       int i,j;
       for(i=0;i<sudokusize;i++)
       {
                for(j=0;j<sudokusize;j++)
                {
                        if(map[i][j]==0)
                        {
                                find(i,j);
                                break;
                        }
                }
       }
       if(Answer)
       {
               if(Answer==1)
               {printf("1\n");
                        for(i=0;i<sudokusize;i++)
                        {
                                for(j=0;j<sudokusize;j++)
                                {

                                        printf("%d ",res[i][j]);
                                }
                                printf("\n");
                        }
	       }
               else
               {
	       	printf("2\n");
               }

        }
        else
        {
	     printf("0\n");
        }
}


int Sudoku::find(int i,int j)
{
	if(Answer>1)
	{
		return 0;
	}
        int flag=0;
        int a,b,c,d,e,f;
        int solve=0;
        int possibility=0;
        int check[9]={0};
        for(a=0;a<9;a++)
        {
                if(map[i][a])
                {
                        check[map[i][a]-1]++;
                }
        }
        for(a=0;a<9;a++)
        {
                if(map[a][j])
                {
                        check[map[a][j]-1]++;
                }

        }
        if(i>=6)
        {
                if(j>=6)
                {{for(a=6;a<9;a++){for(b=6;b<9;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else if(j>=3)
                {{for(a=6;a<9;a++){for(b=3;b<6;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else{{for(a=6;a<9;a++){for(b=0;b<3;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
        }
        else if(i>=3)
        {
                if(j>=6)
                {{for(a=3;a<6;a++){for(b=6;b<9;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else if(j>=3)
                {{for(a=3;a<6;a++){for(b=3;b<6;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else{{for(a=3;a<6;a++){for(b=0;b<3;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
        }
        else
        {
                if(j>=6)
                {{for(a=0;a<3;a++){for(b=6;b<9;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else if(j>=3)
                {{for(a=0;a<3;a++){for(b=3;b<6;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
                else{{for(a=0;a<3;a++){for(b=0;b<3;b++){if(map[a][b]){check[map[a][b]-1]++;}}}}}
        }
//	{printf("Check[%d]:%d ",a,check[a]);if(a==8)printf("\n");}
                for(a=0;a<9;a++)
                {
		if(!check[a])
                        {
				flag=0;
				map[i][j]=a+1;
				depth++;
	//			printf("Depth:%d Zero:%d\n",depth,zero);
	//			printf("Nx= %d Ny= %d, 填入:%d\n",i,j,a+1);
                               	record[depth].x=i;
                                record[depth].y=j;
                                if(depth==zero)
                                {
					Answer++;
					for(e=0;e<sudokusize;e++)
					{
						for(f=0;f<sudokusize;f++)
						{
						res[e][f]=map[e][f];
						}
					}
					map[i][j]=0;
					depth--;
                                        return 1;
                                }
				for(c=j+1;c<9;c++)
                                {
					if(flag){break;}
					if(!map[i][c])
                                        {
						flag=1;
						find(i,c);
					if(Answer>1)return 1;
					}
                                }
				for(c=i+1;c<9;c++)
                                {	if(flag){break;}
					for(d=0;d<9;d++)
        	                        {
                                        	if(!map[c][d])
                                                {if(flag){break;}
						       flag=1;
                                                       find(c,d);
					if(Answer>1)return 1;
					        }
                                        }
                                }
			map[i][j]=0;
			depth--;
                        }
		}
		if(!flag)
		{map[record[depth].x][record[depth].y]=0;}
		return 0;
}

void Sudoku::GiveQuestion()
{
	int test=0;
	int i,j,depthmax=0;
	int ra,rb,rc;
	int temp;
	depth=0;
	srand(time(NULL));
	for(i=0;i<sudokusize;i++)
	{
		for(j=0;j<sudokusize;j++)
		{
		givequestion[i][j]=0;
		map[i][j]=0;
		}
	}
	i=(rand()%9);
	j=(rand()%9);
	rc=((rand()%8)+1);
	map[i][j]=rc;
	zero=80;
	for(i=0;i<sudokusize;i++)
	{
		for(j=0;j<sudokusize;j++)
		{
			if(!map[i][j])
			{
			find(i,j);
			break;
			}
		}
	}
	for(i=0;i<sudokusize;i++)
	{
		for(j=0;j<sudokusize;j++)
		{
		givequestion[i][j]=res[i][j];
		map[i][j]=res[i][j];
		}
	}
	zero=0;
	while(1)
	{
		if(depthmax>5){break;}
		ra=(rand()%9);
		rb=(rand()%9);
		while(map[ra][rb]==0)
		{
		ra=(rand()%9);
		rb=(rand()%9);
		}
		temp=givequestion[ra][rb];
		givequestion[ra][rb]=0;
		map[ra][rb]=0;
		zero++;
		for(i=0;i<sudokusize;i++)
		{
			for(j=0;j<sudokusize;j++)
			{
				if(map[i][j]==0)
				{
					find(i,j);
				}
			}
		}
		if(Answer==2)
		{
		//	printf("1");
			for(i=0;i<sudokusize;i++){for(j=0;j<sudokusize;j++){map[i][j]=givequestion[i][j];}}
			depthmax++;
		}
		else
		{
		//	printf("Answer:%d \n",Answer);
			givequestion[ra][rb]=temp;
			for(i=0;i<sudokusize;i++)
			{
				for(j=0;j<sudokusize;j++)
				{
				map[i][j]=givequestion[i][j];
				}
			}
			zero--;
		}
	}
	for(i=0;i<sudokusize;i++)
	{
		for(j=0;j<sudokusize;j++)
			{
			printf("%d ",map[i][j]);
			}
			printf("\n");
	}
	return ;
}
