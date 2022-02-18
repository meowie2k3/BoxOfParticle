#include <bits/stdc++.h>
#pragma once
using namespace std;

class particle{
    private:
        int x;
        int y;
        
    public:
        particle(){

        }
        particle(int x, int y){
            this->x=x;
            this->y=y;
        }
        void setX(int x){
            this->x=x;
        }
        void setY(int y){
            this->y=y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};