#include <QCoreApplication>
#include <iostream>
#include <memory>

class Render
{
public:
    virtual void RenderShape() = 0;
};

class OpenGLRender : public Render
{
public:
    virtual void RenderShape()
    {
        std::cout << "Render with OpenGL" << std::endl;
    }
};

class DirectXRender : public Render
{
public:
    virtual void RenderShape()
    {
        std::cout << "Render with DirectX" << std::endl;
    }
};

class Shape
{
protected:
    std::shared_ptr<Render> m_render;
public:
    Shape(std::shared_ptr<Render> render) : m_render(render) {}
    virtual void Draw() = 0;
};

class Circle : public Shape
{
public:
    Circle(std::shared_ptr<Render> render) : Shape(render) {}
    virtual void Draw()
    {
        std::cout << "Draw Circle" << std::endl;
        m_render->RenderShape();
    }
};

class Square : public Shape
{
public:
    Square(std::shared_ptr<Render> render) : Shape(render) {}
    virtual void Draw()
    {
        std::cout << "Draw Square" << std::endl;
        m_render->RenderShape();
    }
};

class Triangle : public Shape
{
public:
    Triangle(std::shared_ptr<Render> render) : Shape(render){}
    virtual void Draw()
    {
        std::cout << "Draw Triangle" << std::endl;
        m_render->RenderShape();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto openGLRender = std::make_shared<OpenGLRender>();
    auto circle = std::make_shared<Circle>(openGLRender);
    circle->Draw();

    auto directXRender = std::make_shared<DirectXRender>();
    auto square = std::make_shared<Square>(directXRender);
    auto triangle = std::make_shared<Triangle>(directXRender);
    square->Draw();
    triangle->Draw();

    return a.exec();
}





















