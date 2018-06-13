#pragma once
#include <unordered_map>

//�擾�ł�����̖��O
enum struct SceneParamName
{
	NextScene,
};

//�V�[����
enum struct SceneName
{
	NoChangeScene,
	Title,
	Game,
};

//int�^����̃V�[���p�����[�^�[���L��
class SceneParameter
{
public:
	const static int Error = -1;

private:
	std::unordered_map<SceneParamName, int> parameter;

public:
	SceneParameter();
	void SetParameterData(SceneParamName key, int data);	//�w�肵���p�����[�^�[��ݒ肷��
	int GetParameterData(SceneParamName key);			//�w�肵���p�����[�^�[���擾����
};