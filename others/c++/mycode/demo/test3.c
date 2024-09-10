#include<stdio.h>
#define MAXLENGTH 100//字符串的最大长度为100


int findSubstring(const char *s1, const char *s2) {
    int s1_len = 0;
    int s2_len = 0;
    int i, j;

    // 统计字符串长度
    while (s1[s1_len] != '\0') {
        s1_len++;
    }

    while (s2[s2_len] != '\0') {
        s2_len++;
    }

    for (i = 0; i <= s1_len - s2_len; ) {
        j = 0;

        while (j < s2_len && s1[i + j] == s2[j]) {
            j++;
        }

        if (j == s2_len) {
            // 匹配成功
            return i;
        } else {
            // 否则，移动i到下一个比较的位置
            i++;
        }
    }
    return -1; // 匹配失败
}

int main() {
    char s1[MAXLENGTH];
    char s2[MAXLENGTH];

    //用户输入
    printf("请输入主串（最大长度为100）: ");
    scanf("%s", s1);
    printf("请输入需要搜索的子串（最大长度为100）: ");
    scanf("%s", s2);
    
    //匹配 
    int res=findSubstring(s1, s2);

    //对结果进行判断
    if (res != -1) {
        printf("搜索成功，起始位置：%d\n", res);
    } else {
        printf("搜索失败\n");
    }

    return 0;
}