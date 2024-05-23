// Dont know where to star?

// 1. When you define a new class, try to figure out what public member functions it should have. Then write 
// dummy "stub" code for each of the funtiuons that you'll fix later:

        class foo{
            public:
                int choosAcourseOfAction(){
                    return 0;
                }
        };

// Try to get the project compiling with the dummy code first then replace it with the actual code later


// 2. Once you have the project compiling then go back and replace the dummy code one at a time
// Update the function, re-compile your program, test your new function, and once you've got it working, 
// proceed to the next function. 

// 3. Make backups of your working code frequently. Any time you get a new feature working, make a backup 
// of all your .cpp files just in case you screw something up later. 

/*
    If you use this approach, you'll always have something working that you can test and improve on. 
If you write everything at once, you'll end up with hundreds or thousands of errors and just get frustrated!
So dont do it. 


Game Mechanics

- At the begining of the game you start out with three lives and these three lives last through all the levels 
    you complete and dont refresh unless you beat the game or die and want to play again.

- Everytime the Iceman Avatar spawns he appears at the top middle of the oil field.

- Everytime the starts or re-starts a level his health is refreshed to 100% but the lives remain the same.
    His water blaster is refilled with 5 squirts,
    And given a single sonar charge.

- Each oil field has a number of Boulders, Gold nuggets, and barrels of oil RANDOMLY(random function) 
    placed through the field. Only the boulders will be visible initially, and the others have to be
    discovered by the iceman before they become visible. 

- Navigation is done by the arrow keys. 

- The iceman digs through the oil field in any direction that he moves. The iceman can dig/move anywhere 
    through the field except where the boulders are. 

- The iceman must find and collect all the barrels of oil in the field to progress to the next level.

- There are two types of protesters regular and hardcore that shout at the iceman whenever they get near.
    Each time the iceman is shouted at his health decreases and eventually gives up and quits (loses life)
    At this point, if the iceman has more lives, the player can continue the game on the current level. If
    not then the game is over. 

- In addition to walking around and digging through the field the iceman can also squirt from his water blaster
    (if it has 1-5 of its blasts) by pressing the space bar. A direct hit from the blaster will stun aprotestor 
    and irritate them decreasing their life points. If a protestor's life hit points drop to 0 then they will leave
    the field out of frustration and say "I give up!" 

- Randomly Water pools will bubble up from the tunnels, and the iceman can move onto them to refill his the squirt gun.
    But beare -a water pool disappears quickly! back into the tunnel's ice, so the iceman needs to siphon it off quickly.

- The iceman will also discover gold nuggets randomly distributed throughout the oil field. If the iceman picks up one
    or more gold nuggets, he can use them to bribe the Protestors by dropping a nugget in front of the protester. 
    If a regular protester runs into a gold nugget, it will pick it up and say "I'm rich!" amd leave the oil field, but a hardcore 
    protestor gets bribed he will pick up the gold, stop for a second to gloat, and then resume the hunt to protest against 
    The iceman. If the player drops a Gold nugget and it's not picked up quickly it will sink into the muck of the oil field 
    never to be found again. 

-  If the supporting ice to a boulder is dug up the boulder drops after a short delay. It will fall until it hits the ice or another 
    boulder below. If a protestor gets hit by a boulder they will immediately leave the the oil field. The iceman could also loose all 
    hit points by get hit by a boulder he will lose one of his lives and the level woll restart. 

- Sometimes sonar gets spawned in the upper left and he also starts out with one sonar charge at the start of each level
    the player can press the z key to use the sonar to map the contents of the field with the sonar. 

- There are two types of protesters. Th regualr and the hardcore protestors. They spawn in the upper right corner of the field 
    and will seek ou the iceman to yell at him. Regular protestors are not too dedicated and are easily defeated by getting squirted 
    or bribed. Regular protestors wonder around randomly. if a regular protestor sees the iceman he will run up to him and start 
    yelling at him. Each shout will cause the icemans health to go down. If a regular protester gets hit by a boulder he immediatley 
    gives up and heads to the upper tight corner and disappears but is replaced by another protester soonly after.

- In contrast to the regular protestors the hardcore protesters are much more difficult. They behave almost identically to the regular protestors.
    1. Theyre much more dedicated and so it takes more squirts to irritate them.
    2. They can't be bribed to leave the field. They will stop to enjoy their new riches and then continue chasing the iceman
    3. They can track the iceman even if they can't directly see him. If they are within a short range they can track him. 
        less than 16 horizontal/vertical moves. The range increases with each level of the game. 
        Hint: use a breadth-first search like we learned about in the Queue lecture).
        They will exibit the same movements as the regular protesters if they are not in range of the iceman

- If the iceman looses a life then and the player wants to replay and still has a remaining life then a new oil field will be generated randomly
    with the same amount of difficulty and all initial healths and supplies are set beack to their starting amount.



- The bottom left-most square is the game window has coordinates of 
    x=0, y=0 
    The upper right corner of the game window has the coordinates of 
    x=63, y=63
    The game window is exactly 64 squars wide by 64 squares high. 
    each object in the game barrels actors nuggets etc has exactly 4x4 square immage area.
    The iceman can move anywhere except on the top of a boulder. 
    Protestors are unable to dig through the ice. They can only go where the ice has been removed.
    The iceman and the protester can pass eachother and ocupy the same space on the screen at the same time


- The bottom-leftmost squares of the game window has coordinates of x=0, y=-0 while the upper right squares has coordinates of 
    x=63, y=63. Noptice that x increases to the right and y increases upward
    No game object will have a x/y coordinate grater than 60 or less than zero since they all are 4x4 squares this will cause
    them to be rendered off the screen.
    You can look in the provided file gameconstants.cpp to get an idea of what all the critical values are set to.
    Each game object has a an origin in its bottom left. 

- The oil field whic is comprised of 1x1 iceobjects, occupies the entore width of the game window.
    But only the lower 60 squares of the screen. A single tunnel is always at the center of the field at the start of each level.

- As the game progresses each level will pose new challeneges for the iceman. The number of Barrels of oil that must be collected will increase,
    The number of protestors will increase, The frequency of water and sonar kits will decline, and the protestors move more quickly.
    They are stunned for shorter periods of time when sprayed with water or finding a gold nugget. All of those details are described 
    in later sections of the document.

- Once a new oil field (all of the ice that comprises the 64 w, 64 h field ) and its contents have been generated(boulders, barrels of oil 
    and gold nuggets are distributed through the field) and the iceman has been added to the game, the game play begins,
    Game play is divided into ticks, and there are dozens of ticks per second, (to provide smooth animation and game play) During each tick 
    the following occurs. 

        1. The player has an opportunity to hit a key to move the iceman exactly one square h or v, shoot their squirter (if the iceman has water)
        use a sonar charge to revel the contents of the field, or give up (some levels may be unsolvable, so the player can press the Escape key to 
        loos a life and restart the level from scratch)

        2. Every other object in the game (regular protesters, hardcore, gold nuggets, boulders, etc) with the exception of iceobjects
        (which don't do anything) is given the opportunity to do something. For example, when given the opportunity a regular protestor 
        can move one square (left,right, up, or down) according to its built-in-movement algorithm (the regular protester movement algorithms 
        are described in detail in various Regular protestor sections below.)

        3. One or more new game objects(e.g. Protestors, Sonar kits, or water) may be added to the game; once added, They'll have an opportunity
        to do something during each tick.

        4. One or more existing game objects may be removed from the game. For example, if the iceman picks up a Gold Nugget, its object must be deleted
        from the game (once the iceman's inventory has been updated).

- During the game-play, the player controls the direction of the iceman with the arrow keys, or for lefties and others WASD or the numeric pad.
    up w, 8 
    left a, 4
    down s, 2
    right d, 6
    The player may move the iceman anywhere in the field as they please. The player can give up a life and resart the level at any time. 
    The iceman  may shoot their squirt gun by pressing the spacebar key. If the iceman manages to squirt a regular protestor enough, the protestor 
    will give up and leave and the player will earn points. 

        For causing a regular protester to give up 100 pts
        For causing a Hardcore protester to give up 200pts

    In addition to squirting Protestors, The iceman can dig the ice from under a boulder cousing it to drop on a Protester of both types. 
    If a boulder bonks a protestor the player earns 500 pts.

- The player can also earn points by by dropping gold nuggets in front of the protestors. Should one of them the protestor pcikup a dropped 
    gold nugget, The player earns: 

        25 points for bribing a protestor with gold nuggets
        50 points for for bribing a hardcore protestor with gold nuggets.

    Finally the player also earns points and special benefits by picking up (moving onto the same region as) various items:

        1000 points for barrels of oil (iceman must collect all the barrels of oil to complete each level)
        10 points for a gold nugget. iceman adds one piece of gold to his inventory which they can drop to bribe protestors.
        75 points for Sonar kit (The iceman gets two sonar charges added to their inventory)
        100 points for water (5 squirts worth of water are added to the icemansd inventory)

- The player starts with three lives. The player loses a life if their health reaches zero (from being annoyed by protester shouts or from getting hit by a boulder)

- When the iceman is completeley annoyed (health reaches 0), The current level ends and the player,s number of remaining lives is decremented by 1.
    If the player still has at one life left then they are promted to continue and given another chance by restarting the current level from scratch. 
    If the player has no lives left, then the game is over. Pressing the q key lets you quit the game prematurely. 



So how does a video game work

    So each thing besids the field ice are derived classes of actors and each acter has their own internal algorithms that determine 
        how they will move on in the game. Each actor has its own x & y location, and its own state. 

    
    Once a game begins, gameplay is divided into ticks. A tick is a unit of time, for example, 50 milliseconds(that's 20 ticks per second) 

    During a given tick, the video game calls upon each object's behavioral algorithm and asks the object to perform its behavior. When asked 
    to perform its behavior, each objects behavioral algorithm must decide what to do and then make a change to the objects state (move the object 
    1 square to the left), or change 

    After the current tick is over ans all actors have had a chance to adjust their state(and possibly adjust other actor's states), our game framework (That we provide)
    animates the actors onto the screen in their new configuration. So if a protester changed its location from x=10,y=5 to x=11, y=5 (moved one swuare to the right) 
    then our game framework would erase the graphic of the Protester from location 10,5 on the screen and draw the Protestor's graphic at 11,5 instead. Since this 
    process (asking actors to do something then animate them to the screen) happens some 10-20 times per second, the user will see smoothish animation. 

    Then, the next tick occurs, and each of object's algorithm is again allowed to do something, 
    Our framework displays the updated actors on-screen, and so on.

    Assuming the ticks are quick enough (a fraction of a second), and the actions performed by the objects 
    are subtle enough, when you display each of the objects on the screen over time, it looks like each object is performing 
    a continuous series of fluid motions.

    A video game can be broken into three different Phases:

    Initialization: The game world initialized and prepared for play. This involves allocating one or more actors (Which are c++ objects ) 
    and placing them in the game world so that they will appear in the oil field

    Game play: Game play is broken down into a bunch of ticks. During each tick, all of the actors in the game have a chance to do something, and perhaps die.
    During each tick, new actors may be added to the game and actors who die must be removed from the game world and deleted.

    Cleanup: This phase occurs either when the player has lost a life(but has more lives left), The player has completed the current level, or the player has lost all 
    of their lives and the game is over. This phase frees all of the objects in the world since the level has ended. If the game play is not over then the 
    game proceeds back to the initialization step, where the oil field is repopulated with new occupants and gameplay restarts at the current level. 

*/




