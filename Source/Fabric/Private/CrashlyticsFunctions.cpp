//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FabricPrivatePCH.h"

#if PLATFORM_IOS
NSArray* GetNSStringArray(TArray<FString> FStringArray)
{
	NSMutableArray* NewArray = [NSMutableArray array];
	
	for (auto Itr(FStringArray.CreateIterator()); Itr; Itr++)
	{
		FString String = (*Itr);
		[NewArray addObject:String.GetNSString()];
	}
	
	return NewArray;
}
#endif

bool ValidateAttributes(FString Function, FString Event, TArray<FString> AttributeKeys, TArray<FString> AttributeValues)
{
	if (AttributeKeys.Num() != AttributeValues.Num())
	{
		UE_LOG(LogFabric,Error,TEXT("%s failed for event %s because number of param keys (%i) differs from number of param values (%i)"),*Function,*Event,AttributeKeys.Num(),AttributeValues.Num());
		return false;
	}
	
	int32 MaxAttributes = 20;
	
	if (AttributeKeys.Num() > MaxAttributes)
	{
		UE_LOG(LogFabric,Error,TEXT("%s failed for event %s because the number of keys (%i) can not be greater than %i"),*Function,*Event,AttributeKeys.Num(),MaxAttributes);
		return false;
	}
	
	if (AttributeValues.Num() > MaxAttributes)
	{
		UE_LOG(LogFabric,Error,TEXT("%s failed for event %s because the number of values (%i) can not be greater than %i"),*Function,*Event,AttributeValues.Num(),MaxAttributes);
		return false;
	}
	
	return true;
}

void UCrashlyticsFunctions::CrashlyticsCrash()
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] crash];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsThrowException()
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] throwException];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsSetUserIdentifier(FString Id)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] setUserIdentifier:Id.GetNSString()];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsSetUserName(FString Name)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] setUserName:Name.GetNSString()];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsSetUserEmail(FString Email)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] setUserEmail:Email.GetNSString()];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsLogEvent(FString EventName)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[[Crashlytics sharedInstance] logEvent:EventName.GetNSString()];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsLogEventWithAttribute(FString EventName, FString AttributeKey, FString AttributeValue)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		NSDictionary* Attributes = [NSDictionary dictionaryWithObject:AttributeValue.GetNSString() forKey:AttributeKey.GetNSString()];
		[[Crashlytics sharedInstance] logEvent:EventName.GetNSString() attributes:Attributes];
	});
#endif
}

void UCrashlyticsFunctions::CrashlyticsLogEventWithAttributes(FString EventName, TArray<FString> AttributeKeys, TArray<FString> AttributeValues)
{
	if (ValidateAttributes("CrashlyticsLogEventWithAttributes", EventName, AttributeKeys, AttributeValues) == false)
		return;

#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		NSDictionary* Attributes = [NSDictionary dictionaryWithObjects:GetNSStringArray(AttributeValues) forKeys:GetNSStringArray(AttributeKeys)];
		[[Crashlytics sharedInstance] logEvent:EventName.GetNSString() attributes:Attributes];
	});
#endif	
}
