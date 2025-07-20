#include "word.hpp"

Word::Word(std::string const& w, sf::Font const& font, float const y, int const size) {
    word = w;
    sfText.setString(w);
    sfText.setFont(font);
    sfText.setCharacterSize(size);
    sfText.setFillColor(sf::Color::Cyan);
    sfText.setPosition(0.f, y);
    isActive = true;
}

auto Word::getWordBounds() const -> sf::FloatRect {
    return sfText.getGlobalBounds();
}

auto Word::move(float const x) -> void {
    sfText.move(x, 0.f);
}

auto Word::changeColor(float windowWidth, sf::FloatRect const& bounds) -> void {
    if(bounds.left + bounds.width > windowWidth * 0.5f && bounds.left + bounds.width <= windowWidth * 0.8f) {
        sfText.setFillColor(sf::Color::Yellow);
    } else if(bounds.left + bounds.width > windowWidth * 0.8f) {
        sfText.setFillColor(sf::Color::Red);
    }
}