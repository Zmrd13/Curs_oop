//
// Created by egor on 07.12.2020.
//

#include "TreeNode.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

    TreeNode::TreeNode() : r(rand() % 155+100), g(rand() % 155+100), b(rand() % 155+100) {
        shape.setFillColor(Color(r, g, (b+50), 100));
        shape.setSize(Vector2f(50, 30));
    }
TreeNode::TreeNode(int x, int y) : r(rand() % 155+100), g(rand() % 155+100), b(rand() % 155+100) {
        shape.setSize(Vector2f(x, y));
        shape.setFillColor(Color(r, g, (b+50), 100));
    }
void TreeNode::move(int x, int y) {
        shape.setPosition(x, y);
    }
    RectangleShape TreeNode::draw() {
        return shape;
    }
    void TreeNode::input(int x) {
        data = x;
    }
    int TreeNode::output() {
        return (this->data);
    };
