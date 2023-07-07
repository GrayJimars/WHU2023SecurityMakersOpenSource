/**
 * @file player.h
 * @author yangboyang@jisuanke.com
 * @copyright jisuanke.com
 * @date 2021-07-01
 */ 
#define INF -11451428
#define MAX 11451428
#define K 5//搜索宽度
#define deep 6//搜索深度
#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int step[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
char mat[13][13];
int priority[13][13],max_x,max_y;
int canshu;
int canshu2;
int fenshu;
int getstable(struct Player *player,char now_mat[13][13]);
int is_valid(struct Player *player, int posx, int posy,char now_mat[13][13]);//判断是否可以落子
void init(struct Player *player);//初始化
struct Point place(struct Player *player);//选择落点
int get_chess(struct Player *player,char now_mat[13][13]);//计算此时棋盘中棋子的数量
int dfs(int posx,int posy,int step,char now_mat[13][13],char op_mat[13][13],int max_min_value);//深度优先搜索，最佳值储存再全局变量max_x,max_y中
void set_corners(int x, int y);//辅助作权值表
void change_mat(struct Player *player,int posx,int posy,char now_mat[13][13],char op_mat[13][13]);//假设posx，posy落子,改变地图的情况
void copy(int n,char a1[13][13],char a2[13][13]);//复制地图
int getprior(struct Player *player,char now_mat[13][13]);//计算此时我方总权值
int getmov(struct Player *player,char now_mat[13][13],char op_mat[13][13]);//计算我方行动力与敌方行动力差值

