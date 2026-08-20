#include "GameScene.h"
#include "Bullet.h"
#include "Player.h"

#include "DX2DClasses/Driect2DFramework.h"
#include "DX2DClasses/Vector2.h"

using namespace DX2DClasses;

CGameScene::CGameScene()
	: m_hWnd(nullptr)
	, m_pDX2DFramework(nullptr)
	, m_pPlayer(nullptr)
{
}

CGameScene::~CGameScene()
{
}

void CGameScene::Initialize(
	HWND hWnd,
	CDriect2DFramwork* pDX2DFramework
)
{
	m_hWnd = hWnd;
	m_pDX2DFramework = pDX2DFramework;

	m_pPlayer = new CPlayer();

	m_pPlayer->Initialize(
		m_hWnd,
		m_pDX2DFramework
	);
}

void CGameScene::Update()
{
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
}

void CGameScene::Draw()
{
	// Player Draw
	if (m_pPlayer)
	{
		m_pPlayer->Draw();
	}

	// Bullet Draw
	for (CBullet* bullet : m_bullets)
	{
		if (bullet->GetActive())
		{
			bullet->Draw();
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
}