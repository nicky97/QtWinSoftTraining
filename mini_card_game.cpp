#include<iostream>
#include<algorithm>
using namespace std;



typedef pair<char,int> card;//define new type pair

//Definition of class player
class Player{
private:
    card * ptr;//how many cards does player have
    int size;//numbers of the cards
    int score;//score of the player
public:
    const int getScore()const{return score;}//getter of the score
    Player(){//Default constructor
        size=0;
        score=0;
    }
    ~Player(){//destructor
        delete []ptr;
    }
    void addCard(const card &c){//Add card to hand function
        if(size=0){
            ptr=new card[1];//allocate space for first card
            ptr[size].first=c.first;
            ptr[size].second=c.second;
            if(ptr[size].first=='S'){//if card is heart douple the score of the card
                score+=(2*ptr[size].second);
            }
            else{
                score+=ptr[size].second;//add the number of the card as score
            }
            size++;//increase the cards
        }
        else{
            card * tmp=new card[size+1];//allocate space for the new card
            for(int i=0;i<size;i++){//copy the old cards to the new card array
                tmp[i].first=ptr[i].first;
                tmp[i].second=ptr[i].second;
            }
            tmp[size].first=c.first;
            tmp[size].second=c.second;
            if(tmp[size].first=='S'){//If card is heart double the card value
                score+=(2*tmp[size].second);
            }
            else{
                score+=tmp[size].second;//Increase the score with the new card
            }
            size++;
            delete[]ptr;//dealocate the first card array
            ptr=tmp;//set the ptr to point to tmp space
        }
    }
};//end of class player

//Start of main
int main(){

    const int size=52;//Number of cards
    const int maxPlayers=10;//max of players
    int n,cardperplayer;
    card cards[size]={make_pair('S',1),make_pair('S',2),make_pair('S',3),make_pair('S',4),make_pair('S',5),
    make_pair('S',6),make_pair('S',7),make_pair('S',8),make_pair('S',9),make_pair('S',10),make_pair('S',12),
    make_pair('S',13),make_pair('S',14),make_pair('D',1),make_pair('D',2),make_pair('D',3),make_pair('D',4),
    make_pair('D',5),make_pair('D',6),make_pair('D',7),make_pair('D',8),make_pair('D',9),make_pair('D',10),
    make_pair('D',12),make_pair('D',13),make_pair('D',14),make_pair('B',1),make_pair('B',2),make_pair('B',3),
    make_pair('B',4),make_pair('B',5),make_pair('B',6),make_pair('B',7),make_pair('B',8),make_pair('B',9),
    make_pair('B',10),make_pair('B',12),make_pair('B',13),make_pair('B',14),make_pair('L',1),make_pair('L',2),
    make_pair('L',3),make_pair('L',4),make_pair('L',5),make_pair('L',6),make_pair('L',7),make_pair('L',8),
    make_pair('L',9),make_pair('L',10),make_pair('L',12),make_pair('L',13),make_pair('L',14)};//Initialization of the deck
    random_shuffle(cards,cards+size);//Shyffle the cards
    cout<<"Enter the number of players(MAX 10)"; cin>>n;
    if(n>maxPlayers || n<=1){//If entered more than 10 players too many players
        cout<<"Invalid players"<<endl;
    }
    else{
    cardperplayer=size/n;//calculate how much cards should player hold
    Player *ptr=new Player[n];//allocate players
    int j=0;
    for(int i=0;i<n;i++){
        while(cardperplayer>j){//while player needs cards give him cards
            ptr[i].addCard(cards[j]);//give the card to the player
            j++;
        }
        cardperplayer+=size/n;//increase the cards per player

    }
    for(int i=0;i<n;i++){//print the score
        cout<<"Player "<<i+1<<" Has score:"<<ptr[i].getScore()<<endl;
    }
    delete[]ptr;//dealocate space
    }

return 0;
}//end of main
