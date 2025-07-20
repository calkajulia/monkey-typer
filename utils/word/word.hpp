#pragma once

#include <string>
#include <SFML/Graphics.hpp>

struct Word {
    std::string word;
    sf::Text sfText;
    bool isActive;

    Word(std::string const& w, sf::Font const& font, float y, int size);

    auto getWordBounds() const -> sf::FloatRect;
    auto move(float x) -> void;
    auto changeColor(float windowWidth, sf::FloatRect const& bounds) -> void;
};
