/*
給定一個字串 s，只將字串中所有的母音（a, e, i, o, u，區分大小寫）順序反轉，其他字元位置不變，並回傳結果字串。
母音包括大寫與小寫（'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'）。
非母音（如子音、符號等）位置不變。

1. 以雙指標方式，從字串頭尾分別尋找母音。
2. 只要左右兩邊都遇到母音，就交換它們。
3. 最後回傳交換後的新字串。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 判斷是否為母音（區分大小寫，轉小寫判斷）
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* reverseVowels(char* s) {
    // 雙指標
    int i = 0;
    int j = strlen(s) - 1;
    
    while(i < j) {
        // 找到左邊第一個母音
        while(i < j && !isVowel(s[i])) i++;
        
        // 找到右邊第一個母音
        while(i<j && !isVowel(s[j])) j--;
        
        // 交換左右母音
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
        i++;
        j--;
    }
    return s;
    }