//
// Created by rngesus on 12/24/20.
//

#ifndef MYWORK_BINARYTREE_H
#define MYWORK_BINARYTREE_H

#include<iostream>

class Node{
    Node* leftChild;
    int data;
    Node* rightChild;
public:

    Node(){
        leftChild = rightChild = nullptr;
        data = NULL;
    }

    Node(int data){
        this->data = data;
        leftChild = rightChild = nullptr;
    }

    Node *getLeftChild() const {
        return leftChild;
    }

    void setLeftChild(Node *leftChild) {
        Node::leftChild = leftChild;
    }

    int getData() const {
        return data;
    }

    void setData(int data) {
        Node::data = data;
    }

    Node *getRightChild() const {
        return rightChild;
    }

    void setRightChild(Node *rightChild) {
        Node::rightChild = rightChild;
    }
};

class Queue {
    class QNode{
    public:
        Node* data;
        QNode* next;

        QNode(Node* data){
            this->data = data;
            next = nullptr;
        }
    }*front,*rear;
public:
    Queue(){
        front = rear = nullptr;
    }
    Queue(Node* data){
        this->front = this->rear = new QNode(data);
    }
    void enqueue(Node* data){
        QNode* temp = new QNode(data);
        if(!front) {
            this->front = this->rear = temp;
        }
        else{
            this->rear->next = temp;
            this->rear = temp;
        }
        temp = nullptr;
    }
    Node* dequeue(){
        if(!isEmpty()){
            QNode* holder = this->front;
            Node* temp = this->front->data;
            this->front = this->front->next;
            delete holder;
            return temp;
        }
        else{
            static_assert(1,"YOU CANNOT DEQUEUE AS THE QUEUE IS EMPTY!!!");
        }
    }
    bool isEmpty(){
        return !front;
    }
    ~Queue(){
        while(front){
            this->dequeue();
        }
        front = rear = nullptr;
    }

};

class BinaryTree : protected Node{
    Node* root;
    Queue queue;
public:
    Node* getRoot(){
        return this->root;
    }
    BinaryTree(){
        root = nullptr;
    }
    void createBinaryTree(){
        int temp;
        std::cout<<"Enter the root data = ";
        std::cin>>temp;
        this->root = new Node(temp);
        queue.enqueue(this->root);
        Node* holder;
        while(!queue.isEmpty()){
            holder = queue.dequeue();
            std::cout<<"Enter left of "<<holder->getData()<<" = ";
            std::cin>>temp;
            if(temp!=-1){
                holder->setLeftChild(new Node(temp));
                queue.enqueue(holder->getLeftChild());
            }
            std::cout<<"Enter Right of "<<holder->getData()<<" = ";
            std::cin>>temp;
            if(temp!=-1){
                holder->setRightChild(new Node(temp));
                queue.enqueue(holder->getRightChild());
            }
        }
    }
    void print(){
        Node* holder = nullptr;
        queue.enqueue(this->root);
        while(!queue.isEmpty()){
            holder = queue.dequeue();
            std::cout<<holder->getData()<<",";
            if(holder->getLeftChild()){
                queue.enqueue(holder->getLeftChild());
            }
            if(holder->getRightChild()){
                queue.enqueue(holder->getRightChild());
            }
        }
    }

    /*
     *  Pre = N L R
     *  Post = L R N
     *  In = L N R
     */

    void printPreOrder(Node* node){
        if(node){
            // N
            std::cout<<node->getData()<<",";
            // L
            this->printPreOrder(node->getLeftChild());
            // R
            this->printPreOrder(node->getRightChild());
        }
    }

    void printPostOrder(Node* node){
        if(node){
            // L
            this->printPostOrder(node->getLeftChild());
            // R
            this->printPostOrder(node->getRightChild());
            // N
            std::cout<<node->getData()<<",";
        }
    }

    void printInOrder(Node* node){
        if(node){
            // L
            this->printInOrder(node->getLeftChild());
            // N
            std::cout<<node->getData()<<",";
            // R
            this->printInOrder(node->getRightChild());
        }
    }
    ~BinaryTree(){
        Node* holder = nullptr;
        queue.enqueue(this->root);
        while(!queue.isEmpty()){
            holder = queue.dequeue();
            if(holder->getLeftChild()){
                queue.enqueue(holder->getLeftChild());
            }
            if(holder->getRightChild()){
                queue.enqueue(holder->getRightChild());
            }
            delete holder;
        }
    }

};
#endif //MYWORK_BINARYTREE_H
