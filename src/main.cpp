#include <iostream>
#include <string>
#include "chatbot.cpp"

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
