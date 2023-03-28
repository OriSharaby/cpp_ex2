#include <string>

using namespace std;

namespace ariel
{
    class Card
    {
    private:
        Card(int value, string type);
        Card();
        int compareto(Card card);
    };
    
}