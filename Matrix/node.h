#ifndef NODE_H
#define NODE_H

#include "GUI/Element.h"
#include "Link.h"

class Node : public Element
{
public:
     Node(int posX, int posY, int width, int height);

private:
    Link ** link;
    int value;

};

#endif // NODE_H
