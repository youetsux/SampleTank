#pragma once
#include "Engine/GameObject.h"
#include "EffekseeLib/EffekseerVFX.h"

//��ԁi�{�́j���Ǘ�����N���X
class Tank : public GameObject
{
	int hModel_;		//���f���ԍ�
	int hGroundModel_;	//�n�ʂ̃��f���ԍ�


	//�ړ�
	void Move();

	//�n�ʂɉ��킹��
	void FollowGround();


public:
	//�R���X�g���N�^
	Tank(GameObject* parent);

	//�f�X�g���N�^
	~Tank();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;


	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	std::shared_ptr<EFFEKSEERLIB::EFKTransform> mt;
};