// Here is what the main logic of a video game looks like, in psuedo code (we provide some similar code for you in our provided Gamecontroller.cpp)


        while (The player has lives left ){
            Prompt_the_user_to_start_playing(); //"Press a key to start"

            Initialize_the_game_world(); // You're goin to write this function

            while (The player is stil alive ){
                // each pass through this loop is a tick (1/20th of a sec )
                Ask_all_actors_to_do_something(); 

                If_any_actors_died_then_delete_them_from_the_world(); 

                // We write this code to handle the animation for you
                Animate_all_of_the_alive_actors_to_the_screen(); 
                Sleep_for_50ms_to_give_the_user_time_to_react();
            }
            // The player died - you're are going to write this code
            cleanup_all_game_world_objects(); //you're going to write this 
            if (The player has more lives)
                Prompt_the_player_to_continue();
        }

        Tell_the_user_the_game_is_over();

/*
    And here is what the Ask_all_actors_to_do_something() function might look like
    (which is one of the functions you'll have to write):
*/

        void Ask_all_actors_to_do_something()
        {
            for each actor on level :
                if (the actor is still alive) 
                    tell the actor to do something();
        }


/*
    You will typically use a container (an array, vector, or list) to hold pointers to each of your live actors
    . Each actor (a C++ object) has a do something() method. In this Method, each actor (e.g. a Regular Protestor) 
    can decide what to do. FOr example, here is some psuedo code showing what a hypothetical Regular Protestor might
    decide to do each time it gets asked to do something. 
*/

        class RegularProtester : public .....
        {
            public:
                virtual void doSomething()
                {
                    if I am facing the iceman and he is next to me, Then Shout at the iceman (to annoy him)
                    else if theiceman is visible via direct line of sight, then switch direction to face the iceman;
                        move one square in his direction;
                    else if i'm about to run into an obstacle, then
                        pick a new direction;
                        Move one square in this direction;
                    else 
                        Move one square in my current location
                }
        };

