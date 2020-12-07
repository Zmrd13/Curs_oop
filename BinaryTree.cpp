//
// Created by egor on 07.12.2020.
//

#include "BinaryTree.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include "TreeNode.h"
#include "BinaryTree.h"

int mod = 50;
extern node *root;
extern RenderWindow window;
using namespace std;
using namespace sf;

void Tree::insert(int data, node *Node, int x , int y ) {
        int a = x + 10;
        int b = y + 35;
        node *new_node = new node;

        new_node->left = new_node->right = new_node->parent = NULL;
        new_node->shape.input(data);
        new_node->shape.move(x, y);

        if (!root) {
            root = new_node;
            return;
        }
        if (data >= Node->shape.output()) {
            if (Node->right)
                insert(data, Node->right, x + mod, y + mod);
            else {
                Node->right = new_node;
                new_node->parent = Node;
                new_node->shape.move(x + mod, y + mod);
                new_node->parent->rlink.setSize(::Vector2f(20, 5));
                new_node->parent->rlink.setFillColor(::Color::Magenta);
                new_node->parent->rlink.setRotation(230);
                new_node->parent->rlink.setPosition(::Vector2f(a + 55, b + 15));
            }}
    }

   void Tree::Display(node *Root = root) {
        if (!root) {
            return;
        }
        queue<node *> obj;
        obj.push(Root);
        while (!obj.empty()) {
            node *temp = obj.front();
            window.draw(temp->shape.draw());
            if (temp->left)
                window.draw(temp->llink);
            if (temp->right)
                window.draw(temp->rlink);

            obj.pop();
            if (temp->left)
                obj.push(temp->left);
            if (temp->right)
                obj.push(temp->right);
        }

        window.display();
    }





    BinTree::BinTree(int x,int y) : Tree(),x(x),y(y) {
        root = NULL;
    }
    void BinTree:: insert(int data, node *Node = root,int x,int y) {
        if(x==0||y==0){
            x=this->x;
            y=this->y;
        }
      int  a = x + 10;
        int b = y + 35;
        node *new_node = new node;
        new_node->left = new_node->right = new_node->parent = NULL;
        new_node->shape=TreeNode(50,30);
        new_node->shape.input(data);
        new_node->shape.move(x, y);

        if (!root) {
            root = new_node;
            return;
        }
        if (data >= Node->shape.output()) {
            if (Node->right)
                insert(data, Node->right, x + mod, y + mod);
            else {
                Node->right = new_node;
                new_node->parent = Node;
                new_node->shape.move(x + mod, y + mod);
                new_node->parent->rlink.setSize(::Vector2f(20, 5));
                new_node->parent->rlink.setFillColor(::Color::Magenta);
                new_node->parent->rlink.setRotation(230);
                new_node->parent->rlink.setPosition(::Vector2f(a + 55, b + 15));
            }
        } else if (data < Node->shape.output()) {
            if (Node->left)
                insert(data, Node->left, x - mod, y + mod);
            else {
                Node->left = new_node;
                new_node->parent = Node;
                new_node->shape.move(x - mod, y + mod);
                new_node->parent->llink.setSize(::Vector2f(20, 5));
                new_node->parent->llink.setFillColor(::Color::Cyan);
                new_node->parent->llink.setRotation(130);
                new_node->parent->llink.setPosition(::Vector2f(a - 10, b));
            }
        }
    }

OnlyBiggger::OnlyBiggger(int x, int y):BinTree(x,y) {}
    void OnlyBiggger::Display(node *Root = root) {
        if (!root) {
            return;
        }
        queue<node *> obj;
        obj.push(Root);
        while (!obj.empty()) {
            node *temp = obj.front();
            if(temp->shape.output()>=root->shape.output())
                window.draw(temp->shape.draw());
            if (temp->right)
                if(temp->shape.output()>=root->shape.output())
                    window.draw(temp->rlink);
            obj.pop();
            if (temp->left)
                obj.push(temp->left);
            if (temp->right)
                obj.push(temp->right);
        }

        window.display();
    }

