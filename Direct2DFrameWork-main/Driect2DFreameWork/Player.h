#pragma once

#include "DX2DClasses/GameObject.h"
#include "DX2DClasses/Driect2DFramework.h"

namespace DX2DClasses
{
	class CPlayer : public CGameObject
	{
	private:
		float m_fMoveSpeed = 3.0f;
		bool m_bFireRequested;
		bool m_bPrevSpacePressed;

	public:
		CPlayer();
		virtual ~CPlayer();

		void Initialize(
			HWND hWnd,
			CDriect2DFramwork* pDX2DFramework
		);

		void Update() override;

		bool IsFireRequested() const;
		void ResetFireRequest();
	};
}