#include <QCoreApplication>
#include <iostream>
using namespace std;

class AudioSystem
{
public:
    void PlayAudio()
    {
        cout << "Playing Audio" << endl;
    }
};

class VideoSystem
{
public:
    void PlayVideo()
    {
        cout << "Playing Video" << endl;
    }
};

class GraphicsSystem
{
public:
    void ShowGraphics()
    {
        cout << "Showing graphics" << endl;
    }
};

class MultimediaFacade
{
private:
    AudioSystem m_audio;
    VideoSystem m_video;
    GraphicsSystem m_graphics;
public:
    void LoadMultiMedia()
    {
        m_audio.PlayAudio();
        m_video.PlayVideo();
        m_graphics.ShowGraphics();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MultimediaFacade multimedia;
    multimedia.LoadMultiMedia();

    return a.exec();
}
