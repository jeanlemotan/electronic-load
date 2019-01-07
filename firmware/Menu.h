#pragma once

#include <vector>
#include <string>
#include "AiEsp32RotaryEncoder.h"

class Adafruit_GFX;

class Menu
{
public:
    Menu();

    void pushSubMenu(std::vector<std::string> const& entries, size_t selected, int16_t y);
    void popSubMenu();

    void setSubMenuEntry(size_t idx, std::string const& entry);

    size_t process(AiEsp32RotaryEncoder& knob);

    void render(Adafruit_GFX& display, size_t maxEntries);

private:
    struct SubMenu
    {
        std::vector<std::string> entries;
        size_t crtEntry = 0;
        size_t topEntry = 0;
        int16_t x = 0;
        int16_t y = 0;
        bool popped = false;
        bool finished = false;
    };

    std::vector<SubMenu> m_subMenus;
    size_t m_crtSubMenuIdx = 0;

    float m_targetX = 0;
    float m_crtX = 0;

    void render(Adafruit_GFX& display, SubMenu& data, size_t maxEntries);
};
