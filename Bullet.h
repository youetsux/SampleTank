#pragma once
#include "Engine/GameObject.h"

//�e���Ǘ�����N���X
class Bullet : public GameObject
{

	int hModel_;		//���f���ԍ�
	XMVECTOR move_;		//�ړ��x�N�g��
	float dy_;			//�x�����̉����x

	const float SPEED;		//���x
	const float GRAVITY;	//�d��

public:
	//�R���X�g���N�^
	Bullet(GameObject* parent);

	//�f�X�g���N�^
	~Bullet();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;


	//����
	//�����Gposition	���ˈʒu
	//�����Fdirection	���˕���
	void Shot(XMVECTOR position, XMVECTOR direction);
};