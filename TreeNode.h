//
// Created by egor on 07.12.2020.
//

#ifndef CURS_OOP_TREENODE_H
#define CURS_OOP_TREENODE_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class TreeNode {
private:
    int data;
    int r, g, b;
    RectangleShape shape;

public:
    TreeNode() ;
    TreeNode(int , int ) ;
    void move(int , int ) ;
    RectangleShape draw();
    void input(int);
    int output();
};
struct node {
    node *left, *right, *parent;
    TreeNode shape;
    RectangleShape llink;
    RectangleShape rlink;
} ;

#endif//CURS_OOP_TREENODE_H
