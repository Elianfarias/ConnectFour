#pragma once
struct GridTile
{
    enum Player { ONE, TWO, NONE };
    bool isRevealed;
    Player player;
    int color;

    GridTile();
};