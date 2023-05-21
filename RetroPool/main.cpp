#include <SFML/Graphics.hpp>
#include<iostream>

#define BLOCK_COUNT 100
#define BLOCK_SIZE 6.0f
#define MIN_block_height 100.0f
#define MAX_block_height 600

int main()
{

    float position = 790;
    sf::RenderWindow window(sf::VideoMode(800, 800), "coffie's game");
    //window.setFramerateLimit(300);
    sf::RectangleShape block(sf::Vector2f(BLOCK_SIZE, 50.f));
    //block.setPosition(sf::Vector2f(790, 800));
    //block.setSize(sf::Vector2f(10,-700));
    float block_height[101];
    int num = 100;
    float temp;
    block.setFillColor(sf::Color::Color(180, 80, 80));
    for (int i = 0; i < BLOCK_COUNT; i++) {
        block_height[i] = rand() % MAX_block_height + MIN_block_height;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == event.Closed) {
                window.close();
            }
            if (event.type == event.MouseButtonPressed) {
                for (int i = 0; i < BLOCK_COUNT; i++) {
                    block_height[i] = rand() % MAX_block_height + MIN_block_height;
                }
            }
        }


             
            if (block_height[num] > block_height[num - 1]){
                temp = block_height[num];
                block_height[num] = block_height[num - 1];
                block_height[num - 1] = temp;
                }
            num--;
            if (num <= 0) {
                num = 100;
            }
       
        
        window.clear();
        for (int i = 0; i < BLOCK_COUNT; i++) {
            block.setSize(sf::Vector2f(BLOCK_SIZE, - block_height[i]));
            block.setPosition(sf::Vector2f(790, 800));
            block.move(-(BLOCK_SIZE+1.0f)*i, 0);
            block.setFillColor(sf::Color::Color(block_height[i]/4, 0, 0));
            window.draw(block);
        }
        window.display();
    }

    return 0;
}


// bool hello;
// game loop {
//   
//   input -> set hello to something;
//   game logic / physics -> i can move the sprite according to hello
//   rendering -> render normally
