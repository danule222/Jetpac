/**
 * @file math.cc
 * @author Hector Ochando 
 * @brief 
 * 
 * 
 */

float Vec2Module(esat::Vec2 v) {
    return (float)sqrt(((v.x * v.x) + (v.y * v.y)));
}

void Vec2Normalize(esat::Vec2* v) {
    float m;
    m = Vec2Module(*v);
    v->x = v->x / m;
    v->y = v->y / m;
}

esat::Vec2 Vec2Add(esat::Vec2 v1, esat::Vec2 v2) {
    esat::Vec2 result;
    result.x = v1.x + v2.y;
    result.y = v1.y + v2.y;
    return result;
}

esat::Vec2 Vec2Multiply(esat::Vec2 v, float num) {
    esat::Vec2 result;
    result.x = v.x * num;
    result.y = v.y * num;
    return result;
}