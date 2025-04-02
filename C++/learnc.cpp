#include <iostream>
using namespace std;
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>

float calculate_damage( float attackPower, float defence){
    return max(0.0f, attackPower - defence);
    
}

bool trydodge(){
    int randomNumber = rand() % 100 ;
    return randomNumber % 2 == 0;
}

void AI_Combat(int &player_defence,float &player_attack,float &AI_attack,float &player_health, float &AI_health,int &AI_defence,int &player_action, int &randomNumber){
    //player moves
    if (player_action == 1){
        cout << "You attacked\n";
        if (trydodge())
        {
            cout <<"Hakura dodged the attack\n";
        }
        else{
            cout << "Hakura got hit\n";
            float damage= calculate_damage(player_attack,AI_defence);
            AI_defence -= 10;
            AI_health -= damage;
            cout << "Opponent health is " << AI_health <<" Hp"<< "Opponent defence is " << AI_defence<<" Dp\n";
        }
    }
    if (player_action == 2){
        cout << "You defended\n";
        AI_attack /=2;
        float damage= calculate_damage(AI_attack,player_defence);
        player_defence -= 5;
        player_health -= damage;
        cout << "Your health is " << player_health <<" Hp"<< "Your defence is " << player_defence<<" Dp\n";
    }
    if (player_action == 3){
        cout << "You used special move\n";
                cout << "Hakura got hit\n";
                player_attack *=2;
                float damage= calculate_damage(player_attack,AI_defence);
                AI_defence -= 20;
                AI_health -= damage;
                cout << "Opponent health is " << AI_health <<" Hp"<< "Opponent defence is " << AI_defence<<" Dp\n";
        }
    if (player_action == 4){
        cout << "You trys to dodge\n";
        if (trydodge())
        {
            cout <<"You dodged the attack\n";
        }
        else{
            cout << "You got hit\n";
            float damage= calculate_damage(player_attack,AI_defence);
            AI_defence -= 10;
            AI_health -= damage;
            cout << "Opponent health is " << AI_health <<" Hp"<< "Opponent defence is " << AI_defence<<" Dp\n";
        }}
       
    //Ai moves
    if (randomNumber ==1){
        cout << "Hakura attacked\n";
        if (trydodge())
        {
            cout <<"You dodged the attack\n";
        }
        else{
            cout << "You got hit\n";
            float damage= calculate_damage(AI_attack,player_defence);
            player_defence -= 10;
            player_health -= damage;
            cout << "Your health is " << player_health <<" Hp"<< "Your defence is " << player_defence<<" Dp\n";
        }} 
    if (randomNumber ==2){
        cout << "Hakuara Defended\n";
        player_attack /=2;
        float damage= calculate_damage(player_attack,AI_defence);
        AI_defence -= 5;
        AI_health -= damage;
        cout << "opponent health is " << AI_health <<" Hp"<< "opponent defence is " << AI_defence<<" Dp\n";
    }
    if (randomNumber ==3){
        cout << "Hakura used special move\n";
                cout << "You got hit\n";
                AI_attack *=2;
                float damage= calculate_damage(AI_attack,player_defence);
                player_defence -= 20;
                player_health -= damage;
                cout << "Your health is " << player_health <<" Hp"<< "Your defence is " << player_defence<<" Dp\n";
        }
    if (randomNumber ==4){
        cout << "Hakura trys to dodge\n";
        if (trydodge())
        {
            cout <<"Hakura dodged the attack\n";
        }
        else{
            cout << "Hakura got hit\n";
            float damage= calculate_damage(player_attack,AI_defence);
            AI_defence -= 10;
            AI_health -= damage;
            cout << "Opponent health is " << AI_health <<" Hp"<< "Opponent defence is " << AI_defence<<" Dp\n";
            }
        }

    }