int get_chess(struct Player *player,char now_mat[13][13])
{
    int cnt=0;
    for(int i=0;i<player->row_cnt;i++)
    {
        for(int j=0;j<player->col_cnt;j++)
        {
            if(now_mat[i][j]=='O'||now_mat[i][j]=='o')
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int getstable(struct Player *player,char now_mat[13][13])
 {
    int stable[3] = {0, 0, 0};
    int cind1[4] = {0};
    int cind2[4] = {0};
    cind1[2]=cind1[3]=player->col_cnt-1;
    cind2[1]=cind2[2]=player->col_cnt-1;
    int inc1[4] = {0, 1, 0, -1};
    int inc2[4] = {1, 0, -1, 0};
    int stop[4] = {0};
    int i, j;
    for (i = 0; i < 4; i++) 
    {
        if (now_mat[cind1[i]][cind2[i]]=='O') 
        {
            stop[i] = 1;
            stable[0] += 1;
            for (j = 1; j < player->col_cnt; j++) 
            {
                if (now_mat[cind1[i]+inc1[i]*j][cind2[i]+inc2[i]*j]!='O')
                {
                    break;
                } 
                else 
                {
                    stop[i] = j + 1;
                    stable[1] += 1;
                }
            }
        }
    }
    for (i = 0; i < 4; i++) 
    {
        if (now_mat[cind1[i]][cind2[i]]=='O') 
        {
            for (j = 1; j <player->col_cnt - stop[(i+3)%4]; j++) 
            {
                if (now_mat[cind1[i]-inc1[(i+3)%4]*j][cind2[i]-inc2[(i+3)%4]*j]!='O') 
                {
                    break;
                } 
                else 
                {
                    stable[1] += 1;
                }
            }
        }
    }
    int colfull[13]={0};
    int rowfull[13]={0};
    int diag1full[26]={0};
    int diag2full[26]={0};
    for(i=0;i<player->col_cnt;i++)
    {
        for(j=0;j<player->col_cnt;j++)
        {
            if(now_mat[i][j]!='O'&&now_mat[i][j]!='o')
                break;
        }
        if(j==player->col_cnt)
            rowfull[i]=1;
        for(j=0;j<player->col_cnt;j++)
        {
            if(now_mat[j][i]!='O'&&now_mat[j][i]!='o')
                break;
        }
        if(j==player->col_cnt)
            colfull[i]=1;
    }
    for(i=0;i<player->col_cnt*2-1;i++)
    {
        int diacnt=player->col_cnt-abs((player->col_cnt*2-2)/2-i);
        int startx,starty;
        if(i<player->col_cnt-1)
        {
            startx=player->col_cnt-1-i;
            starty=0;
        }
        else
        {
            startx=0;
            starty=i-player->col_cnt+1;
        }
        for(j=0;j<diacnt;j++)
        {
            if(now_mat[startx+j][starty+j]!='O'&&now_mat[startx+j][starty+j]!='o')
                break;
        }
        if(j==diacnt)
            diag1full[i]=1;
        if(i<player->col_cnt-1)
        {
            startx=player->col_cnt-1-i;
            starty=player->col_cnt-1;
        }
        else
        {
            startx=0;
            starty=2*player->col_cnt-2-i;
        }
        for(j=0;j<diacnt;j++)
        {
            if(now_mat[startx+j][starty-j]!='O'&&now_mat[startx+j][starty-j]!='o')
                break;
        }
        if(j==diacnt)
            diag2full[i]=1;
    }
    for(i=1;i<player->col_cnt-1;i++)
    {
        for(j=1;j<player->col_cnt-1;j++)
        {
            int diag1=j-i+player->col_cnt-1;
            int diag2=2*player->col_cnt-2-j-i;
            if(now_mat[i][j]=='O'&&colfull[j]&&rowfull[i]&&diag1full[diag1]&&diag2full[diag2])
            {
                stable[2]++;
            }
        }
    }
    return stable[0]+stable[1]+stable[2];
}

void change_mat(struct Player *player,int posx,int posy,char now_mat[13][13],char op_mat[13][13])
{
    now_mat[posx][posy]='O';
    op_mat[posx][posy]='o';
    for (int dir = 0;  dir < 8; dir++) 
    {
        int x = posx + step[dir][0];
        int y = posy + step[dir][1];
        if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt) 
        {
            continue;
        }
        if (now_mat[x][y] != 'o') 
        {
            continue;
        }
        int x0=x,y0=y;
        while (true) 
        {
            x += step[dir][0];
            y += step[dir][1];
            if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt || (now_mat[x][y] >= '1' && now_mat[x][y] <= '9')) 
            {
                break;
            }
            if (now_mat[x][y] == 'O') 
            {
                for(int i=x0,j=y0;i!=x||j!=y; i += step[dir][0],j += step[dir][1])
                {
                    now_mat[i][j]='O';
                    op_mat[i][j]='o';
                }
                break;
            }
        }
    }
}

void copy(int n,char a1[13][13],char a2[13][13])
{
    for(int i=0;i<n;i++)
        strcpy(a1[i],a2[i]);
}

int getmov(struct Player *player,char now_mat[13][13],char op_mat[13][13])
{
    int mov=0,op_mov=0;
    for(int i=0;i<player->row_cnt;i++)
    {
         for(int j=0;j<player->col_cnt;j++)
        {
            if(is_valid(player,i,j,now_mat))
            {
                mov++;
            }
            if(is_valid(player,i,j,op_mat))
            {
                op_mov++;
            }
         }
    }
    return mov-op_mov;
}

int getprior(struct Player *player,char now_mat[13][13])
{
    int prior=0,cnt=0,cnt2=0;
    fenshu=0;
    for(int i=0;i<player->row_cnt;i++)
    {
        for(int j=0;j<player->col_cnt;j++)
        {
            if(now_mat[i][j]=='O')
            {
                prior+=priority[i][j];
                cnt++;
                fenshu++;
            }
            else if(now_mat[i][j]=='o')
            {
                cnt2++;
            }
        }
    }
    if(cnt==0)
    {
         return -100000;
    }
    if(cnt2==0)
    {
        return 1000000;
    }
    return prior;
}

int dfs(struct Player *player, int step,char now_mat[13][13],char op_mat[13][13],int max_min_value)
{
    if(step>deep)
    {
        return getprior(player,now_mat)+canshu*getmov(player,now_mat,op_mat)+10*getstable(player,now_mat)+canshu2*fenshu;
    }
    int x[K+1],y[K+1];
    for(int i=0;i<K;i++)
    {
        x[i]=y[i]=-1;
    }
    for(int i=0;i<player->row_cnt;i++)
    {
         for(int j=0;j<player->row_cnt;j++)
        {
            if(is_valid(player,i,j,now_mat))
            {
                int k=K-1;
                while(k>=0&&(x[k]==-1||priority[i][j]>priority[x[k]][y[k]]))
                {
                    x[k+1]=x[k];
                    y[k+1]=y[k];
                    k--;
                }
                x[k+1]=i;
                y[k+1]=j;
            }
        }
    }
    if(x[0]==-1)
    {
        if(step==1)
        {
            max_x=-1,max_y=-1;
            return 0;
        }
        char next_mat[13][13];
        char n_o_mat[13][13];
        copy(player->row_cnt,next_mat,now_mat);
        copy(player->row_cnt,n_o_mat,op_mat);
        if(step%2==1)
        {
            return dfs(player,step+1,n_o_mat,next_mat,INF);
        }
        else
        {
            return dfs(player,step+1,n_o_mat,next_mat,MAX);
        }
    }
    int ex_value;
    if(step%2==1)
    {
        ex_value=INF;
    }
    else
    {
        ex_value=MAX;
    }
    for(int i=0;i<K&&x[i]!=-1;i++)
    {
        char next_mat[13][13];
        char n_o_mat[13][13];
        copy(player->row_cnt,next_mat,now_mat);
        copy(player->row_cnt,n_o_mat,op_mat);
        change_mat(player,x[i],y[i],next_mat,n_o_mat);
        int value=dfs(player,step+1,n_o_mat,next_mat,ex_value);
        if(step%2==1)
        {
             if(value>max_min_value)
             {
                 return MAX;
             }
             if(value>ex_value)
             {
                ex_value=value;
                if(step==1)
                {
                    max_x=x[i];
                    max_y=y[i];
                }
            }
        }
        else
        {
            if(value<max_min_value)
            {
                 return INF;
            }
            if(value<ex_value)
            {
                ex_value=value;
            }
        }
        
    }
    return ex_value;
}

int is_valid(struct Player *player, int posx, int posy,char now_mat[13][13]) 
{
    if (posx < 0 || posx >= player->row_cnt || posy < 0 || posy >= player->col_cnt) 
    {
        return false;
    }
    if (now_mat[posx][posy] == 'o' ||now_mat[posx][posy] == 'O') 
    {
        return false;
    }
    int step[8][2] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
    for (int dir = 0;  dir < 8; dir++) 
    {
        int x = posx + step[dir][0];
        int y = posy + step[dir][1];
        if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt) 
        {
            continue;
        }
        if (now_mat[x][y] != 'o') 
        {
            continue;
        }
        while (true) 
        {
            x += step[dir][0];
            y += step[dir][1];
            if (x < 0 || x >= player->row_cnt || y < 0 || y >= player->col_cnt || (now_mat[x][y] >= '1' && now_mat[x][y] <= '9')) 
            {
                break;
            }
            if (now_mat[x][y] == 'O') 
            {
                return true;
            }
        }
    }
    return false;
}