/*
    And here's what the iceman's doSomething() method might look like:
*/

        class Iceman: public .....
        {
            public:
                virtual void doSomething()
                {
                    try to get user input (if any is available)
                        If the user pressed the UP key and that square is open
                            Then increase my y location by one;
                        If the user pressed the DOWN key and that square is open 
                            Then Decrease my y location by one;

                    If the user pressed the space bar to fire and the iceman has water then
                        Introduce a new Squirt Object into the game facing the same direction as the player;
                }
        };

/*
    What do you have to do? 


    You must creat a number of different classes to implient the iceman game. Your Classes must
    work properly with out provided classes, and you must modify our classes of our source files in any way 
    to get your classes to work properly. Here are the specific classes that you must create.


    1. You must create a class called StudentWorld that is responsible for keeping track of your game world(including 
    the oil field) and all of its actors/objects (e.g. the iceman, protestors, boulders, ice etc) that are inside of 
    the oil field.


    2. You must create a class to represent the ICEMAN in the game.

    3. You must create the classes for Regular Protesters, Hardcore protesters, squirts (that the iceman shoots), Water, 
    Sonar Kits, Gold nuggets, ice, ice boulders, and barrels of oil, as well as any additional base classes (Goodie base class)
    thats common to all pick-uppable like water, Gold Nuggets, etc, if you kneed one... that are required to implement the game



    You have to create the StudentWorld Class

    Your StudentWorldsClass is responsible for orchestrating virtually all game play -it keeps track of the whole game world (the ice 
    of the field, and all of its inhabitants such as Protestors, the iceman, boulders, Goodies, etc). Its responsible for initializing 
    the game world at the start of the game, and destroying all of the actors in the game world when the user loses a life or when actors 
    disappear (Regular Protestors leaves the oil field after being sufficiently annoyed by being repeadedly squirted)

    Your StudentWorld class must be derived from our gameworld class (found in GameWorld.h) and must implimnent at least these three methods 
    (which are defined as pure virtual funtions in our GameWorldClass):
 

*/



        virtual int init() = 0;
        virtual int move() = 0;
        virtual void cleanup() = 0; 


