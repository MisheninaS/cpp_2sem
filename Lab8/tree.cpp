#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

struct Tree {
    TreeNode* root;
    int len;
};

TreeNode* create_node(int value) {
    TreeNode* node = new TreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    node->parent = nullptr;
    return node;
}

Tree* create_empty() {
    Tree* tree = new Tree;
    tree->root = nullptr;
    tree->len = 0;
    return tree;
}

Tree* create_empty(int val) {
    Tree* empty_tree = new Tree;
    empty_tree->root = create_node(val);
    empty_tree->len = 1;
    return empty_tree;
}

void add_value(Tree* tree, int val) {
    tree->len++;
    TreeNode* new_node = create_node(val);
    if (tree->root == nullptr) {
        tree->root = new_node;
        return;
    }
    TreeNode* current = tree->root;
    while (true) {
        if (val > current->value) {
            if (current->right != nullptr) {
                current = current->right;
            } else {
                current->right = new_node;
                current->right->parent = current;
                break;
            }
        } else {
            if (current->left != nullptr) {
                current = current->left;
            } else {
                current->left = new_node;
                current->left->parent = current;
                break;
            }
        }
    }
}

TreeNode* find_value(Tree* tree, int val) {
    TreeNode* current = tree->root;
    while (current->value != val) {
        if (current->value < val) {
            if (current->right != nullptr) {
                current = current->right;
            } else {
                return nullptr;
            }
        } else if (current->value > val) {
            if (current->left != nullptr) {
                current = current->left;
            } else {
                return nullptr;
            }
        }
    }
    return current;
}

TreeNode* find_biggest(TreeNode* node) {
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

TreeNode* find_smallest(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void remove_by_value(Tree* tree, int value) {
    TreeNode* node_to_delete = find_value(tree, value);
    if (node_to_delete == nullptr) {
        return;
    }
    TreeNode* left = node_to_delete->left;
    TreeNode* right = node_to_delete->right;
    TreeNode* parent = node_to_delete->parent;
    delete node_to_delete;
    if (parent == nullptr) {
        if (left != nullptr) {
            tree->root = left;
            find_biggest(left)->right = right;
        } else if (right != nullptr) {
            tree->root = right;
            find_smallest(right)->left = left;
        } else {
            tree->root = nullptr;
        }
    } else if (node_to_delete == parent->left) {
         if (left != nullptr) {
            parent->left = left;
            find_biggest(left)->right = right;
        } else if (right != nullptr) {
            parent->left = right;
            find_smallest(right)->left = left;
        } else {
            parent->left = nullptr;
        }
    } else if (node_to_delete == parent->right) {
         if (left != nullptr) {
            parent->right = left;
            find_biggest(left)->right = right;
        } else if (right != nullptr) {
            parent->right = right;
            find_smallest(right)->left = left;
        } else {
            parent->right = nullptr;
        }
    }

}

void pre_order(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << " ";
    pre_order(node->right);
    pre_order(node->left);
}

void pre_order_tree(Tree* tree) {
    pre_order(tree->root);
}

void inf_order(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    inf_order(node->left);
    std::cout << node->value << " ";
    inf_order(node->right);
}

void inf_order_tree(Tree* tree) {
    inf_order(tree->root);
}

void post_order(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    post_order(node->left);
    post_order(node->right);
    std::cout << node->value << " ";
}

void post_order_tree(Tree* tree) {
    post_order(tree->root);
}

void find_all_leaves(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    find_all_leaves(node->left);
    if ((node->left == nullptr) && (node->right == nullptr)) {
        std::cout << node->value << " ";
    }
    find_all_leaves(node->right);
}

void find_all_leaves_tree(Tree* tree) {
    find_all_leaves(tree->root);
}

void print_node(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << "node: " << node << ", value = " << node->value << "\n\tleft:   " << node->left << "\n\tright:  " << node->right << "\n\tparent: " << node->parent << "\n";
    print_node(node->left);
    print_node(node->right);
}

void print_tree(Tree* tree) {
    print_node(tree->root);
}

int main() {}
