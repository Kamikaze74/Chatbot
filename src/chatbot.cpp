#include <vector>
#include <algorithm>
#include <sstream>
#include "node.cpp"

class Chatbot 
{
private:
    
    Node start;
    Node current;
    Node hallo;

    Node newNode(std::string nutzerEingabe, std::string id, std::string text)
    {
        Node node = Node(nutzerEingabe, id, text);
        node.verlaufPush(hallo);
        return node;
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
        start = newNode("","","Wie kann ich dir sonst noch helfen?");
        hallo = newNode("hallo", "0.0", "Guten Tag, wie kann ich helfen?");
        hallo.setRepetable(true);
        Node software = newNode("software", "1.0", "Schalten Sie den Flugmodlus aus.");
        Node hardware = newNode("hardware", "2.0", "Stellen Sie den Schalter auf EIN.");
        Node lan = newNode("lan", "3.0", "Geben Sie in einem Terminal mal ipconfig ein und schauen Sie, ob Sie eine IP-Adresse, Netzmaske und ein Gateway haben.");
        Node wlan = newNode("wlan", "4.0", "Haben Sie die WLAN-Karte vielleicht hardwareseitig oder softwareseitig ausgeschaltet?");
        Node netzwerk = newNode("netzwerk", "5.0", "Haben Sie WLAN oder LAN?");

        start.verlaufPush(software);
        start.verlaufPush(hardware);
        start.verlaufPush(lan);
        start.verlaufPush(wlan);
        start.verlaufPush(netzwerk);
        start.verlaufPush(hallo);
        current = start;
    }

    void respondNode(std::string userInput) 
    {
        current.text = "Sorry, das habe ich leider nicht verstanden.";
        
        std::string lowerInput = toLowerCase(userInput);

        if (lowerInput.compare("an anfang") == 0)
            current = start;

        if(lowerInput.compare(current.nutzerEingabe) == 0)
            current.text = "Du wiederholst Dich!";

        current.nutzerEingabe = lowerInput;

        for(int i = 0; i < current.verlauf.size(); i++)
            if(current.verlauf[i].nutzerEingabe.compare(lowerInput) == 0 && current.text.compare(lowerInput) != 0)
            {
                 if(current.verlauf[i].repetable)
                    current.verlauf[i].verlauf = current.verlauf;
                current = current.verlauf[i];
            }

       
    }

    bool abschied(std::string userInput)
    {
        std::string lowerInput = toLowerCase(userInput);
        return lowerInput == "exit" || lowerInput == "quit" || lowerInput == "ciao";
    }

    std::string respond(std::string userInput){
        
        if (userInput.empty())
            return "Koennten Sie bitte etwas lauter sprechen.";

        respondNode(userInput);
        return current.text;
    }
};