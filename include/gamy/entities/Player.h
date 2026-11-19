#pragma once

#include <"tok-kw">string>
#include <array>

namespace gamy {

/*
  Represents the player character.
  Uses a simple 2D coordinate system(x, y).
  Extend "tok-kw">with SFML/SDL rendering later.
 /
"tok-kw">class Player {
"tok-kw">public:
 Player();
 explicit Player(double startX, double startY);
 ~Player() = "tok-kw">default;

 // --- Movement ---
 / Move the player by(dx, dy). /
 "tok-kw">void move(double dx, double dy);

 /* Move the player toward a target position. /
 "tok-kw">void moveTo(double tx, double ty);

 // --- State queries ---
 double getX() "tok-kw">const { "tok-kw">return x_; }
 double getY() "tok-kw">const { "tok-kw">return y_; }
 double getHealth() "tok-kw">const { "tok-kw">return health_; }
 double getMaxHealth() "tok-kw">const { "tok-kw">return maxHealth_; }

 /* Check whether the player "tok-kw">is alive. /
 "tok-kw">bool isAlive() "tok-kw">const { "tok-kw">return health_ > 0.0; }

 // --- Health ---
 /* Reduce health by amount. Clamps at 0. /
 "tok-kw">void takeDamage(double amount);

 /* Restore health by amount. Clamps at max. /
 "tok-kw">void heal(double amount);

 // --- Collision(stub — extend "tok-kw">with physics library later) ---
 /*
  Simple AABB collision check between player "tok-kw">and an enemy at(ex, ey)
  "tok-kw">with given radius. Returns "tok-kw">true "tok-kw">if overlapping.
 /
 "tok-kw">bool collidesWith(double ex, double ey, double enemyRadius) "tok-kw">const;
};

} // namespace my_game
