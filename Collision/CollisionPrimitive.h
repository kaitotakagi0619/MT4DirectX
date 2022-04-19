#pragma once

#include <DirectXMath.h>

struct Sphere //��
{
	//���S���W
	DirectX::XMVECTOR center = { 0,0,0,1 };
	//���a
	float radius = 1.0f;
};

struct Plane //����
{
	//�@���x�N�g��
	DirectX::XMVECTOR normal = { 0,1,0,0 };
	//���_(0,0,0)����̋���
	float distance = 0.0f;
};

class Triangle //�@���t���̎O�p�`
{
public:
	//���_���W3��
	DirectX::XMVECTOR p0;
	DirectX::XMVECTOR p1;
	DirectX::XMVECTOR p2;
	//�@���x�N�g��
	DirectX::XMVECTOR normal;

public:
	//�@���̌v�Z
	void ComputeNormal();
};

struct Ray //���C(������)
{
	//�n�_���W
	DirectX::XMVECTOR start = { 0, 0, 0, 1 };
	//����
	DirectX::XMVECTOR dir = { 1, 0, 0, 0 };
};