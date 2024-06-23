# include "iGraphics.h"
# include "gl.h"

#define N_PLANETS 9
int orbit=1,sorbit=1;

int g_sunX, g_sunY, g_sunR;
int j,i;

int g_planetMajorAxisLen[N_PLANETS] = {160,200,240,280,320,360,400,440,480};
int g_planetMinorAxisLen[N_PLANETS] = {120,150,180,210,240,270,300,330,360};
int g_planetRadius[N_PLANETS] = {10,10,8,8,15,20,25,25,25};
int g_planetSweepAngle[N_PLANETS] = {0,0,0,0,0,0,0,0,0};
int g_planetDelSweepAngle[N_PLANETS] = {9,8,2,2,2,6,4,3,2};
int g_satelliteOrbitR, g_satelliteR, g_satelliteSweepAngle,g_satelliteOrbit,g_satellite;

void drawStar(int x, int y, int r)
{
    iSetColor(256, 256, 0);
    iFilledCircle(x, y, r);
}

void drawOrbit(int x, int y, int a, int b)
{
    if(orbit%2==1)
    {
        iSetColor(188, 256, 178);
        iEllipse(x, y, a, b);
    }
}

void drawPlanet(int x, int y, int orbitA, int orbitB, int planetR, int sweepAngle,int i)
{
    double pi = 2*acos(0);
    double sweepRadian = sweepAngle * pi / 180;
    int planetX = x + orbitA * cos(sweepRadian);
    int planetY = y + orbitB * sin(sweepRadian);

    iSetColor(256-i*5, 125+i*10, 256-i*10);
    iFilledCircle(planetX, planetY, planetR);
}

void drawSatellite(
    int x,
    int y,
    int planetOrbitA,
    int planetOrbitB,
    int planetSweepAngle,
    int satelliteOrbitR,
    int j,
    int satelliteR,
    int satelliteSweepAngle)
{
    double pi = 2*acos(0);
    double planetSweepRadian = planetSweepAngle * pi / 180;
    double satelliteSweepRadian = satelliteSweepAngle * pi / 180;

    int planetX = x +planetOrbitA * cos(planetSweepRadian);
    int planetY = y +planetOrbitB * sin(planetSweepRadian);

    int satelliteX = planetX + satelliteOrbitR * cos(satelliteSweepRadian);
    int satelliteY = planetY + j* sin(satelliteSweepRadian);
    iSetColor(256, 62, 62);
    iFilledCircle(satelliteX, satelliteY, satelliteR);
    if(sorbit%2!=0)
    {
        iSetColor(256-j*10, 62+j*10, 62);
        iEllipse(planetX,planetY,satelliteOrbitR,j);
    }
}
void iDraw()
{
    double centerX, centerY;
    int i;

    iClear();
    iShowBMP(0,0,"1.bmp");
    drawStar(g_sunX, g_sunY, g_sunR);

    for (i = 0; i < N_PLANETS; i++)
    {
        centerX = g_sunX + sqrt(pow(g_planetMajorAxisLen[i], 2) - pow(g_planetMinorAxisLen[i], 2));
        centerY = g_sunY;
        drawOrbit(centerX, centerY, g_planetMajorAxisLen[i], g_planetMinorAxisLen[i]);
        drawPlanet(
            centerX,
            centerY,
            g_planetMajorAxisLen[i],
            g_planetMinorAxisLen[i],
            g_planetRadius[i],
            g_planetSweepAngle[i],
            i
        );
        if (i == 2)
        {
            for(j=1; j<2; j++)
            {
                drawSatellite(
                    centerX,
                    centerY,
                    g_planetMajorAxisLen[i],
                    g_planetMinorAxisLen[i],
                    g_planetSweepAngle[i],
                    g_satelliteOrbitR+j*10,
                    j*10,
                    g_satelliteR,
                    g_satelliteSweepAngle
                );
            }
        }
        if( i== 3)
        {
            int j;
            for(j=1; j<=2; j++)
            {
                drawSatellite(
                    centerX,
                    centerY,
                    g_planetMajorAxisLen[i],
                    g_planetMinorAxisLen[i],
                    g_planetSweepAngle[i],
                    g_satelliteOrbitR+j*10,
                    j*10,
                    g_satelliteR,
                    g_satelliteSweepAngle
                );
            }
        }
    }
    iSetColor(255, 255, 255);
    iText(10, 10, "Press m/M to zoom out, b/B to zoom in, o/O to remove planet orbit, s/S to remove satellite orbit, p for pause, r for resume, END for exit.");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'p')
    {
        //do something with 'q'
        iPauseTimer(0);
    }
    if(key == 'r')
    {
        iResumeTimer(0);
    }
    if(key == 'o' || key== 'O')
    {
        orbit++;
    }
    if(key == 's' || key== 'S')
    {
        sorbit++;
    }
    if(key == 'm' || key== 'M')
    {
        g_sunX/=1.5;
        g_sunY/=1.5;
        g_sunR/=1.5;
        g_satelliteOrbitR/=1.5;
        g_satelliteR/=1.5;

        for(int i=0; i<N_PLANETS; i++)
        {
            g_planetMajorAxisLen[i]/=1.5;
            g_planetMinorAxisLen[i]/=1.5;
            g_planetRadius[i]/=1.5;

        }
    }
    if(key == 'b' || key== 'B')
    {
        g_sunX*=1.5;
        g_sunY*=1.5;
        g_sunR*=1.5;
        g_satelliteOrbitR*=1.5;
        g_satelliteR*=1.5;
        for(int i=0; i<N_PLANETS; i++)
        {
            g_planetMajorAxisLen[i]*=1.5;
            g_planetMinorAxisLen[i]*=1.5;
            g_planetRadius[i]*=1.5;
        }

    }

}
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        g_sunX++;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        g_sunX--;
    }
    if(key == GLUT_KEY_UP)
    {
        g_sunY--;
    }
    if(key == GLUT_KEY_DOWN)
    {
        g_sunY++;
    }
}

void movePlanets()
{
    const int g_dSatelliteSweepAngle = 1;

    int i;

    for (i = 0; i < N_PLANETS; i++)
    {
        g_planetSweepAngle[i] = (g_planetSweepAngle[i] + g_planetDelSweepAngle[i])%360;
        g_satelliteSweepAngle = (g_satelliteSweepAngle + g_dSatelliteSweepAngle)%360;
    }
}

int main()
{
    const int CX_MAX = 1366;
    const int CY_MAX = 768;

    // Initialize Sun's position and size.
    g_sunX = 150;
    g_sunY = CY_MAX/2;
    g_sunR = 50;

    g_satelliteOrbitR = 25;
    g_satelliteR= 5;

    g_satelliteOrbit=15;
    g_satellite=5;

    //place your own initialization codes here.
    iSetTimer(20, movePlanets);
    iInitialize(CX_MAX, CY_MAX, "Solar system!");

    return 0;
}

