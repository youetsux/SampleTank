#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Cannon.h"
#include "Ground.h"

#include <DirectXMath.h>
using namespace DirectX;

//�R���X�g���N�^
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1), hGroundModel_(-1)
{
}

//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("/Model/TankBody.fbx");
	assert(hModel_ >= 0);

	//�q���Ƃ��ĖC����쐬
	Instantiate<Cannon>(this);

	//�e���������Ƃ��Ƀ��[�h����Ə�����������̂ŁA�\�߃��[�h���Ă���
	int hBulletModel;
	hBulletModel = Model::Load("Model/Bullet.fbx");
	assert(hBulletModel >= 0);

	//���^�̓����蔻������
	BoxCollider* collision = new BoxCollider(XMVectorSet(0, 0.5f, 0, 0), XMVectorSet(1, 1, 1, 0));
	AddCollider(collision);

	EFFEKSEERLIB::gEfk->AddEffect("TAMA", "tama.efk");

	EFFEKSEERLIB::EFKTransform t;//matrix isLoop, maxFrame, speed
	DirectX::XMStoreFloat4x4(&(t.matrix), transform_.GetWorldMatrix());
	t.isLoop = true; //�J��Ԃ�ON
	t.maxFrame = 80; //80�t���[��
	t.speed = 1.0; //�X�s�[�h
	mt = EFFEKSEERLIB::gEfk->Play("TAMA", t);
}

//�X�V
void Tank::Update()
{
	//�ړ�
	Move();

	//�n�ʂɉ��킹��
	FollowGround();

	//�G���������Ȃ�������N���A��ʂ�
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
	XMMATRIX tr = XMMatrixTranslation(0, 1.0, 0.5);
	XMMATRIX rt = XMMatrixRotationY(XM_PI);
	DirectX::XMStoreFloat4x4(&(mt->matrix), rt*tr*this->GetWorldMatrix());
}

//�ړ�
void Tank::Move()
{
	//��Ԃ������Ă�������ɉ�]������s��
	XMMATRIX rotateMatrix = XMMatrixRotationY(transform_.rotate_.vecY / 180 * 3.14f);

	//�ړ��x�N�g��
	XMVECTOR  moveVector = XMVector3TransformCoord(XMVectorSet(0, 0, 0.2f, 0), rotateMatrix);



	//�O�i
	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += moveVector;
	}

	//���
	if (Input::IsKey(DIK_S))
	{
		transform_.position_ -= moveVector;
	}

	//�E����
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 1;
	}

	//������
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.vecY -= 1;
	}
}

//�n�ʂɉ��킹��
void Tank::FollowGround()
{

	//�܂��n�ʂ̃��f���ԍ���m��Ȃ�
	if (hGroundModel_ == -1)
	{
		//���f���ԍ��𒲂ׂ�
		hGroundModel_ = ((Ground*)FindObject("Ground"))->GetModelHandle();
	}

	//�����n�ʂ̃��f���ԍ���m���Ă���
	else
	{
		//���C��������
		RayCastData data;
		data.start = transform_.position_;		//��Ԃ̌��_����
		data.start.vecY = 0;						//����0�i�n�ʂ͈�ԍ����Ƃ���ł�Y<0�ɂȂ��Ă���j
		data.dir = XMVectorSet(0, -1, 0, 0);			//�^������

														//�n�ʂɑ΂��ă��C������
		Model::RayCast(hGroundModel_, &data);

		//���C���n�ʂɓ���������
		if (data.hit)
		{
			//��Ԃ̍�����n�ʂɂ��킹��
			//�iY=0�̍������烌�C�����āAdata.dist���[�g����ɒn�ʂ��������Ƃ������Ƃ�
			//�@�����̕W���́w-data.dist���[�g���x�Ƃ������ƂɂȂ�j
			transform_.position_.vecY = -data.dist;
		}
	}
}

//�`��
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}