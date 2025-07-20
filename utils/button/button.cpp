#include "button.hpp"

Button::Button(float const width, float const x, float const y,
                sf::Color const& backgroundColor, sf::Color const& textColor,
                sf::Font const& font, std::string const& t) {
    field = sf::RectangleShape(sf::Vector2f(width, 50.f));
    field.setFillColor(backgroundColor);
    field.setOutlineThickness(10.f);
    field.setOutlineColor(sf::Color::Black);
    field.setPosition(x, y);

    text = t;
    sfText.setString(text);
    sfText.setFont(font);
    sfText.setCharacterSize(30);
    sfText.setFillColor(textColor);
    sfText.setPosition(x, y);

    isActive = false;
}

auto Button::draw(sf::RenderWindow& window) const -> void {
    window.draw(field);
    window.draw(sfText);
}

auto Button::isClicked(sf::RenderWindow const &window) const -> bool {
    auto mousePosition = sf::Mouse::getPosition(window);
    return field.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

auto Button::activate() -> void {
    isActive = true;
    field.setFillColor(sf::Color::Magenta);
}

auto Button::deactivate() -> void {
    isActive = false;
    field.setFillColor(sf::Color::Blue);
}