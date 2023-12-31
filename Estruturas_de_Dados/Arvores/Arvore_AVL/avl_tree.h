//! Copyright [2023] <Artur Soda>

#include <algorithm>
#include "array_list.h"

namespace structures {

template<typename T>
class AVLTree {
public:
	AVLTree();

    ~AVLTree();

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    int height() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;



private:
    struct Node {
        explicit Node(const T& data_) {
			data = data_;
			height_ = 0;
			left = nullptr;
			right = nullptr;
		}

        T data;
        int height_;
        Node* left;
        Node* right;


        int height() {
            return height_;
        }
    };

    Node* root_;
    std::size_t size_;

	int getHeight(Node* root) const {
		if (root == nullptr) {
			return -1;
		} else {
			return root->height_;
		}
	}

	int getBalance(Node* root) const {
		if (root == nullptr) {
			return 0;
		} else {
			return (getHeight(root->left) - getHeight(root->right));
		}
	}

	int updateHeight(Node* root) {
		return (1 + std::max(getHeight(root->left), getHeight(root->right)));
	}

	Node* minValue(Node* root) {
		Node* p = root;
		while (p->left != nullptr) {
			p = p->left;
		}
		return p;
	}

	Node* simpleLeft(Node* root) {
		Node* p = root->right;
		root->right = p->left;
		p->left = root;

		root->height_ = updateHeight(root);
		p->height_ = updateHeight(p);

		return p;
	}

	Node* simpleRight(Node* root) {
		Node* p = root->left;
		root->left = p->right;
		p->right = root;

		root->height_ = updateHeight(root);
		p->height_ = updateHeight(p);

		return p;
	}

	Node* doubleLeft(Node* root) {
		root->right = simpleRight(root->right);
		return simpleLeft(root);
	}

	Node* doubleRight(Node* root) {
		root->left = simpleLeft(root->left);
		return simpleRight(root);
	}


	Node* insert_aux(const T& data, Node* root) {
		if (root == nullptr) {
			Node* p = new Node(data);
			return p;
		}

		if (data < root->data) {
			root->left = insert_aux(data, root->left);
		} else if (data > root->data) {
			root->right = insert_aux(data, root->right);
		} else {
			return root;
		}

		root->height_ = updateHeight(root);
		int balance = getBalance(root);

		if (balance > 1) {
			if (data < root->left->data) {
				return simpleRight(root);

			} else if (data > root->left->data) {
				return doubleRight(root);
			}
		} else if (balance < -1) {
			if (data > root->right->data) {
				return simpleLeft(root);
			} else if (data < root->right->data) {
				return doubleLeft(root);
			}
		}
		return root;
	}

	Node* remove_aux(const T& data, Node* root) {
		if (root == nullptr) {
			return root;
		}

		if (data < root->data) {
			root->left = remove_aux(data, root->left);
		} else if (data > root->data) {
			root->right = remove_aux(data, root->right);

		} else {
			if ((root->left == nullptr) && (root->right == nullptr)) {
				delete root;
				root = nullptr;
			} else if (root->left == nullptr) {
				Node* temp = root;
				root = root->right;
				delete temp;
			} else if (root->right == nullptr) {
				Node* temp = root;
				root = root->left;
				delete temp;
			} else {
				Node* temp = minValue(root->right);
				root->data = temp->data;
				root->right = remove_aux(temp->data, root->right);
			}
		}

		if (root == nullptr)
			return root;

		root->height_ = updateHeight(root);
		int balance = getBalance(root);

		if (balance > 1) {
			if (getBalance(root->left) >= 0) {
				return simpleRight(root);
			} else {
				return doubleRight(root);
			}
		}
		if (balance < -1) {
			if (getBalance(root->right) <= 0) {
				return simpleLeft(root);
			} else {
				return doubleLeft(root);
			}
		}
		return root;
	}

	bool contains_aux(const T& data, Node* root) const {
		if (root == nullptr) {
			return false;
		} else if (data == root->data) {
			return true;
		} else if (data < root->data) {
			return contains_aux(data, root->left);
		} else {
			return contains_aux(data, root->right);
		}
	}

	void pre_order_aux(ArrayList<T>& list, Node* root) const {
		if (root == nullptr) {
			return;
		}
		list.push_back(root->data);
		this->pre_order_aux(list, root->left);
		this->pre_order_aux(list, root->right);
	}

	void in_order_aux(ArrayList<T>& list, Node* root) const {
		if (root == nullptr) {
			return;
		}
		this->in_order_aux(list, root->left);
		list.push_back(root->data);
		this->in_order_aux(list, root->right);
	}

	void post_order_aux(ArrayList<T>& list, Node* root) const {
		if (root == nullptr) {
			return;
		}
		this->post_order_aux(list, root->left);
		this->post_order_aux(list, root->right);
		list.push_back(root->data);
	}
};

}  //  namespace structures

// -----

template<typename T>
int structures::AVLTree<T>::height() const {
	return getHeight(root_);
}

template<typename T>
structures::AVLTree<T>::AVLTree() {
	root_ = nullptr;
	size_ = 0;
}

template<typename T>
structures::AVLTree<T>::~AVLTree() {
	while (!this->empty()) {
		this->remove(root_->data);
	}
}

template<typename T>
void structures::AVLTree<T>::insert(const T& data) {
	if (!this->contains(data)) {
		root_ = this->insert_aux(data, root_);
		size_++;
	}
}

template<typename T>
void structures::AVLTree<T>::remove(const T& data) {
	if (this->contains(data)) {
		root_ = this->remove_aux(data, root_);
		size_--;
	}
}

template<typename T>
bool structures::AVLTree<T>::contains(const T& data) const {
	return this->contains_aux(data, root_);
}

template<typename T>
bool structures::AVLTree<T>::empty() const {
	return (size_ == 0);
}

template<typename T>
std::size_t structures::AVLTree<T>::size() const {
	return size_;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::pre_order() const {
	ArrayList<T> list;
	this->pre_order_aux(list, root_);
	return list;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::in_order() const {
	ArrayList<T> list;
	this->in_order_aux(list, root_);
	return list;
}

template<typename T>
structures::ArrayList<T> structures::AVLTree<T>::post_order() const {
	ArrayList<T> list;
	this->post_order_aux(list, root_);
	return list;
}
