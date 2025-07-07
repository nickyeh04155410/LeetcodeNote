/*
給定兩個字串 word1 和 word2，請交錯地合併這兩個字串，也就是：
先取 word1 的第一個字元，再取 word2 的第一個字元，
再取 word1 的第二個字元，再取 word2 的第二個字元，
依此類推，直到其中一個字串的所有字元都取完。
如果有任何一個字串還有剩下的字元，就把這些字元直接加到結果字串的最後面。

1. 先分別取得兩個字串的長度。
2. 分配一塊新的記憶體，能存下兩個字串合併後的內容（加上結尾的 '\0'）。
3. 用一個迴圈同時從兩個字串各取一個字元，交錯寫入新字串。
4. 如果有任何一個字串還沒取完，就用另一個迴圈將剩下的字元寫入新字串的尾端。
5. 加上字串結尾符號 '\0'。
6. 回傳新合併的字串。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    // 取得兩字串長度
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int result_size = len1 + len2;

    // 分配一塊足夠的記憶體 (合併長度+1)
    char* result = malloc((result_size + 1) * sizeof(char));
    if (!result) return NULL;

    // i 用於遍歷 word1 和 word2；k 用於 result 字串
    int i = 0, k = 0;
    while(i < len1 && i < len2){
        result[k++] = word1[i]; // 取 word1 的第 i 個字元
        result[k++] = word2[i]; // 取 word2 的第 i 個字元
        i++;
    }

    // 如果 word1 或 word2 還沒取完，把剩下的字元都加到 result
    while (i < len1) result[k++] = word1[i++];
    while (i < len2) result[k++] = word2[i++];
    result[k] = '\0';
    return result; // 回傳新字串
}