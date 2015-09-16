#include<iostream>
#include<string>
#include "NaLIRSystem.h"
#include "Sentence.h"
using namespace std;

int main() {
    NaLIRSystem system;
    //cout << "Start of the program"<<endl;
    string command = "##2_query## show me the papers' on VLDB.";
    //cout << command << endl;
    system.conductCommand(command);

}

void NaLIRSystem::conductCommand(std::string& command)
{
    //cout<<"command is\t"<<command<<endl;
    //queryInput.replace(17, 2, "ram");

    if(command.find("##2_query##") != std::string::npos) {
        std::string delimiter = "## ";
        std::string queryInput = command.substr(command.find(delimiter) + delimiter.length(), command.length());
        Query nalirQuery(queryInput);
        //cout<<command.find_first_of("##2_query##")<<endl;
        //cout<<queryInput<<endl;
    }
		//{
		//	if(command.split("## ").length > 1)
		//	{
		//		String queryInput = command.split("## ")[1];
		//		long startTime = System.nanoTime();
		//		nalirQuery = new Query(queryInput, db.schemaGraph); // Step 1. given a natural language and a schema graph, build a nalirQuery: including translate a sentence into an object Sentence;
		//		long endTime = System.nanoTime();
		//		long duration = (endTime - startTime);
		//		System.out.println(duration/1000);
		//		writer.println(duration/1000);
		//		//for(int it=0; it<nalirQuery.sentence.outputWords.length; it++){
		//		//	System.out.println(nalirQuery.sentence.outputWords[it].toString());
		//        //}
		//		startTime = System.nanoTime();
		//		StanfordNLParser.parse(nalirQuery, lexiParser); // Step 2. given a natural language query and a schema graph, use stanford parser to parse it into a parse tree;
		//		endTime = System.nanoTime();
		//		duration = (endTime - startTime);
		//		System.out.println(duration/1000);
		//		writer.println(duration/1000);
		//		//System.out.println(nalirQuery.parseTree);
		//		startTime = System.nanoTime();
		//		NodeMapper.phraseProcess(nalirQuery, db, tokens); // Step 3. tokenize the parse tree;
		//		//System.out.println(nalirQuery.parseTree);
		//		EntityResolution.entityResolute(nalirQuery);
		//		//System.out.println(nalirQuery.parseTree);
		//		TreeStructureAdjustor.treeStructureAdjust(nalirQuery, db);
		//		endTime = System.nanoTime();
		//		duration = (endTime - startTime);
		//		System.out.println(duration/1000);
		//		writer.println(duration/1000);
		//		//System.out.println(nalirQuery.parseTree);

		//		//System.out.println(nalirQuery.parseTree);
		//		//System.out.println(PrintForCheck.allParseTreeNodePrintForCheck(nalirQuery.parseTree)); 

		//		String json_query = PrintForCheck.jsonOutput(nalirQuery).toString();
		//		//System.out.println(json_query);
		//		ArrayList<Integer> mappedTemplates = mapper.map(json_query); 
		//		
		//		nalirQuery.mappedTemplates.clear();
		//		nalirQuery.mappedTemplates.addAll(mappedTemplates);
		//		startTime = System.nanoTime();
		//		nalirQuery.instantiate(db.templates);
		//		endTime = System.nanoTime();
		//		duration = (endTime - startTime);
		//		System.out.println(duration/1000);
		//		writer.println(duration/1000);
		//		writer.println("-----------------------------");
		//		//System.out.println(nalirQuery.translatedSQL);
		//		
		//		
		//		htmlGen(nalirQuery, html); 
		//	}
		//}
		//else if(command.startsWith("##3_mapSchema##"))
		//{
		//	if(command.split(" ").length > 2)
		//	{
		//		int id = Integer.parseInt(command.split(" ")[1]); 
		//		int value = Integer.parseInt(command.split(" ")[2]); 
		//		
		//		nalirQuery.parseTree.searchNodeByOrder(id).choice = value; 
		//		EntityResolution.entityResolute(nalirQuery); 
		//		TreeStructureAdjustor.treeStructureAdjust(nalirQuery, db); 

		//		String json_query = PrintForCheck.jsonOutput(nalirQuery).toString(); 
		//		ArrayList<Integer> mappedTemplates = mapper.map(json_query); 
		//		
		//		nalirQuery.mappedTemplates.clear();
		//		nalirQuery.mappedTemplates.addAll(mappedTemplates); 
		//		nalirQuery.instantiate(db.templates);
		//		
		//		htmlGen(nalirQuery, html); 
		//	}
		//}
		//else if(command.startsWith("##4_mapValue##"))
		//{
		//	if(command.split(" ").length > 2)
		//	{
		//		int id = Integer.parseInt(command.split(" ")[1]); 
		//		int value = Integer.parseInt(command.split(" ")[2]); 
		//		
		//		ParseTreeNode node = nalirQuery.parseTree.searchNodeByOrder(id); 
		//		node.mappedElements.get(node.choice).choice = value; 
		//		EntityResolution.entityResolute(nalirQuery); 
		//		TreeStructureAdjustor.treeStructureAdjust(nalirQuery, db); 

		//		String json_query = PrintForCheck.jsonOutput(nalirQuery).toString(); 
		//		ArrayList<Integer> mappedTemplates = mapper.map(json_query); 
		//		
		//		nalirQuery.mappedTemplates.clear();
		//		nalirQuery.mappedTemplates.addAll(mappedTemplates); 
		//		nalirQuery.instantiate(db.templates);
		//		
		//		htmlGen(nalirQuery, html); 
		//	}
		//}
		//else if(command.startsWith("##5_mapTemplate##"))
		//{
		//	if(command.split(" ").length > 1)
		//	{
		//		int select = Integer.parseInt(command.split(" ")[1]); 
		//		nalirQuery.selectedTemplate = select; 
		//		htmlGen(nalirQuery, html); 
		//	}
		//}
		//else if(command.startsWith("##6_getResult##"))
		//{
		//	try
		//	{
		//		System.out.println(nalirQuery.translatedSQL.get(nalirQuery.selectedTemplate));
		//		nalirQuery.finalResult = db.conductSQL(nalirQuery.translatedSQL.get(nalirQuery.selectedTemplate)); 
		//	}
		//	catch(Exception e)
		//	{}
		//	htmlGen(nalirQuery, html); 
		//}
		//
		//return html.toJSONString(); 
    //cout<<command<<endl;


}

