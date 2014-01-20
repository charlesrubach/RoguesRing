#ifndef __TEXT_H
#define __TEXT_H
	
#include <pebble.h>
#include "constants.h"
	
static char * cheat_sheet[TOTAL_HIEROGLYPHS + 1] = {
	"Human Chimney / Jack-O-Lantern\nBreathe in the initial smoke after striking a match to blow out smoke from your mouth.\n\
		Place a lit match inside your mouth and slowly inhale so you don't get burned.", // 1, 2
	"Static Shot / Static Charge Match\nSlap your right cheek and then left cheek and bring down your hand to knock over a\
		piece of paper.\nMake a match jump by pinching the match between your thumb and ring finger and flicking the end with your\
		middle finger. Build up anticipation by rubbing the match on things to build up \'static electricity\'",	// 3, 4
	"Bang Your Head\nPlace a quarter on your forehead and bang the side of your head against the table to make it fall off. \
		Firmly press the quarter on the person you are scamming so they think it is there even though it is not.", // 5
	"Four Quarters\nIn four moves get the quarters from the diamon configuration to a line configuration. You can only move one quarter\
		at a time and you can\'t pick them up. When you let go of the quarter it needs to be touching at least two other quarters.", // 6
	"The Race\nBet you can down two pints before someone can down two shots. Neither person can touch each other or each other\'s glass and no double fisting. \
		Ask for a head start. They can\'t start drinking the shot until you put the pint back on the bar. Place the empty pint over one of their\
		shots and finish the second pint at your leisure.", // 7
	"The Mirror\nBet someone they can\'t mirror you. Do several steps and take a sip of your drink. Do a few more steps and then spit \
		the liquid back in your drink. They will lose because they already swallowed their drink.", // 8
	"Kung Fu Match\nSet up the field goal configuration with three matches on a box of wooden matches. Have a friend karate chop the match to try\
		to get the top match to break. In actuality it will light up in their hand. Keep enforcing that they squeeze the matches hard so they stick\
		when the match lights. If they do break the match and it does not light slam down the two matches for them.", // 9
	"Three Caps, One Beverage\nThe goal is to get the far left cap in between the middle and far right cap. You can move the far left cap, you can\
		touch the middle cap, but it cannot move. You cannot touch the far right with your finger or the far left one. Hold the middle cap and hit it with the \
		far left cap causing the far right to move so you can complete the puzzle.", // 10 
	"The Heist 1, 2 & 3\nHeist #1\nPlace a $5 dollar bill under a pint glass. Place a match between two pint glasses as the \'alarm\'. The alarm goes off \
		if the match drops. You cannot touch the match. Light the head of the match so it fuses to the side of the pint glass and take the money.\n\
		Heist #2\nPlace a nickle under a glass. Balance a match on top of the nickle. The alarm goes off if the nickle falls over or if someone touches or moves the \
		safe or if someone bumps the table. You can disable the alarm if the match falls off of the nickle. Use the static of a pinched straw to move the match and\
		make it fall.\n\
		Heist #3\nSetup a tripod configuration with matches and have one match on top of an altoid. The match heads should all be touching. Remove the altoid without \
		touching any of the matches. Light the matches on fire and remove the altoid.", // 11, 12, 13
	"Tic Tac Toe\nWrite down your prediction. Play a game of Tic Tac Toe. Go first with X. If opponent plays a corner, you play in the square clockwise to them. \
		If opponent plays a center spot you play the square clockwise to them.", // 14
	"Petals Around The Rose\nMake sure to state the name of the game and that it is important. Also the answer will always be even or 0. Add up all of the dots around \
		the center dot of the 3 or 5 die.", // 15
	"Advanced Nim\nSet up three piles of coins 3, 5 and 7. You can take as many as you want from a single pile per turn. If you take the last one you lose. It does \
		not matter who goes first. Create one of the five configurations 357, 246, 111, 145 or two even piles on your turn.", // 16
	"Whiskey vs Water\nDescription", // 17
	"Beer Thumbcuffs\nDescription",	// 18
	"11 Cent Slide\nDescription",	// 19
	"Circumference vs Height\nDescription",	// 20
	"The Equation\nDescription", // 21
	"Five Rooms Puzzle\nDescription", // 22 Really Hard or Impossible
	"Number Grid\nDescription", // 22 Really Hard or Impossible
	"Prophetic Dominoes\nDescription", // 23
	"VII=I\nDescription", // 24
	"5+5+5\nDescription", // 25	
};

const ResHandle hieroglyph[TOTAL_HIEROGLYPHS + 1] = 
{
	(ResHandle)RESOURCE_ID_CHIMNEY_LANTERN,
	(ResHandle)RESOURCE_ID_STATIC_SHOT_CHARGE_MATCH,
	(ResHandle)RESOURCE_ID_BANG_YOUR_HEAD,
	(ResHandle)RESOURCE_ID_FOUR_QUARTERS,
	(ResHandle)RESOURCE_ID_THE_RACE,
	(ResHandle)RESOURCE_ID_THE_MIRROR,
	(ResHandle)RESOURCE_ID_KUNG_FU_MATCH,
	(ResHandle)RESOURCE_ID_THREE_CAPS_ONE_BEVERAGE,
	(ResHandle)RESOURCE_ID_THE_HEIST,
	(ResHandle)RESOURCE_ID_TIC_TAC_TOE,
	(ResHandle)RESOURCE_ID_PETALS_AROUND_THE_ROSE,
	(ResHandle)RESOURCE_ID_ADVANCED_NIM,
	(ResHandle)RESOURCE_ID_WHISKEY_VS_WATER,
	(ResHandle)RESOURCE_ID_BEER_THUMBCUFFS,
	(ResHandle)RESOURCE_ID_ELEVEN_CENT_SLIDE,
	(ResHandle)RESOURCE_ID_CIRCUMFERENCE_VS_HEIGHT,
	(ResHandle)RESOURCE_ID_THE_EQUATION,
	(ResHandle)RESOURCE_ID_FIVE_ROOMS_PUZZLE,
	(ResHandle)RESOURCE_ID_NUMBER_GRID,
	(ResHandle)RESOURCE_ID_PROPHETIC_DOMINOES,
	(ResHandle)RESOURCE_ID_VII_EQUALS_I,
	(ResHandle)RESOURCE_ID_FIVE_PLUS_FIVE_PLUS_FIVE,	
};
#endif //__TEXT_H