/*
    The code you write must never call any of these three funtions. Instead our provided game framework will call these functions for you. 
    So you have to impliment them correctly, but you wont ever call these functions yourself in the code.

    When a new level starts (at the start of a game, or when the player completes a leveland advances to the next level), our game framework
    will call the init() Method that you defined in your StudentWorld class. YOu dont call this function; instead, our provided framework code 
    calls it for you.

    

*/



// Student World must be derived from GameWorld Class which provide the following methods for us to use 

        unsigned int getlives() const;  // can be used to determine how many lives the player has 

        void decLives();  // Reduced the number of lives by one.

        void incLives();   // increases the number of lives by 

        unsigned int getScore() const;  // can be used to determine the players current score 

        unsigned int getLevel() const;  // can be used to determine the players current level number

        void increasScore(); //is used bt your studentworld class (or other classes) to increase the user score when the iceman ittitates protestoers 
        // with a squirt, picks up a barrel or a goodie of some sort, or bonks a protester with a boulder. etc. When your code calls this method, 
        // you must specify how many points the player gets (e.g. 100 points for irritating  Regular protester to the point where it gives up) . 
        // This means that the game score is controlled by our GameWorld-objectyou must not maintain your own score member variable in your own classes
        // void increaseScore(unsigned int howMuch); 

        void setGameStatText(string text); // method is used to specify what text is displayed at the top of the game screen. 

        bool getKey(int & value); // can be used to determine if the user has hit a key on the Keyboard to move the player or to fire. This method 
        // returns true if the user hit a key during the current tick, and false otherwise. THe only argument to this method is a variable that will be 
        // filled in with the key that was pressed by the user. If the player does hit a key, the argument will be set to one of the following values





