#include <iostream>
#include <climits>

using namespace std;

int main(){
    int arr[5]={2,5,1,7,10};
    int l=0;
    int r=0;
    int maxlen=0;
    int target=14;
    int sum=0;
    while(r<5){
        sum+=arr[r];
        if(sum<=target){
            maxlen=max(maxlen,r-l+1);
        }
        while(sum>target){
            sum-=arr[l];
            l++;
        }
        r++;
    }
    cout<<maxlen<<endl;
}