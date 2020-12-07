#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
int mod = 50;
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1000, 800), "Curs Work");
class TreeNode {
private:
    int data;
    int r, g, b;
    RectangleShape shape;

public:
    TreeNode() : r(rand() % 155+100), g(rand() % 155+100), b(rand() % 155+100) {
        shape.setFillColor(Color(r, g, (b+50), 100));
        shape.setSize(Vector2f(50, 30));
    }
    TreeNode(int x, int y) : r(rand() % 155+100), g(rand() % 155+100), b(rand() % 155+100) {
        shape.setSize(Vector2f(x, y));
        shape.setFillColor(Color(r, g, (b+50), 100));
    }
    void move(int x, int y) {
        shape.setPosition(x, y);
    }
    RectangleShape draw() {
        return shape;
    }
    int input(int x) {
        data = x;
    }
    int output() {
        return (this->data);
    };
};
struct node {
    node *left, *right, *parent;
    TreeNode shape;
    RectangleShape llink;
    RectangleShape rlink;
} * root;

class Tree {
private:
public:
    virtual void insert(int data, node *Node = root, int x = 500, int y = 50) {
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

    virtual void Display(node *Root = root) {
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
};


class BinTree : public Tree {
private:
    int x ,y;
    int a, b;
public:

    BinTree(int x=250,int y=10) : Tree(),x(x),y(y) {
        root = NULL;
    }
    void insert(int data, node *Node = root,int x=0,int y=0) {
        if(x==0||y==0){
            x=this->x;
            y=this->y;
        }
        a = x + 10;
        b = y + 35;
        node *new_node = new node;
        new_node->left = new_node->right = new_node->parent = NULL;
        new_node->shape=TreeNode(60,20);
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
};
class OnlyBiggger:public BinTree{
private:
public:
    void Display(node *Root = root) {
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
                if(temp->shape.output()>root->shape.output())
                window.draw(temp->rlink);
            obj.pop();
            if (temp->left)
                obj.push(temp->left);
            if (temp->right)
                obj.push(temp->right);
        }

        window.display();
    }
};

int main() {
    int n;
    int flag=-1;
    BinTree obj(250);
    OnlyBiggger obj_b;
    cout<<"ONLY BIGGER LINKS OR ALL ?1/2";
    Vertex background[4] =
            {
                    Vertex(Vector2f(0, 0), Color(130, 0, 0)),
                    Vertex(Vector2f(0, 800), Color(130, 0, 100)),
                    Vertex(Vector2f(1000, 800), Color(130, 0, 120)),
                    Vertex(Vector2f(1000, 0), Color(50, 0, 130)),
            };
    while(flag<0||flag>2){
        cin>>flag;
    }
    while (window.isOpen()) {

        Event event;
        window.draw(background, 4, Quads);

if(flag==1) {
            obj_b.Display(root);
        }
        else{
            obj.Display(root);
        }
        while (window.pollEvent(event)) {
            if (event.type == ::Event::Closed)
                window.close();
        }
        cin >> n;
        obj.insert(n);

        window.clear();
    }

    return 0;
}