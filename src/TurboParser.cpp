#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<vector>
#include "TurboParser.h"
#include "ParseTree.h"

using namespace std;


void TurboParser::createConll(std::vector<std::string> words)
{
  std::vector<std::string>::iterator it;
  it = words.begin();
  int iterate = 0;
  ofstream conllTagging;
  conllTagging.open("../data/NaLIR.conll.tagging"); 
  for (it = words.begin(); it<words.end(); it++) {
      //std::cout << iterate <<"\t" << *it <<endl;
      conllTagging << *it <<"\t_" << endl;
      ++iterate;
  }
  conllTagging.close();


}

void TurboParser::parseDependencyOutput()
{
    std::vector <std::string> treeTableEntry;
    std::string line;
    std::ifstream inputFile("../data/NaLIR.conll.predpos.pred");
    int tempPos=0;
    int tempCount;
    std::string tempString;
    std::string subString;
    while (std::getline(inputFile, line))
    {
        //cout << line <<endl;
        std::istringstream iss(line);
        tempString = line;
        tempCount=0;
        while(tempString.find("\t") != std::string::npos) {
          //cout << "a" << tempString <<endl;
          subString = tempString.substr(0,tempString.find("\t"));
          tempPos = tempString.find("\t") + 1;
          //cout << "b" << subString <<"-end sub " << tempPos<< "-end temppos" <<endl;
          tempString = tempString.substr(tempPos,tempString.length());
          //cout << "c" << tempString <<endl;
          if(tempCount == 0 || tempCount == 1 || tempCount == 3 || tempCount == 6 || tempCount == 7 )
            treeTableEntry.push_back(subString);
          ++tempCount;
        }
        treeTableEntry.push_back(tempString);
        treeTable.push_back(treeTableEntry);
        treeTableEntry.clear();
        //here you should dump tempstring also
    }
}

void TurboParser::viewDependencyOutput() 
{
    //cout << treeTable.size() << endl;
    std::vector <std::vector <std::string> >::iterator row;
    std::vector <std::string>::iterator column;
    for (row = treeTable.begin(); row != treeTable.end(); row++) {

        //cout << (*row).size() << endl;
      for (column = row->begin(); column != row->end(); column++) {
          cout << *column << " ";
      }
      cout << endl;
    }
}

void TurboParser::createConllPredictedTags()
{
//  std::vector<std::string>::iterator it;
//  it = words.begin();
//  for (it = words.begin(); it<words.end(); it++) {
//      conllTagging << iterate <<"\t" << *it <<"\t" <<"_" << endl;
//      //conllTagging << *it <<"\t_" << endl;
//      ++iterate;
//  }
//  conllTagging.close();
//
    std::string line;
    std::ifstream inputFile("../data/NaLIR.conll.tagging.pred");
    std::string first,second;
    int iterate = 0;
    ofstream conllTagging;
    conllTagging.open("../data/NaLIR.conll.predpos"); 
    while (std::getline(inputFile, line))
    {
        ++iterate;
        std::istringstream iss(line);
        //cout << line <<endl;
        first = line.substr(0,line.find("\t"));
        second = line.substr(line.find("\t")+1,line.length());
        //cout<< first << " and " << second << endl;
        if(!line.empty()) {
            conllTagging<< iterate << "\t" <<first << "\t" << "_"  << "\t" << second << "\t" << second<< "\t" << "_" << "\t" << "_" << "\t" << "_" <<endl;
        }
    }
    conllTagging.close();

}

void TurboParser::buildTree()
{
    bool *doneList;
    int sizeOfTree = treeTable.size();
    doneList = new bool[sizeOfTree];
    ParseTree tree;
    //cout << sizeof(doneList) << " " << sizeOfTree<<endl;
    for (int i=0; i<sizeOfTree; i++) {
        doneList[i] = false;
    }
    //cout << treeTable[1][0][0] << endl;
    
    for (int i=0; i<sizeOfTree; i++) {
        //cout << treeTable[i][1] << endl;
        //cout << i <<endl;
        if(treeTable[i][0][0] != 0 && treeTable[i][3] == "0") {
            //cout<<"once coming here \n";
            tree.buildNode(treeTable[i]);
            doneList[i] = true;
        }
    }

}
