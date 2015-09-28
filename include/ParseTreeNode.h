#ifndef Parse_Tree_Node_H
#define Parse_Tree_Node_H
#include<string>

extern int NODEID;
class ParseTreeNode 
{
    public:
    
	int nodeID; 
	int wordOrder; // word order in the sentence; 
    std::string label; // word itself; 
	std::string pos; // part of speech; 
	std::string relationship; // dependency relationship; 
	std::string tokenType; // CMT, NT, VT and so forth; 
	std::string function; // only exist in OT and FT; 
	//ArrayList<ParseTreeNode> children = new ArrayList<ParseTreeNode>(); 
    ParseTreeNode *parent;
    std::vector <ParseTreeNode> children;


    std::string QT; 
	std::string prep; 
	std::string leftRel; 
	//ArrayList<MappedSchemaElement> mappedElements = new ArrayList<MappedSchemaElement>(); 
	int choice; 
	bool isAdded; 

    ParseTreeNode ()
    {
        //NODEID = 0; 
	    wordOrder = -1; // word order in the sentence; 
	    pos = "NA"; // part of speech; 
	    relationship = "NA"; // dependency relationship; 
	    tokenType = "NA"; // CMT, NT, VT and so forth; 
	    function = "NA"; // only exist in OT and FT; 
	    //ArrayList<ParseTreeNode> children = new ArrayList<ParseTreeNode>(); 

	    QT = ""; 
	    prep = ""; 
	    leftRel = ""; 
	    //ArrayList<MappedSchemaElement> mappedElements = new ArrayList<MappedSchemaElement>(); 
	    choice = -1; 
	    isAdded = false; 
    }

    ParseTreeNode(int wordOrder, std::string label, std::string pos, std::string relationship, ParseTreeNode *parent) 
    {
        nodeID = NODEID;
        NODEID++; 
        this->wordOrder = wordOrder; 
        this->label = label; 
        this->pos = pos; 
        this->relationship = relationship; 
        this->parent = parent;   

    }
	
	//void ParseTreeNode(int wordOrder, string label, string pos, string relationship, ParseTreeNode parent) // node exist in sentence;
	//{
	//	this.nodeID = NODEID;
	//	NODEID++; 
	//	this.wordOrder = wordOrder; 
	//	this.label = label; 
	//	this.pos = pos; 
	//	this.relationship = relationship; 
	//	this.parent = parent; 		
	//}

};
#endif
