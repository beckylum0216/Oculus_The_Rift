#include <pch.h>
#include <iostream>

#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
{
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	int result = 0;
	int flags = MIX_INIT_MP3;

	

	Mix_Volume(-1, 50);

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		std::cout << "Failed to init SDL" << std::endl;
		exit(1);
	}

	if (flags != (result = Mix_Init(flags))) {
		std::cout << "Could not initialize mixer, result: " << std::endl;
		std::cout << "Mix_Init: " << Mix_GetError() << std::endl;
		exit(1);
	}
	songs.resize(10);

	songs[0] = Mix_LoadMUS("data/test_song.mp3");

	songs[1] = Mix_LoadMUS("data/bgm_menu.mp3");

	songs[2] = Mix_LoadMUS("data/bgm_stage1.mp3");

	songs[3] = Mix_LoadMUS("data/bgm_stage2.mp3");

	songs[4] = Mix_LoadMUS("data/bgm_stage3.mp3");

	currentSong = songs[0];
}

MusicPlayer::~MusicPlayer()
{
	Mix_FreeMusic(songs[0]);
	Mix_FreeMusic(songs[1]);
	Mix_FreeMusic(songs[2]);
	Mix_FreeMusic(songs[3]);
	Mix_FreeMusic(songs[4]);
}

void MusicPlayer::PlaySong()
{
	if (!Mix_PlayingMusic())
	{
		if (currentSong == songs[1])
		{
			if (!menuCheck)
			{
				Mix_VolumeMusic(30);
				Mix_FadeInMusic(currentSong, 1, 100);
				menuCheck = true;
			}
			else
			{
				return;
			}
		}
		else
		{
			Mix_VolumeMusic(30);
			Mix_FadeInMusic(currentSong, -1, 100);
		}
	}
}

void MusicPlayer::SetSong(int songIn)
{
	if (songs[songIn] != currentSong)
	{
		if (songIn == 1)
		{
			menuCheck = false;
		}

		Mix_FadeOutMusic(500);
		currentSong = songs[songIn];
	}
}

void MusicPlayer::StopMusic()
{
	Mix_RewindMusic();
	Mix_PauseMusic();
}

void MusicPlayer::ResumeMusic()
{
	
	if (Mix_PausedMusic() == 1)
	{
		Mix_ResumeMusic();
	}
	
}
