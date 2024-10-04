#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    int arr[5] = {1, 0, 1, 0, 1};
    int tar = 2;

    // Brute-force approach
    int count = 0;
    for(int i = 0; i < 5; i++) {
        int temp = 0;
        for(int j = i; j < 5; j++) {
            temp += arr[j];
            if(temp == tar) {
                count++;
            }
        }
    }
    cout << "Brute-force count: " << count << endl;

    // Optimized approach using prefix sums and hash map
    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    count = 0;

    for(int i = 0; i < 5; i++) {
        prefixSum += arr[i];

        // Check if current prefix sum equals the target
        if(prefixSum == tar) {
            count++;
        }

        // Check if there exists a prefix sum that when removed gives us `tar`
        if(prefixSumCount.find(prefixSum - tar) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - tar];
        }

        // Store the current prefix sum in the map
        prefixSumCount[prefixSum]++;
    }

    cout << "Optimized count: " << count << endl;

    return 0;
}
