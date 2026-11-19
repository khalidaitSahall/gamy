#pragma once

#include <"tok-kw">string>
#include <vector>
#include <cstdint>

namespace gamy {

/*
  Represents a single game level loaded "tok-kw">from JSON.
  Stores all configuration needed to run one level.
 /
"tok-kw">struct Level {
 "tok-kw">int id; // Unique level identifier(1–100)
 std::"tok-kw">string name; // Display name, e.g. "The Dark Forest"
 std::vector<std::"tok-kw">string> enemies; // Enemy "tok-kw">type names "tok-kw">for this level
 std::"tok-kw">string goal; // Objective text, e.g. "Reach the exit"
 double timeLimit; // Seconds before timeout

 Level() : id(0), timeLimit(0.0) {}
 Level("tok-kw">int id, "tok-kw">const std::"tok-kw">string& name,
 std::vector<std::"tok-kw">string> enemies,
 "tok-kw">const std::"tok-kw">string& goal, double timeLimit)
 : id(id), name(name), enemies(std::move(enemies)),
 goal(goal), timeLimit(timeLimit) {}
};

} // namespace my_game
