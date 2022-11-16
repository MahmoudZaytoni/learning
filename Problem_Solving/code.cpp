#include <iostream>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while (t--) {
      int n;
      cin>>n;
      cout << "\n" << n << " ";
      if(n%4==0||n%7==0||n%47==0||n%74==0||n%477==0)
          cout<<"YES"<<endl;
      else
          cout<<"NO"<<endl;

    }
    return 0;
}