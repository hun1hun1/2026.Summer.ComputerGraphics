#include "Player.h"

#include "DX2DClasses/Image.h"
#include "DX2DClasses/InputManager.h"
#include "DX2DClasses/Time.h"

namespace DX2DClasses
{
	CPlayer::CPlayer()
		: m_fMoveSpeed(10.0f)
		, m_bFireRequested(false)
		, m_bPrevSpacePressed(false)
	{
	}

	CPlayer::~CPlayer()
	{
	}

	void CPlayer::Initialize(
		HWND hWnd,
		CDriect2DFramwork* pDX2DFramework
	)
	{
		// 플레이어 이미지 생성
		CImage* pPlayerImage =
			new CImage(
				pDX2DFramework->GetD2DRenderTarget(),
				pDX2DFramework->GetImagingFactory(),
				8
			);

		// player00.png ~ player07.png
		pPlayerImage->ManualLoadImage(
			hWnd,
			L"Images\\Player\\player%02d.png"
		);

		// 부모 클래스 초기화
		CGameObject::Initialize(
			pPlayerImage,
			true,
			true
		);

		// 플레이어 시작 위치
		GetTransform().SetTransrate(
			100.0f,
			200.0f
		);

		SVector2 imageSize = pPlayerImage->GetImageSize();

		m_collider.InitCollider(
			&GetTransform(),
			SVector2(
				imageSize.x / 2.0f, imageSize.y / 2.0f
			),
			imageSize,
			0.25f
		);
	}

	void CPlayer::Update()
	{
		if (!GetActive())
			return;

		CTransform& transform = GetTransform();

		// 이동
		if (CInputManager::GetAsyncKeyStatePress(VK_RIGHT))
		{
			transform.Transrate(
				SVector2(m_fMoveSpeed, 0.0f)
			);
		}

		if (CInputManager::GetAsyncKeyStatePress(VK_LEFT))
		{
			transform.Transrate(
				SVector2(-m_fMoveSpeed, 0.0f)
			);
		}

		if (CInputManager::GetAsyncKeyStatePress(VK_UP))
		{
			transform.Transrate(
				SVector2(0.0f, -m_fMoveSpeed)
			);
		}

		if (CInputManager::GetAsyncKeyStatePress(VK_DOWN))
		{
			transform.Transrate(
				SVector2(0.0f, m_fMoveSpeed)
			);
		}

		// 스페이스바
		/*if (CInputManager::GetAsyncKeyStatePress(VK_SPACE))
		{
			m_bFireRequested = true;
		}*/

		bool bSpacePressed =
			CInputManager::GetAsyncKeyStatePress(VK_SPACE);

		if (bSpacePressed && !m_bPrevSpacePressed)
		{
			m_bFireRequested = true;
		}

		m_bPrevSpacePressed = bSpacePressed;

		CGameObject::Update();
	}

	bool CPlayer::IsFireRequested() const
	{
		return m_bFireRequested;
	}

	void CPlayer::ResetFireRequest()
	{
		m_bFireRequested = false;
	}

	CCircleCollider* CPlayer::GetCollider()
	{
		return &m_collider;
	}
}