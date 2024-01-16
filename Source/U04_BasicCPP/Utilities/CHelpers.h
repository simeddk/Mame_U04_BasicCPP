#pragma once

class U04_BASICCPP_API CHelpers
{
public:
	template<typename T>
	static void GetClass(TSubclassOf<T>* OutClass, FString InPath)
	{
		ConstructorHelpers::FClassFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), TEXT("Class Not Found"));
		
		*OutClass = asset.Class;
	}

	template<typename T>
	static void GetAsset(T** OutObject, FString InPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*InPath);
		verifyf(asset.Succeeded(), TEXT("Asset Not Found"));

		*OutObject = asset.Object;
	}
};