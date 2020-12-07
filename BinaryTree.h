//
// Created by egor on 07.12.2020.
//

#ifndef CURS_OOP_BINARYTREE_H
#define CURS_OOP_BINARYTREE_H
#include "TreeNode.h"
class Tree {
public:
    virtual void insert(int, node*, int, int);
    virtual void Display(node*);
};
class BinTree : public Tree {
private:
    int x ,y;
public:
    BinTree(int ,int );
    void insert(int, node*,int x=0,int y=0);
};
class OnlyBiggger:public BinTree{
private:
public:
    OnlyBiggger(int x=0,int y=0);
    void Display(node*);};
#endif//CURS_OOP_BINARYTREE_H
