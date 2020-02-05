#ifndef SECTASK_H
#define SECTASK_H

#include <stack>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

/// DFS

class GraphSit
{
    int n;
public:
    vector<vector<int> > Vec;
    int siz()
    {
        return n;
    }
    int add_vertex(unsigned int c)
    {
        Vec.resize(n+c);
        return n+=c;
    }
    void addedge(int v, int w)
    {
        Vec[v].push_back(w);
        Vec[w].push_back(v);
    }
    GraphSit()
    {
        n=0;
    }

    int Build2()
    {
        int sit[n] = {0};
        stack<int> que;
        for (int v=0; v<siz(); v++)
        {
            if(sit[v]==0)
            {
                sit[v]=1;
                que.push(v);
                while (!que.empty())
                {
                    int w= que.top();
                    que.pop();
                    for (int i=0; i<Vec[w].size(); i++)
                    {
                        if(!sit[Vec[w][i]])
                        {
                            que.push(Vec[w][i]);
                            sit[Vec[w][i]]=((sit[w]==1)?2:1);
                        }
                        else
                        {
                            if(sit[Vec[w][i]]==sit[w])
                            {
                                throw(logic_error("Not possible"));
                            }
                        }

                    }
                }
            }
        }
        for (int i=0; i<n; i++)
            cout << i <<" sits at: " <<sit[i] << endl;
        return 0;
    }



};




#endif // SECTASK_H
