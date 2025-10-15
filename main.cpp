#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

class Chatbot 
{
public:
    Chatbot() 
    {
        // Konstruktor
    }

    std::string respond(const std::string& userInput) 
    {
        return "Tut mir leid, das habe ich nicht verstanden.";
    }
};

int main() 
{
    Chatbot bot;

    std::cout << "Chatbot: Hallo! Wie kann ich helfen?\n";
    std::string input;

    std::cout << "> ";
    std::getline(std::cin, input);
    std::cout << "Chatbot: " << input << "\n";

    std::cout << "Chatbot: Auf Wiedersehen!\n";
    return 0;
}
