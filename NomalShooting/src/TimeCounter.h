#pragma once

//時間計測くん
class TimeCounter
{
private:
	int cntTime;	//経過時間
	int endTime;	//終了時間
	bool isTimeEnd;	//終了時間以上計測しているか否か

public:
	TimeCounter();

	//経過時間を0にする
	void ResetCntTime();

	//終了時間を設定する
	void SetEndTime(int setEndTime);

	//時間を測る
	void Run();

	//現在の経過時間を返す
	int GetNowCntTime() const;

	//経過時間が終了時間まで到達していたらtrueを返す
	bool IsTimeEnd() const;
};