cmake_minimum_required(VERSION 3.29)
project(monkey_typer)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(monkey_typer main.cpp
        gameSettings/gameSettings.hpp
        gameWindow/gameWindow.hpp
        gameWindow/gameWindow.cpp
        settingsWindow/settingsWindow.hpp
        settingsWindow/settingsWindow.cpp
        utils/button/button.hpp
        utils/button/button.cpp
        utils/textField/textField.hpp
        utils/textField/textField.cpp
        utils/word/word.hpp
        utils/word/word.cpp
        utils/utils.hpp
        utils/utils.cpp)
target_link_libraries(monkey_typer sfml-graphics)