/*
SODOKU
SOLVED BY PLABON DIBRA
DATE:7/11/2020
USING RECURSION,BACKTRACK
*/
#include<bits/stdc++.h>
using namespace std;
int  im=0,a[10][10],R[10][11],C[10][11],B[4][4][11];
stack< pair< int,pair<int,int> > >st;
void p()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(a[i][j]==0)
                cout<<". ";
            else
                cout<<a[i][j]<<" ";
            if(j%3==2)
                cout<<"| ";
        }
        cout<<endl;
        if(i%3==2)
            cout<<"-----------------------\n";
    }
    cout<<"\n\n";
}
void solve(int r,int c,int v)
{
//    cout<<"R,C,V "<<r<<","<<c<<","<<v<<endl;
    if(a[r][c]!=0)
    {
        c++;
        if(c>8)
        {
            c=0;
            r++;
        }
        if(r>8)
            return ;
        else
            solve(r,c,1);
    }
    else if(v<10 && R[r][v]==0 && C[c][v]==0 && B[r/3][c/3][v]==0)
    {
        st.push({r,{c,v}});
        a[r][c]=v;
        R[r][v]=1;
        C[c][v]=1;
        B[r/3][c/3][v]=1;
//        cout<<"r3,c3 "<<r/3<<","<<c/3<<endl;
//        cout<<"R,C,V "<<r<<","<<c<<","<<v<<endl<<endl;
//        p();
        c++;
        if(c>8)
        {
            c=0;
            r++;
        }
        if(r>8)
            return ;
        solve(r,c,1);
    }
    else if(v<10)
    {
        solve(r,c,++v);
    }
    else if(!st.empty())
    {
        int rr=st.top().first;
        int cc=st.top().second.first;
        int vv=st.top().second.second;
        st.pop();
        a[rr][cc]=0;
        R[rr][vv]=0;
        C[cc][vv]=0;
        B[rr/3][cc/3][vv]=0;
//        p();
        solve(rr,cc,++vv);
    }
    else
    {
        cout<<"Not Possible!"<<endl;
        im=1;
        return ;
    }
}
int main()
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                R[i][a[i][j]]=1;
                C[j][a[i][j]]=1;
                B[i/3][j/3][a[i][j]]=1;
            }
        }
    cout<<"Entered :\n";
    p();
    solve(0,0,1);
    getchar();
    if(im==0)
    {
        cout<<"Solved!\n";
        p();
    }
    return 0;
}



/// Input Pattern
/*
0 8 0 0 0 7 0 5 0
9 1 5 0 0 2 6 0 7
0 0 7 5 0 0 9 0 3
0 0 0 0 0 3 8 9 1
0 0 9 8 0 0 0 2 0
0 0 0 0 0 0 0 0 0
1 0 2 0 8 0 4 7 9
0 0 0 7 0 4 0 0 0
0 0 4 2 0 0 0 0 0
*/

