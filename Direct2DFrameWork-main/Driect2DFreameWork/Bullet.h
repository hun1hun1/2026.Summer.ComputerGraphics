#pragma once

#include "DX2DClasses/GameObject.h"
#include "DX2DClasses/Driect2DFramework.h"

namespace DX2DClasses
{
	class CBullet : public CGameObject
	{
	private:
		float m_fSpeed;

	public:
		CBullet();
		~CBullet();

		void Initialize(
			HWND hWnd,
			CDriect2DFramwork* pDX2DFramework,
			const SVector2& position
		);

		void Update() override;
	};
}