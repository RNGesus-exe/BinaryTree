#include"BinaryTree.h"

int main(){
    BinaryTree tree;
    tree.createBinaryTree();
    tree.printPreOrder(tree.getRoot());
    std::cout<<std::endl;
    tree.printPostOrder(tree.getRoot());
    std::cout<<std::endl;
    tree.printInOrder(tree.getRoot());
    std::cout<<std::endl;
    tree.print();
    return 0;
}