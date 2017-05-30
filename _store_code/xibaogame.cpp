#include<iostream>
#define MAXROW 10
#define MAXCOL 25
using namespace std;

int map[MAXROW][MAXCOL],newMap[MAXROW][MAXCOL];
void init();
int neighbors(int , int);
void outputMap();
void copyMap();
int main(){
    int row, col;
    char ans;
    init();
    while(1)
    {
        outputMap();
        for(row=1;row<MAXROW-1;row++)
        {
            for(col=1;row<MAXCOL-1;col++)
            {
                switch(neighbors(row,col)){
                    case 0:
                    case 1:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                        newMap[row][col] = 0;
                        break;
                    case 2:
                        newMap[row][col] = map[row][col];
                        cout<<"x"<<endl;
                        break;
                    case 3:
                        newMap[row][col] =1;
                        cout<<"y"<<endl;
                        break;
                }
            }
        }
        //copyMap();
        cout<<"continue??"<<endl;
        //cin>>ans;
        //if(ans != 'Y')
          //  break;
    }
    return 0;
}

void init()
{
    int row, col;
    for(row=0;row<MAXROW;row++)
    {
        for(col=0;col<MAXCOL;col++)
        {
            map[row][col]=0;
            newMap[row][col]=0;
        }
    }
    cout<<"life game"<<endl;
    cout<<"输入坐标 存活的细胞 x 和 y:"<<endl;
    cout<<" 0<= x <= "<<(MAXROW-1)<<"and 0 <= y <= "<<(MAXCOL-1)<<endl;
    while(1)
    {
        cin>>row>>col;
        if(0<=row&&row<=MAXROW && 0<=col&&col<MAXCOL)
            map[row][col]=1;
        else if (row ==-1||col ==-1)
            break;
        else
            cout<<"input error"<<endl;
    }
}

int neighbors(int row, int col)
{
    int count=0,c,r;
    for(r=row-1;r<=row+1;r++)
        for(c=col-1;c<=col+1;c++)
        {
            if(map[r][c]==1)
                count++;
        }
    if(map[row][col]==1)
        count--;
    return count;
}

void outputMap(){
    cout<<"cell status:"<<endl;
    for(int row=0;row<MAXROW;row++)
    {
        cout<<endl;
        for(int col=0;col<MAXCOL;col++)
        {
            if(map[row][col]==1)
                cout<<'#';
            else
                cout<<'-';
        }
    }
}

void copyMap(){
    int row,col;
    for (row=0;row<MAXROW;row++)
        for(col=0;col<MAXCOL;col++)
            map[row][col]=newMap[row][col];
}

