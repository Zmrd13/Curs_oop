#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
int mod=50;
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1000, 800), "Curs Work");
Vertex background[4] =
        {
                Vertex(Vector2f(0, 0), Color(130, 0, 0)),
                Vertex(Vector2f(0, 800), Color(130, 0, 100)),
                Vertex(Vector2f(1000, 800), Color(130, 0, 120)),
                Vertex(Vector2f(1000, 0), Color(50, 0, 130)),
        };
struct node
{
    int data;
    node *left, *right, *parent;
    Text txt;
   RectangleShape shape;
   RectangleShape llink;
   RectangleShape rlink;
}*root;
class Tree
{
public:
    Tree();
    void insert(int, node*, int, int, int, int);
    void Display(node*);

};
Tree::Tree() { root = NULL; }
void Tree::insert(int data, node* Node = root, int x = 500, int y = 50, int a=0 , int b=0 )

{
    a=x+10;
    b=y+35;
    node* new_node = new node;
    new_node->shape.setFillColor(Color(255,205,200,200));
    new_node->left = new_node->right = new_node->parent = NULL;
    new_node->data = data;
    new_node->shape.setSize(Vector2f(50,30));
    new_node->txt.setPosition(::Vector2f(x, y));
    new_node->shape.setPosition(::Vector2f(x, y));

    if (!root)
    {
        root = new_node;
        return;
    }
    if (data >= Node->data)
    {
        if (Node->right)
            insert(data, Node->right, x + mod, y + mod, a + mod, b + mod);
        else
        {
            Node->right = new_node;
            new_node->parent = Node;
            new_node->shape.setPosition(::Vector2f((x + mod), (y + mod)));
            new_node->parent->rlink.setSize(::Vector2f(20, 5));
            new_node->parent->rlink.setFillColor(::Color::Magenta);
            new_node->parent->rlink.setRotation(230);
            new_node->parent->rlink.setPosition(::Vector2f(a+55, b+15));
        }
    }
    else if (data < Node->data)
    {
        if (Node->left)
            insert(data, Node->left, x - mod, y + mod, a - mod, b + mod);
        else
        {
            Node->left = new_node;
            new_node->parent = Node;
            new_node->shape.setPosition(::Vector2f((x - mod), (y + mod)));
            new_node->parent->llink.setSize(::Vector2f(20, 5));
            new_node->parent->llink.setFillColor(::Color::Cyan);
            new_node->parent->llink.setRotation(130);
            new_node->parent->llink.setPosition(::Vector2f(a-10, b));
        }
    }
}
void Tree::Display(node* Root = root)
{
    if (!root)
    {
        return;
    }
    window.draw(background, 4, Quads);
    queue<node*> obj;
    obj.push(Root);
    while (!obj.empty())
    {

        node* temp = obj.front();
        window.draw(temp->shape);
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

int main()
{ Font f;
    int n;
    Tree obj;
    for(int i;i<10;i++){
        n=rand()%1000;
        obj.insert(n);
    }
    while (window.isOpen())
    {

        ::Event event;

        obj.Display();

        while (window.pollEvent(event))
        {
            if (event.type == ::Event::Closed)
                window.close();
        }

        window.clear();
    }

    return 0;
}