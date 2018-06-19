#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "Math.h"


//�摜��
enum struct ImageName
{
	BackImage,			//�w�i
	PlayerImage,		//�v���C���[
	EnemyImage,			//�G
	NomalBulletImage,	//�ʏ�e
	BombEffect,			//�����G�t�F�N�g
};

//�摜�f�[�^
struct ImageData
{
	int*		handle;		//�O���t�B�b�N�n���h��
	int			sheetNum;	//�摜����
	Math::Box2D	size;		//�摜�T�C�Y
};

//�摜�ǂݍ��݂���
class ImageLoader
{
private:
	std::unordered_map<ImageName, ImageData> imageData;	//�摜�f�[�^

	ImageLoader() = default;

public:
	~ImageLoader();

	//�摜�ǂݍ���
	void LoadOneImage(ImageName imgName, const std::string& filePath);
	
	//�摜�����ǂݍ���
	void LoadDivImage(ImageName imgName, const std::string& filePath, int allNum, int xNum, int yNum, int xSize, int ySize);

	//�摜�f�[�^�̎擾
	const ImageData& GetImageData(ImageName imgName);
	
	//�摜�f�[�^�̉��
	void DeleteImageData(ImageName imgName);

	//�S�Ẳ摜�f�[�^�̉��
	void AllDeleteImageData();

	//�C���X�^���X�𓾂�
	static ImageLoader& GetInstance();
};

//-----------------------------------------------------------------------------
namespace Image
{
	static ImageLoader& imageLoader = ImageLoader::GetInstance();
}