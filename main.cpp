#include <iostream>
using namespace std;
#include "Solution.h"
#include <stdio.h>
#include <vector>
#include <queue>
int main() {
    vector<vector<int>> nums;
    int a[5]={4,10,15,24,26};
    int b[4]={0,9,12,20};
    int c[4]={5,18,22,30};
   vector<int> a1(a,a+5);
   vector<int> b1(b,b+4);
   vector<int> c1(c,c+4);
   nums.push_back(a1);
   nums.push_back(b1);
   nums.push_back(c1);
   for(int i=0;i<3;i++){
       for(int j=0;j<nums[i].size();j++)
           printf("%d  ",nums[i][j]);
       cout<<endl;
   }
    Solution solution;
    vector<int> ans=solution.smallestRange(nums);
    for(vector<int>::iterator it=ans.begin();it!=ans.end();it++)
        cout<<*it<<endl;
        return 0;
}
