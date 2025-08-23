
/* Problem : Given a string and a number of lines, print the string in a zigzag form. In zigzag, characters are printed out diagonally from top left to bottom right until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

               t     a     g
                h   s z   a
                 i i   i z
                  s     g
 */
#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
void solve()
{
    string s;cin>>s;
    int k;cin>>k;
    int n=s.size();
    vector<vector<char>>zigzag(k,vector<char>(n,' '));
    int row=0;
    bool des=true;
    for(int i=0; i<n; i++)
    {
        zigzag[row][i]=s[i];
        if(row==k-1)
            des=false;
        else if(row==0)
            des=true;
        if(des)
            row++;
        else
            row--;
    }
    for(int i=0; i<k; i++)
    {
        for(int p=0; p<n; p++)
            cout<<zigzag[i][p];
        cout<<endl;
    }

}
int32_t main()
{
    fio;
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T = 1;
    //cin >> T;
    for (int __ = 1; __ <= T; __++)
    {
        // cout << "Case " << __ << ": ";
        solve();
    }
    return 0;
}
