#pragma once
#include "Engine/GameObject.h"

//�n�ʂ��Ǘ�����N���X
class Infomation : public GameObject
{
	int hPict_;    //�摜�ԍ�

public:
	//�R���X�g���N�^
	Infomation(GameObject* parent);

	//�f�X�g���N�^
	~Infomation();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};