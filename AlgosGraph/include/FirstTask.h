#ifndef FIRSTTASK_H
#define FIRSTTASK_H

#include <vector>
#include <stack>
#include <iostream>
#include <list>
#include <queue>
using namespace std;

/// BFS

struct Node
{
    int pt;  // The cordinates of a cell
    Node *prev;
};

class BFS
{
    int n;
public:
    BFS(int n)
    {
        this->n = n;
        adj = new list<int>[n];
    }
    ~BFS() {};
    int no;

    list<int> *adj;

    int siz()
    {
        return n;
    }

    void addedge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    int calculate(int s =0, int finish =0 )
    {
        if((s!=finish) && finish<n && s<n)
        {
        vector<int> path;
        vector<int> rightPath;
        bool *visited = new bool[n];
        int pred[n];
        for(int i = 0; i < n; i++)
            visited[i] = false;

        list<int> queue;

        visited[s] = true;
        int start = s;
        queue.push_back(s);

        list<int>::iterator i;
        int fir =0;
        while(!queue.empty())
        {
            s = queue.front();
            queue.pop_front();
            path.push_back(s);
            if (s==finish)
            {
                rightPath.push_back(s);
                int joke=path.size()-1;
                while(pred[path[joke]]!=start)
                {
                    int korz =path[joke];
                    rightPath.push_back(pred[korz]);
                    for(int ze=0; ze<path.size(); ze++)
                    {
                        if(path[ze]==pred[path[joke]])
                        {
                            joke=ze;
                        }
                    }
                }
                cout << endl << endl<< endl  << "The fastest way out is: " << endl;
                rightPath.push_back(pred[path[joke]]);
                for(int i=rightPath.size()-1; i>=0; i--)
                {
                    cout << rightPath[i] << " \t ";
                }
                cout << endl << endl<< endl<< endl;

                return rightPath.size();
            }



            for (i = adj[s].begin(); i != adj[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    pred[*i] = s;
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        }

        cout << "Sorry young magician you shell not pass";
        return -1;
    }


};

#endif // FIRSTTASK_H
