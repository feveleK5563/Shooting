#pragma once

//���Ԍv������
class TimeCounter
{
private:
	int cntTime;	//�o�ߎ���
	int endTime;	//�I������
	bool isTimeEnd;	//�I�����Ԉȏ�v�����Ă��邩�ۂ�

public:
	TimeCounter();

	//�o�ߎ��Ԃ�0�ɂ���
	void ResetCntTime();

	//�I�����Ԃ�ݒ肷��
	void SetEndTime(int setEndTime);

	//���Ԃ𑪂�
	void Run();

	//���݂̌o�ߎ��Ԃ�Ԃ�
	int GetNowCntTime() const;

	//�o�ߎ��Ԃ��I�����Ԃ܂œ��B���Ă�����true��Ԃ�
	bool IsTimeEnd() const;
};