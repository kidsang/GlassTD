#ifndef HarmCheck_h__
#define HarmCheck_h__
class Maze;

class HarmCheck
{
private:
public:
	HarmCheck(){};
	~HarmCheck(){};
	void bulletHarm(float harm, float& blood);
	void fireHarmCheck(float harm, float& time, float& blood, float timeSinceLastFrame);
	void iceHarmCheck(float harm, float& time, float& speed, float speedTemp, float timeSinceLastFrame);
	void spikeweedHarmCheck(float harm, float& blood, bool isOnSpikeweed);
	void swampHarmCheck(float harm, float& speed, float speedTemp, bool isInSwamp);
	bool checkIsDead(float blood);
};



#endif // HarmCheck_h__