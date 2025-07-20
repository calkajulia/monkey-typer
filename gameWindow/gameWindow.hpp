#pragma once

#include <SFML/Graphics.hpp>
#include "../gameSettings/gameSettings.hpp"

auto startGameWindow(float windowWidth, float windowHeight,
                        sf::Font const& font,  GameSettings const& gameSettings) -> void;