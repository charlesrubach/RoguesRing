#ifndef __TEXT_H
#define __TEXT_H
	
#include <pebble.h>
#include "constants.h"
	
static char * cheat_sheet[TOTAL_HIEROGLYPHS + 1] = {
	"Human Chimney / Jack-O-Lantern\n\
	Inhale the initial sulfur flash after striking a match through your nose to blow out \
	smoke from your mouth. (Warning: likely unhealthy.)\nPlace a lit match inside your mouth \
	and slowly inhale so you don\'t get burned.",

	"Static Shock Static / Charge Match\n\
	Slap your right cheek and then left cheek and bring down your hand to knock over a piece \
	of paper. Remember that the direction of your swooping motion determines whether this works, \
	and that you can blast the vortex around a bottle or pint glass.\n\
	To make a match jump, build up anticipation by rubbing the match on things to build up \
	\'static electricity\', then pinch the match between your thumb and ring finger and flick \
	the end with your middle finger as you approach the first match.",

	"Bang Your Head\n\
	Place a quarter on your forehead and bang the side of your head against the table to show \
	how difficult it is to make fall off. Wrap your fingernails around the edges of the quarter \
	as you firmly press on your target’s forehead so they think it is there even though it is \
	not. Laugh.",

	"Four Quarters\n\
	In four moves get the quarters from the diamond configuration to a line configuration.\
	You can only move one quarter at a time and you can\'t pick them up. When you let go of \
	the quarter it needs to be touching at least two other quarters. (see episode for answer)",

	"The Race\n\
	Bet you can down two pints before someone can down two shots. Neither person can touch \
	each other or each other\'s glass and no double fisting. Ask for a head start. They can\'t \
	start drinking the shot until you put the pint back on the bar. Place the empty pint over \
	one of their shots and finish the second pint at your leisure.",

	"The Mirror\n\
	Bet someone they can\'t mirror you. Do several steps and take a sip of your drink. Do a few \
	more steps and then spit the liquid back in your drink. They’ll lose, since they already swallowed their drink.",

	"Kung Fu Match\n\
	Have target pinch matches on a box into the field goal configuration shown. Have him karate \
	chop the match to try to break the top match. In actuality, it will light up in their hand (no, \
	seriously. They’ll get burned). Keep enforcing that they squeeze the matches hard so they stick \
	when the match lights. If they do break the match and it does not light slam down the two matches for them.",

	"Three Caps, One Beverage\n\
	The goal is to get the far left cap in between the middle and far right cap. You can move the far \
	left cap, you can touch the middle cap, but it cannot move. You cannot touch the far right with your \
	finger or the far left one. Hold the middle cap and hit it with the far left cap causing the far right \
	to move so you can complete the puzzle.",

	"The Heist 1, 2 & 3\n\
	Heist #1\n\
	Place a $5 dollar bill under a pint glass. Place a match between two pint glasses as the \'alarm\'. \
	The alarm goes off if the match drops. You cannot touch the match. Light the head of the match so \
	it fuses to the side of the pint glass and take the money.\n\
	Heist #2\n\
	Place a nickel under a glass. Balance a match on top of the nickel. The alarm goes off if the \
	nickel falls over or if someone	touches or moves the safe or if someone bumps the table. You \
	can disable the alarm if the match falls off of the nickel. Use the static of a pinched straw \
	to move the match and make it fall.\n\
	Heist #3\n\
	Setup a tripod configuration with matches and have one match on top of an altoid. \
	The match heads should all be touching. Remove the altoid without touching any of the matches. \
	Light the matches on fire and remove the altoid.",

	"Tic Tac Toe\n\
	Write down your prediction. Play a game of Tic Tac Toe. Go first with X. If opponent plays \
	a corner, you play in the square clockwise to them. If opponent plays a center spot you play \
	the square clockwise to them.",

	"Petals Around The Rose\n\
	Make sure to state the name of the game and that it is important. Also the answer will always \
	be even or 0. Add up all of the dots around the center dot of the 3 or 5 die.",

	"Advanced Nim\nSet up three piles of coins 3, 5 and 7. You can take as many as you want \
	from a single pile per turn. If you take the last one you lose. It does not matter who goes \
	first. Create one of the five configurations 357, 246, 111, 145 or two even piles on your turn.",

	"Whiskey vs Water\n\
	Ask for two totally full shot glasses: one filled with whiskey, one with water. The challenge: \
	swap the liquids between the glasses without using a third vessel of any kind. The solution: place \
	a business card over the water glass, flip it, place it on the whiskey glass, and then \
	ever-so-slightly pull back the business card, so just a crack opens between them. Watch \
	as the two liquids trade places over 5 minutes.",

	"Beer Thumbcuffs\n\
	Ditch your friend at the bar by asking him to place his thumbs as shown in this glyph. \
	As he wonders what comes next, balance his full pint of beer on his thumbs. Finally: leave. He’s trapped.",

	"11 Cent Slide\nSetup the coins as shown. The goal is to get all the pennies on one side, \
	and all the dimes on another, only by jumping them along the line, always in pairs of 11 cents. \
	For the solution, refer to the episode and remember \"over, over, half-over, swap, obvious.\"",

	"Circumference vs Height\nHave everyone kick in a dollar to bet which is longer: the \
	circumference around the mouth of a pint glass, or its height. Keep stacking packs of \
	cigarettes to make the pint taller until all agree that the height must be greater. Finally, \
	wrap a napkin around the mouth and unfold to show that circumference wins.",

	"The Equation\n\
	Set up matches to show the incorrect roman-numeral equation I+II+III=IIII. Moving one \
	match (and keeping it on the same side of the equals sign), make the equation true. Solution \
	is I+I+I+I=IIII",

	"Five Rooms Puzzle\n\
	One half of the \"hard or impossible\" scam. Set up the 5-rooms puzzle as shown, and challenge \
	them to run a continuous curving line through every single wall segment. (They can\'t.)",

	"Number Grid\n\
	Set up the blank grid as shown, and challenge them to write numbers 1-8 without any number \
	touching the next number in the sequence (*EVEN ON A DIAGONAL*). This one\'s hard, but not \
	impossible. Remember: this one’s most powerful when coupled with the 5-rooms puzzle. As long \
	as they don\'t know which is the \"real\" puzzle, they’ll make no progress on either.",

	"Prophetic Dominoes\n\
	Ask your friend to make a giant chain of dominoes, using all the dominoes in the box. When he \
	gets to the end, reveal your prediction of the two end segments being 5 and 3. (Method: steal \
	out the 5/3 domino beforehand. In a full set, a complete chain would be a circle.)",

	"VII=I\n\
	Moving just one match, make this a true equation. Solution: change VII into the square root of 1 \
	(which, naturally, equals one.)",
	
	"5+5+5\n\
	Using just ONE line, make 5+5+5=550. Solution: change to 545+5=550"
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