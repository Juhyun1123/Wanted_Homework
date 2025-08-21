#pragma once
#include <iostream>
#include "Stack.h"
#include "List.h"

class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;

	virtual const char* GetName() = 0;
	virtual ICommand* Clone() const = 0;

	friend std::ostream& operator<<(std::ostream& os, ICommand& cmd)
	{
		return os << cmd.GetName();
	}
};

class Command_A : public ICommand
{
public:
	virtual void Execute() override { std::cout << "Execute A" << "\n"; }
	virtual void Undo() override { std::cout << "Undo A" << "\n"; }
	virtual void Redo() override { std::cout << "Redo A" << "\n"; }

	virtual const char* GetName() override { return commandName; }
	virtual ICommand* Clone() const override { return new Command_A(); }

private:
	const char* commandName = "Command_A";
	int testNumber = 1;
};

class Command_B : public ICommand
{
public:
	virtual void Execute() override { std::cout << "Execute B" << "\n"; }
	virtual void Undo() override { std::cout << "Undo B" << "\n"; }
	virtual void Redo() override { std::cout << "Redo B" << "\n"; }

	virtual const char* GetName() override { return commandName; }
	virtual ICommand* Clone() const override { return new Command_B(); }

private:
	const char* commandName = "Command_B";
	int testNumber = 2;
};

class Command_C : public ICommand
{
public:
	virtual void Execute() override { std::cout << "Execute C" << "\n"; }
	virtual void Undo() override { std::cout << "Undo C" << "\n"; }
	virtual void Redo() override { std::cout << "Redo C" << "\n"; }

	virtual const char* GetName() override { return commandName; }
	virtual ICommand* Clone() const override { return new Command_C(); }

private:
	const char* commandName = "Command_C";
	int testNumber = 3;
};

class Command_D : public ICommand
{
public:
	virtual void Execute() override { std::cout << "Execute D" << "\n"; }
	virtual void Undo() override { std::cout << "Undo D" << "\n"; }
	virtual void Redo() override { std::cout << "Redo D" << "\n"; }

	virtual const char* GetName() override { return commandName; }
	virtual ICommand* Clone() const override { return new Command_D(); }

private:
	const char* commandName = "Command_D";
	int testNumber = 4;
};

class Command_E : public ICommand
{
public:
	virtual void Execute() override { std::cout << "Execute E" << "\n"; }
	virtual void Undo() override { std::cout << "Undo E" << "\n"; }
	virtual void Redo() override { std::cout << "Redo E" << "\n"; }

	virtual const char* GetName() override { return commandName; }
	virtual ICommand* Clone() const override { return new Command_E(); }

private:
	const char* commandName = "Command_E";
	int testNumber = 5;
};

class CommandFactory
{

public:
	CommandFactory()
	{
		commands.Add(new Command_A());
		commands.Add(new Command_B());
		commands.Add(new Command_C());
		commands.Add(new Command_D());
		commands.Add(new Command_E());
	}

	~CommandFactory()
	{
		for (int i = 0; i < commands.Size(); ++i)
		{
			delete commands[i];
		}
	}

	ICommand* CreateCommand(const char* commandName)
	{
		for (int i = 0; i < commands.Size(); ++i)
		{
			if (strcmp(commandName, commands[i]->GetName()) == 0)
			{
				ICommand* newCommand = commands[i]->Clone();
				return newCommand;
			}
		}

		return nullptr;
	}

private:
	List<ICommand*> commands;
};

