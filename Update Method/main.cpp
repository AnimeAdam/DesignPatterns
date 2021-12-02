//The Update Method just houses several updates into an entity.

namespace SampleCode
{
    static const int MAX_ENTITIES = 10;

    //^entity-class
    class Entity
    {
    public:
        Entity()
            : x_(0), y_(0)
        {}

        virtual ~Entity() {}
        virtual void update() = 0;

        double x() const { return x_; }
        double y() const { return y_; }

        void setX(double x) { x_ = x; }
        void setY(double y) { y_ = y; }

    private:
        double x_;
        double y_;
    };
    //^entity-class

    //^game-world
    class World
    {
    public:
        World()
            : numEntities_(0)
        {}

        void gameLoop();

    private:
        Entity* entities_[MAX_ENTITIES];
        int numEntities_;
    };
    //^game-world

    //^game-loop
    void World::gameLoop()
    {
        while (true)
        {
            // Handle user input...

            // Update each entity.
            //^update-component-entities
            for (int i = 0; i < numEntities_; i++)
            {
                entities_[i]->update();
            }
            //^update-component-entities

            // Physics and rendering...
        }
    }
    //^game-loop

    //^skeleton
    class Skeleton : public Entity
    {
    public:
        Skeleton()
            : patrollingLeft_(false)
        {}

        virtual void update()
        {
            if (patrollingLeft_)
            {
                setX(x() - 1);
                if (x() == 0) patrollingLeft_ = false;
            }
            else
            {
                setX(x() + 1);
                if (x() == 100) patrollingLeft_ = true;
            }
        }

    private:
        bool patrollingLeft_;
    };
    //^skeleton

    //^statue
    class Statue : public Entity
    {
    public:
        Statue(int delay)
            : frames_(0),
            delay_(delay)
        {}

        virtual void update()
        {
            if (++frames_ == delay_)
            {
                shootLightning();

                // Reset the timer.
                frames_ = 0;
            }
        }

    private:
        int frames_;
        int delay_;

        void shootLightning()
        {
            // Shoot the lightning...
        }
    };
    //^statue
}

namespace ForwardToDelegate
{
    class Entity;

    class Entity
    {
    public:
        Entity* state_;
        void update();
    };

    //^forward
    void Entity::update()
    {
        // Forward to state object.
        state_->update();
    }
    //^forward
}

namespace VariableTimeStep
{
    class Skeleton
    {
    public:
        double x;
        bool patrollingLeft_;
        void update(double elapsed);
    };

    //^variable
    void Skeleton::update(double elapsed)
    {
        if (patrollingLeft_)
        {
            x -= elapsed;
            if (x <= 0)
            {
                patrollingLeft_ = false;
                x = -x;
            }
        }
        else
        {
            x += elapsed;
            if (x >= 100)
            {
                patrollingLeft_ = true;
                x = 100 - (x - 100);
            }
        }
    }
    //^variable
}