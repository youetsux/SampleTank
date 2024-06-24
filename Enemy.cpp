#include "Enemy.h"
#include "Engine/Model.h"
#include "Engine/Audio.h"
#include "Engine/SceneManager.h"
#include "Ground.h"

//�R���X�g���N�^
Enemy::Enemy(GameObject * parent)
	:GameObject(parent, "Enemy"), hModel_(-1), hSound_(-1)
{
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//������
void Enemy::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model/Enemy.fbx");
	assert(hModel_ >= 0);


	//�A�j���[�V�����̐ݒ�
	Model::SetAnimFrame(hModel_, 0, 300, 2.0f);


	//�T�C�Y
	transform_.scale_ = XMVectorSet(2.0f, 2.0f, 2.0f, 0);


	//�ʒu
	transform_.position_.vecX = (float)(rand() % 100 - 50);
	transform_.position_.vecZ = (float)(rand() % 100 - 50);


	//�n�ʂ̍���
	RayCastData data;
	data.start = transform_.position_;
	data.dir = XMVectorSet(0, -1, 0, 0);
	int hGroundModel = ((Ground*)FindObject("Ground"))->GetModelHandle();
	Model::RayCast(hGroundModel, &data);
	transform_.position_.vecY = -data.dist;


	//����
	transform_.rotate_.vecY = (float)(rand() % 360);


	//�����蔻��ǉ�
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0.7f, 0, 0), 2.0f);
	AddCollider(collision);


	//�T�E���h�f�[�^�̃��[�h
	hSound_ = Audio::Load("Audio/Explode.wav");
	assert(hSound_ >= 0);
}

//�X�V
void Enemy::Update()
{
}

//�`��
void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Enemy::Release()
{
}



//�����ɓ�������
void Enemy::OnCollision(GameObject * pTarget)
{
	//�e�ɓ�������
	if (pTarget->GetObjectName() == "Bullet")
	{
		//����������
		KillMe();

		//����i�e�j������
		pTarget->KillMe();

		//���ʉ���炷
		Audio::Play(hSound_);
	}


	//�v���C���[�i��ԁj�ɓ�������
	if (pTarget->GetObjectName() == "Tank")
	{
		//�Q�[���I�[�o�[�V�[����
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
	}
}