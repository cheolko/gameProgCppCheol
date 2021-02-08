#pragma once
#include <vector>

class Actor 
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor( class  Game* game);
	virtual ~Actor();

	void	Update(float  deltaTime);
	void	UpdateComponents(float  deltaTime);
	virtual	void	UpdateActor(float  deltaTime);

	void  AddComponent(class  Component* component);
	void  RemoveComponent(class  Component* component);

	// getter/setter
	
	void SetPosition(const Vector2& pos) { mPosition = pos; }
	void SetScale(float scale) { mScale = scale; }
	void SetRotation(float rotation) { mRotation = rotation; }
	void SetState(State state) { mState = state; }

	const Vector2& GetPosition() const { return mPosition; }
	float GetScale() const { return mScale; }
	float GetRotation() const { return mRotation; }
	State GetState() const { return  mState; }
	class Game* GetGame() { return mGame; }

private:
	State		mState;
	Vector2		mPosition;
	float		mScale;
	float		mRotation;

	std::vector<class Component*>	mComponents;
	class Game*		mGame;
};


