#include "GameoverScene.h"
#include "Engine/Image.h"

//�R���X�g���N�^
GameoverScene::GameoverScene(GameObject * parent)
	: GameObject(parent, "GameoverScene"), hPict_(-1)
{
}

//������
void GameoverScene::Initialize()
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Picture/GameoverScreen.jpg");
	assert(hPict_ >= 0);
	Image::SetRect(hPict_, 0, 0, 1280, 720);
}

//�X�V
void GameoverScene::Update()
{
}

//�`��
void GameoverScene::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void GameoverScene::Release()
{
}