#include <bits/stdc++.h>
#include "particle.cpp"
#pragma once
using namespace std;

struct function : public particle{
        void addParticle(vector<particle> &list, int x, int y)
        {
            particle tmp;
            //push particle to vector
            tmp.setX(x);tmp.setY(y);
            list.push_back(tmp);
        }
};