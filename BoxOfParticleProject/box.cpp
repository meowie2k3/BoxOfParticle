#include <bits/stdc++.h>
#include <time.h>
#include <vector>
#include "particle.cpp"
#pragma once
#define N 0
#define NE 1
#define E 2
#define SE 3
#define S 4
#define SW 5
#define W 6
#define NW 7

using namespace std;
class box : public particle{
    private:
     int width;
     int height;
     vector<particle*> list;
     bool draw[100][100];
    public:
        box(int width, int height) : particle(){
            this->width=width;
            this->height=height;
        }
        void setWidth(int a){
            this->width=a;
        }
        void setHeight(int a){
            this->height= a;
        }
        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }
        int getListsize(){
            return list.size();
        }
        void addParticle(int x, int y){
            particle* tmp= new particle(x,y);
            //cout << tmp->getX() << " " << tmp->getY();
            list.push_back(tmp);
        }
        void printPos(int n){
            int x= list[n-1]->getX();
            int y=list[n-1]->getY();
            cout << "Particle " << n << ": [" << x << "," << y <<"]\n";
        }
        void printPos(particle* a){
            int x= a->getX();
            int y= a->getY();
            cout << "Particle requested"<< ": [" << x << "," << y <<"]\n";
        }
        void printAll(){
            for(int i=0;i<list.size();i++)
            {
                int x= list[i]->getX();
                int y=list[i]->getY();
                cout << "Particle " << i+1 << ": [" << x << "," << y << "]\n";
            }
        }
        void move(int direction, int numOfParticle){
            particle* a= list[numOfParticle];
            switch (direction)
            {
            case N:
                if(a->getY()-1>=0){
                    a->setY(a->getY()-1);
                    break;
                }
                else
                    break;
            case NE:
                if(a->getY()-1>=0){
                    a->setY(a->getY()-1);
                }
                if(a->getX()+1<width){
                    a->setX(a->getX()+1);
                    break;
                }
                else break;
            case E:
                if(a->getX()+1<width){
                    a->setX(a->getX()+1);
                    break;
                }
                else break;
            case SE:
                if(a->getY()+1<height){
                    a->setY(a->getY()+1);
                }
                if(a->getX()+1<width){
                    a->setX(a->getX()+1);
                    break;
                }
                else break;
            case S:
                if(a->getY()+1<height){
                    a->setY(a->getY()+1);
                    break;
                }
                else break;
            case SW:
                if(a->getY()+1<height){
                    a->setY(a->getY()+1);
                }
                if(a->getX()-1>=0){
                    a->setX(a->getX()-1);
                    break;
                }
                else break;
            case W:
                if(a->getX()-1>=0){
                    a->setX(a->getX()-1);
                    break;
                }
                else break;
            case NW:
                if(a->getY()-1>=0){
                    a->setY(a->getY()-1);
                }
                if(a->getX()-1>=0){
                    a->setX(a->getX()-1);
                    break;
                }
                else break;
            default:
                cout << "invalid move: " << direction << '\n';
                break;
            }
            list[numOfParticle]->setX(a->getX());
            list[numOfParticle]->setY(a->getY());
        }
        bool isCollide(){
            //bool draw[width+1][height+1];
            memset(draw, false, sizeof(draw));
            
            for(int i=0;i<list.size();i++){
                int x= list[i]->getX();
                int y= list[i]->getY();
                if(draw[x][y]==true)
                {
                    return true;
                }
                else draw[x][y]=true;
            }
            return false;
        }
        void visualize(){
            memset(draw, false, sizeof(draw));
            for(int i=0;i<list.size();i++){
                int x= list[i]->getX();
                int y= list[i]->getY();
                if(draw[x][y]==false){
                    draw[x][y]=true;
                }
            }
            for(int i=0;i<=height+2;i++)
                cout << "-";
            cout << '\n';
            for(int i=0;i<width+1;i++)
            {
                cout << "|";
                for(int j=0;j<height+1;j++)
                {
                    if(draw[i][j]==true)
                        cout << "*";
                    else cout << " ";
                }
                cout << "|\n";
            }
            for(int i=0;i<=height+2;i++)
                cout << "-";
            cout << '\n';
        }
        bool isFull(){
            for(int i=0;i<width;i++){
                for(int j=0;j<height;j++){
                    if(draw[i][j]==false)
                        return false;
                }
            }
            return true;
        }
};