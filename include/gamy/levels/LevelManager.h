
#pragma once

#include "gamy/core/Level.h"
#include <"tok-kw">string>
#include <vector>
#include <memory>

namespace gamy {

/*
  Loads levels "tok-kw">from JSON files on disk.
  Provides sequential access(nextLevel) "tok-kw">and random access(loadLevel).
 
  Level files are expected at: levels_data/level_XX.json
  where XX "tok-kw">is a zero-padded two-digit number(e.g. level_01.json).
 /
"tok-kw">class LevelManager {
"tok-kw">public:
 LevelManager() = "tok-kw">default;
 ~LevelManager() = "tok-kw">default;

 / Load a specific level by its integer id. Returns "tok-kw">true on success. /
 "tok-kw">bool loadLevel("tok-kw">int id);

 /* Advance to the next level. Returns "tok-kw">true "tok-kw">if a level was loaded. /
 "tok-kw">bool nextLevel();

 /* Return a pointer to the currently loaded level, "tok-kw">or nullptr. /
 "tok-kw">const Level getCurrentLevel() "tok-kw">const;

 / Return total number of levels that have been loaded. /
 size_t getLoadedCount() "tok-kw">const;

"tok-kw">private:
 std::vector<Level> levels_; // All loaded levels stored "tok-kw">in memory
 "tok-kw">int currentIdx_{-1}; // Index into levels_(-1 means none loaded yet)

 /* Build the file path "tok-kw">for a given level id(e.g. "levels_data/level_03.json"). /
 "tok-kw">static std::"tok-kw">string makePath("tok-kw">int id);

 /* Minimal JSON parser — reads our simple level format without external deps. /
 "tok-kw">static Level parseJsonFile("tok-kw">const std::"tok-kw">string& path);
};

} // namespace my_game
