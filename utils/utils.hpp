#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "button/button.hpp"
#include "word/word.hpp"

auto loadWords(std::vector<std::string>& words, int amount) -> bool;
auto handleUserInput(sf::Event const& event, std::string& userInput) -> void;
auto generateRandomY(float windowHeight, std::vector<float> const& usedY) -> float;
auto updateScore(std::string& userInput, Word& word, int& score, int maxScore, sf::Text& scoreText) -> void;

auto createSfText(std::string const& text, sf::Font const& font, int size, sf::Color const& color, float x, float y) -> sf::Text;
auto createButtons(float buttonWidth, float y, sf::Font const& font, std::vector<std::string> const& labels) -> std::vector<Button>;