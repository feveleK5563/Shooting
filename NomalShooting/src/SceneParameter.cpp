#include "SceneParameter.h"

SceneParameter::SceneParameter()
{
	parameter[SceneParamName::NextScene] = (int)SceneName::NoChangeScene;
}

//�w�肵���p�����[�^�[��ݒ肷��
void SceneParameter::SetParameterData(SceneParamName key, int data)
{
	parameter[key] = data;
}

//�w�肵���p�����[�^�[���擾����
int SceneParameter::GetParameterData(SceneParamName key)
{
	auto it = parameter.find(key);//�w��L�[���擾

	if (it == parameter.end()) //����������G���[
	{
		return Error;//�G���[
	}
	else
	{
		return it->second;//��������l��Ԃ�
	}
}