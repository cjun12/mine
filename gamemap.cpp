#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

void printMap(char** const ippMap,int iW,int iH)
{
    cout<<"print map"<<endl;
    for(int i=0; i<iH; i++)
    {
        for(int j=0; j<iW; j++)
        {
            cout<<ippMap[i][j]<<" ";
        }
        cout<<endl;
    }
}

void init(char** ippMap,int iW,int iH)
{
    for(int i=0; i<iH; i++)
    {
        for(int j=0; j<iW; j++)
        {
            ippMap[i][j]='0';
        }
    }
}

void mining(char** ippMap,int iW,int iH,int iNum)
{
    srand((unsigned)time(NULL));
    for(int i=0; i<iNum; i++)
    {
        int iWPos=rand()%iW;
        int iHPos=rand()%iH;
        if(ippMap[iHPos][iWPos]=='*')
        {
            i--;
            continue;
        }
        ippMap[iHPos][iWPos]='*';
    }
}
void addHint(char** ippMap,int iW,int iH)
{
    for(int i = 0; i<iH; i++)
    {
        for(int j = 0 ; j<iW; j++)
        {
            if(ippMap[i][j]=='*')
            {
                for(int k=i-1; k<=i+1; k++)
                {
                    if(k<0||k>=iH)
                    { continue; }
                    for(int l=j-1; l<=j+1; l++)
                    {
                        if(l<0||l>=iW||(k==i&&l==j))
                        { continue; }
                        if(ippMap[k][l]!='*')
                            ippMap[k][l]+=1;
                    }
                }
            }
        }
    }
}
void destory(char** ippMap,int iW,int iH)
{
    cout<<"destory"<<endl;
    for(int i=0; i<iH; i++)
    {
        delete[] ippMap[i];
    }
    delete[] ippMap;
}
int main()
{
    char **ippMap;
    int iW,iH;
    int iNum;
    cout<<"W and H:"<<endl;
    while(cin>>iW>>iH)
    {
        ippMap = new char*[iH];
        for(int i=0; i<iH; i++)
        {
            ippMap[i] = new char[iW];
        }
        init(ippMap,iW,iH);
        printMap(ippMap,iW,iH);
        cout<<"Num:"<<endl;
        cin>>iNum;
        mining(ippMap,iW,iH,iNum);
        printMap(ippMap,iW,iH);
        addHint(ippMap,iW,iH);
        printMap(ippMap,iW,iH);
        destory(ippMap,iW,iH);
        cout<<"W and H:"<<endl;
    }
}
