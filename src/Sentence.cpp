#include<iostream>
#include<string>
#include "Sentence.h"

using namespace std;

void Sentence::wordSplit(std::string& queryInput)
{
    size_t start = queryInput.find("'s");  //Find and replace 's and ' 
    //cout<<start<<endl;
    if( start != std::string::npos) {
        //cout<<"First place\n";
        queryInput.replace(start, std::string("'s").length(), " ");
    }
    //cout<<queryInput<<endl;
    //cout<<start;
    start = queryInput.find("' ");
    if( start != std::string::npos) {
        //cout<<"Second place\n";
        queryInput.replace(start, std::string("' ").length(), " ");
    }
    std::string curWord = "";

    while(queryInput[queryInput.length()-1] == '.' || queryInput[queryInput.length()-1] == ' '  || queryInput[queryInput.length()-1] == '?' || queryInput[queryInput.length()-1] == '\t' || queryInput[queryInput.length()-1] == '\n') // remove the ending ?, ., and so forth;
    {
        //cout<<"coming in here";
        //queryInput.replace(queryInput[queryInput.length()-2], 1, " ");
        //cout<<queryInput<<endl;
        //cout<<queryInput[queryInput.length()-1]<<endl;
        queryInput.replace(queryInput.length()-1, 1, "");
        //queryInput.replace(10, 1, " ");
        //cout<<queryInput<<endl;
        //cout<<queryInput.length()<<endl;
    }
    queryInput.append(" ");
    //cout<<start;
    //cout<<queryInput[queryInput.length()-1]<<endl;
    bool ifCited = false;
    for(unsigned int i = 0; i < queryInput.length(); i++) {
        char c = queryInput[i];
        //cout<<c<<endl;
		if(c == '\t' || c == '\n' || c == ' ') {
		    if(ifCited == false) {
                wordList.push_back(curWord); 
				curWord = ""; 
				while(i < queryInput.length()-1 && (queryInput[i+1] == '\t' || queryInput[i+1] == '\n' 
					|| queryInput[i+1] == ' ' || queryInput[i+1] == ',')) {
						i++; 
				}
			}
			else {
			    curWord += queryInput[i]; 
		    }
		} else if(c == '\'') {
            if(ifCited == false) {
				if(queryInput[i+1] == 't') {
                    curWord += queryInput[i]; 
                } else {
                    wordList.push_back(curWord); 
                    wordList.push_back("\'s"); 
					curWord = ""; 
					if(i < queryInput.length()-1 && queryInput[i+1] == 's') {
                        i++; 
					}
					i++; 
				}
			} else {
					curWord += queryInput[i]; 
			}				
		} else if(c == ',') {
            if(ifCited == false) {
				wordList.push_back(curWord); 
				wordList.push_back(","); 
				curWord = ""; 
                while(i < queryInput.length()-1 && (queryInput[i+1] == '\t' || queryInput[i+1] == '\n' || queryInput[i+1] == ' ' 
					|| queryInput[i+1] == ',')) {
						i++; 
				}
			} else {
				curWord += queryInput[i]; 
			}
		} else if(c == '\"') { 
            if(ifCited == false) {
			    ifCited = true; 
			} else {
				ifCited = false; 
			}
		} else {
			curWord += queryInput[i]; 				
		}
		
    }
}

void Sentence::printForCheck() 
{
    for(unsigned int it=0; it<wordList.size(); it++) {
        cout<<wordList[it]<<endl;

    }
}