// (constants defined in the GameConstants.h)
        // KEY_PRESS_LEFT
        // KEY_PRESS_RIGHT
        // KEY_PRESS_UP
        // KEY_PRESS_DOWN
        // KEY_PRESS_SPACE
        // KEY_PRESS_ESCAPE
        // KEY_PRESS_TAB
        // KEY_PRESS_LEFT
        // Z,
        // Z,

void getKey(int& value);
void playSound(int soundID); //  method can e used to play a sound effect when an important event happens during the game. You can find constants
// that describe what noise to make inside of the ganeConstants.h file. Here is how the playSound() method might be used.

// If a regular Protester reaches zero hit points and dies 
// thenthey make a dying sound. 

if (theProtestorHasZeroHitPoints())
    Gamecontroller::getInstance().playSound(SOUND_PROTESTORS_GIVE_UP)






// The following objects must be distributed randomly throughout the game

//B bouldersr in each level, where:
        int B = min(current_level_number / 2 + 2, 9)

// G Gold nuggets in each level, where: 
        int G = max(5-current_level_number / 2,2)

// L Barrels of oil in eacg level, where 
        int L = min(2 + current_level_number, 21)




// The move() method must return one of three different values when iut returns at the end of 
// each tick

        GWSTATUS_PLAYER_DIED
        GWSTATUS_CONTINUE_GAME
        GWSTATUS_FINISHED_LEVEL



IMPORTANT!!!! The "skeleton" code that we provide to you is hard coded to return a GWSTATUS_PLAYER_DIED status 
value from your dummy version of the move() method. Unlessyou change this value to GWSTATUS_CONTINUE_GAME your 
game will not display anything.


