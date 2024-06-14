#pragma once
#ifndef SOUND_H
#define SOUND_H

#include "bn_music.h"
#include "bn_config_audio.h"
#include "bn_sound.h"
#include "bn_audio.h"
#include "bn_music_items_info.h"
#include "bn_sound_items_info.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"

class SoundController{
public:
    static SoundController& getInstance(){
        static SoundController instance;

        return instance;
    }
    void play_music(){
        if(m_Paused){
            m_Current_Music.play(m_Volume / 100, true);
            m_Paused = false;
        }
    }

    void set_music(bn::music_item music){
        m_Current_Music = music;
        m_Current_Music.play(m_Volume / 100, true);
    }

    void play_sound(bn::sound_item sound){
        sound.play(m_SFX_Volume / 100);
    }
    void play_sound(bn::sound_item sound, int volume){
        sound.play(volume / 100);
    }

    void play_sound(bn::sound_item sound, int volume, bn::fixed speed){
        sound.play(volume/100, speed, 0);
    }

    void update_music(){
        if(m_Paused){
            bn::music::pause();
        }
    }

    void pause(){
        bn::music::pause();
        m_Paused = true;
    }



    SoundController(SoundController const&) = delete;
    void operator=(SoundController const&)  = delete;

private:
    bn::music_item m_Current_Music = bn::music_items::castle8bit;
    bn::fixed m_SFX_Volume = 100;
    bn::fixed m_Volume = 50;
    bool m_Paused = true;

private:
    SoundController(){};
};





#endif // SOUND_H
