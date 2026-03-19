
// Ara 

void CInstanceBase::LevelUp()
{
	__AttachEffect(EFFECT_LEVELUP);
}


// Kod bloðun üstüne ekle 

#ifdef ENABLE_TITLE_SYSTEM
void CInstanceBase::AttachSpecialEffectOverHead(DWORD effect)
{
	if (effect >= EFFECT_NUM)
		return;

	ClearSpecialEffectOverHead();

	const float fOverHeadZ = GetBaseHeight() + m_GraphicThingInstance.GetHeight() + 80.0f;
	D3DXVECTOR3 v3Pos(0.0f, 0.0f, fOverHeadZ);
	m_dwOverHeadSpecialEffect = m_GraphicThingInstance.AttachEffectByID(0, nullptr, ms_adwCRCAffectEffect[effect], &v3Pos);
}

void CInstanceBase::ClearSpecialEffectOverHead()
{
	if (!m_dwOverHeadSpecialEffect)
		return;

	__DetachEffect(m_dwOverHeadSpecialEffect);
	m_dwOverHeadSpecialEffect = 0;
}
#endif