//void Sentence::wordSplit(std::string& queryInput)
//{
//    size_t start = queryInput.find("'s");  //Find and replace 's and ' 
//    //cout<<start<<endl;
//    if( start != std::string::npos) {
//        //cout<<"First place\n";
//        queryInput.replace(start, std::string("'s").length(), " ");
//    }
//    //cout<<queryInput<<endl;
//    //cout<<start;
//    start = queryInput.find("' ");
//    if( start != std::string::npos) {
//        //cout<<"Second place\n";
//        queryInput.replace(start, std::string("' ").length(), " ");
//    }
//    std::string curWord = "";
//
//    while(queryInput[queryInput.length()-1] == '.' || queryInput[queryInput.length()-1] == ' '  || queryInput[queryInput.length()-1] == '?' || queryInput[queryInput.length()-1] == '\t' || queryInput[queryInput.length()-1] == '\n') // remove the ending ?, ., and so forth;
//    {
//        //cout<<"coming in here";
//        //queryInput.replace(queryInput[queryInput.length()-2], 1, " ");
//        //cout<<queryInput<<endl;
//        //cout<<queryInput[queryInput.length()-1]<<endl;
//        queryInput.replace(queryInput.length()-1, 1, "");
//        //queryInput.replace(10, 1, " ");
//        //cout<<queryInput<<endl;
//        //cout<<queryInput.length()<<endl;
//    }
//    queryInput.append(" ");
//    //cout<<start;
//    //cout<<queryInput[queryInput.length()-1]<<endl;
//    bool ifCited = false;
//    for(unsigned int i = 0; i < queryInput.length(); i++) {
//        char c = queryInput[i];
//        //cout<<c<<endl;
//		if(c == '\t' || c == '\n' || c == ' ') {
//		    if(ifCited == false) {
//                wordList.push_back(curWord); 
//				curWord = ""; 
//				while(i < queryInput.length()-1 && (queryInput[i+1] == '\t' || queryInput[i+1] == '\n' 
//					|| queryInput[i+1] == ' ' || queryInput[i+1] == ',')) {
//						i++; 
//				}
//			}
//			else {
//			    curWord += queryInput[i]; 
//		    }
//		} else if(c == '\'') {
//            if(ifCited == false) {
//				if(queryInput[i+1] == 't') {
//                    curWord += queryInput[i]; 
//                } else {
//                    wordList.push_back(curWord); 
//                    wordList.push_back("\'s"); 
//					curWord = ""; 
//					if(i < queryInput.length()-1 && queryInput[i+1] == 's') {
//                        i++; 
//					}
//					i++; 
//				}
//			} else {
//					curWord += queryInput[i]; 
//			}				
//		} else if(c == ',') {
//            if(ifCited == false) {
//				wordList.push_back(curWord); 
//				wordList.push_back(","); 
//				curWord = ""; 
//                while(i < queryInput.length()-1 && (queryInput[i+1] == '\t' || queryInput[i+1] == '\n' || queryInput[i+1] == ' ' 
//					|| queryInput[i+1] == ',')) {
//						i++; 
//				}
//			} else {
//				curWord += queryInput[i]; 
//			}
//		} else if(c == '\"') { 
//            if(ifCited == false) {
//			    ifCited = true; 
//			} else {
//				ifCited = false; 
//			}
//		} else {
//			curWord += queryInput[i]; 				
//		}
//		
//    }
//}

 
