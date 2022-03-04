#include "LightSource.hpp"
LightSource::LightSource() :
    shader{" ", " "},
    _vertices{
                                 -0.125f, 0.125f, 0.125f,
                             },
    _indices{
                             }{

}

LightSource::~LightSource() {}

void LightSource::setMatUniform() {}

void LightSource::activateShader() {}

void LightSource::draw() {}
