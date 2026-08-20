#include "Bullet.h"

#include "DX2DClasses/Image.h"

namespace DX2DClasses
{
	CBullet::CBullet()
		: m_fSpeed(8.0f)
	{
	}

	CBullet::~CBullet()
	{
	}

	void CBullet::Initialize(
		HWND hWnd,
		CDriect2DFramwork* pDX2DFramework,
		const SVector2& position
	)
	{
		CImage* pBulletImage =
			new CImage(
				pDX2DFramework->GetD2DRenderTarget(),
				pDX2DFramework->GetImagingFactory(),
				4
			);

		// 실제 이미지 경로에 맞춰 수정
		pBulletImage->ManualLoadImage(
			hWnd,
			L"Images\\Effect\\itemeffect%02d.png"
		);

		CGameObject::Initialize(
			pBulletImage,
			true,
			true
		);

		// 플레이어가 바라보는 방향에 맞춰
		// 오른쪽으로 약간 떨어진 위치에서 생성
		GetTransform().SetTransrate(position);
	}

	void CBullet::Update()
	{
		if (!GetActive())
			return;

		// 오른쪽으로 이동
		GetTransform().Transrate(
			SVector2(m_fSpeed, 0.0f)
		);

		if (GetTransform().GetTransrate().x > 800.0f)
		{
			SetActive(false);
		}

		CGameObject::Update();
	}
}