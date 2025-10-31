#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "src/chatbot.cpp"



TEST_CASE( "finde passende antwort", "[Chatbot]" ) {
    
    Chatbot bot; 

    auto check_response = [&](const std::string& input, const std::string& expected_output) {
        REQUIRE( bot.respond(input) == expected_output );
    };

    SECTION( "test_exit" ) {
        
        REQUIRE( bot.abschied("exit") == true );
        REQUIRE( bot.abschied("QUIT") == true );
        REQUIRE( bot.abschied("ciao") == true );
        REQUIRE( bot.abschied("Exit") == true );
        REQUIRE( bot.abschied("hallo") == false );
    }

    SECTION( "kein input" ) {
        check_response("", "Koennten Sie bitte etwas lauter sprechen.");
    }

    SECTION( "passen die antworten" ) {
        
        check_response("irgendwas", "Sorry, das habe ich leider nicht verstanden."); 
        
        check_response("irgendwas", "Du wiederholst Dich!"); 
        
        check_response("hallo", "Guten Tag, wie kann ich helfen?");
        
        check_response("keine chance", "Sorry, das habe ich leider nicht verstanden."); 

        check_response("keine chance", "Du wiederholst Dich!"); 
    }

    SECTION( "noch ein chatverlauf" ) {

        check_response("software", "Schalten Sie den Flugmodlus aus.");

        check_response("hallo", "Guten Tag, wie kann ich helfen?");
        
        check_response("hallo", "Du wiederholst Dich!");

        check_response("an anfang", "Wie kann ich dir sonst noch helfen?");
        
        check_response("an anfang", "Du wiederholst Dich!");
    }
}