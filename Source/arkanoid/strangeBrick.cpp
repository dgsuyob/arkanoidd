// Fill out your copyright notice in the Description page of Project Settings.


#include "strangeBrick.h"
#include "Ball.h"
#include "paddle.h"

AstrangeBrick::AstrangeBrick() {

}
void AstrangeBrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void AstrangeBrick::behavior()
{
	if (Apaddle::Tick) {
		this->FinishDestroy();
	}
}
