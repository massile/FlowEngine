#pragma once

#include "../graphics/Mesh.h"
#include "Parser.h"

class ObjParser : public Parser<Mesh>
{
public:
    ObjParser(const std::string &filepath);
    ~ObjParser();

    Mesh parse() override;
};
