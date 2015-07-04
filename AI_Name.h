#include "game.h"
#ifndef __AI_NAME_H__
#define __AI_NAME_H__

// If you added a new AI, please change this number
#define MAX_AI_NUM 11

// You need to declare you function here!
Point ExampleAI(const NodeType board[BoardSize][BoardSize], NodeType yourType);
Point GTAIFunc(const NodeType board[BoardSize][BoardSize], NodeType yourType);
Point ActualPlayer(const NodeType board[BoardSize][BoardSize], NodeType yourType);
Point dummyProcedure(const NodeType board[BoardSize][BoardSize], NodeType mytype);
// And add your function here!
const struct S_AI AIList[MAX_AI_NUM] = {
//   ID | Function Name   | Name
    {1,   ExampleAI       , "Example"},
    {2,   GTAIFunc        , "GaoTian AI"},
    {5,   dummyProcedure  , "DummyIndex's Mashiro"},
    {10,  ActualPlayer    , "Player"}
};

#endif
