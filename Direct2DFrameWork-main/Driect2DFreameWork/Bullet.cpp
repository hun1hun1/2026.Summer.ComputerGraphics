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

		// 총알 이미지 크기
		SVector2 imageSize =
			pBulletImage->GetImageSize();

		// Circle Collider
		m_collider.InitCollider(
			&GetTransform(),

			// 이미지 중심
			SVector2(
				imageSize.x / 2.0f,
				imageSize.y / 2.0f
			),

			// 이미지 크기
			imageSize,

			// Collider 크기 비율
			0.3f
		);
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

	CCircleCollider* CBullet::GetCollider()
	{
		return &m_collider;
	}
}
