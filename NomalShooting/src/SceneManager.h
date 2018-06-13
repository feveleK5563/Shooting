#pragma once
#include <memory>
#include "SceneAbstract.h"

//�V�[���Ǘ�
class SceneManager
{
private:
	std::unique_ptr<SceneAbstract> Scene;

public:
	//�R���X�g���N�^(�ŏ��ɐݒ肷��V�[���������ɓ����)
	SceneManager(SceneName SceneName);

private:
	//�w�肵���V�[���ɕύX
	void SetScene(SceneParameter parameter);

public:
	//�V�[���̃A�b�v�f�[�g����
	void Update();

	//�V�[���̕`�揈��
	void Draw();
};