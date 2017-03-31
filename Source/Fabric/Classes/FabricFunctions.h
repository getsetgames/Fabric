//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "UObject/Object.h"
#include "UObject/ScriptMacros.h"
#include "FabricFunctions.generated.h"

UCLASS(NotBlueprintable)
class UFabricFunctions : public UObject
{
	GENERATED_BODY()
	
public:
	// UFUNCTION(BlueprintPure, meta = (Keywords = "keyword1 keyword2"), Category = "Fabric")
	// static bool ExamplePureFunction();
	//
	// UFUNCTION(BlueprintCallable, meta = (Keywords = "keyword1 keyword2"), Category = "Fabric")
	// static void ExampleBlueprintFunction(bool pass);
};
