#ifndef NaLIRSystem_H
#define NaLIRSystem_H

#include "Query.h"
class NaLIRSystem 
{
    public:
	    int TOPJ; 
	    int TOPK;  
        void conductCommand(std::string&);

    NaLIRSystem()
    {
        /*
         *  TO BE ADDED CONNECTION TO DATABASE
         */
        TOPJ=10;
        TOPK=10;
        
    }
	//public Statement statement;
	//public PrintWriter writer = new PrintWriter("/home/ram/data.txt", "UTF-8");
	//LexicalizedParser lexiParser; 
	//RDBMS db; 
	//Document tokens; 
	//TemplateMapper mapper; 
	//
	//Query nalirQuery; 
	
};
#endif
