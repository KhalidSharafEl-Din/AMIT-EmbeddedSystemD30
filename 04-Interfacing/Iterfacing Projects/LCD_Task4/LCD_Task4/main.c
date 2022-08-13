/*
 * LCD_Task4.c
 *
 * Created: 6/28/2022 11:33:02 PM
 * Author : Khalid
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "Keypad_interface.h"
#include "DIO_interface.h"

typedef struct {
		s8 PosX; 
		s8 PosY;
		s8 prevX;
		s8 prevY; 
		u8 Score;
		u8 Lives;
		u8 Input;
	}player;
	
const u8 hearts[5][2] = {{5,1},{10,0},{0,1},{13,1},{3,0}};
	  u8 currentHeart =0;	
	  
void initPlayer(player* Pn);
void getPlayerInput(player* Pn);
void movePlayer(player* Pn);
void drawPlayer(player* Pn);
void drawStats(player* Pn);
void lossLive(player* Pn);
u8 scoredHeart(player* Pn);
u8 isWinner(player* Pn);

void drawHeart();

void titleScreen();
void winScreen();
void gameOverSCreen();

int main(void)
{
	DIO_VoidInit();
	LCD_Init();
	KEYPAD_init();
	
	player p1;		initPlayer(&p1);
	
	u8 playerSP1[] = {0x0E,0x0E,0x04,0x0E,0x15,0x04,0x0A,0x0A};
	u8 heartSP1[]  = {0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00};
		
	LCD_CreateChar(0, playerSP1);
	LCD_CreateChar(1, heartSP1);
	
	
    /* Replace with your application code */
    while (1) 
	{	titleScreen();
		drawHeart();
		drawPlayer(&p1);
		drawStats(&p1);
		while(1){
			getPlayerInput(&p1);
			movePlayer(&p1);
		
			if(scoredHeart(&p1)){ p1.Score++;   currentHeart++;}
			if(isWinner(&p1)){
				winScreen();
				_delay_ms(1500);
				initPlayer(&p1);
				currentHeart=0;
				LCD_Clear();
				break;
			}
			drawHeart();
			drawPlayer(&p1);
			drawStats(&p1);
			_delay_ms(10);
		}
		
    }
}

void initPlayer(player* Pn){
	Pn->Score=0;
	Pn->PosX=0;
	Pn->PosY=0;
	Pn->Lives=3;
}

void movePlayer(player* Pn){
	
	Pn->prevX = Pn->PosX;
	Pn->prevY = Pn->PosY;
	
	if(Pn->Input == '6'){Pn->PosX++;}
	if(Pn->Input == '4'){Pn->PosX--;}
	if(Pn->Input == '8'){Pn->PosY++;}
	if(Pn->Input == '2'){Pn->PosY--;}
		
	if(Pn->PosX >_LCD_COLS-3){Pn->PosX=_LCD_COLS-3;lossLive(Pn);}
	if(Pn->PosY >_LCD_ROWS-1){Pn->PosY=_LCD_ROWS-1;lossLive(Pn);}
		
	if(Pn->PosX < 0){Pn->PosX=0;lossLive(Pn);}
	if(Pn->PosY < 0){Pn->PosY=0;lossLive(Pn);}
	
	
		
}

void drawPlayer(player* Pn){
	if((Pn->prevX != Pn->PosX) || (Pn->prevY != Pn->PosY)){
		LCD_Puts(Pn->prevX, Pn->prevY, " ");
		LCD_PutCustom(Pn->PosX, Pn->PosY, 0);
	}
	
}

void drawStats(player* Pn){
	LCD_Puts(_LCD_COLS-2, _LCD_ROWS-1,"S");
	LCD_Put(Pn->Score+48);
	LCD_Puts(_LCD_COLS-2, _LCD_ROWS-2,"L");
	LCD_Put(Pn->Lives+48);
}

void getPlayerInput(player* Pn){
	Pn->Input = KEYPAD_getButton();
	while(Pn->Input == KEYPAD_getButton());
}

u8 scoredHeart(player* Pn){
	if((Pn->PosX==hearts[currentHeart][0]) && (Pn->PosY==hearts[currentHeart][1])){return 1;}
	else{return 0;}
}

u8 isWinner(player* Pn){
	 if (Pn->Score >=5 ) return 1;
	 else return 0;
}

void lossLive(player* Pn){
	LCD_Clear();
	LCD_Puts(2,0, "Dude Careful");
	LCD_Puts(1,1, "Don't Fall off");
	_delay_ms(500);
	LCD_Clear();
	Pn->Lives --;
	if(Pn->Lives == 0){
		LCD_Clear();
		gameOverSCreen();
		_delay_ms(1500);
		initPlayer(Pn);
		currentHeart=0;
		LCD_Clear();
	}
}

void titleScreen(){
	LCD_Clear();
	LCD_Puts(2,0, "The Collector");
	LCD_Puts(0,1, "A Platform Game");
	_delay_ms(2000);
	LCD_Clear();
}
void winScreen(){
	LCD_Clear();
	LCD_Puts(4,0, "You Win");
	LCD_Puts(3,1, "Great Job");
	_delay_ms(1000);
	LCD_Clear();
	LCD_Puts(4,0, "Game Dev");
	LCD_Puts(0,1, "KhalidSharafElDn");
}



void gameOverSCreen(){
	LCD_Clear();
	LCD_Puts(4,0, "You Lose");
	LCD_Puts(3,1, "Game Over");
	_delay_ms(1000);
	LCD_Clear();
	LCD_Puts(4,0, "Game Dev");
	LCD_Puts(0,1, "KhalidSharafElDn");
	
}

void drawHeart(){
	LCD_PutCustom(hearts[currentHeart][0],hearts[currentHeart][1],1);
}