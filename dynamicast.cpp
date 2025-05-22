class Base
{
    virtual void Print() {} //Want to use dynamic_cast must have polymorphism
};

class Enemy : public Base
{
private:
    int x{ 5 };
public:
    void DoNothing() { x++; }
};

class Player : public Base
{

};

int main()
{
    Enemy* enemy = new Enemy();
    Base* baseEnemy = new Enemy();
    Base* basePlayer = new Player();

    Base* ptrBase = (Base*)enemy;
    Enemy* ptrEnemy = (Enemy*)baseEnemy;
    ptrEnemy->DoNothing();
    ptrEnemy = (Enemy*)basePlayer;
    ptrEnemy->DoNothing();
    ptrEnemy = static_cast<Enemy*>(baseEnemy);
    ptrEnemy->DoNothing();
    ptrEnemy = static_cast<Enemy*>(basePlayer);
    ptrEnemy->DoNothing();
    ptrEnemy = dynamic_cast<Enemy*>(baseEnemy);
    ptrEnemy->DoNothing();
    ptrEnemy = dynamic_cast<Enemy*>(basePlayer);
    ptrEnemy->DoNothing();
}