#pragma once

#include "SafeDelete.h"
#include "DirectXCommon.h"
#include <DirectXMath.h>
#include "Input.h"
#include "Sprite.h"
#include "Object3d.h"
#include "ParticleManager.h"
#include "DebugText.h"
#include "Audio.h"
#include "Light.h"
#include "CollisionPrimitive.h"

// ゲームシーン
class GameScene
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

private: // 静的メンバ変数
	static const int debugTextTexNumber = 0;

public: // メンバ関数

	// コンストクラタ
	GameScene();

	// デストラクタ
	~GameScene();

	// 初期化
	void Initialize(DirectXCommon* dxCommon, Input* input, Audio* audio);

	// 毎フレーム処理
	void Update();

	// 描画
	void Draw();

	// パーティクル生成
	void CreateParticles();

	void CreateLight();


private: // メンバ変数
	DirectXCommon* dxCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	DebugText debugText;


	XMFLOAT3 cameraPos = { 0,0,0 };
	float cameraPosZ = -50.0f;

	// ゲームシーン用
	Camera* camera = nullptr;
	//Sprite* spriteBG = nullptr;
	Sprite* sprite[1] = { nullptr };
	ParticleManager* particleMan = nullptr;
	Light* light = nullptr;

	Model* modelSkydome = nullptr;
	Model* modelGround = nullptr;
	Model* modelFighter = nullptr;
	Model* modelFighter2 = nullptr;
	Model* modelSphere = nullptr;

	Object3d* objSphere =  nullptr ;
	Object3d* dome = nullptr;
	Object3d* ground = nullptr;
	Object3d* player = nullptr;
	Object3d* enemy = nullptr;

	float gravity;

	//エネミー
	XMFLOAT3 e_pos; //座標
	XMFLOAT3 old_e_pos; //1フレーム前の座標
	XMFLOAT3 b_pos; //座標
	XMFLOAT3 old_b_pos; //1フレーム前の座標
	float e_down;
	float vecX;
	float vecY;
};