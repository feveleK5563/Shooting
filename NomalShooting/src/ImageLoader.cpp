#include "DxLib.h"

#include "ImageLoader.h"

//�f�X�g���N�^
ImageLoader::~ImageLoader()
{
	AllDeleteImageData();
}

//�摜�ǂݍ���
void ImageLoader::LoadOneImage(ImageName imgName, const std::string& filePath)
{
	if (imageData.find(imgName) != imageData.end())
	{
		return;
	}

	//string�^��filePath��char*�ɕϊ�
	char* path = new char[filePath.size() + 1];
	std::char_traits<char>::copy(path, filePath.c_str(), filePath.size() + 1);

	//�ǂݍ��񂾉摜�̃f�[�^���i�[
	imageData[imgName].handle = new int[1]{LoadGraph(path)};
	imageData[imgName].sheetNum = 1;
	int xSize, ySize;
	GetGraphSize(*(imageData[imgName].handle), &xSize, &ySize);
	imageData[imgName].size = { 0, 0, xSize, ySize };

	delete[] path;
}

//�摜�����ǂݍ���
void ImageLoader::LoadDivImage(ImageName imgName, const std::string& filePath, int allNum, int xNum, int yNum, int xSize, int ySize)
{
	if (imageData.find(imgName) != imageData.end())
	{
		return;
	}

	//string�^��filePath��char*�ɕϊ�
	char* path = new char[filePath.size() + 1];
	std::char_traits<char>::copy(path, filePath.c_str(), filePath.size() + 1);

	imageData[imgName].handle = new int[allNum] {};
	LoadDivGraph(path, allNum, xNum, yNum, xSize, ySize, imageData[imgName].handle);
	imageData[imgName].sheetNum = allNum;
	imageData[imgName].size = { 0, 0, xSize, ySize };

	delete[] path;
}

//�摜�f�[�^�̎擾
const ImageData& ImageLoader::GetImageData(ImageName imgName)
{
	return imageData[imgName];
}

//�摜�f�[�^�̉��
void ImageLoader::DeleteImageData(ImageName imgName)
{
	for (int i = 0; i < imageData[imgName].sheetNum; ++i)
	{
		DeleteGraph(imageData[imgName].handle[i]);
	}
	delete imageData[imgName].handle;
	imageData.erase(imgName);
}

//�S�Ẳ摜�f�[�^�̉��
void ImageLoader::AllDeleteImageData()
{
	for (	auto it = imageData.begin();
			it != imageData.end();)
	{
		for (int i = 0; i < it->second.sheetNum; ++i)
		{
			DeleteGraph(it->second.handle[i]);
		}
		delete it->second.handle;
		it = imageData.erase(it);
	}
}

//�C���X�^���X�𓾂�
ImageLoader& ImageLoader::GetInstance()
{
	static ImageLoader imageLoader;
	return imageLoader;
}