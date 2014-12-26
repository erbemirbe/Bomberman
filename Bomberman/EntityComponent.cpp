//EntityComponent.cpp

#include "stdafx.h"
#include "EntityComponent.h"

EntityComponent::EntityComponent()
{
	m_activated = true;
}

EntityComponent::~EntityComponent()
{

}


void EntityComponent::Activate()
{
	m_activated = true;
}

void EntityComponent::Deactivate()
{
	m_activated = false;
}

void EntityComponent::Attach()
{

}

void EntityComponent::Detach()
{
	
}

void EntityComponent::Destroy()
{
		
}