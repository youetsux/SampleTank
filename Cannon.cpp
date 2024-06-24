#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Bullet.h"

//�R���X�g���N�^
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1),
	SWING_SPEED(1.5f)
{
}

//�f�X�g���N�^
Cannon::~Cannon()
{
}

//������
void Cannon::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model/TankHead.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Cannon::Update()
{
	//�E����
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.vecY+= SWING_SPEED;
	}

	//������
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.vecY -= SWING_SPEED;
	}

	//����
	if (Input::IsKeyDown(DIK_SPACE))
	{
		//�e���V�[���ɒǉ�
		GameObject* playScene = FindObject("PlayScene");
		Bullet* pBullet = Instantiate<Bullet>(FindObject("PlayScene"));

		//�C��̐�[�ƍ��{�̈ʒu���擾
		XMVECTOR shotPos = Model::GetBonePosition(hModel_, "ShotPoint");		//��[
		XMVECTOR cannonRoot = Model::GetBonePosition(hModel_, "CannonRoot");	//���{

		//����
		pBullet->Shot(shotPos, shotPos - cannonRoot);
	}

	//�J�����̏œ_��C��ɍ��킹��
	XMVECTOR target = XMVector3TransformCoord(transform_.position_, transform_.GetWorldMatrix());
	Camera::SetTarget(target);
}

//�`��
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Cannon::Release()
{
}