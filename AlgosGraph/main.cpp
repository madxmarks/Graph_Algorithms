#include "SecTask.h"
#include "FirstTask.h"
#include <fstream>
#include <chrono>
#include <windows.h>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

int main()
{


        BFS M(10);
        M.addedge(1,0);
        M.addedge(1,2);
        M.addedge(2,3);
        M.addedge(2,4);
        M.addedge(4,6);
        M.addedge(6,7);
        M.addedge(7,9);
        M.addedge(0,3);
        M.addedge(0,9);

        int nu = 3;
        vector<int> mini;
        mini.resize(nu);
        int sta; int en;

        for (int i=0; i<nu; i++){
            cout << " Enter your start ";
            cin >> sta;
            cout << " Enter your end ";
            cin >> en;
            mini[i]=(M.calculate(sta, en));
        }

        unsigned int miini =0;
        int sho = 0;
        for (int i=0; i<nu; i++){
        if (mini[i]<miini)
        {
            miini=mini[i];
            sho = i;
        }
        }
        cout <<" The length of the shortest path is " << miini;




        cout << endl << endl<< endl<< endl;
        GraphSit G;
        int nume=6;
        G.add_vertex(nume);
        G.addedge(0,1);
        G.addedge(1,3);
        G.addedge(2,0);
        G.addedge(2,3);
        G.addedge(4,3);
        G.addedge(3,5);
        G.Build2();



    return 0;
}

