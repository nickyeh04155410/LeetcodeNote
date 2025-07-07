/*
給定一個整數陣列 candies，candies[i] 表示第 i 個小孩手上的糖果數，還有一個整數 extraCandies，你可以把這些糖果全部給某一個小孩。
請你判斷，對於每個小孩，如果把所有 extraCandies 都給他，他會不會成為糖果最多的小孩（可以是並列最多）。
請回傳一個布林陣列，result[i] 代表第 i 個小孩在獲得 extraCandies 後是否達到最大值。

1. 先找出目前所有小孩手上的最大糖果數（max）。
2. 對每一個小孩，判斷 candies[i] + extraCandies 是否大於等於 max。
3. 回傳結果陣列（每個元素 true/false）。


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    // 找出所有小孩的最大糖果數
    int max = 0;

    for (int i = 0; i < candiesSize; i++) {
        if (max < candies[i])
            max = candies[i];
    }

    // 分配記憶體給回傳陣列
    bool* result = malloc(sizeof(bool) * candiesSize);

    // 檢查每個小孩加上 extraCandies 是否 >= max
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max)
            result[i] = true;
        else
            result[i] = false;
    }

    // 告訴呼叫者這個陣列的長度
    *returnSize = candiesSize;
    return result;
}