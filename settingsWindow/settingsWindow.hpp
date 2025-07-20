#pragma once

#include <SFML/Graphics.hpp>
#include "../gameSettings/gameSettings.hpp"

auto startSettingsWindow(float windowWidth, float windowHeight, sf::Font const& font) -> GameSettings;