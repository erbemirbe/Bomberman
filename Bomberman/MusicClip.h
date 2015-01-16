#ifndef MUSICCLIP_H_INCLUDED
#define MUSICCLIP_H_INCLUDED
#include <SDL_mixer.h>
 
class MusicClip
{
public:
        MusicClip();
        ~MusicClip();
        MusicClip(Mix_Music* p_xClip);
 
        void Play();
        void Pause();
        void Stop();
 
        void Volume(int _volume);
private:
        Mix_Music* m_xClip;
        int m_iChannel;
};

#endif //MUSICCLIP_H_INCLUDED