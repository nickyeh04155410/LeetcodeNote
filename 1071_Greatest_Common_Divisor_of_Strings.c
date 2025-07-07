/*
給定兩個只含大寫英文的字串 str1 和 str2，
請找出最長的字串 x，使得 x 可以重複拼接組成 str1 並且也能組成 str2。
如果不存在，回傳空字串。

只有當 str1 和 str2 都是由同一個 pattern 連續拼接而成時，才有答案。
這個 pattern 的長度必須同時整除 str1.length 和 str2.length，也就是它們長度的最大公因數（GCD）。
用 str1 + str2 是否等於 str2 + str1 來檢查有沒有這個 pattern。
若有，取 str1 前 最大公因數個字元即為答案。
*/



// 輾轉相除法計算最大公因數
int gcd(int a, int b) {
    while (b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

char *gcdOfStrings(char *str1, char *str2) {
    // 得到string長度
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // 建立字串緩衝區，str1、str2 兩者最大為1000
    char s1s2[2005], s2s1[2005];

    // 先把 str1 複製到 s1s2 裡
    strcpy(s1s2, str1);

    // 接著把 str2 接到 s1s2 後面，建立str1 + str2
    strcat(s1s2, str2);

    // 如同上述操作
    strcpy(s2s1, str2);
    strcat(s2s1, str1);

    /* 比較兩個字串是否完全相同
       如果不相同（!= 0），代表 str1 和 str2 沒有共同的 pattern，
       這時候就配置一個空的字串（只含有 '\0'），並且回傳，表示沒有答案。
       假設 str1 和 str2 都是由同一個 pattern 重複構成，
       那麼 str1 + str2 和 str2 + str1 拼起來應該會一模一樣，
       如果不一樣，代表兩個字串不是由同一個 pattern 重複構成。 
    */
    if (strcmp(s1s2, s2s1) != 0) {
        char *empty = calloc(1, sizeof(char));
        return empty;
    }
    
    // 這裡計算 str1 和 str2 長度的最大公因數
    int len = gcd(len1, len2);

    // 分配動態記憶體
    char *ans = calloc(len + 1, sizeof(char));
    // 複製str1 前 len 個字元，也就是最大pattern
    strncpy(ans, str1, len);
    ans[len] = '\0';
    return ans;
}