int StudentWorld::move()
{
    //update the game status Line
    updateDisplayText();  // update the score/lives text at screen top

    // The term "Actors" refers to all Protestors, the player, Goodies, 
    // Boulders, Barrels of oil, Holes, Squirts, Exit, etc.
    //  Give each of the actors in the game world
    if (actor[i] is still active/alive)
    {
        // ask each actor to do something (e.g. move)
        tellThisActorToDoSomething(actor[i]);
        if(thePlayerDIedDuringThisTick()== True)
            return GWSTATUS_FINISHED_LEVEL;
    }

    //Remove newly-dead actors after each tick
    removeDeadGameObjects(); //delete dead game objects
    // return the proper result 
    if (thePLayerCompletedTheCurrentLevel() == True)
    {
        playFinishedLevelSoud();
        return GWSTATUS_FINISHED_LEVEL;
    }
    // the player hasnt completed the current level and hasnt died
    // let them continue playing the current level
    return GWSTATUS_CONTINUE_GAME;
}


// Give each actor a chance to do something 








// add New actors During each tick

// 1. A new Protester (regular/hardcore) may only be added to the oil field after at 
// least T ticks have passed since the last Protester of any type was added, where:

        int T = max(25,200-current_level_number)

// 2. The target number P of Protesters that should be on the oil field is equal to 

        intP = min(15, 2 + current_level_number *1.5 )

// Based on #1 above, you can only add a new protester to the oil field ever T tick, 
// so the actual number of Protesters on the oil field at any particvular time may be
// less than the target number P  

// 3. The first Proteste must be added to the oil field during the very first tick of each
// level (and any replays of the level)

// 4. Assuming the appropriate numer of ticks T has elapsed since the last Protester was added
// to the oil field, AND the current number of Protesters on the oil field is less than P,
// then you must add a new Protester to the oil field during the current tick. All Protesters
// must start at location x=60,y=60 on the screen. The odds of the Protesters being a 
// HardCore Protester(vs. Regular Protester) must be determined with this formula.


        int probabilityofHardcore = min(90,current_level_number *10+30)

// 5. Ther is 1 in G chance that a new Water Pool or Sonar Kit Goodie will be added to 
// the field during any particular tick, where:

        int G = current_level *25 +300

// Assuming a new goodie should be added, there is a 1/5 chance that you add a new sonar kit 
// that you should add a new Sonar Kit, and a 4/5 chance you should add a Water Goodie.

Each new Sonar Kit must be added at x=0, y=60 screen.

// Each new Water Goodie must be added to a random ice-less spot in the oil field.
// Water may only be added to a location if the entire 4x4 grid at that location is free
// of ice.

// Remove Dead Actors after each tick




     // Read documentation page 21 






// Updating the Display Text

// Your move() method must updat the game statistics at the top of the screen during every 
tick by calling the setGameStatText () method that we provide in our gameWorld class. 
// You could do this by calling a function like the one below from your StudentWorlds
// move() method; 



