#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "shape.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL initialization failed!" << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Polymorphic Shapes Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "Window creation failed!" << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Renderer creation failed!" << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Clear screen with white background
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Set draw color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Store different shapes in one container using polymorphism
    std::vector<Shape*> shapes;
    
    shapes.push_back(new Square(100, 100, 150));
    shapes.push_back(new Rectangle(300, 200, 200, 100));
    shapes.push_back(new Circle(400, 300, 75)); 

    std::cout << "Drawing " << shapes.size() << " shapes using polymorphism..." << std::endl;

    // Draw all shapes with a loop
    for (Shape* shape : shapes) {
        shape->draw(renderer);
    }

    // Present the rendered content
    SDL_RenderPresent(renderer);

    std::cout << "✓ All shapes drawn successfully!" << std::endl;
    std::cout << "Window will close in 5 seconds..." << std::endl;

    SDL_Delay(5000);

    // Clean up all shapes
    for (Shape* shape : shapes) {
        delete shape;
    }

    // SDL cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << "✓ shapes test completed!" << std::endl;
    return 0;
}