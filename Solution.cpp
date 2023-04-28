#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> leftProfit(n, 0);
        vector<int> rightProfit(n, 0);
        
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            leftProfit[i] = max(leftProfit[i-1], prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightProfit[i] = max(rightProfit[i+1], maxPrice-prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }
        
        return maxProfit;
    }
};
// Time Complexity O(n);
// Space Complexity O(n);
// int main() {
//     Solution solution;
   
//     vector<int> prices_month1 = {3,3,5,0,0,3,1,4};
//     /* Answer : 6 */
//   cout << solution.maxProfit(prices_month1) << endl;

//     vector<int> prices_month2 = {1,2,3,4,5};
//     /* Answer : 4 */
//     cout << solution.maxProfit(prices_month2) << endl;

//     vector<int> prices_month3 = {7,6,4,3,1};
//     /* Answer : 0 */
//     cout << solution.maxProfit(prices_month3) << endl;

//     return 0;
// }


// /*Dynamic input from the main funtion*/
int main(){
  Solution solution;
    int n,x;   // if the prices in 1.8 rs or dollar we can represent it with float 
    cout<<"Enter the size of stock array"<<endl;
    cin>>n;
    vector<int> prices(n,0);
    for (int i=0;i<n;i++){
        cin>>x;
        prices.push_back(x);
    }
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}
