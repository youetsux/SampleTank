#include "Infomation.h"
#include "Engine/Image.h"

//�R���X�g���N�^
Infomation::Infomation(GameObject * parent)
	:GameObject(parent, "Infomation"), hPict_(-1)
{
	//�摜�f�[�^�̃��[�h
	hPict_ = Image::Load("Picture/info.png");
	assert(hPict_ >= 0);

	//�ʒu
	transform_.position_ = XMVectorSet(-0.75f, 0.8f, 0, 0);
}

//�f�X�g���N�^
Infomation::~Infomation()
{
}

//������
void Infomation::Initialize()
{

}

//�X�V
void Infomation::Update()
{
}

//�`��
void Infomation::Draw()
{
	Image::SetTransform(hPict_, transform_);
	Image::Draw(hPict_);
}

//�J��
void Infomation::Release()
{
}


