#include<iostream>
#include<string.h>

using namespace std;

char crossword[100][100],word[100];
int l;

void searching(int n,int a,int b)
{
    static int _count=1;

    switch(n)
    {
        case 1:
            {
                if(_count==l)
                {
                    cout<<a+l<<","<<b+l<<" to "<<a+1<<","<<b+1;
                    _count=1;
                    return;
                }

                else if(crossword[a-1][b-1]==word[_count])
                {
                    _count++;
                    searching(1,a-1,b-1);
                }
                else _count=1;
                return;
            }

        case 2:
        {
            if(_count==l)
            {
                cout<<a+l<<","<<b+1<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a-1][b]==word[_count])
            {
                _count++;
                searching(2,a-1,b);
            }
            else _count=1;
            return;
        }

        case 3:
        {
            if(_count==l)
            {
                cout<<a+l<<","<<b-l+2<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a-1][b+1]==word[_count])
            {
                _count++;
                searching(3,a-1,b+1);
            }
            else _count=1;
            return;
        }

        case 4:
        {
            if(_count==l)
            {
                cout<<a+1<<","<<b+l<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a][b-1]==word[_count])
            {
                _count++;
                searching(4,a,b-1);
            }
            else _count=1;
            return;
        }

        case 6:
        {
            if(_count==l)
            {
                cout<<a+1<<","<<b-l+2<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a][b+1]==word[_count])
            {
                _count++;
                searching(6,a,b+1);
            }
            else _count=1;
            return;
        }

        case 7:
        {
            if(_count==l)
            {
                cout<<a-l+2<<","<<b+l<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a+1][b-1]==word[_count])
            {
                _count++;
                searching(7,a+1,b-1);
            }
            else _count=1;
            return;
        }

        case 8:
        {
            if(_count==l)
            {
                cout<<a-l+2<<","<<b+1<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a+1][b]==word[_count])
            {
                _count++;
                searching(8,a+1,b);
            }
            else _count=1;
            return;
        }

        case 9:
        {
            if(_count==l)
            {
                cout<<a-l+2<<","<<b-l+2<<" to "<<a+1<<","<<b+1;
                _count=1;
                return;
            }

            else if(crossword[a+1][b+1]==word[_count])
            {
                _count++;
                searching(9,a+1,b+1);
            }
            else _count=1;
            return;
        }

        default:
            {
                _count=1;
                return;
            }
    }
}




void square(int i,int j)
{
    int x,y;
    int d=0;

    for(x=i-1;x<i+2;x++)
    {
        for(y=j-1;y<j+2;y++)
        {
            d++;
            if(x==i&&y==j) continue;
            else if(crossword[x][y]==word[1]) searching(d,i,j);
        }
    }
}



int main()
{
    int i,j,k,m;

    cout<<"enter size of crossword-";
    cin>>m;

    cout<<"enter the crossword\n";

    for(i=0;i<m;i++)
    {
        cin>>crossword[i];
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<crossword[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<"enter word to search:";

    cin>>word;

    l=strlen(word);

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(crossword[i][j]==word[0])
            {
                square(i,j);
            }
        }
    }

    return 0;
}
