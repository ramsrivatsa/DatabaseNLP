#ifndef Parse_Tree_H
#define Parse_Tree_H
#include<vector>
#include "ParseTreeNode.h"

class ParseTree 
{
    public:
        void buildNode(std::vector<std::string> input);
        ParseTreeNode root;
        std::vector <ParseTreeNode> allNodes;
        std::vector <ParseTreeNode> parseTreeNodes;
        
        ParseTree()
        {
            root.wordOrder = 0;
            root.label = "ROOT";
            root.pos = "ROOT";
            root.relationship = "ROOT";
            root.parent = NULL;
            //ParseTreeNode root(0, "ROOT", "ROOT", "ROOT", NULL);
            allNodes.push_back(root);
            root.tokenType = "ROOT";
            
        }

};
#endif
