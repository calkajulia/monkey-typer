#include "utils.hpp"

#include <iostream>

auto loadWords(std::vector<std::string>& words, int const amount) -> bool {
    auto file = std::fstream("../assets/words.txt");

    if(!file.is_open()) {
        std::cout << "Couldn't open file \"words.txt\"\n";
        return false;
    }

    auto word = std::string();
    for(int i = 0; i < amount; i++) {
        file >> word;
        words.push_back(word);
    }
    return true;
}

auto handleUserInput(sf::Event const& event, std::string &userInput) -> void {
    if(event.text.unicode == '\b' && !userInput.empty()) {
        userInput.pop_back();
    } else if (event.text.unicode == '\n' || event.text.unicode == '\r') {
        userInput.clear();
    } else if (event.text.unicode < 123 && event.text.unicode > 96) {
        userInput.push_back(static_cast<char>(event.text.unicode));
    }
}

auto generateRandomY(float const windowHeight, std::vector<float> const& usedY) -> float {
    auto randY = 0.f;
    do {
        randY = 25.f + ((std::rand() % ((static_cast<int>(windowHeight) - 125) / 25)) * 25);
    } while(std::ranges::find(usedY, randY) != usedY.end());
    return randY;
}

auto updateScore(std::string& userInput, Word& word, int& score, int const maxScore, sf::Text& scoreText) -> void {
    if(userInput == word.word) {
        score += 1;
        scoreText.setString("Score: " + std::to_string(score) + "/" + std::to_string(maxScore));

        word.isActive = false;
        userInput.clear();
    }
}

auto createSfText(std::string const& text, sf::Font const& font, int size, sf::Color const& color, float x, float y) -> sf::Text {
    auto sfText = sf::Text(text, font, size);
    sfText.setFillColor(color);
    sfText.setPosition(x, y);
    return sfText;
}

auto createButtons(float buttonWidth, float y, sf::Font const& font, std::vector<std::string> const& labels) -> std::vector<Button> {
    auto buttons = std::vector<Button>();
    for(auto i = 0; i < labels.size(); i++) {
        auto button = Button(
            buttonWidth,
            i * buttonWidth,
            y,
            sf::Color::Blue,
            sf::Color::White,
            font,
            labels[i]
            );
        buttons.push_back(button);
    }
    return buttons;
}