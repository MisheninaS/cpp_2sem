#include <iostream>;

typedef int node_type;

struct StackNode {
    node_type value;
    StackNode* next;
};

struct Stack {
    StackNode* first;
    StackNode* last;
    int len;
};

StackNode* create_node(node_type value) {
    StackNode* node = new StackNode;
    node->value = value;
    return node;
}

Stack* create_empty() {
    Stack* empty_stack = new Stack;
    empty_stack->first = nullptr;
    empty_stack->last = nullptr;
    empty_stack->len = 0;
    return empty_stack;
}

void push(Stack* st, node_type val) {
    StackNode* new_node = create_node(val);
    StackNode* x;
    if (st->len == 0) {
        st->first = new_node;
        st->last = new_node;
        st->len = 1;
    } else {
        st->last->next = new_node;
        st->last = new_node;
        st->len++;
    }
}

void pop(Stack* st) {
    if (st->len == 1) {
        delete st->first;
        st->first = nullptr;
        st->last = nullptr;
        st->len = 0;
        return;
    }
    if (st->len == 0) {
        StackNode* old_element = st->first;
        st->first = old_element->next;
        delete old_element;
        st->len--;
        return;
    }
    StackNode* current = st->first;
    for (int i = 0; i < ((st->len)-2); ++i) {
        current = current->next;
    }
    StackNode* old_element = current->next;
    current->next = old_element->next;
    delete old_element;
    st->len--;
}

void print_stack(Stack* st) {
    StackNode* current = st->first;
    for (int i = 0; i < st->len; ++i) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Stack* st = create_empty();
    node_type x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;
    push(st, x1);
    push(st, x2);
    push(st, x3);
    print_stack(st);
    pop(st);
    print_stack(st);
}
