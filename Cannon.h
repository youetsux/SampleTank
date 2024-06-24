#pragma once
#include "Engine/GameObject.h"

//��Ԃ̖C����Ǘ�����N���X
class Cannon : public GameObject
{
	const float SWING_SPEED;	//���񑬓x

	int hModel_;    //���f���ԍ�

public:
	//�R���X�g���N�^
	Cannon(GameObject* parent);

	//�f�X�g���N�^
	~Cannon();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};