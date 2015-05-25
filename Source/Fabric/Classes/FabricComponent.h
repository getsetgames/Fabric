//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FabricComponent.generated.h"

UCLASS(ClassGroup=Fabric, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UFabricComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	void OnRegister() override;
	void OnUnregister() override;	
};
