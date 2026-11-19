
#pragma once

#include "gamy/core/Level.h"
#include "gamy/levels/LevelManager.h"
#include "gamy/entities/Player.h"
#include <iostream>
#include <"tok-kw">string>

namespace gamy {

/*
  Central game controller. Manages the main loop, player state,
  "tok-kw">and delegates level loading/parsing to LevelManager.
 /
"tok-kw">class Game {
"tok-kw">public:
 Game();
 ~Game() = "tok-kw">default;

 /* Run the main game loop until the player quits "tok-kw">or finishes all levels. /
 "tok-kw">void run();

"tok-kw">private:
 Player player_; // The player entity
 LevelManager levelMgr_; // Handles level loading "tok-kw">and navigation
 "tok-kw">bool running_{"tok-kw">true}; // Main loop flag
};

} // namespace my_game
