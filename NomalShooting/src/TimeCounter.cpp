#include "TimeCounter.h"

TimeCounter::TimeCounter():
	cntTime(0),
	endTime(0),
	isTimeEnd(false) {}

//経過時間を0にする
void TimeCounter::ResetCntTime()
{
	cntTime = 0;
	isTimeEnd = false;
}

//終了時間を設定する
void TimeCounter::SetEndTime(int setEndTime)
{
	endTime = setEndTime;
	isTimeEnd = false;
}

//時間を測る
void TimeCounter::Run()
{
	if (cntTime >= endTime)
	{
		isTimeEnd = true;
	}

	++cntTime;
}

//現在の経過時間を返す
int TimeCounter::GetNowCntTime() const
{
	return cntTime;
}

//経過時間が終了時間まで到達していたらtrueを返す
bool TimeCounter::IsTimeEnd() const
{
	return isTimeEnd;
}