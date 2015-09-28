#include<iostream>
#include<cstdlib>
#include<string>
#include "ParseTree.h"
using namespace std;
int NODEID=0;
bool ParseTree::buildNode(std::vector<std::string> input)
{
    int temp;
    if(root.children.empty()) {
        //cout << input[0] <<"inga vantha podhum \n";
        temp = atoi(input[0].c_str());
        ParseTreeNode node(temp, input[1], input[2], input[4], &root);
        //cout << node.label<<endl;
        root.children.push_back(node);
        allNodes.push_back(node);
        return true;
    } else {
        std::vector <ParseTreeNode> list;
        list.push_back(root);
        while(!list.empty()) {
            ParseTreeNode parent = list.front();
            list.erase(list.begin());
            if(parent.wordOrder == atoi(input[3].c_str())) {
                temp = atoi(input[0].c_str());
                ParseTreeNode node(temp, input[1], input[2], input[4], &parent);
                parent.children.push_back(node);
                allNodes.push_back(node);
                return true;
            }
            list = parent.children;   
        }

    }
    return false;
}

//int convertString(const char *s)
//{
//    int i;
//    i = 0;
//    while(*s >= '0' && *s <= '9') {
//        i = i * 10 + (*s - '0');
//        s++;
//    }
//    return i;
//}
