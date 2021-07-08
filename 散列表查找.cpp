#include <iostream>
using namespace std;

#define MAX 1000

typedef struct node {
    int key;         //关键字域
    node* next;      //指针域
} node, *link;

int p;              //除留余数法的p值
node hashtab[MAX];  //结点数组，用于存放每个单链表的头指针地址

void get_prime(int n) {
    bool find_prime = false;
    for (int i = n; i >= 2; i--) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) break;
            else if (j == i - 1) {
                find_prime = true;
                p = i;    //更新p值
                break;
            }
        }
        if (find_prime) break;
    }
}


int h(int key) {
    return key % p;
}

void create_list(int key) {  // Construct hash table
    link temp, n;
    int index;
    n = new node;
    n->key = key;
    n->next = NULL;
    index = h(key);

    // 头插法，需要改成尾插法
    //temp = hashtab[index].next;
    //if (temp != NULL) {
    //    n->next = temp;
    //    hashtab[index].next = n;
    //} else {
    //    hashtab[index].next = n;
    //}

    // 尾插法
    temp = hashtab[index].next;
    if (!temp) {
        hashtab[index].next = n;
        return;
    }
    while (temp -> next)
        temp = temp -> next;
    temp -> next = n;
}

int hash_search(int key) {  // Hash lookup function
    link pointer;
    int index;

    index = h(key);
    pointer = hashtab[index].next;

    cout << "开始搜索哈希表[" << index << "]：";

    while (pointer != NULL) {
        cout << pointer -> key << " ";
        if (pointer->key == key) {
            cout << "【查找成功】" << endl;
            return 1;
        }
        else
            pointer = pointer->next;
    }
    cout << "NULL 【查找失败】" << endl;
    return 0;
}

int main() {

    // 用户输入元素
    int n;
    cout << "请输入元素个数：";
    cin >> n;
    int data[n];
    get_prime(n);   // 决定除留余数法的p值
    cout << "请输入元素：";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    // 构建散列表
    for (int index = 0; index < n; index++) {
        create_list(data[index]);
    }

    // 输出散列表
    for (int i = 0; i < p; i++) {
        cout << "散列表[" << i << "]：";
        link temp = hashtab[i].next;

        while (temp != NULL) {
            cout << temp -> key << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // 散列表查找
    int key;
    cout << "请输入要查找的值：";
    cin >> key;
    hash_search(key);

    return 0;
}
