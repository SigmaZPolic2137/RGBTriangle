#pragma once

#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

#include <span>
#include <string>

struct AppState {
	const char * AppName = "SDLGPU";

	SDL_Window * Window = nullptr;
	SDL_GPUDevice * GPUDevice = nullptr;

	int WindowWidth = 800;
	int WindowHeight = 600;

	bool FullScreen = false;
	bool VSync = false;
	bool ShowFPS = false;

	Uint64 LastTime = 0;
	double DeltaTime = 0;
	double ElapsedTime = 0;

	bool Debug = false;

	SDL_GPUGraphicsPipeline * Pipeline = nullptr;
	Uint32 VerticesCount = 0;
	SDL_GPUBuffer * VertexBuffer = nullptr;
};

struct alignas(16) FrameUniforms {
	float ElapsedTime;
};

struct Vector3 {
	float X;
	float Y;
	float Z;
};

struct Vertex {
	Vector3 Position;
};

bool IsFullScreen(SDL_Window *);
bool ToggleFullScreen(SDL_Window *, bool *);

bool SetVSyncSetting(AppState *);

SDL_GPUShader * LoadShader(SDL_GPUDevice *, const std::string &);

bool CreatePipeline(AppState *);
bool CreateVertexBuffer(AppState *, std::span <Vertex>);