#include <sstream>
#include <vector>

class Node
{
    private:    
        std::string nutzerEingabe;
        std::string node_id = "";
        std::string text = "";
        std::vector<Node> verlauf;
        bool repetable = false;

    public:
        Node(std::string nutzerEingabe, std::string node_id, std::string text){
            this->nutzerEingabe = nutzerEingabe; this->node_id = node_id; this->text = text;
        }

        
        std::vector<Node> verlauf(){    return verlauf; }
        void verlaufPush(Node node){    verlauf.push_back(node);    }
        void setRepetable( bool x){     repetable = x;  }
};