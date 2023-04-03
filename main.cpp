
#include <iostream>
using namespace std;
#include<stdlib.h>

char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int turn = 'x';
    int row,column;
    bool draw = false;
    
void display_arr(){
    system("tput clear");
    cout<<"\n\n......Tick  Cross  Game....."<<endl;
    cout<<"\n....JUNAID RANA ...."<<endl;
    cout<<"\n\nplayer 1 [x]"<<endl;
    cout<<"\nplayer 2 [0]"<<endl;
    
    cout<<"\t\t     |     |     "<<endl;  
    cout<<"\t\t  "<<arr[0][0]<<"  |  "<<arr[0][1] <<"  |   "<<arr[0][2]<<"   \n";
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<arr[1][0]<<"  | "<<arr[1][1]<<"   |   "<<arr[1][2]<<"   \n";
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<arr[2][0]<<"  | "<<arr[2][1]<<"   |   "<<arr[2][2]<<"   \n";
    cout<<"\t\t     |     |     "<<endl;
    
}
void player_turn(){
    int choice;
    
    if(turn == 'x')
    cout<<"\n\tplayer 1 [x] turn:";
    
    if(turn == '0')
    cout<<"\n\tplayer 2 [0] turn:";

    cin>>choice;
    switch(choice){
  case 1: row=0; column =0; break;
  case 2: row=0; column =1; break;
  case 3: row=0; column =2; break;
  case 4: row=1; column =0; break;
  case 5: row=1; column =1; break;
  case 6: row=1; column =2; break;
  case 7: row=2; column =0; break;
  case 8: row=2; column =1; break;
  case 9: row=2; column =2; break;
   default:
   cout<<"Invalid choice\n";
     break;
    }
    if(turn == 'x' && arr[row][column]!='x' && arr[row][column]!='0')
    {
        arr[row][column]= 'x';
        turn='0';
    }
    else if(turn == '0'&& arr[row][column]!='x' && arr[row][column]!='0')
    {
        arr[row][column]= '0';
        turn ='x';
    }
   else{
       cout<<"  Box already filled\n  please try again!!\n\n";
       player_turn();
   }
    display_arr();
}
  bool gameover(){
   //cheek win
   for(int i=0; i<3; i++)
   if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] ||arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
   return false;
   if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
   return false;
   
   for(int i=0; i<3; i++)
   for(int j=0; j<3; j++)
   if(arr[i][j]!='x' && arr[i][j]!='0')
   return true;
   // game draw
   draw = true;
   return false;
}

int main(){
    
    while(gameover())
    {
    display_arr();
    player_turn();
   // display_arr();
   gameover();
    }
    if(turn == 'x' && draw == false)
    cout<<"player 2 [0] wins !! congratulations\n";
    
    else if(turn == '0' && draw == false)
    cout<<"player 1 [x] wins !! congratulations\n";
    else
    cout<<"GAME DRAW!!\n";
}