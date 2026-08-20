#include "GameScene.h"
#include "Bullet.h"
#include "Player.h"

#include "DX2DClasses/Driect2DFramework.h"
#include "DX2DClasses/Vector2.h"
#include "DX2DClasses/Time.h"

#include <cstdlib>
#include <ctime>

using namespace DX2DClasses;

CGameScene::CGameScene()
	: m_hWnd(nullptr)
	, m_pDX2DFramework(nullptr)
	, m_pPlayer(nullptr)
	, m_pDebugBrush(nullptr)
{
}

CGameScene::~CGameScene()
{
	Release();
}

void CGameScene::Initialize(
	HWND hWnd,
	CDriect2DFramwork* pDX2DFramework
)
{
	m_hWnd = hWnd;
	m_pDX2DFramework = pDX2DFramework;

	m_pDebugBrush = new CColorBrush();

	m_pDebugBrush->CreateColorBrush(
		m_pDX2DFramework->GetD2DRenderTarget(),
		D2D1::ColorF(D2D1::ColorF::Red)
	);

	m_pPlayer = new CPlayer();

	m_pPlayer->Initialize(
		m_hWnd,
		m_pDX2DFramework
	);

	srand((unsigned int)time(nullptr));

	// 테스트용 Enemy 생성
	/*CEnemy* pEnemy = new CEnemy();

	pEnemy->Initialize(
		m_hWnd,
		m_pDX2DFramework,
		SVector2(800.0f, 200.0f)
	);

	m_enemies.push_back(pEnemy);*/
}

void CGameScene::Update()
{
	float deltaTime = CTime::GetDeltaTimeModify();

	m_fEnemySpawnTimer += deltaTime;

	if (m_fEnemySpawnTimer >= m_fEnemySpawnInterval)
	{
		m_fEnemySpawnTimer -= m_fEnemySpawnInterval;

		SpawnEnemy();
	}

	// Player Update
	if (m_pPlayer)
	{
		m_pPlayer->Update();

		// 발사 요청 확인
		if (m_pPlayer->IsFireRequested())
		{
			SVector2 bulletPosition =
				m_pPlayer->GetTransform().GetTransrate();

			// 플레이어의 앞쪽에서 생성
			bulletPosition.x += 30.0f;

			CBullet* pBullet = new CBullet();

			pBullet->Initialize(
				m_hWnd,
				m_pDX2DFramework,
				bulletPosition
			);

			m_bullets.push_back(pBullet);

			// 발사 요청 처리 완료
			m_pPlayer->ResetFireRequest();
		}
	}

	// Bullet Update
	for (CBullet* bullet : m_bullets)
	{
		if (bullet->GetActive())
		{
			bullet->Update();
		}
	}

	// Enemy Update
	for (CEnemy* enemy : m_enemies)
	{
		if (enemy->GetActive())
		{
			enemy->Update(
				m_pPlayer->GetTransform().GetTransrate()
			);
		}
	}

	CheckCollision();
}

void CGameScene::Draw()
{
	// Player Draw
	if (m_pPlayer)
	{
		m_pPlayer->Draw();

		m_pPlayer->GetCollider()->DrawOutline(
			m_pDebugBrush,
			2.0f
		);
	}

	// Bullet Draw
	for (CBullet* bullet : m_bullets)
	{
		if (bullet->GetActive())
		{
			bullet->Draw();

			bullet->GetCollider()->DrawOutline(
				m_pDebugBrush,
				1.0f
			);
		}
	}

	// Enemy
	for (CEnemy* enemy : m_enemies)
	{
		if (enemy->GetActive())
		{
			enemy->Draw();

			enemy->GetCollider()->DrawOutline(
				m_pDebugBrush,
				2.0f
			);
		}
	}
}

void CGameScene::Release()
{
	// Bullet 해제
	for (CBullet* bullet : m_bullets)
	{
		if (bullet)
		{
			bullet->Release();
			delete bullet;
		}
	}

	m_bullets.clear();

	// Player 해제
	if (m_pPlayer)
	{
		m_pPlayer->Release();

		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	if (m_pDebugBrush)
	{
		delete m_pDebugBrush;
		m_pDebugBrush = nullptr;
	}

	// Enemy 해제
	for (CEnemy* enemy : m_enemies)
	{
		if (enemy)
		{
			enemy->Release();
			delete enemy;
		}
	}

	m_enemies.clear();
}

void CGameScene::CheckCollision()
{
	for (CBullet* bullet : m_bullets)
	{
		if (!bullet->GetActive())
			continue;

		for (CEnemy* enemy : m_enemies)
		{
			if (!enemy->GetActive())
				continue;

			if (bullet->GetCollider()->ToCircle(
				enemy->GetCollider()))
			{
				bullet->SetActive(false);
				enemy->SetActive(false);

				break;
			}
		}
	}
}

void CGameScene::SpawnEnemy()
{
	CEnemy* pEnemy = new CEnemy();

	float randomY = 50.0f + (rand() % 500);

	pEnemy->Initialize(
		m_hWnd,
		m_pDX2DFramework,
		SVector2(800.0f, randomY)
	);

	m_enemies.push_back(pEnemy);
}