int fightingscene(){
        srand(time(0));
        int player_action;
        int randomNumber;
        float player_health=100, AI_health=100;
        float player_attack=40, AI_attack=35;
        int player_defence=100, AI_defence=100;
    
        while (player_health>0 && AI_health>0)
        {
            cout <<"\n";
            cout <<"Enter 1 for attack, 2 for defence, 3 for special move, 4 for dodge\n";
            cin >> player_action;
            cout <<"\n";
            randomNumber= rand() % 4+1; 
            AI_Combat(player_defence,player_attack, AI_attack, player_health, AI_health, AI_defence, player_action, randomNumber);
    
            cout <<"\n";
            cout<< "Player Health: "<<player_health<<" | AI Health: "<<AI_health<<endl;
            cout<< "Player Defence: "<<player_defence<<" | AI Defence: "<<AI_defence<<endl;
            cout<<"\n";
    
            if (player_health<=0){
                cout<< "You Lost "<<"Wasted"<<endl;
                break;
            }
            else if (AI_health<=0){
                cout<< "You Won "<<"Fatality"<<endl;
                break;
            }
        }
            
    }


int Fighting(int b){
    if (b == 1){
        cout << "You have chosen Hakura\n";    
        fightingscene();
    }
    else if (b == 2){
        cout << "You have chosen Methalaru\n";
    }    
    else if (b == 3){
        cout << "You have chosen Humperyn\n";
    }
    else if (b == 4){
        cout << "You have chosen Wohaonka\n";
    }
    else if (b == 5){
        cout << "You have chosen Korishamaru\n";
}
}




int Rules(){
    cout << "Rules of the game\n";
    cout << "1. You can only attack once per turn\n";
    cout << "2. You can only defence once per turn\n";
    cout << "3. You can only use special moves once per turn untill unless the enemy is stunned\n";
    cout << "4. The game will end when either the player or the enemy will die\n";
    cout << "5. The Enemy are Ai runs own their won logical algorithm to choose the best moves\n";
    cout << "6. The Enemy strike and damage , and defence is increased upon the difficulty of the game and also deppends upon the skill of the enemy\n";
    cout << "7. The special moves are only available after 3 turns and common moves are used\n";
    cout << "8. The chance of getting damage or dodging attack is depend upon the defence of the player and difficulty of the game\n";
    return 0;
}



int AI_Details(){
    while (true)
    {
        cout <<"1.Hakura"<<endl<<"2.Methalaru"<<endl<<"3.Humperyn"<<endl<<"4.Wohaonka"<<endl<<"5.Korishamaru"<<endl<<"6.Exit"<<endl;
        cout <<"Enter the number before the enemy name to know their skills and details";
        int x;
        cin >> x;
        if (x == 1){
            cout <<"Name:- Hakura\n"<<"Gender:- Male\n"<<"Age:- 34\n"<<"Hakura is a middle age muscular guy he has strong defence so all the damage to him will be halfed and some attack might do no damage\n"<<"Special_Moves:- Punisher he willgrab you and crush you with his muscle, Lowering your defence and chances to dodge attacks\n";
        }

        else if (x == 2){
            cout <<"Name:- Methalaru\n"<<"Gender:- Male\n"<<"Age:- 26\n"<<"Methalaru is a young guy who is gay and he attacks with a frying pan and if he strikes you the damage will be lower but defence will be affect significantly with multiple strikesn\n"<<"Specail_Move:- Backslap in which he slaps your back with the pan with good speed lowering your defence and lower the damage by half, that you do when you strike for next 2 turns\n";
        }

        else if (x == 3){
            cout <<"Name:- Humperyn\n"<<"Gender:- Male\n"<<"Age:- 33\n"<<"Humperyn is a middle age street figter known for his high damage in fighting also becomes invincible for 1 move if he is lower in health\n"<<"Special_Moves:- The streetflaw in this moves he kicks your thigh so hard that you could barely defence another attack and the damage of tthe move is higher if it hits you 2 times in a row almost killing you instantly\n";
        }

        else if (x == 4){
            cout <<"Name:- Wohaonka\n"<<"Gender:- Female\n"<<"Age:- 25\n"<<"Wohaonka is a young girl who is a street fighter but she is very weak.. but she is beautifull and stunning luring any men to surrender or to convince to not hit her instead hit her at night..\n"<<"Special_Moves:- The Lustclap she uses this move to lure you and on successfull hit your move will be skipped and your defence will be lowered by half and the effect stays on till the end of the match\n";
        }

        else if (x == 5){
            cout <<"Name:- Korishamaru\n"<<"Gender:- Male\n"<<"Age:- 30\n"<<"Korishamaru is a middle age man with a big body and he is a vry strong samurai with high defence and high damage in fighting with his katana when he strikes you successfully you will get a bleeding effect that will last for 10secs and your defence will be lowered by 20%/ and the damage will be lowered by 20%\n""Special_Moves:- The thunder slash he uses this move when his health is halfed and on successfull hit you will be stunned for 10secs and within this time period he can strike you again as your defence will be lowered by 100%/and the damage will be lowered by 10%/ but the effect will stay for 20 sec after that your defence and damage will be restored\n";
        }

        else if (x == 6){
            break;
        }
        else{
            cout <<"\n";
            Sleep(2000);
            cout <<"Invalid choice"<<endl;
        }
             }
    return 0;   
                    }
