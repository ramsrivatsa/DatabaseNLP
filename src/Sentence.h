#ifndef Sentence_H
#define Sentence_H
#include<vector>
class Sentence 
{
	//public ArrayList<String> wordList = new ArrayList<String>(); 
	//public String [] outputWords; 
	//
    public:
        void wordSplit(std::string&);
        void printForCheck();
        std::vector<std::string> wordList; // output words and this datastructure signifies the same thing
	    Sentence(std::string& queryInput) // Step 1. split a nlq into a wordlist; 
	    {
		    wordSplit(queryInput);
            //printForCheck();
	//	outputWords = new String [wordList.size()]; 
	//	for(int i = 0; i < outputWords.length; i++)
	//	{
	//		outputWords[i] = wordList.get(i); 
	//	}
	    }
	//
	// Step 1. split a sentence into a list of words (words), in which words in " " are considered as one word;  
	//
	//public String printForCheck()
	//{
	//	String result = ""; 
	//	for(int i = 0; i < outputWords.length; i++)
	//	{
	//		result += "\"" + outputWords[i] + "\" "; 
	//	}
	//	System.out.println(result); 
	//	return result + "\n"; 
	//}
};
#endif