void setDisplayText(){
    int level = getCUrrentGameLevel();
    int lives = getNumLivesLeft();
    int health = getCurrentHealth(); 
    int squirts = getSquirtsLeftInSquirtGun();
    int gold = getPLayerGoldCount(); 
    int barrelsLeft = getNumberOfBarrelsIsRemainingToBePickedUp();
    int sonar = getPlayerSOnarChargedCount(); 
    int sore = getCurrentScore(); 

    //Next, create a string from yout statistics of the form 
    // lv1: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: Scr: 32100 


    string s = someFunctionYouUseToFormatThingsNicely(Level, lives, health, squirts, gold, barrelsLeft, sonar, score); 

    // Finally, update the display text at the top of the screen with your newly created
    // stats
    setGameStatText(s); // calls our provided GameWorld::setGameStatText 



// NEVER REPEAT BEHAVIORS OF ACTORS THAT CAN BE MOVED INTO A BASE CLASS

// ALL OF THE GAME OBJECTS MUST BE DERIVED FROM THE PROVIDED BASE CLASS CALLED GraphObject


class Actor: public GraphObject{
public:
};


class Protester: public Actor{
public: 
};


class HardCoreProtester: public Protester{
public: 
}; 


// Graphobject is a class that was created to hide all the base logic of rendering a charachter 
// on screen. If you dont derive your classes from GraphObject then nothing will render on 
// screen. 


GraphObject(int imageID, int startX, int startY, 
    DIRECTION startDirection, float size = 1.0,
    unsigned int depth = 0);
void setVisible(bool shouldDisplay); 
void getx() const;
void gety() const;
void moveTo(int x, int y);
DIRECTION getDirection() const; // Directions: up, down, left, right
void setDirection(DIRECTION d); // Directions: up, down, left, right


GraphObject(
    int imageID,
    int startX,
    int startY,
    DIRECTION startDirection,
    float size = 1.0,
    unsigned int depth = 0;
)


// make a seperate vector of alive `


// When you construct the GraphObject, You must specify the following parameters:
// 1. An imageID that indicates what graphical image (aka sprite) our graphics engine
// Should display on the screen one of the fololwing IDs, found in GameConstants.h,
// Must be passed in for the imageID value:

IID_PLAYER
IID_PROTESTER
IID_HARD_CORE_PROTESTER
IID_WATER_SPURT
IID_BOULDER
IID_BARREL
IID_ICE
IID_GOLD
IID_SONAR
IID_WATER_POOL


// 2. You must specify th initial x,y locatio of the object. The x value may range from 0 
// to VIEW_WIDTH-SPRITE_WIDTH inclusive. Notice that you pass the coordinates as 
// x,y (i,e, column, row and not row, column). 

// 3. You must specify the initial direction that each obect will be facing. Acceptable 
// values unclude: up, down, left, and right. The definitiions for these values may be found in 
// the GraphObject class within Graphobject,h


// 4. You must specify the size of the image. Most images (Protesters, Gold, Nuggets, ther Iceman, etc)
// will have a size of 1.0, which is the equivalent of a 4 squares by f squares on the screen. In constrast
// Ice will always have a size of .25 making it 1 square by 1 square. 

// 5. You must specify the depth of tge image. This value indicates whether the image is in 
// the foreground(0), in the background(10) or somwhere in between. If two images are drawn at the same location,
// the graph object with the smaller depth value will be drawn on top of the graphObject with the larger depth value,
// either partially or completely obscuring it. We will specify what the depth should be for each of your 
// GraphObject-derived classes in the sections below. 



        setVisible(bool shouldDisplay);

// New GraphObjects start out invisible and are not displayed on the screen until the programmer calles the setVisible()
// method with a value of true for the parameter. This method is used to tell our graphical system whether or ot to display 
// a particular GraphObject on the screen. If you setVisible(true) on a Graphobject, then your object will be displayed on 
// screen automatically by our framework. 

        int getX() const 
        int getY() const 

// Dont put x and y in the derived classes cause there are already in the base class.

        void moveTo(int x, int y)
// must be used to update the location of a GraphObject within the oil field. For example, if a regular protesters movement
// logic dictates that it should move to the right, you must do something like the following:
        
        
        MoveTo(getX() + 1, y); // move one square to the right 

// You must use the moveTo methos to adjust the location of a GameObject in the game if you want that object to be properly
// animeted. As with the Graphobkect constructor, note that the order of theparameters to moveTo is x,y (col, row) and NOT y,x(row,col)

        DIRECTION getFirection() const 
        void SetDireciton(DIRECTION D)



// These two methods are used to get and set the current direction the GraphObject is facing. Valid values include the standard  up, down, 
// left, right. Changing the direction causes our graphics engine to automatically rotate the image appropriately before displaying it on 
// the screen. Now you know about the GraphObject base class, you need to derive all game objects from it either directly or indirectly 




// To see if the user hit a key. If the user hit a key, the function returns true and the int variable passed to it is set to code for the
// key. Otherewise, the function immediately returns flase, meaning that no key was hit. This functino could be used as follows:

        void Iceman::doSomething()
        {
            int ch;
            if (getWorld()->getKey(ch) == true)
            {
                        // user hit a key this tick!
                switch (ch)
                {
                    case KEY_PRESS_LEFT:
                    ... move player to the left 
                    break;
                    // etc...
                }
            }
        }

        setVisible(true); 

        