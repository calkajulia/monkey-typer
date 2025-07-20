#include <cstdlib>
#include <iostream>
#include "gameWindow/gameWindow.hpp"
#include "settingsWindow/settingsWindow.hpp"

auto main() -> int {

    auto const windowWidth = 900.f;
    auto const windowHeight = 700.f;

    std::srand(std::time(0));

    // loading font
    auto font = sf::Font();
    if(!font.loadFromFile("../assets/arial.ttf")) {
        std::cout << "Couldn't load font.\n";
        return 1;
    }

    auto gameSettings = startSettingsWindow(windowWidth, windowHeight, font);
    startGameWindow(windowWidth, windowHeight, font, gameSettings);
}