int Run_exe(){
    while (true)
    {
        cout << "Wait while the game is loading\n";
        Sleep(3000);
        cout << "Loading assets....\n";
        cout << "Loading game....\n";
        Sleep(8000);
        cout << "Starting the game....\n";
        Sleep(3000);
        cout << "Game started"<<endl;
        cout << "Good Luck\n";
        cout <<"\n";
        cout <<"\n";
        cout <<"1.Hakura"<<endl<<"2.Methalaru"<<endl<<"3.Humperyn"<<endl<<"4.Wohaonka"<<endl<<"5.Korishamaru"<<endl<<"6.See Character Details"<<endl<<"7.Exit"<<endl;
        cout <<"Choose Your Character by entering the number before the name: \n";
        int x;
        cin >> x;
        cout <<"\n";
        cout <<"1.Hakura"<<endl<<"2.Methalaru"<<endl<<"3.Humperyn"<<endl<<"4.Wohaonka"<<endl<<"5.Korishamaru"<<endl<<"6.See Character Details"<<endl<<"7.Exit"<<endl;
        cout <<"Choose Your Opponent by entering the number before the name: \n";
        int b;
        cin >> b;
        switch (x){
            case 1:
                cout <<"You have chosen Hakura"<<endl;
                
                break;
            case 2:
                cout <<"You have chosen Methalaru"<<endl;
                
                break;
            case 3:
                cout <<"You have chosen Humperyn"<<endl;
                
                break;
            case 4:
                cout <<"You have chosen Wohaonka"<<endl;
                
                break;
            case 5:
                cout <<"You have chosen Korishamaru"<<endl;
                
                break;
            case 6:
                AI_Details();
                continue;
            case 7:
                cout <<"You have chosen to exit the game"<<endl;
                break;
            default:
                cout <<"\n";
                Sleep(2000);
                cout <<"Invalid choice"<<endl;
                break;
                        }

         switch (b){
            case 1:
                Fighting(b);
                break;
            case 2:
                Fighting(b);
                break;
            case 3:
                Fighting(b);
                break;
            case 4:
                Fighting(b);
                break;
            case 5:
                Fighting(b);
                break;
                            }
            
                                        }
                                    }





int main() {
    
    
    while(true)
        {
            int x;
            cout <<"Welcome to DemanGame\n";
            cout <<"Enter your name: ";
            string Player_Name;
            cin >> Player_Name;
            cout <<"Enter your age: ";
            int Player_Age;
            cin >> Player_Age;
            cout <<"Enter your gender: ";
            string Player_Gender;
            cin >> Player_Gender;
            cout <<"Enter 1. To start the game\n"<<"Enter 2. To get the manual of the game\n"<<"Enter 3. To know the rules of the game\n"<<"Enter 4. To know the details of the game Characters\n"<<"Enter 5. To change the difficulty of the game\n"<<"Enter 6. To exit the game\n";
            cin >> x;
            cin.clear();
            cin.ignore(10000, '\n');
            switch (x)
            {
            case 1:
                Run_exe();
                break;
            
            case 2:
                
                break;
            
            case 3:
                Rules();
                break;
            
            case 4:
                AI_Details();
                break;
            
            case 5:
            
                break;
            
            case 6:
                exit(0);
                break;
            default:
                break;
            }
        }
    

    return 0;
}