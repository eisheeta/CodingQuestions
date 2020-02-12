#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//print a diamond pattern for n lines when n is odd
//eg. n=5
//  *
// ***
//*****
// ***
//  *
void diamondpattern(){
    
    int n, c, k, space=1;
    
    cin>>n;
    int m = (n/2)+1;
    space=(m)-1;
    for (k=1; k<=m; k++)
    {
    for(c=1; c<=space; c++)
    {
        cout<<" ";
    }
    space--;
    for(c=1; c<=(2*k-1); c++)
    {
        cout<<"*";
    }
    cout<<"\n";
    }
    space=1;
    for(k=1; k<=((m)-1); k++)
    {
    for(c=1; c<=space; c++)
    {
        cout<<" ";
    }
    space++;
    for(c=1 ; c<=(2*(m-k)-1); c++)
    {
        cout<<"*";
    }
    cout<<"\n";
    }
}


//hollow diamond in rectangle
/* eg. n=5

*** ***
**   **
*     *
**   **
*** ***

*/
void diRec(){
    int i, j, m, rows;
    cin >> m;
    rows = (m/2)+1;
    
    //loop for display upper half part of the pattern
    for(i=1; i<=rows; i++){
        for(j=i; j<=rows; j++){
            cout<<"*";//print star
    }
    for(j=1; j<=(2*i-1); j++){
       cout<<" ";//print space
    }
    for(j=i; j<=rows; j++){
       cout<<"*";//print star
    }
    cout<<"\n";
}
    //loop for printing lower half part  of the pattern
    for(i=2; i<=rows; i++){
        for(j=1; j<=i; j++){
            cout<<"*";//print star
    }
        for(j=(2*i-3); j<(2*rows-2); j++){
            cout<<" ";//print space
    }
        for(j=1; j<=i; j++){
            cout<<"*";
    }
        cout<<"\n";//move to next line
    }

}

//print x pattern
void xpattern(int n){
    int i, j;
    int count;

    
    cin>>n;
    int m = (n/2)+1;

    count = m * 2 - 1;

    for(i=1; i<=count; i++)
    {
        for(j=1; j<=count; j++)
        {
            if(j==i || (j==count - i + 1))
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
}



//print floyd's traingle
void floydstraingle(int rows){
    int i, j;
    int k = 1;
    for(i=1; i<=rows; ++i)
    {
    for(j=1; j<=i; ++j)
    {
    cout<<k<<"\t";
    ++k;
    }
    cout<<"\n";
    }

}

//print previous sum triangle with n as no of rows
// 0
// 1 1
// 2 3 5
// 8 13 21 34   

void prevSumTriangle(int n)
{
    int k=1, prev=0;
    cout<<"0\n";
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            
            if(i==2 && j==1)
                cout<<"1 ";
            
            else{
                cout<<k+prev<<" ";
                int temp = k;
                k = prev +k;
                prev=temp;
            }     
        }
        cout<<"\n";
    }
}
int main() {

    //diamondpattern();
    //diRec();
    //xpattern(5);
    //floydstraingle(4);
    prevSumTriangle(4);

    return 0;
}