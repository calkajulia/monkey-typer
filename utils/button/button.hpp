#pragma once

#include <SFML/Graphics.hpp>

struct Button {
    sf::RectangleShape field;
    sf::Text sfText;
    std::string text;
    bool isActive;

    Button(float width, float x, float y,
            sf::Color const& backgroundColor, sf::Color const& textColor,
            sf::Font const& font, std::string const& t);

    auto draw(sf::RenderWindow& window) const -> void;
    auto isClicked(sf::RenderWindow const& window) const -> bool;
    auto activate() -> void;
    auto deactivate() -> void;
};