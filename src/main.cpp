#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Chatbot 
{
private:
    std::vector<std::pair<std::string, std::string>> dictionary;        // verschachtele vektor (datenstrucktur) mit pair obekjekten die zwei strings speichert

    std::string toLowerCase(const std::string& input) const             // & referenz auf das objekt und keine copie. const verändert das objekt nicht
    {
        std::string isLowerCase = input;
        std::transform(isLowerCase.begin(), isLowerCase.end(), isLowerCase.begin(),  // von, bis, nach,
        [](unsigned char c){ return std::tolower(c);});                            // transmutaion (änderung) PK1 Lambda ausdruck. [] beginn eined Labdausdrucks

        return isLowerCase;
    }

public:
    Chatbot() 
    {
        dictionary.push_back({"software","Schalten Sie den Flugmodus aus."});
        dictionary.push_back({"hardware", "Stellen Sie den Schalter auf EIN."});
        dictionary.push_back({"lan", "Geben Sie in einem Terminal mal ipconfig ein und schauen Sie, ob Sie eine IP-Adresse, Netzmaske und ein Gateway haben."});
        dictionary.push_back({"wlan", "Haben Sie die WLAN-Karte vielleicht hardwareseitig oder softwareseitig ausgeschaltet?"});
        dictionary.push_back({"netzwerk","Haben Sie WLAN oder LAN?"});
        dictionary.push_back({"hallo", "Guten Tag, wie kann ich helfen?"});
    }

    std::string respond(const std::string& userInput) 
    {
        if (userInput.empty())
            return "Koennten Sie bitte etwas lauter sprechen.";

        std::string lowerInput = toLowerCase(userInput);

        for (const auto x : dictionary)
            if(lowerInput == x.first)
                return x.second;

        return "Tut mir leid, das habe ich nicht verstanden.";
    }

    bool abschied(const std::string& userInput) const
    {
        std::string lowerInput = toLowerCase(userInput);

        return lowerInput == "exit" || lowerInput == "quit" || lowerInput == "ciao";
    }
};

int main() 
{
    Chatbot bot;

    std::cout << "\nChatbot: Hallo! Wie kann ich helfen?";

    std::string input;

    do
    {
        std::cout << "\n> ";
        std::getline(std::cin, input);

        if (bot.abschied(input))
            break;

        std::cout << "\nChatbot: " << bot.respond(input);

    } while (true);
    

    std::cout << "Chatbot: Auf Wiedersehen!\n";
    return 0;
}
