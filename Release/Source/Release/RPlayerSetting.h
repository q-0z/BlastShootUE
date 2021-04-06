// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RELEASE_API RPlayerSetting
{
public:

	static RPlayerSetting* GetPlayerSetting()
	{
		static RPlayerSetting* singleton_ = new RPlayerSetting();
		return singleton_;
	}
	RPlayerSetting(RPlayerSetting const&) = delete;
	void operator=(RPlayerSetting const&) = delete;

	RPlayerSetting();
	~RPlayerSetting();

public:
	float movementRate = 5;
};
