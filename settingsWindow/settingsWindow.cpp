#include "settingsWindow.hpp"

#include "../utils/textField/textField.hpp"
#include "../utils/utils.hpp"

auto startSettingsWindow(float const windowWidth, float const windowHeight, sf::Font const& font) -> GameSettings{
    auto gameSettings = GameSettings();

    auto const buttonWidth = windowWidth / 3;

    auto window = sf::RenderWindow(
        sf::VideoMode(windowWidth, windowHeight),
        "Monkey Typer - Settings",
        sf::Style::Default,
        sf::ContextSettings(0, 0, 8));

    auto amountField = TextField(
        windowWidth,
        0.f,
        0.f,
        sf::Color::Black,
        sf::Color::Cyan,
        font,
        "SELECT WORDS AMOUNT:"
        );
    auto amountButtons = createButtons(
        buttonWidth,
        60.f,
        font,
        {"20", "40", "80"});
    amountButtons[0].activate();
    gameSettings.wordsAmount = 20;

    auto speedField = TextField(
        windowWidth,
        0.f,
        120.f,
        sf::Color::Black,
        sf::Color::Cyan,
        font,
        "SELECT WORDS SPEED:"
        );
    auto speedButtons = createButtons(
        buttonWidth,
        180.f,
        font,
        {"0.02", "0.04", "0.06"});
    speedButtons[0].activate();
    gameSettings.wordsSpeed = 0.02f;

    auto sizeField = TextField(
        windowWidth,
        0.f,
        240.f,
        sf::Color::Black,
        sf::Color::Cyan,
        font,
        "SELECT WORDS SIZE:"
        );
    auto sizeButtons = createButtons(
        buttonWidth,
        300.f,
        font,
        {"20", "30", "40"});
    sizeButtons[0].activate();
    gameSettings.wordsSize = 20;

    auto startGameButton = Button(
        windowWidth / 4,
        (windowHeight / 2.f) - (50.f / 2.f),
        500.f,
        sf::Color::Green,
        sf::Color::Black,
        font,
        "START GAME"
    );

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                for(auto& button : amountButtons) {
                    if(button.isClicked(window)) {
                        for(auto& b : amountButtons) {
                            b.deactivate();
                        }
                        button.activate();
                        gameSettings.wordsAmount = std::stoi(button.text);
                    }
                }
                for(auto& button : speedButtons) {
                    if(button.isClicked(window)) {
                        for(auto& b : speedButtons) {
                            b.deactivate();
                        }
                        button.activate();
                        gameSettings.wordsSpeed = std::stof(button.text);
                    }
                }
                for(auto& button : sizeButtons) {
                    if(button.isClicked(window)) {
                        for(auto& b : sizeButtons) {
                            b.deactivate();
                        }
                        button.activate();
                        gameSettings.wordsSize = std::stoi(button.text);
                    }
                }

                if(startGameButton.isClicked(window)) {
                    window.close();
                    return gameSettings;
                }
            }
        }

        // window
        window.clear(sf::Color::Black);
        speedField.draw(window);
        amountField.draw(window);
        sizeField.draw(window);
        for(auto& fontButton : amountButtons) {
            fontButton.draw(window);
        }
        for(auto& speedButton : speedButtons) {
            speedButton.draw(window);
        }
        for(auto& sizeButton : sizeButtons) {
            sizeButton.draw(window);
        }
        startGameButton.draw(window);
        window.display();
    }

    return gameSettings;
}