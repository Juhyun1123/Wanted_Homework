#include "UndoRedoEventSystem.h"

UndoRedoEventSystem::~UndoRedoEventSystem()
{
	ICommand* command;
	while (!undo.IsEmpty())
	{
		command = undo.Pop();
		delete command;
		command = nullptr;
	}

	while (!redo.IsEmpty())
	{
		command = redo.Pop();
		delete command;
		command = nullptr;
	}
}

void UndoRedoEventSystem::Run()
{
	while (Input())
	{

	}
}

bool UndoRedoEventSystem::Input()
{
	char buffer[256];

	std::cout << "����� �Է��ϼ��� : ";
	std::cin >> buffer;

	Upper(buffer);
	
	if (strcmp(buffer, "A") == 0)
	{
		ExecuteCommand("Command_A");
	}
	else if (strcmp(buffer, "B") == 0)
	{
		ExecuteCommand("Command_B");
	}
	else if (strcmp(buffer, "C") == 0)
	{
		ExecuteCommand("Command_C");
	}
	else if (strcmp(buffer, "D") == 0)
	{
		ExecuteCommand("Command_D");
	}
	else if (strcmp(buffer, "E") == 0)
	{
		ExecuteCommand("Command_E");
	}
	else if (strcmp(buffer, "UNDO") == 0)
	{
		Undo();
	}
	else if (strcmp(buffer, "REDO") == 0)
	{
		Redo();
	}
	else if (strcmp(buffer, "SHOW") == 0)
	{
		std::cout << "Undo ";
		undo.Print();

		std::cout << "Redo ";
		redo.Print();
	}
	else
	{
		std::cout << "�Է��� �߸��Ǿ����ϴ�.\n";
		std::cout << "���α׷��� �����մϴ�.\n";
		return false;
	}

	return true;
}

void UndoRedoEventSystem::Upper(char* buffer)
{
	for (int i = 0; i < strlen(buffer); ++i)
	{
		if ('a' <= buffer[i] && buffer[i] <= 'z')
		{
			buffer[i] -= 32;
		}
	}
}


void UndoRedoEventSystem::ExecuteCommand(const char* commandName)
{
	ICommand* exeCommand = factory.CreateCommand(commandName);

	if (exeCommand == nullptr)
	{
		std::cout << "Error : Ŀ�ǵ� �Է��� �����߽��ϴ�.\n";
		return;
	}

	exeCommand->Execute();
	undo.Push(exeCommand);
	redo.Clear();
}

void UndoRedoEventSystem::Undo()
{
	if (undo.IsEmpty())
	{
		std::cout << "Error : Undo�� ������ϴ�.\n";
		return;
	}

	ICommand* undoCommand = undo.Pop();
	undoCommand->Undo();
	redo.Push(undoCommand);
}

void UndoRedoEventSystem::Redo()
{
	if (redo.IsEmpty())
	{
		std::cout << "Error : Redo�� ������ϴ�.\n";
		return;
	}

	ICommand* redoCommand = redo.Pop();
	redoCommand->Redo();
	undo.Push(redoCommand);
}