// Keyboard.cpp

#include "stdafx.h"
#include "Keyboard.h"

Keyboard::Keyboard()
{
	for (int i = 0; i < sizeof(m_keys); i++)
		m_keys[i] = false;
}

bool Keyboard::IsKeyDown(int index)
{
	if (index < 0 || index >= sizeof(m_keys))
		return false;
	return m_keys[index];
}

void Keyboard::SetKeyboard(int index, bool state)
{
	m_keys[index] = state;
}

bool Keyboard::IsKeyDownOnce(int index)
{
	if (index < 0 || index >= sizeof(m_lastKeys))
		return false;
	return (m_keys[index] && !m_lastKeys[index]);
}

void Keyboard::SetLastKeyboard()
{
	for (int i = 0; i < 255; i++)
	{
		m_lastKeys[i] = m_keys[i];
	}
}