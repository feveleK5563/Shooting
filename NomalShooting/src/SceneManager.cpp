#include "Scene_Title.h"
#include "Scene_Game.h"

#include "SceneManager.h"


//�R���X�g���N�^(�ŏ��ɐݒ肷��V�[���������ɓ����)
SceneManager::SceneManager(SceneName SceneName)
{
	SceneParameter parameter;
	parameter.SetParameterData(SceneParamName::NextScene, (int)SceneName);
	SetScene(parameter);
}

//�w�肵���V�[���ɕύX
void SceneManager::SetScene(SceneParameter parameter)
{
	//�󂯎�����p�����[�^�[���玟�̃V�[�����擾
	SceneName nextScene = SceneName(parameter.GetParameterData(SceneParamName::NextScene));

	//���̃V�[����NoChangeScene�������疳��
	if (nextScene == SceneName::NoChangeScene) return;

	Scene.reset();
	switch (nextScene)
	{
	case SceneName::Title:
		Scene = std::make_unique<Scene_Title>(parameter);
		break;

	case SceneName::Game:
		Scene = std::make_unique<Scene_Game>(parameter);
		break;

	default:
		//�G���[�I�I
		break;
	}
}

//�V�[���̃A�b�v�f�[�g����
void SceneManager::Update()
{
	Scene->Update();
	SetScene(Scene->GetParameter());
}

//�V�[���̕`�揈��
void SceneManager::Draw()
{
	Scene->Draw();
}