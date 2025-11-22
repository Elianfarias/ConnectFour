#pragma once
struct GridTile
{
    char face;
    bool isRevealed;
    bool isMatched;

    GridTile();
    void DrawTile();
};