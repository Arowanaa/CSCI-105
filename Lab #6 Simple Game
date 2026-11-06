// SimpleBounceGame.cpp
// Edited by: Matthew Chang, 10/25/23
//
// This program illustrates some basic graphics functions, control structures,
// and ways to use variables.
// 
// Add a "target" to make this into a simple game
//
// Key Commands:
// G - Toggle Gravity
// T - Toggle Trails
// C - Toggle changing colors
// M - Move Target
// Q or ESC - Quit
// 
// Click mouse to change position of the circle

#include "graphics.h"
#include <string>
#include <random>

using namespace std;

// Random Engine
random_device myEngine;
uniform_real_distribution<double> randomReal(0.0, 1.0);

// Initialize score counter
int score = 0;


// Function Prototypes
void drawTarget(double x, double y, int color);

void moveTarget(double& x, double& y);

void showScore();

 

int main()
{

    bool keepGoing = true;       // keep running while this is true
    bool eraseTrails = true;     // erase previous object by drawing it in black
    bool gravityOn = false;      // turn on gravity, which changes velocity
    bool changeColorsOn = false; // Constantly change colors

    char keyPressed;
    int mouseX, mouseY;
    int currentColor = RED; // Starting color

    const int NUM_TARGETS = 10; // Define the number of targets

    // Initialize an array to hold target positions
    double targetX[NUM_TARGETS];
    double targetY[NUM_TARGETS];

    // Variables to keep track of position, previous position,
    // and velocity

    double pointX1, pointY1; // Current position of point 1
    double prevX1, prevY1;   // Previous position of point 1
    double xVel1, yVel1;     // Velocity of point 1

    // Set Initial Position
    pointX1 = 140.2;
    pointY1 = 150.1;

    // Set Initial Velocity
    xVel1 = 6.1;
    yVel1 = 3.4;

    // Open a graphics window size 800 pixels wide x 600 pixels high
    initwindow(800, 600);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    // Target positions
    
    for (int i = 0; i < NUM_TARGETS; i++) {
        targetX[i] = randomReal(myEngine) * 600.0 + 100.0;
        targetY[i] = randomReal(myEngine) * 300.0 + 50.0;
    }
    

    // Draw all targets
    int tempX;
    int tempY;

    for (int i = 0; i < NUM_TARGETS; i++) {
        for (int k = 0; k < NUM_TARGETS; k++) {
            if (targetX[i] != targetX[k] && targetY[i] != targetY[k]) {
                drawTarget(targetX[i], targetY[i], YELLOW);
            }
            else if (targetX[i] == targetX[k] && targetY[i] == targetY[k]) {
                tempX = randomReal(myEngine) * 600.0 + 100.0;
                tempY = randomReal(myEngine) * 300.0 + 50.0;
                while (tempX < targetX[i] + 55 && tempY < targetY[i] + 55 && tempX > targetX[i] - 55 && tempY > targetY[i] - 55) {
                    tempX = randomReal(myEngine) * 600.0 + 100.0;
                    tempY = randomReal(myEngine) * 300.0 + 50.0;
                }
                drawTarget(targetX[tempX], targetY[tempY], YELLOW);
            
                
            
        }
    }
    

    // Main Loop - Keep running until user quits (while keepGoing is true)
    while (keepGoing) {

 

        delay(60);

        // -------------- Move and Control the Point Positions ---------------

        // Remember previous position so we can erase it later
        prevX1 = pointX1;
        prevY1 = pointY1;

        // Move the position (Add Velocity to Position)
        pointX1 += xVel1;
        pointY1 += yVel1;

        
        showScore();
        // Check for collision statement with all targets
        for (int i = 0; i < NUM_TARGETS; i++) {
            double pos = sqrt((pointX1 - targetX[i]) * (pointX1 - targetX[i]) + (pointY1 - targetY[i]) * (pointY1 - targetY[i]));

            // Score counting
            if (pos < 70) {
                score += 100;
                moveTarget(targetX[i], targetY[i]);
                showScore();
            }
        }
        
        
        //Print position of ball for debugging
        //char s[20]; 
        //sprintf_s(s, "pos: %d", pos); 
        //setcolor(WHITE);
        //outtextxy(10, 100, &s[0]);
       
        

 


        // Erase old object if eraseTrails is on
        if (eraseTrails) {
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            fillellipse((int)prevX1, (int)prevY1, 20, 20);
        }

        // If there's gravity, add to y velocity
        if (gravityOn) {
            yVel1 += 0.3;
        }

        // Change current color if changeColorsOn is true
        if (changeColorsOn) {
            setcolor(currentColor);
            setfillstyle(SOLID_FILL, currentColor);
            // Cycle through colors 1 to 15 (0 is black)
            currentColor = ((currentColor + 1) % 15) + 1;
        }
        else {
            setcolor(BLACK); //black outline, to see better with trails on
            setfillstyle(SOLID_FILL, WHITE); //white interior
        }

        // -------------- Check to see if a key has been pressed ---------------------
        if (kbhit()) {
            keyPressed = getch();

            // KEY: Q or ESC pressed
            if (keyPressed == 'q' || keyPressed == 'Q' || keyPressed == 0x1b) {  // q - quit, 0x1b is ESC key
                keepGoing = false;
            }// end if (Q)

            //if (keyPressed == 'm' || keyPressed == 'M')
                //moveTarget(targetX, targetY);

            //if (keyPressed == 's' || keyPressed == 'S')
              //score += 100;

            //Toggle Trails with T key
            if (keyPressed == 't' || keyPressed == 'T')
                eraseTrails = !eraseTrails;

            // Toggle Gravity with G key
            //    This illustrates a shorter way to toggle
            if (keyPressed == 'g' || keyPressed == 'G')
                gravityOn = !gravityOn;

            //Toggle Change Colors with C key
            if (keyPressed == 'c' || keyPressed == 'C') {
                changeColorsOn = !changeColorsOn;
            }
        }//end if kbhit()

        // -------------- Check to see if a mouse was clicked ---------------------
        if (ismouseclick(WM_LBUTTONUP)) {
            getmouseclick(WM_LBUTTONUP, mouseX, mouseY);
            pointX1 = mouseX;
            pointY1 = mouseY;
        }//end if ismouseclick()

        // -------------- Draw Object in new Position ---------------

        // Draw object in new position
        // Draw filled in circle at pointX1, pointY1
        fillellipse((int)pointX1, (int)pointY1, 20, 20);

        // Bounce off walls by reversing velocity if it's near edge
        // Bounce off left/right wall
        if (pointX1 + xVel1 > 770.0 || pointX1 + xVel1 < 30.0) {
            xVel1 = xVel1 * -1.0; //multiplying by -1 changes the direction
        }

        // Bounce off top/bottom walls
        if (pointY1 + yVel1 > 570.0 || pointY1 + yVel1 < 30.0) {
            yVel1 *= -1.0; // another way to multiply by -1
        }

    } // end while kbhit

    // After while(keepGoing), the game is over

    //closegraph(); // shut down the graphics window
    return 0;
} // end main()

 

// Function Definitions

void drawTarget(double x, double y, int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    fillellipse((int)x, (int)y, 50, 50);
}

void moveTarget(double& x, double& y) {
    drawTarget(x, y, BLACK);  // Erase target from old location
    x = randomReal(myEngine) * 600.0 + 100.0;
    y = randomReal(myEngine) * 300.0 + 50.0;
    drawTarget(x, y, YELLOW); // Draw target in new, random location
}

void showScore() {
    char s[20]; // An array of char, which is a string
    sprintf_s(s, "Score: %d", score); // "print" score into a string

    setcolor(WHITE);
    outtextxy(20, 20, &s[0]); // Draw that string in the graphics window
}
