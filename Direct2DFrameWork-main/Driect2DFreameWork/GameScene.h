#pragma once
#include "DX2DClasses/SceneManager.h"
#include "DX2DClasses/ColorBrush.h"

#include "Enemy.h"

#include <vector>

namespace DX2DClasses
{
	class CPlayer;
	class CBullet;

	class CGameScene : public ISceneManager
	{
	private:
		HWND m_hWnd;
		CDriect2DFramwork* m_pDX2DFramework;

		CPlayer* m_pPlayer;

		std::vector<CBullet*> m_bullets;
		std::vector<CEnemy*> m_enemies;

		CColorBrush* m_pDebugBrush;

		float m_fEnemySpawnTimer = 0.0f;
		float m_fEnemySpawnInterval = 1.0f;

		void SpawnEnemy();

		void CheckCollision();

	public:
		CGameScene();
		~CGameScene();

		void Initialize(
			HWND hWnd,
			CDriect2DFramwork* pDX2DFramework
		) override;

		void Release() override;
		void Update() override;
		void Draw() override;
	};
}