/*
有兩個非空的 singly-linked list，分別用反向順序（低位數在前）存儲一個非負整數的每一位數字。
請回傳這兩數字相加的結果，也用相同格式（反向儲存）表示，結果用 linked list 回傳。

1. 用一個dummy head輔助指標來簡化操作，避免特判第一個節點。
2. 使用 curr 指標動態生成新節點，把每位數的加總結果存進 linked list。
3. 同時考慮進位，每次運算都加上 carry。
4. l1/l2 若長度不一樣，用 0 補位。
5. 最後若還有進位，也要補一個新節點。
*/

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // 建立一個虛擬頭節點 dummyHead，方便操作
    struct ListNode* dummyHead = malloc(sizeof(struct ListNode));
    dummyHead->val = 0;
    dummyHead->next = NULL;

    // curr 用來追蹤新串列的目前位置
    struct ListNode* curr = dummyHead;

    // 進位值（每一位加總超過 10 就有進位）
    int carry = 0;

    // 只要還有數字要加（l1 或 l2 不是 NULL），或還有進位就繼續
    while (l1 != NULL || l2 != NULL || carry != 0) {

        // 取出當前 l1 和 l2 節點的值，若為 NULL 則當作 0
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;

        // 計算本位加總，並加入進位
        int sum = carry + x + y;
        
        // 更新進位（只要 >= 10 就要進位到下一位）
        carry = sum / 10;

        // 建立新節點，把本位數字存進去（sum % 10）
        curr->next = malloc(sizeof(struct ListNode)); // 分配新節點
        curr->next->val = sum % 10; // 只取本位數字
        curr->next->next = NULL; // 初始化下一個指標為 NULL
        curr = curr->next; // 移動 curr 到新節點

        // l1, l2 分別往下一位移動（若不是 NULL）
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    // 結果的頭節點實際上是 dummyHead->next（dummyHead 只是輔助)
    struct ListNode* result = dummyHead->next;
    free(dummyHead);  // Free the memory allocated for dummyHead
    return result;
}