#pragma once
#include "Engine/GameObject.h"

//�n�ʂ��Ǘ�����N���X
class Ground : public GameObject
{

	int hModel_;    //���f���ԍ�


public:
	//�R���X�g���N�^
	Ground(GameObject* parent);

	//�f�X�g���N�^
	~Ground();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	//���f���ԍ��̃Q�b�^�[
	int GetModelHandle() { return hModel_; }
};