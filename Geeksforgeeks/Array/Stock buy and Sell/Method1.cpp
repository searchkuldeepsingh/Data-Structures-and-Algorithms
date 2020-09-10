// Program to find best buying and selling days

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[],int start,int end) {
  
  if(start<=end)
  return 0;
  
  int profit = 0;
  for(int i=start;i<end;i++) {
    for(int j=i+1;j<=end;j++) {
      if(price[j]>price[i]) {
        int currentProfit = ((price[j]-price[i])+ maxProfit(price,start,i-1) + maxProfit(price,j+1,end));
        profit = max(profit,currentProfit);
      }
    }
  }
  return profit;
}
 
int main() {
  
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++) {
      cin>>a[i];
    }
    
    cout<<maxProfit(a,0,n)<<endl;
  }
}
