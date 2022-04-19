#pragma once

#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include <d3dx12.h>

class Light
{
private: // �G�C���A�X
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;
	using XMVECTOR = DirectX::XMVECTOR;

public: // �T�u�N���X
	// �萔�o�b�t�@�p�f�[�^�\����B0
	struct ConstBufferData
	{
		XMVECTOR lightv; //���C�g�ւ̕�����\���x�N�g��
		XMFLOAT3 lightcolor; //���C�g�̐F
	};

private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;

public: // �ÓI�����o�֐�
	// �ÓI������
	static void StaticInitialize(ID3D12Device* device);
	//�C���X�^���X����
	static Light* Create();

private: // �����o�ϐ�
	// �萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	//���C�g��������(�P�ʃx�N�g��)
	XMVECTOR lightdir = { 1, 0, 0, 0 };
	//���C�g�F
	XMFLOAT3 lightcolor = { 1, 1, 1 };
	//�_�[�e�B�t���O
	bool dirty = false;

public: // �����o�֐�
	//������
	void Initialize();
	//�萔�o�b�t�@�]��
	void TransferConstBuffer();
	//���C�g�������Z�b�g
	void SetLightDir(const XMVECTOR lightdir);
	//���C�g�̐F���Z�b�g
	void SetLightColor(const XMFLOAT3 lightcolor);
	//�X�V
	void Update();
	//�`��
	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);
};