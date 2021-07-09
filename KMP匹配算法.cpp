#include <vector>
#include <iostream>

using namespace std;

vector<int> get_next(string pattern) {
    int pattern_length = pattern.length();
    vector<int> next(pattern_length + 1);
    next[0] = -1;
    int j = -1;

    for (int i = 0; i < pattern_length; i++) {
        while (j != -1 && pattern[j] != pattern[i]) {
            j = next[j];
        }
        j++;
        next[i + 1] = j;
    }
    return next;
}

void kmp(string pattern, string text) {
    int text_length = text.length(), pattern_length = pattern.length();
    vector<int> next = get_next(pattern);

    int j = 0;  // 子串指针j
    for (int i = 0; i < text_length; i++) {   // 主串指针i
        while (j != -1 && pattern[j] != text[i]) {
            j = next[j];    // 回退
        }
        j++;
        if (j == pattern_length) {
            cout << "匹配成功，匹配下标为" << i - j + 1 << endl;
            return;
        }
    }
    cout << "匹配失败" << endl;
}

int main() {
    // 用户输入
    string text;
    string pattern;
    cout << "请输入主串text：";
    cin >> text;
    cout << "请输入子串pattern：";
    cin >> pattern;

    // 匹配字符串
    kmp(pattern, text);

    return 0;
}