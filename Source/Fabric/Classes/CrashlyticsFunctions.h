//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "CrashlyticsFunctions.generated.h"

UCLASS(NotBlueprintable)
class UCrashlyticsFunctions : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsCrash();
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsThrowException();
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsSetUserIdentifier(FString Id);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsSetUserName(FString Name);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsSetUserEmail(FString Email);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics answers analytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsLogEvent(FString EventName);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics answers analytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsLogEventWithAttribute(FString EventName, FString AttributeKey, FString AttributeValue);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "crashlytics answers analytics"), Category = "Fabric|Crashlytics")
	static void CrashlyticsLogEventWithAttributes(FString EventName, TArray<FString> AttributeKeys, TArray<FString> AttributeValues);
};
