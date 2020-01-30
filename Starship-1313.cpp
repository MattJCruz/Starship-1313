//Spaceship 1313
//A text adventure game by Matthew Cruz
//No external resources required. Just run and enjoy!
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int option;
int pHealth = 10;
int eHealth = 10;
int damage;
bool playVal = true;
void combatLoop(int i);
string nextCmd;
//////////////////////////////////////////////////////////////////////////////////////////Game Flavor Text
const string TEXT[3][3]=
{
    {
        "You exit the closet into the main engine room. The first alien\n\
squats atop one of the four cylindrical nuclear reactors, sipping\n\
power from it with its proboscis plunged deep into the energy conduits.\n\
A well-placed shot to the control panel will induce the tamper-protection\n\
protocol and electrocute the alien.\n\n\n",

        "You make your way out of the engine room into the cargo hold. \n\
A second alien appears, different from the first, scrounging around in the shipping crates, \n\
most likely looking for valuables. Just above it is a cargo crane \n\
holding a heavy-looking crate. You realize you can use your datapad\n\
to take control of the crane. \n\n\n",

        "You've finally made it to the bridge. The last alien sits at the pilot's chair,\n\
likely plotting a course to their home planet. You know you must act quickly \n\
but you aren't quite sure what to do now. You stealthily investigate your surroundings\n\
and notice a toxic gas canister on one of the passed-out crew member's belts.\n\n\n"
    },

    {
        "Will you (1) shoot the alien or (2) shoot the control panel?\n",

        "Will you (1) shoot the alien or (2) drop the cargo crane's contents? \n",

        "Will you (1) shoot the alien or (2) fill the room with toxic gas?\n"
    },

    {
        "Electricity pulses from the insulated casings of the reactors.\n\
The alien shrieks as it's electrocuted. Its shiny green scales turn\n\
to a dull, charred brown and it perishes.\n",

        "You drop the cargo onto the alien. It squirms beneath the crate,\n\
attempting to escape, and shrieks madly. It soon succumbs to the \n\
crushing weight of the crate and perishes.\n",

        "You activate your helmet's atmospheric filters, pull the canister's pin,\n\
and toss it into the bridge. The alien shrieks as it inhales the toxin, turning to\n\
its source. It approaches you but soon convulses and perishes.\n"
    }
};



int main()
{
    while(playVal == true)
    {
        system ("CLS");
        pHealth = 10;
//////////////////////////////////////////////////////////////////////////////////////////Intro
        cout
                <<"You wake up in a utility closet with a welt on your forehead.\n"
                <<"The last thing you remember is making repairs to the reactors\n"
                << "of the research vessel 1313. You find the doorknob unlocked.\n"
                <<"What happened?  Thinking it unwise to open the door without \n"
                <<"checking what's outside, you refer to the security feed on your data pad.\n"
                << endl;

        cout
                << "You gaze upon a shocking sight. The bridge, main cargo hold, \n"
                << "and main engine room are each occupied by a menacing, hulking \n"
                << "humanoid with fangs like daggers and green, tough-looking scales. \n"
                << "All around them lie the unconscious crew.\n"
                << endl;

        cout
                << "You know what you must do now: head to the bridge and commandeer\n"
                << "the ship to bring it to safety. It will be incredibly perilous, but there's no\n"
                << "other option. It must be done. You must defeat each alien to save yourself\n"
                << "and the rest of your crew. You have only a self-defense blaster, a datapad, \n"
                << "and a protective helmet.\n\n"
                << "Do you think you can do it? (1)Yes, or (0)no?"
                << endl;

        cin >> playVal;
        system ("CLS");
//////////////////////////////////////////////////////////////////////////////////////////Game Loop
        while(playVal == true)
        {
            for (int y = 0; y<= 2; y++)
            {
                cout << TEXT[0][y];
                combatLoop(y);
                if(pHealth<=0)
                {
                    cout << "\nYou've lost to the alien." << endl;
                    break;
                }
                else
                    cout << "\nYou've defeated the alien!" << endl;
                if(y<2)
                {
                    cout << "You have " << pHealth << " health left.\n" << endl;
                }
                eHealth = 10;
                cout << "Press a key and enter to continue." << endl;
                cin >> nextCmd;
                system ("CLS");
            }
            if(pHealth>0)
                cout << "You've done it! You comandeer the ship and contact the Intergalactic Security Force,\n"
                         <<"deftly piloting the vessel and escaping the alien's wrath.\n\n\n";
                     cout << "Would you like to play again? 0 for no, 1 for yes." << endl;
            cin >> playVal;
            if(playVal == true)
                break;
            system ("CLS");
        }
    }
    cout << "Goodbye!\n\n";
}

//////////////////////////////////////////////////////////////////////////////////////////Combat Loop
void combatLoop(int i)//Add parameter here to print from text array in loop.
{
    damage = rand()%3+1;//Alien and player inflict a random amount of damage on one another.
    while (pHealth>0&&eHealth>0)
    {
        cout << "The enemy's health is :" << eHealth << endl;
        cout << "Your health is :" << pHealth << "\n" << endl;
        cout << "What will you do?" <<endl;
        cout << TEXT[1][i];
        cin >>option;
        system ("CLS");
        switch(option)
        {
        case 1 :
            cout << "You inflict " << damage << " damage upon the alien." << endl;;
            eHealth -=damage;
            damage = rand()%3+1;
            pHealth-=damage;
            cout << "The alien inflicts " << damage << " damage upon you.\n" << endl;;
            break;
        case 2 :
            eHealth = 0;
            cout << TEXT[2][i];
            break;
        default:
            cout << "Please choose a valid value.\n";
        }
    }
}