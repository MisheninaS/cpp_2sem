#include <iostream>;

typedef int node_type;

struct ListNode{
    node_type value;
    ListNode* next;
};

struct List {
    ListNode* first;
    ListNode* last;
    int len;
};

ListNode* create_node(node_type value) {
    ListNode* node = new ListNode;
    node->value = value;
    return node;
}

List* create_empty(){
    List* empty_list = new List;
    empty_list->first = nullptr;
    empty_list->last = nullptr;
    empty_list->len = 0;
    return empty_list;
}

void add2end(List* listik, node_type val) {
    ListNode* new_node = create_node(val);
    if (listik->len == 0) {
        listik->first = new_node;
        listik->last = new_node;
        listik->len = 1;
    } else {
        listik->last->next = new_node;
        listik->last = new_node;
        listik->len++;
    }
}

void add2begin(List* listik, node_type val) {
    ListNode* new_node = create_node(val);
    if (listik->len == 0) {
        listik->first = new_node;
        listik->last = new_node;
        listik->len = 1;
    } else {
        new_node->next = listik->first;
        listik->first = new_node;
        listik->len++;
    }
}

void remove_by_value(List* listik, node_type val) {
    if (listik->first->value == val) {
        ListNode* old_element = listik->first;
        listik->first = listik->first->next;
        if (listik->len == 1) {
            listik->last = nullptr;
        }
        listik->len--;
        delete old_element;
    } else {
        ListNode* current = listik->first;
        for (int i = 0; i < listik->len - 1; ++i) {
            if (current->next->value == val) {
                ListNode* old_element = current->next;
                current->next = current->next->next;
                if (i == listik->len - 2) {
                    listik->last = current;
                }
                listik->len--;
                delete old_element;
                break;
            }
        }
    }
}

List* copy_list(List* old_list) {
    List* new_list = create_empty();
    if (old_list->len == 0) {
        return new_list;
    }
    new_list->first = create_node(old_list->first->value);
    ListNode* new_current = new_list->first;
    ListNode* old_current = old_list->first->next;
    for (int i = 0; i < old_list->len - 1; ++i) {
        new_current->next = create_node(old_current->value);
        new_current = new_current->next;
        old_current = old_current->next;
    }
    new_list->last = new_current;
    new_list->len = old_list->len;
    return new_list;
}

void print_list(List* listik) {
    ListNode* current = listik->first;
    for (int i = 0; i < listik->len; ++i) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

List* create_reverse(List* old_list) {
    List* new_list = create_empty();
    if (old_list->len == 0) {
        return new_list;
    }
    new_list->last = create_node(old_list->first->value);
    ListNode* new_current = new_list->last;
    ListNode* old_current = old_list->first->next;
    for (int i = 0; i < old_list->len - 1; ++i) {
        ListNode* new_node = create_node(old_current->value);
        new_node->next = new_current;
        new_current = new_node;
        old_current = old_current->next;
    }
    new_list->first = new_current;
    new_list->len = old_list->len;
    return new_list;
}

List* merge_lists(List* list1, List* list2) {
    if (list1->len == 0) {
        return copy_list(list2);
    }
    if (list2->len == 0) {
        return copy_list(list1);
    }
    List* new_list1 = copy_list(list1);
    List* new_list2 = copy_list(list2);
    new_list1->last->next = new_list2->first;
    new_list1->last = new_list2->last;
    new_list1->len += new_list2->len;
    delete new_list2;
    return new_list1;
}

void add_i(List* listik, int index, node_type value) {
    if (index > listik->len || index < 0) {
        std::cout << "wrong index";
    }
    ListNode* new_node = create_node(value);
    if (listik->len == 0) {
        listik->first = new_node;
        listik->last = new_node;
        listik->len = 1;
        return;
    }
    if (index == 0) {
        new_node->next = listik->first;
        listik->first = new_node;
        listik->len++;
        return;
    }
    ListNode* current = listik->first;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    if (index == listik->len) {
        listik->last = new_node;
    }
    listik->len++;
}

void del_i(List* listik, int index) {
    if (index < 0 || index >= listik->len) {
        std::cout << "wrong index";
    }
    if (listik->len == 1) {
        delete listik->first;
        listik->first = nullptr;
        listik->last = nullptr;
        listik->len = 0;
        return;
    }
    if (index == 0) {
        ListNode* old_element = listik->first;
        listik->first = old_element->next;
        delete old_element;
        listik->len--;
        return;
    }
    ListNode* current = listik->first;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    ListNode* old_element = current->next;
    current->next = old_element->next;
    delete old_element;
    listik->len--;
}

int main() {
    List* listik = create_empty();
    node_type x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;
    add2end(listik, x1);
    add2end(listik, x2);
    add2end(listik, x3);
    print_list(listik);
    remove_by_value(listik, 3);
    print_list(listik);
    add_i(listik, 1, 4);
    print_list(listik);
    del_i(listik, 1);
    print_list(listik);
}
