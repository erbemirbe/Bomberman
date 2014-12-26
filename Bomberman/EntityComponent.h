//EntityComponent.h
//Entity component base
#pragma once

class EntityComponent
{
public:
	EntityComponent();
	~EntityComponent();
	void Activate();
	void Deactivate();
	void Attach();
	void Detach();
	void Destroy();

	//freeze/lock?
	//unfreeze/unlock?

private:
	bool m_activated;
};
