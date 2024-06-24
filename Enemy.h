#pragma once
#include "Engine/GameObject.h"

//�G���Ǘ�����N���X
class Enemy : public GameObject
{

	int hModel_;	//���f���ԍ�
	int hSound_;	//�T�E���h�ԍ�

public:
	//�R���X�g���N�^
	Enemy(GameObject* parent);

	//�f�X�g���N�^
	~Enemy();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
	//�����FpTarget�@������������
	void OnCollision(GameObject * pTarget) override;
};