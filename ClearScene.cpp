#include "ClearScene.h"
#include "Engine/Image.h"

//�R���X�g���N�^
ClearScene::ClearScene(GameObject * parent)
	: GameObject(parent, "ClearScene"), hPict_(-1)
{
}

//������
void ClearScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Picture/ClearScreen.jpg");
	assert(hPict_ >= 0);
	Image::SetRect(hPict_, 0, 0, 1280, 720);
}

//�X�V
void ClearScene::Update()
{
}

//�`��
void ClearScene::Draw()
{
		Image::SetTransform(hPict_, transform_);
		Image::Draw(hPict_);
}

//�J��
void ClearScene::Release()
{
}