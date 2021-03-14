#include <iostream>;

typedef int node_type;

struct QueueNode {
    node_type value;
    QueueNode* next;
};

struct Queue {
    QueueNode* first;
    QueueNode* last;
    int len;
};

QueueNode* create_node(node_type value) {
    QueueNode* node = new QueueNode;
    node->value = value;
    return node;
}

Queue* create_empty() {
    Queue* empty_queue = new Queue;
    empty_queue->first = nullptr;
    empty_queue->last = nullptr;
    empty_queue->len = 0;
    return empty_queue;
}

void enqueue(Queue* qu, node_type val) {
    QueueNode* new_node = create_node(val);
    if (qu->len == 0) {
        qu->first = new_node;
        qu->last = new_node;
        qu->len = 1;
    } else {
        qu->last->next = new_node;
        qu->last = new_node;
        qu->len++;
    }
}

void dequeue(Queue* qu) {
    if (qu->len < 2) {
        delete qu->first;
        qu->first = nullptr;
        qu->last = nullptr;
        qu->len = 0;
        return;
    } else {
        QueueNode* old_element = qu->first;
        qu->first = old_element->next;
        delete old_element;
        qu->len--;
        return;
    }
}

void print_queue(Queue* qu) {
    QueueNode* current = qu->first;
    for (int i = 0; i < qu->len; ++i) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Queue* qu = create_empty();
    node_type x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;
    enqueue(qu, x1);
    enqueue(qu, x2);
    enqueue(qu, x3);
    print_queue(qu);
    dequeue(qu);
    print_queue(qu);
    dequeue(qu);
    print_queue(qu);
}
