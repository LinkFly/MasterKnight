// Fill out your copyright notice in the Description page of Project Settings.

#include "Utils.h"


// Sets default values for this component's properties
AUtils::AUtils()
{
	
}

UClass* AUtils::FindClass(FString NameOfClass)
{
	// Bad Code!!!!!!!!!!!!!!
	/*const TCHAR* ClassName = *NameOfClass;
	check(ClassName);

	UObject* ClassPackage = Cast<UObject>(ANY_PACKAGE);

	if (ClassPackage) {
		if (UClass* Result = FindObject<UClass>(ClassPackage, ClassName))
			return Cast<UClass>(Result);
		if (UObjectRedirector* RenamedClassRedirector = FindObject<UObjectRedirector>(ClassPackage, ClassName))
			return (UClass*)CastChecked<UClass>(RenamedClassRedirector->DestinationObject);
	}*/
	return nullptr;
}