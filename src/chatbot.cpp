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
        std::string node_id;
        std::string text;
        std::vector<Node> verlauf;
    };
    

    std::string toLowerCase(std::string input)
        {
        std::string isLowerCase = input;
        std::transform(isLowerCase.begin(), isLowerCase.end(), isLowerCase.begin(),  // von, bis, nach,
        [](unsigned char c){ return std::tolower(c);});                            // transmutaion (änderung) PK1 Lambda ausdruck. [] beginn eined Labdausdrucks

        return isLowerCase;
    }

public:

    Node start;



    Chatbot() 
    {
        // Dialogbaum mit Note
        Node hallo;
        hallo.nutzerEingabe = "hallo";
        hallo.node_id = "0.0";
        hallo.text = "Guten Tag, wie kann ich helfen?";

            Node software;
                software.nutzerEingabe = "software";
                software.node_id = "1.0";
                software.text = "Schalten Sie den Flugmodus aus.";

            Node hardware;
                hardware.nutzerEingabe = "hardware";
                hardware.node_id = "2.0";
                hardware.text = "Stellen Sie den Schalter auf EIN.";

            Node lan;
                lan.nutzerEingabe = "lan";
                lan.node_id = "3.0";
                lan.text = "Geben Sie in einem Terminal mal ipconfig ein und schauen Sie, ob Sie eine IP-Adresse, Netzmaske und ein Gateway haben.";

            Node wlan;
                wlan.nutzerEingabe = "wlan";
                wlan.node_id = "4.0";
                wlan.text = "Haben Sie die WLAN-Karte vielleicht hardwareseitig oder softwareseitig ausgeschaltet?";
            
            Node netzwerk;
                netzwerk.nutzerEingabe = "netzwerk";
                netzwerk.node_id = "5.0";
                netzwerk.text = "Haben Sie WLAN oder LAN?";

        hallo.verlauf.push_back(software);
        hallo.verlauf.push_back(hardware);
        hallo.verlauf.push_back(lan);
        hallo.verlauf.push_back(wlan);
        hallo.verlauf.push_back(netzwerk);

        start.verlauf.push_back(hallo);


    }

    Node respondNode(std::string userInput) 
    {
        if (userInput.empty())
        {
            Node leise;
            leise.text = "Koennten Sie bitte etwas lauter sprechen.";
            leise.verlauf = start.verlauf;
            return leise;
        }

        std::string lowerInput = toLowerCase(userInput);

        for(Node x : start.verlauf)
            if(x.nutzerEingabe.compare(lowerInput) == 0)
                return x;

        Node wieBitte;
        wieBitte.nutzerEingabe = "Geben Sie in einem Terminal mal ipconfig ein und schauen Sie, ob Sie eine IP-Adresse, Netzmaske und ein Gateway haben.";
        wieBitte.verlauf = start.verlauf;
        return wieBitte;
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