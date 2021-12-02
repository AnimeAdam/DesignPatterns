//Component is basically just GameObjects

namespace BaseGameObject
{
    class GameObject;
    class Graphics;
    class World;

    class InputComponent
    {
    public:
        virtual ~InputComponent() {}
        virtual void update(GameObject& obj) = 0;
    };

    class PlayerInputComponent : public InputComponent
    {
    public:
        virtual void update(GameObject& obj)
        {
        }
    };

    //^14
    class PhysicsComponent
    {
    public:
        virtual ~PhysicsComponent() {}
        virtual void update(GameObject& obj, World& world) = 0;
    };

    class GraphicsComponent
    {
    public:
        virtual ~GraphicsComponent() {}
        virtual void update(GameObject& obj, Graphics& graphics) = 0;
    };
    //^14

    //^15
    class GameObject
    {
    public:
        int velocity;
        int x, y;

        GameObject(InputComponent* input,
            PhysicsComponent* physics,
            GraphicsComponent* graphics)
            : input_(input),
            physics_(physics),
            graphics_(graphics)
        {}

        void update(World& world, Graphics& graphics)
        {
            input_->update(*this);
            physics_->update(*this, world);
            graphics_->update(*this, graphics);
        }

    private:
        InputComponent* input_;
        PhysicsComponent* physics_;
        GraphicsComponent* graphics_;
    };
    //^15

    //^16
    class BjornPhysicsComponent : public PhysicsComponent
    {
    public:
        virtual void update(GameObject& obj, World& world)
        {
            // Physics code...
        }
    };

    class BjornGraphicsComponent : public GraphicsComponent
    {
    public:
        virtual void update(GameObject& obj, Graphics& graphics)
        {
            // Graphics code...
        }
    };
    //^16

    //^17
    GameObject* createBjorn()
    {
        return new GameObject(new PlayerInputComponent(),
            new BjornPhysicsComponent(),
            new BjornGraphicsComponent());
    }
    //^17
}