#pragma once
#include "Command.h"
#include "Stack.h"

class UndoRedoEventSystem
{

public:
	UndoRedoEventSystem() = default;
	~UndoRedoEventSystem();

	void Run();

private:
	bool Input();
	void Upper(char* buffer);

	void ExecuteCommand(const char* commandName);
	void Undo();
	void Redo();

private:
	CommandFactory factory;

	Stack<ICommand*> undo;
	Stack<ICommand*> redo;
};