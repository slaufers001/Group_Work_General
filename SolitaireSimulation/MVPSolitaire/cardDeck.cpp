#include <stdlib.h>     /* srand, rand */
#include <iostream>
#include <list>
#include "Card.cpp"
#include<random>


class cardDeck {
    public:
std::vector<Card> unShuffle;
std::list<Card> shuffled;
int randomInt;

//constructs a card instance made up of the cards number,
//suit and whether its value is visible to the user or not
    cardDeck(){
        makeClub();
        //shuffleDeck();
        makeSpade();
        //shuffleDeck();
        makeHeart();
        //shuffleDeck();
        makeDiamond();
        shuffleDeck();

        //for(std::list<Card>::iterator it=unShuffle.begin(); it != unShuffle.end(); ++it)
        //    std::cout <<  it->toString();



        //for(std::list<Card>::iterator it=shuffled.begin(); it != shuffled.end(); ++it)
          //  std::cout <<  it->toString();
    }
        //used to construct pass/fail test decks
        //@param test indicates whether the deck should pass(test = 0) or fail(test = 0)
        cardDeck(int test){
            if(test == 0){
                //construct first part of deck

                for(int i = 13; i >= 4; i--){
                    shuffled.emplace_back(i, "C", false);
                }
                 for(int i = 13; i >= 3; i--){
                    shuffled.emplace_back(i, "S", false);
                }
                shuffled.emplace_back(13, "H", false);
                shuffled.emplace_back(12, "H", false);
                for(int i = 3; i >= 1; i--){
                    shuffled.emplace_back(i, "C", false);
                }
                shuffled.emplace_back(2, "S", false);
                shuffled.emplace_back(1, "S", false);
                for(int i = 1; i <= 13; i++){
                    shuffled.emplace_back(i, "D", false);
                }
                for(int i = 1; i <= 11; i++){
                    shuffled.emplace_back(i, "H", false);

            }
            // for (Card card: shuffled){
            //     std::cout<<card.toString()<<"\n";
            // }
            }
        }
    void makeDiamond(){
       for(int i= 1; i <= 13; i = i + 1){
           unShuffle.emplace_back(i, "D", false);
       }
   }
   void makeSpade(){
       for(int i= 1; i <= 13; i = i + 1){
           unShuffle.emplace_back(i, "S", false);
       }
   }
   void makeHeart(){
       for(int i= 1; i <= 13; i = i + 1){
           unShuffle.emplace_back(i, "H", false);
       }
   }
   void makeClub(){
       for(int i= 1; i <= 13; i = i + 1){
           unShuffle.emplace_back(i, "C", false);
       }
   }

   //Shuffles the deck using the original fisher yates theory
   std::list<Card> shuffleDeck(){
       for(int n = unShuffle.size(); n > 0; n--){
           srand(time(NULL));
           randomInt = rand() % unShuffle.size();
           //std::cout<< randomInt<< "||";
           Card temp = unShuffle[randomInt];
           shuffled.push_back(temp);
           unShuffle.erase(unShuffle.begin() + randomInt);
        }

        return shuffled;
   }
};


