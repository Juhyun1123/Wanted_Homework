#include <iostream>

class ICommand
{
public:

    // 명령 실행 메소드.
    virtual void Execute() = 0;

    // 명령 반대 실행 메소드.
    virtual void Undo() = 0;
};

class CommandA : public ICommand
{
public:
    // Inherited via ICommand
    virtual void Execute() override
    {
        std::cout << "A 명령이 실행됐습니다.\n";
    }

    virtual void Undo() override
    {
        std::cout << "A 명령이 취소됐습니다.\n";
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
        std::cout << "B 명령이 실행됐습니다.\n";
    }

    virtual void Undo() override
    {
        std::cout << "B 명령이 취소됐습니다.\n";
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