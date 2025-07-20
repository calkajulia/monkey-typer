#pragma once

#include <SFML/Graphics.hpp>

struct TextField {
    sf::RectangleShape field;
    sf::Text sfText;

    TextField(float width, float x, float y,
                sf::Color const& backgroundColor, sf::Color const& textColor,
                sf::Font const& font, std::string const& text);

    auto draw(sf::RenderWindow& window) const -> void;
    auto update(std::string const& text) -> void;
};