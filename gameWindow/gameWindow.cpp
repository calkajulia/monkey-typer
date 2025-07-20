#include "gameWindow.hpp"

#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/textField/textField.hpp"
#include "../utils/utils.hpp"
#include "../utils/word/word.hpp"

auto startGameWindow(float const windowWidth, float const windowHeight,
                        sf::Font const& font,  GameSettings const& gameSettings) -> void {

    // loading words
    auto words = std::vector<std::string>();
    if(!loadWords(words, gameSettings.wordsAmount)) {
        return;
    }

    // window
    auto window = sf::RenderWindow(
        sf::VideoMode(windowWidth, windowHeight),
        "Monkey Typer",
        sf::Style::Default,
        sf::ContextSettings(0, 0, 8));

    auto inputField = TextField(
        windowWidth,
        0.f,
        windowHeight - 50.f,
        sf::Color::White,
        sf::Color::Blue,
        font,
        " "
        );

    auto scoreText = createSfText("Score: 0/" + std::to_string(gameSettings.wordsAmount), font, 30, sf::Color::Green, 10.f, 10.f);

    // words
    auto visibleWords = std::vector<Word>();
    auto wordsIndex = 0;

    auto userInput = std::string();

    auto clock = sf::Clock();
    auto wordSpawnTimer = 0.f;

    // game status
    auto score = 0;
    auto gameOver = false;
    auto gameWon = false;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            } else if(event.type == sf::Event::TextEntered) {
                handleUserInput(event, userInput);
            }
        }

        if(gameWon || gameOver) {
            window.clear(sf::Color::Black);
            auto text = gameWon ? "You win!!" : "Game Over :(";
            auto color = gameWon ? sf::Color::Green : sf::Color::Red;
            auto endText = createSfText(text, font, 50, color, windowWidth / 2 - 150.f, windowHeight / 2 - 50.f);
            window.draw(endText);
            window.display();
            continue;
        }

        // adding 2 new words to visibleWords every 2 sec
        auto usedY = std::vector<float>();
        float timePassed = clock.restart().asSeconds();
        wordSpawnTimer += timePassed;
        if(wordSpawnTimer >= 2.0f && wordsIndex < words.size()) {
            wordSpawnTimer = 0.f;
            for(int i = 0; i < 2 && wordsIndex < words.size(); i++) {
                auto randY = generateRandomY(windowHeight, usedY);
                auto newWord = Word(words[wordsIndex], font, randY, gameSettings.wordsSize);
                visibleWords.push_back(newWord);
                usedY.push_back(randY);
                wordsIndex++;
            }
        }

        // updating visibleWords and game status
        for(auto& word : visibleWords) {
            auto bounds = word.getWordBounds();
            if(bounds.left + bounds.width > windowWidth) {
                gameOver = true;
            } else if (word.isActive) {
                word.move(gameSettings.wordsSpeed);
                word.changeColor(windowWidth, bounds);
                updateScore(userInput, word, score, gameSettings.wordsAmount, scoreText);

                if(score == words.size()) {
                    gameWon = true;
                }
            }
        }

        // removing inactive visibleWords
        for(int i = 0; i < visibleWords.size(); i++) {
            if(!visibleWords[i].isActive) {
                visibleWords.erase(visibleWords.begin() + i);
            }
        }

        // updating user input
        inputField.update(userInput);

        // window
        window.clear(sf::Color::Black);
        inputField.draw(window);
        window.draw(scoreText);
        for(const auto& word : visibleWords) {
            window.draw(word.sfText);
        }
        window.display();
    }
}
