#include <vector>
#include <algorithm>
#include <sstream>
#include "node.cpp"

class Chatbot 
{
private:
    
    Node start;     // start node
    Node current;   // node sich fortzubewegen
    Node hallo;     // node's die in jeder anderen node enthaleten sein sollen auch als seperaten vector realisierbar

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
        [](unsigned char c){ return std::tolower(c);});                            // transmutaion (änderung) PK1 Lambda ausdruck. ??[] beginn eined Labdausdrucks

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
        current.setText("Sorry, das habe ich leider nicht verstanden.");

        if(userInput.compare(current.getNutzerEingabe()) == 0)  // innerhalb von dieser methode sind gleiche eingaben erlaubt solange sie im verlauf vorhanden sind
            current.setText("Du wiederholst Dich!");

        current.getNutzerEingabe() = userInput;

        // & um eine referenz zu dem obejkt zu erhalten
        for(Node& x : current.getVerlauf())
            if(x.getNutzerEingabe().compare(userInput) == 0 && current.getText().compare(userInput) != 0)
            {
                 if(x.getRepetable())
                    x.getVerlauf() = current.getVerlauf();

                current = x;
                break;
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

        std::string lowerInput = toLowerCase(userInput);

        if (userInput.compare("an anfang") == 0)
            current = start; return current.getText();

        respondNode(lowerInput);
        return current.getText();
    }
};