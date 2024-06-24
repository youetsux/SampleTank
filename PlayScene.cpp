#include "PlayScene.h"
#include "Tank.h"
#include "Ground.h"
#include "Enemy.h"
#include "Infomation.h"

//�R���X�g���N�^
PlayScene::PlayScene(GameObject * parent)
	: GameObject(parent, "PlayScene"),
	ENEMY_NUM(5)
{
}

//������
void PlayScene::Initialize()
{
	Instantiate<Tank>(this);
	Instantiate<Ground>(this);

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		Instantiate<Enemy>(this);
	}

	Instantiate<Infomation>(this);
}

//�X�V
void PlayScene::Update()
{
}

//�`��
void PlayScene::Draw()
{
}

//�J��
void PlayScene::Release()
{
}