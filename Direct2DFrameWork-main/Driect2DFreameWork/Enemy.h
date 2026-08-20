#pragma once

#include "DX2DClasses/GameObject.h"
#include "DX2DClasses/Driect2DFramework.h"
#include "DX2DClasses/Colliders.h"

namespace DX2DClasses
{
	class CEnemy : public CGameObject
	{
	private:
		float m_fMoveSpeed;

		CCircleCollider m_collider;

	public:
		CEnemy();
		virtual ~CEnemy();

		void Initialize(
			HWND hWnd,
			CDriect2DFramwork* pDX2DFramework,
			const SVector2& position
		);

		void Update(const SVector2& playerPosition);

		CCircleCollider* GetCollider();
	};
}