#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Chatbot 
{
private:
    
    struct Node
    {
        std::string nutzerEingabe;
        std::string node_id = "";
        std::string text = "";
        std::vector<Node> verlauf;
    };

    Node start;
    Node backToRoot;

    Node newNode(std::string nutzerEingabe, std::string id, std::string text)
    {
        Node node;
        node.nutzerEingabe = nutzerEingabe;
        node.node_id = id;
        node.text = text;
        node.verlauf.push_back(backToRoot);
    }

    std::string toLowerCase(std::string input)
        {
        std::string isLowerCase = input;
        std::transform(isLowerCase.begin(), isLowerCase.end(), isLowerCase.begin(),  // von, bis, nach,
        [](unsigned char c){ return std::tolower(c);});                            // transmutaion (änderung) PK1 Lambda ausdruck. [] beginn eined Labdausdrucks

        return isLowerCase;
    }

public:

    Chatbot() 
    {
        // Dialogbaum mit Note
        backToRoot = newNode("neustart", "0.1", "Wie kann ich sonst noch Helfen?");
        Node hallo = newNode("hallo", "0.0", "Guten Tag, wie kann ich helfen?");
        Node software = newNode("software", "1.0", "Schalten Sie den Flugmodlus aus.");
        Node hardware = newNode("hardware", "2.0", "Stellen Sie den Schalter auf EIN.");
        Node lan = newNode("lan", "3.0", "Geben Sie in einem Terminal mal ipconfig ein und schauen Sie, ob Sie eine IP-Adresse, Netzmaske und ein Gateway haben.");
        Node wlan = newNode("wlan", "4.0", "Haben Sie die WLAN-Karte vielleicht hardwareseitig oder softwareseitig ausgeschaltet?");
        Node netzwerk = newNode("netzwerk", "5.0", "Haben Sie WLAN oder LAN?");

        start.verlauf.push_back(software);
        start.verlauf.push_back(hardware);
        start.verlauf.push_back(lan);
        start.verlauf.push_back(wlan);
        start.verlauf.push_back(netzwerk);
        start.verlauf.push_back(hallo);
        start.verlauf.push_back(backToRoot);
    }

    Node respondNode(std::string userInput) 
    {
        start.text = "Sorry, das habe ich leider nicht verstanden.";

        if (userInput.empty())
            start.text = "Koennten Sie bitte etwas lauter sprechen.";
        
        std::string lowerInput = toLowerCase(userInput);

        if(lowerInput.compare(start.nutzerEingabe) == 0)
            start.text = "Du wiederholst Dich!";

        for(Node x : start.verlauf)
            if(x.nutzerEingabe.compare(lowerInput) == 0)
                return x;

        
        start.nutzerEingabe = lowerInput;
        return start;
    }

    bool abschied(std::string userInput)
    {
        std::string lowerInput = toLowerCase(userInput);

        return lowerInput == "exit" || lowerInput == "quit" || lowerInput == "ciao";
    }

    std::string respond(std::string userInput){
        start = respondNode(userInput);
        return start.text;
    }
};