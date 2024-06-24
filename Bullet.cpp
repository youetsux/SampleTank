#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

//�R���X�g���N�^
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1),
	SPEED(0.3f), GRAVITY(0.001f)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model/Bullet.fbx");
	assert(hModel_ >= 0);

	//�Փ˔���
	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.5f);
	AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
	//�ړ�
	transform_.position_ += move_;

	//�d��
	move_.vecY += dy_;
	dy_ -= GRAVITY;


	//������x�Ⴂ�ʒu�܂ŗ����������
	if (transform_.position_.vecY < -5)
	{
		KillMe();
	}
}

//�`��
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}


//����
void Bullet::Shot(XMVECTOR position, XMVECTOR direction)
{
	//�ʒu
	transform_.position_ = position;

	//�ړ��́A�����œn���ꂽ������SPEED�̑���
	move_ = XMVector3Normalize(direction) * SPEED;
}