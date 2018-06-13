#include "TimeCounter.h"

TimeCounter::TimeCounter():
	cntTime(0),
	endTime(0),
	isTimeEnd(false) {}

//�o�ߎ��Ԃ�0�ɂ���
void TimeCounter::ResetCntTime()
{
	cntTime = 0;
	isTimeEnd = false;
}

//�I�����Ԃ�ݒ肷��
void TimeCounter::SetEndTime(int setEndTime)
{
	endTime = setEndTime;
	isTimeEnd = false;
}

//���Ԃ𑪂�
void TimeCounter::Run()
{
	if (cntTime >= endTime)
	{
		isTimeEnd = true;
	}

	++cntTime;
}

//���݂̌o�ߎ��Ԃ�Ԃ�
int TimeCounter::GetNowCntTime() const
{
	return cntTime;
}

//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
bool TimeCounter::IsTimeEnd() const
{
	return isTimeEnd;
}