void set_corners(int x, int y) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            priority[x + i][y + j] = -25;
        }
    }
}

void init(struct Player *player)
{
	for(int i=0;i<player->row_cnt;i++)
        for(int j=0;j<player->col_cnt;j++)
            mat[i][j]=player->mat[i][j];
     int row = player->row_cnt;
    int col = player->col_cnt;
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            priority[i][j] = 2;
        }
    }
    set_corners(0, 0), set_corners(0, col - 2);
    set_corners(row - 2, 0), set_corners(row - 2, col - 2);
    priority[0][0] = priority[0][col-1] = priority[row-1][0] = priority[row-1][col-1] = 500;
    priority[1][1] = priority[1][col-2] = priority[row-2][1] = priority[row-2][col-2] = -45;
    priority[2][2] = priority[2][col-3] = priority[row-3][2] = priority[row-3][col-3] = 3;
    for (int i = 2; i < col - 2; i++) 
    {
        priority[0][i] = priority[row - 1][i] = 5;
        priority[1][i] = priority[row - 2][i] = 1;
    }
    for (int i = 2; i < row - 2; i++) 
    {
        priority[i][0] = priority[i][col - 1] = 5;
        priority[i][1] = priority[i][col - 2] = 1;
    }
    priority[0][2] = priority[0][col-3] = priority[row-1][2] = priority[row-1][col-3] = 10;
    priority[2][0] = priority[row-3][0] = priority[2][col-1] = priority[row-3][col-1] = 10;
}

struct Point place(struct Player *player) 
{
    char op_mat[13][13],now_mat[13][13];
    if(player->col_cnt==8)
    {
        canshu=15;
    }
    else if(player->col_cnt==10)
    {
        canshu=12;
    }
    else 
    {
        canshu=10;
    }
    for(int i=0;i<player->row_cnt;i++)
        for(int j=0;j<player->col_cnt;j++)
        {
            now_mat[i][j]=player->mat[i][j];
            if(player->mat[i][j]=='O')
            {
                op_mat[i][j]='o';
            }
            else if(player->mat[i][j]=='o')
            {
                op_mat[i][j]='O';
            }
            else
            {
                op_mat[i][j]=player->mat[i][j];
            }
        }
    int chess=get_chess(player,now_mat);
    if(player->row_cnt*player->row_cnt-chess<=player->row_cnt)
    {
        canshu2=2;
    }
    else 
    {
        canshu2=0;
    }
    dfs(player,1,now_mat,op_mat,MAX);
    struct Point max_point=initPoint(max_x,max_y);
	return max_point;
}
