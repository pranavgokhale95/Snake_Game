 #include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
//int temp_flag_turn=0;
using namespace std;
bool snake_dies(vector<int>& snakeX, vector<int>& snakeY)
{
    for(int i=1;i<snakeX.size();i++)
    {
        if(snakeX[i]==snakeX[0] && snakeY[i]==snakeY[0])
        {
            return true;
        }
    }
    return false;
}
void display(vector<int>& snakeX, vector<int>& snakeY)
{
    for(int i=0;i<snakeX.size();i++)
    {
        cout<<snakeX[i];
        cout<<snakeY[i];
        cout<<endl;
    }
}
void update_grid(vector<int>& snakeX, vector<int>& snakeY,char grid[15][15],int hideX,int hideY)
{
    for(int i=0;i<snakeX.size();i++)
    {

        grid[snakeY[i]][snakeX[i]]='o';
    }
    grid[hideY][hideX]=' ';
}
int food_position_generate()
{
    int food_pos;
    food_pos=(rand()%12)+1;
    return food_pos;
}
int position_solve(int pos)
{
    if(pos<=0)
    {
        pos=13+pos;
    }
    else
    {
        pos=pos%14;
        if(pos==0)
        {
            pos=1;
        }
    }

    return pos;
}

void clearscreen()
{
    system("CLS");
}
void renderscreen(int posX, int posY,char grid[15][15])  //function to display only! Put logic in other functions
{

        clearscreen();
        for(int y=0;y<15;y++)
        {
            for(int x=0;x<15;x++)
            {
                cout<<grid[y][x];
            }
            cout<<endl;
        }
}
void gameover(int posX, int posY,char grid[15][15])
{
    clearscreen();
    Sleep(500);
    renderscreen(posX,posY,grid);
    Sleep(500);
    clearscreen();
    Sleep(500);
    renderscreen(posX,posY,grid);
    Sleep(500);
    clearscreen();
    Sleep(500);
    clearscreen();
    cout<<"Game Over bitch! Game over!"<<endl;
    Sleep(500);
    //cout<<"Always wanted to say that :P"<<endl;


}
int main()
{
    vector<int> snakeX;
    vector<int> snakeY;
    vector<int> foodbufX;
    vector<int> foodbufY;
    vector<int> snakelenAddCount;
    bool food_flag=true;
    int flag_turn=0;
    int hideX,hideY;
    int score=0;
    int foodX,foodY;
    int snake_len_temp=-1;
    signed int posX=7;
    signed int posY=7;
    snakeX.push_back(7);
    snakeY.push_back(7);
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    char direction;
    char grid[15][15]={{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'!',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','!'},
                       {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}
                       };

    while(1)
    {
            if(food_flag==true)
            {
                foodX=food_position_generate();
                foodY=food_position_generate();
                //foodX=10;
                //foodY=7;
                grid[foodY][foodX]='$';
                food_flag=false;
            }
            if(posX==foodX && posY==foodY)
            {
                food_flag=true;
                score++;
                foodbufX.push_back(foodX);
                foodbufY.push_back(foodY);
                snakelenAddCount.push_back(score);
                //display(snakeX,snakeY);
                snake_len_temp=score;
                //Sleep(2000);
            }



            posX=position_solve(snakeX[0]);
            posY=position_solve(snakeY[0]);
            renderscreen(posX,posY,grid);
            //cout<<posX<<" "<<posY<<endl;
            cout<<"Snake Length: "<<score+1<<endl;

            Sleep(1);
            direction=getch();
            //TODO set a variable called flag_len, unique flags for each direction, change then diff != 0 ie, render only one
            if(score>=1)
            {
                hideX=snakeX[snakeX.size()-1];
                hideY=snakeY[snakeY.size()-1];

                for(int i=snakeX.size()-1;i>0;i--)
                {

                    snakeX[i]=snakeX[i-1];
                    snakeY[i]=snakeY[i-1];


                }
            }
            else{
                hideX=snakeX[0];
                hideY=snakeY[0];
            }

            if(direction=='a')
            {
                posX--;
            }
            else if(direction=='d')
            {
                posX++;
            }
            else if(direction=='w')
            {
                posY--;
            }
            else if(direction=='s')
            {
                posY++;
            }

            snakeX[0]=posX;
            snakeY[0]=posY;

            if (score!=0)
            {
                snakelenAddCount[0]=snakelenAddCount[0]-1; //check before and after the renderscreen

            }
            if(score!=0)
            {
                    if(snakelenAddCount[0]==0)
                {
                    snakeX.push_back(foodbufX[0]);
                    snakeY.push_back(foodbufY[0]);
                    foodbufX.erase(foodbufX.begin());
                    foodbufY.erase(foodbufY.begin());
                    snakelenAddCount.erase(snakelenAddCount.begin());
                }
            }
            if(snake_dies(snakeX,snakeY))
            {
                gameover(posX,posY,grid);
                //cout<<"Game over scenario"<<endl;
                //display(snakeX,snakeY);
                Sleep(5000);
                break;
            }
            else
            {

                snakeX[0]=position_solve(snakeX[0]);
                snakeY[0]=position_solve(snakeY[0]);
                update_grid(snakeX,snakeY,grid,hideX,hideY);
            }
            display(snakeX,snakeY); //debug function

            //Sleep(1000);

    }
    cout<<"High score was:"<<score;
    Sleep(5000);
	return 0;
}

