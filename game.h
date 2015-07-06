#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>

#ifndef __GAME_H__
#define __GAME_H__
#define BoardSize 19

enum NodeType {Empty, Black, White};

static const char* blackChar = "○";
static const char* whiteChar = "●";

class Point{
public:
    Point() {x = -1; y = -1;};
    Point(int xx, int yy) {x = xx; y = yy;};
    Point(const Point & p) {x = p.x; y = p.y;};
    void Set(int xx, int yy) {x = xx; y = yy;};
    void Copy(const Point & p) {x = p.x; y = p.y;};
    bool Valid() const {return (0 <= x && x < BoardSize && 0 <= y && y < BoardSize);};
    bool operator == (Point& p) const {return(x == p.x && y == p.y);};
    bool operator != (const Point& p) const {return(x != p.x || y != p.y);};


    int x;
    int y;
};

typedef Point (*AIFunc)(const NodeType[BoardSize][BoardSize], NodeType);
//typedef Point (*AIFunc)(const NodeType**, NodeType);

struct S_AI {
    int id;
    AIFunc func;
    const char* name;
};

typedef struct S_AI S_AI;

typedef std::map<int, struct S_AI> AI_Map;

class GameSettings
{
public:
    GameSettings();
    bool isPrint;
    bool isRandFirst;
    int  sleepTime;
    bool isNormal;
};

class Game {
public:
    Game();
    void Initialize();
    bool Move(Point p);
    NodeType Play(S_AI, S_AI);
    NodeType CheckVictory();
    NodeType GetType(Point p);
    void PrintBoard();
    void PreSetBoard();
    void SetGamerAI(int gamer1ID, int gamer2ID);
    
    GameSettings settings;
    bool isBlackPlaying;
    NodeType board[BoardSize][BoardSize];
    std::string boardChar[BoardSize*2][BoardSize*2];
    AI_Map aiMap;
private:
    NodeType CheckNode(Point p);
};

#endif
