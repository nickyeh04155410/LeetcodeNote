/*
給定一個整數陣列 flowerbed，裡面只有 0（未種）和 1（已種），
一個整數 n，代表想再種 n 朵花。
花不能種在相鄰的位置（也就是連續的 1 不允許）。

1. 遍歷陣列
    檢查每一格是否可以種花。
    若能種，則種一朵（將該格設為 1），並 n--。
    若 n==0，提前回傳 true。

2. 檢查能否種花的條件
    目前這一格要是 0。
    左邊（若存在）和右邊（若存在）都要是 0。
    邊界視為 0，不會種到外面。

3. 遍歷結束後
    檢查 n 是否已經小於等於 0，若是則 true，否則 false。

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for (int i = 0; i < flowerbedSize; i++) {
        // 檢查當前、左側、右側是否都為 0（邊界視為 0）
        if (flowerbed[i]==0){

            /* 
            三元運算子(ternary operator)， if … else … 的精簡版
            條件式 ? 條件式為true時執行的陳述句 : 條件式為false時執行的陳述句
            int left = (i == 0) ? 0 : flowerbed[i - 1]; 
            ==
            int left;
            if (i == 0){
                left = 0;            
            } else{
                left = flowerbed[i - 1];
            }
            */
            int left = (i == 0) ? 0 : flowerbed[i - 1]; 
            int right = (i == flowerbedSize - 1) ? 0 : flowerbed[i + 1];

            // 若左右皆為 0 ，則種花
            if (left == 0 && right ==0){
                flowerbed[i] = 1;
                n--;
                if (n == 0) return true; // 若花已種夠，return true
            }
        }
    }
    return n <= 0;
}