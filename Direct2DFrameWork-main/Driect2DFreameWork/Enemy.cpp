#include "Enemy.h"

#include "DX2DClasses/Image.h"

namespace DX2DClasses
{
	CEnemy::CEnemy()
		: m_fMoveSpeed(5.0f)
	{
	}

	CEnemy::~CEnemy()
	{
	}

	void CEnemy::Initialize(
		HWND hWnd,
		CDriect2DFramwork* pDX2DFramework,
		const SVector2& position
	)
	{
		CImage* pEnemyImage =
			new CImage(
				pDX2DFramework->GetD2DRenderTarget(),
				pDX2DFramework->GetImagingFactory(),
				8
			);

		// eagle00.png ~ eagle07.png
		pEnemyImage->ManualLoadImage(
			hWnd,
			L"Images\\Enemy\\eagle%02d.png"
		);

		CGameObject::Initialize(
			pEnemyImage,
			true,
			true
		);

		// 적 생성 위치
		GetTransform().SetTransrate(position);

		// 이미지 크기
		SVector2 imageSize = pEnemyImage->GetImageSize();

		// Collider 생성
		m_collider.InitCollider(
			&GetTransform(),
			SVector2(
				imageSize.x / 2.0f,
				imageSize.y / 2.0f
			),
			imageSize,
			0.3f
		);
	}

	void CEnemy::Update(const SVector2& playerPosition)
	{
		if (!GetActive())
			return;

		SVector2 enemyPosition =
			GetTransform().GetTransrate();

		// 플레이어까지의 방향
		SVector2 direction;

		direction.x = playerPosition.x - enemyPosition.x;
		direction.y = playerPosition.y - enemyPosition.y;

		// 방향 벡터 정규화
		float length = direction.Magnitude();

		if (length > 0.0f)
		{
			direction.x /= length;
			direction.y /= length;

			GetTransform().Transrate(
				direction * m_fMoveSpeed
			);
		}

		CGameObject::Update();
	}

	CCircleCollider* CEnemy::GetCollider()
	{
		return &m_collider;
	}
}