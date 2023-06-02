#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Sprite.h"
#include "Paddle.h"
#include "Block.h"
#include "Manager.h"
#include "homeScreen.cpp"
#include "Game.h"

//  Template kolizji
template <class T1, class T2> bool isIntersecting(T1& A, T2& B) {
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}