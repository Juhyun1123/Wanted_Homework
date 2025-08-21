#include <iostream>

class ICommand
{
public:

    // ��� ���� �޼ҵ�.
    virtual void Execute() = 0;

    // ��� �ݴ� ���� �޼ҵ�.
    virtual void Undo() = 0;
};

class CommandA : public ICommand
{
public:
    // Inherited via ICommand
    virtual void Execute() override
    {
        std::cout << "A ����� ����ƽ��ϴ�.\n";
    }

    virtual void Undo() override
    {
        std::cout << "A ����� ��ҵƽ��ϴ�.\n";
    }

private:
    const char* commandName = "A";
    int testNumber = 100;
};

class CommandB : public ICommand
{
public:
    // Inherited via ICommand
    virtual void Execute() override
    {
        std::cout << "B ����� ����ƽ��ϴ�.\n";
    }

    virtual void Undo() override
    {
        std::cout << "B ����� ��ҵƽ��ϴ�.\n";
    }
};
/*
#include <vector>

int main()
{
    std::vector<ICommand*> commands;

    commands.emplace_back(new CommandA());
    commands.emplace_back(new CommandB());

    for (auto* command : commands)
    {
        //command->Execute();
        command->Undo();
    }
}

*/