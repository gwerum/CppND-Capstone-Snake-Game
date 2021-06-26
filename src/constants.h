#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>

namespace constants {
    inline constexpr std::size_t kFramesPerSecond{60};
    inline constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    inline constexpr std::size_t kScreenWidth{640};
    inline constexpr std::size_t kScreenHeight{640};
    inline constexpr std::size_t kGridWidth{32};
    inline constexpr std::size_t kGridHeight{32};
};

#endif