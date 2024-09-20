#include <iostream>
using namespace std;

int main(){
int arr[8]={-2,-3,4,-1,-2,1,5,-3};
int ans = INT_MIN;
int sum=0;
for(int i=0;i<8;i++){
    if(sum<0)sum=0;
    sum+=arr[i];
    ans=max(sum,ans);
}
cout<<ans;
}