//
// BFS.
// has a static method that run the algorithm.
//

#ifndef EX1_BFS_H
#define EX1_BFS_H

#include "../coordinates/Point.h"
#include "../coordinates/Grid.h"
#include "../coordinates/Node.h"

class BFS {
public:
    static stack<CoordinatedItem *> *use(Grid *Graph, CoordinatedItem *root, CoordinatedItem *dest);

    static void BFSAlgo(Grid *Graph, CoordinatedItem *root);

    static stack<CoordinatedItem *> *getTrip(CoordinatedItem *dest);
};


#endif //EX1_BFS_H
