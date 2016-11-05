/*input
2
na
banananobano
6
foobar
foo
9
foobarfoo
barfoobarfoobarfoobarfoobarfoo
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void knuth_morrish_prat(string a,string b,vector<int> F)
{
  int i = 0;
  int j = 0;
  int m = a.size();
  int n = b.size();
  for( ; ; )
  {  if(j==n) break;
    
     if(a[i]==b[j])
     {
     	i++;
     	j++;
     	if(i==m) { cout<<j-i<<endl; }
     }
     else if(i>0) { i = F[i]; }
     else j++;


  }
  // cout<<"\n";
}
void build_failure_function(string a,string b)
{
   int m = a.size();
   vector <int> F(m+1);
   F[0]=F[1]=0;
   int j;
   for(int i=2;i<=m;i++)
   { 
   	 j = F[i-1];

   	 for( ; ;)
   	 {
   	 	if(a[j]==a[i-1])
   	 	{
   	 		F[i] = j+1;
   	 		break;
   	 	}

   	 	j = F[j];

   	 	if(j==0) { F[i]=0 ; break; }

   	 }

   }
    knuth_morrish_prat(a,b,F);
 /*  for(int i=1;i<=m;i++)
   {
   	cout<<F[i];
   }
   */
}
int main()
{ 
	 int n;
	 string a,b;
	 while(cin>>n>>a>>b)
	 {
	 	build_failure_function(a,b);
	 	cout<<"\n";

	 }



	return 0;
}
