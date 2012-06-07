#include "HarmCheck.h"
#include "Maze.h"

void HarmCheck::bulletHarm( float harm, float& blood )
{
	
}


void HarmCheck::fireHarmCheck( float harm, float& time, float& blood, float timeSinceLastFrame )
{
	
	/// 火属性伤害运作
	if(harm != 0 && time > 0)
	{
		blood -= harm;
		time -= timeSinceLastFrame;
	}
}

void HarmCheck::iceHarmCheck( float harm, float& time, float& speed, float speedTemp, float timeSinceLastFrame )
{
	/// 冰属性伤害运作
	if(harm != 0 && time > 0)
	{
		speed = speedTemp * harm;
		time -= timeSinceLastFrame;
	}
	else 
		speed = speedTemp;
}

void HarmCheck::spikeweedHarmCheck( float harm, float& blood, bool isOnSpikeweed )
{
	if(isOnSpikeweed)
		blood -= harm;
}

void HarmCheck::swampHarmCheck( float harm, float& speed, float speedTemp, bool isInSwamp )
{
	if(isInSwamp)
		speed = speedTemp * harm;
	else 
		speed = speedTemp;
}

bool HarmCheck::checkIsDead( float blood )
{
	if(blood < 0 || blood == 0)
		return true;
	else 
		return false;
}

