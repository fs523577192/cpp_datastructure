#ifndef H_BinaryTree
#define H_BinaryTree

#include "Tree.hpp"

namespace NS_DataStructure {

    template<typename E> M_declare_interface_with_base(BinaryTree, Tree<E>)

        protected: template<typename T> M_declare_interface(BinaryTreeNodeBase)

            M_interface_method T* getLeft() M_end_interface_method
            M_interface_method void setLeft(T* p_left) M_end_interface_method

            M_interface_method T* getRight() M_end_interface_method
            M_interface_method void setRight(T* p_right) M_end_interface_method

            M_interface_method E getElement() M_end_interface_method
            M_interface_method void setElement(E element) M_end_interface_method

        M_end_interface

        protected: M_declare_interface_with_base(BinaryTreeNode, BinaryTreeNodeBase<BinaryTreeNode>)

        M_end_interface

        protected: class DefaultBinaryTreeNode: M_implements BinaryTreeNode {

            public: DefaultBinaryTreeNode(E element) {
                setElement(element);
            }

            public: BinaryTreeNode* getLeft() {
                return p_left;
            }
            public: void setLeft(BinaryTreeNode* p_left) {
                this->p_left = p_left;
            }

            public: BinaryTreeNode* getRight() {
                return p_right;
            }
            public: void setRight(BinaryTreeNode* p_right) {
                this->p_right = p_right;
            }

            public: E getElement() {
                return element;
            }
            public: void setElement(E element) {
                this->element = element;
            }

            private: BinaryTreeNode* p_left = nullptr;
            private: BinaryTreeNode* p_right = nullptr;
            private: E element;
        };

        protected: M_declare_interface_with_base(BinaryTreeNodeWithParent, BinaryTreeNodeBase<BinaryTreeNodeWithParent>)

            M_interface_method BinaryTreeNodeWithParent* getParent() M_end_interface_method
            M_interface_method void setParent(BinaryTreeNodeWithParent* p_parent) M_end_interface_method

        M_end_interface

        protected: class DefaultBinaryTreeNodeWithParent: M_implements BinaryTreeNodeWithParent {

            public: DefaultBinaryTreeNodeWithParent(E element) {
                setElement(element);
            }

            public: BinaryTreeNodeWithParent* getLeft() {
                return p_left;
            }
            public: void setLeft(BinaryTreeNodeWithParent* p_left) {
                this->p_left = p_left;
            }

            public: BinaryTreeNodeWithParent* getRight() {
                return p_right;
            }
            public: void setRight(BinaryTreeNodeWithParent* p_right) {
                this->p_right = p_right;
            }

            public: BinaryTreeNodeWithParent* getParent() {
                return p_parent;
            }
            public: void setParent(BinaryTreeNodeWithParent* p_parent) {
                this->p_parent = p_parent;
            }

            public: E getElement() {
                return element;
            }
            public: void setElement(E element) {
                this->element = element;
            }

            private: BinaryTreeNodeWithParent* p_left = nullptr;
            private: BinaryTreeNodeWithParent* p_right = nullptr;
            private: BinaryTreeNodeWithParent* p_parent = nullptr;
            private: E element;
        };

    M_end_interface
};

#endif // H_BinaryTree
