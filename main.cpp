#include <SFML/Graphics.hpp>
#include <iostream>
#include "BinaryTree.h"
RenderWindow window(VideoMode(1000, 800), "Curs Work");
node *root;

int main() {
    int n;
    int flag=-1;
    BinTree obj(250,10);
    OnlyBiggger s_obj(750,10);
    cout<<"ONLY BIGGER LINKS OR ALL ?1/2";
    Vertex background[4] =
            {
                    Vertex(Vector2f(0, 0), Color(230, 200, 0,150)),
                    Vertex(Vector2f(0, 800), Color(130, 0, 100,150)),
                    Vertex(Vector2f(1000, 800), Color(130, 200, 120,150)),
                    Vertex(Vector2f(1000, 0), Color(250, 200, 230,150)),
            };
    while(flag<0||flag>2){
        cin>>flag;
    }
    while (window.isOpen()) {

        Event event;
        window.draw(background, 4, Quads);

if(flag==1) {
    s_obj.Display(root);
        }
        else{
            obj.Display(root);

        }
        while (window.pollEvent(event)) {
            if (event.type == ::Event::Closed)
                window.close();
        }
        cin >> n;
        obj.insert(n,root);
        window.clear();
    }

    return 0;
}