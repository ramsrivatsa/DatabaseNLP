#ifndef Parser_H
#define Parser_H
class TurboParser
{
    public:
        
        std::vector <std::vector <std::string> > treeTable;
        void createConll(std::vector<std::string>);
        void createConllPredictedTags();
        void parseDependencyOutput();
        void viewDependencyOutput();

};
#endif
