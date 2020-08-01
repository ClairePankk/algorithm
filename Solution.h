//
// Created by 潘俊佳 on 2020/8/1.
//

#ifndef INC_632__SOLUTION_H
#define INC_632__SOLUTION_H
#include <queue>
#include <vector>
#include <math.h>
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int RangeLeft = 0, RangeRight = INT_MAX; //定义返回向量左右界限
        int size = nums.size();
        vector<int> next(size);//int为数据类型的vector初始化的值都是0

        //定义piority_queue 优先权的意义是，当前元素在数组中的值在原始二维vector中是升序，在队列中也是升序
        auto cmp = [&](const int& u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

       int minValue=0,maxValue=INT_MIN;
       // 划重点！！！！maxValue必须定义成INT_MIN，因为目的是找到nums[i][0]中的最大值，所以maxValue的初始值一定要小
        for (int i=0;i<size;++i){
            maxValue=max(maxValue,nums[i][0]);
            pq.emplace(i);
        }
        while (true){
            int row=pq.top();
            pq.pop();
            minValue=nums[row][next[row]];
            if(maxValue-minValue<RangeRight-RangeLeft){
                RangeLeft=minValue;
                RangeRight=maxValue;
                //更新左右界限
            }
            if(next[row]==nums[row].size()-1){
                break;
                //如果对于某一行数组，next[row]指向最后一个元素，该数组已经遍历完了，再继续下去将不符合题目要求：k个列表中的每个列表至少有一个数包含在其中
            }
            ++next[row];
            maxValue=max(maxValue,nums[row][next[row]]);
            pq.emplace(row);
        }
        return {RangeLeft,RangeRight};  //返回解向量
    }
};




#endif //INC_632__SOLUTION_H
