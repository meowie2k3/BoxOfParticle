/*Imagine that we have a box to store particles. Initially, we place randomly 3 particles in that box.
After each step, these particles will move freely inside the box. If two particles collide, a new particle will be placed randomly in the box. 
We want to simulate the movement particles for n steps and count the number of particles in the box.
Implement a box of particles (write a class of box, a class for particle) in such a way that
1.    A box has a fixed size: fixed width and height (10pts)
2.    Each particle has a position (x, y) where 0 ≤ x ≤ width of the box, and 0 ≤ y ≤ height of the box (10pts)
3.    A particle can move in one of the directions below but cannot move out of the box (20pts).
+ North (decreasing its y by 1), 
+ North East (decreasing its y by 1 and increasing its x by 1), 
+ East (increasing its x by 1), 
+ South East (increasing its y by 1 and increasing its x by 1)
+ South (increasing its y by 1), 
+ South West (increasing its y by 1 and decreasing its x by 1), 
+ West (decreasing its x by 1), 
+ North West (decreasing its y by 1 and decreasing its x by 1) 
Hint: declare an enum type for Direction
4.    If two particles collide, a new particle will be placed randomly in the box(20pts)
and a class for simulation where for each step,
5.    It makes all particles in the box move (5pts)
6.    It shows the number of particles in the box (5pts)
7.    It visualizes the box with particles inside (10pts)*
 -------------------------------
| *        *                   *|
|        *               **     | 
|                *              |
-------------------------------*/
#include <bits/stdc++.h>
#include <time.h>
#include "box.cpp"
#include "particle.cpp"
#include "function.cpp"

using namespace std;

int randomNUm(){
    //get random number
    return rand();
}

string directionTrans(int a){
    string res;
    switch (a)
    {
    case 0:
        res= "North";
        break;
    case 1:
        res="North East";
        break;
    case 2:
        res="East";
        break;
    case 3:
        res="South East";
        break;
    case 4:
        res="South";
        break;
    case 5:
        res="South West";
        break;
    case 6:
        res="West";
        break;
    case 7:
        res="North West";
        break;
    default:
        res= "Invalid move!!";
        break;
    }
    return res;
}

int main(){
    int width,height;
    cout << "insert width: ";cin >> width;
    cout << "insert height: ";cin >> height;
    cout << '\n'; 

    box* box1 = new box(width, height);
    //cout << box1->getWidth() << " " << box1->getHeight();

    srand((unsigned) time(0));//initial seed value to system clock
    cout << "Generating 3 particle:\n";
    for(int i=0;i<3;i++){
        box1->addParticle(randomNUm()%width, randomNUm()%height);
    }
    //box1->printPos(1); 

    box1->printAll();
    while(box1->isCollide()==true){
            int x1= rand() % width;
            int y1= rand() % height;
            cout << "Collision detected! Adding particle at [" << x1 << "," << y1 << "]\n";
        }
    box1->visualize();
    int moves;
    cout << "insert number of moves: ";
    cin >> moves;
    for(int z=0;z<moves;z++)
    {
        cout << "Move number " << z+1 << ":\n";
        int direction=randomNUm() % 8;
        int particleChosen= randomNUm() % box1->getListsize();
        cout << "Choosing particle " << particleChosen << ", direction " << directionTrans(direction) << '\n';
        box1->move(direction, particleChosen);
        box1->printAll();
        if(box1->isCollide()==true){
            int x1= rand() % width;
            int y1= rand() % height;
            cout << " Collision detected! Adding particle at [" << x1 << "," << y1 << "] and restart this move.\n";
            box1->addParticle(x1,y1);
            z--;
            continue;
        }
        else box1->visualize();
    }
    system("PAUSE");
}