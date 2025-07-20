#include "textField.hpp"

TextField::TextField(float const width, float const x, float const y,
                        sf::Color const& backgroundColor, sf::Color const& textColor,
                        sf::Font const& font, std::string const& text) {
    field = sf::RectangleShape(sf::Vector2f(width, 50.f));
    field.setFillColor(backgroundColor);
    field.setPosition(x, y);

    sfText.setString(text);
    sfText.setFont(font);
    sfText.setStyle(sf::Text::Bold);
    sfText.setCharacterSize(30);
    sfText.setFillColor(textColor);
    sfText.setPosition(x, y);
}

auto TextField::draw(sf::RenderWindow& window) const -> void {
    window.draw(field);
    window.draw(sfText);
}

auto TextField::update(std::string const& text) -> void {
    sfText.setString(text);
}