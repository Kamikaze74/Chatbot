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
        Node(){};
        Node(std::string nutzerEingabe, std::string node_id, std::string text){
            this->nutzerEingabe = nutzerEingabe; this->node_id = node_id; this->text = text;
        }

        // also & für eine referenz sonst wird eine kopie übergeben der den objekt selbst nicht verändert??
        // vielleicht auch noch verbesserungen mit const (wenn ich wüsste wie das geht) // erstellt keien kopien??
        std::vector<Node>& getVerlauf()  {   return verlauf;          }
        bool& getRepetable()             {   return repetable;        }
        void verlaufPush(Node node)     {   verlauf.push_back(node); }
        void setRepetable( bool x)      {   repetable = x;           }
        std::string& getNutzerEingabe()  {   return nutzerEingabe;    }
        std::string& getText()           {   return text;             }
        void setText(std::string text)  {   this-> text = text;      }
};