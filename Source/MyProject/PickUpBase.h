// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpBase.generated.h" //This is the last include in header files, helps deal with memory management (ex. deletes pointer if you didn't do that)

UCLASS() //allows Unreal to know that this is an unreal class
class MYPROJECT_API APickUpBase : public AActor
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties (constructor)
	APickUpBase();


	// Called every frame, helps with things that require that
	virtual void Tick(float DeltaTime) override;

	/** Return the mesh for the pickup */
	FORCEINLINE class UStaticMeshComponent* GetMesh() const { return PickupMesh; }

	/** Return whether or not the pickup is active */
	UFUNCTION(BlueprintPure, Category = "Pickup") //Ufunction allows you to create blueprints within Unreal
		bool IsActive(); //checks whether actor is within the level and activated

	/**Allows other classes to safely change whether or not the pickup is active*/
	UFUNCTION(BlueprintCallable, Category = "Pickup") //BlueprintPure returns values, Callable lets you go into other functions
		void SetActive(bool NewPickupState);

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//True when the pickup can be used, and false when pickup is deactivated
	bool bIsActive;

private:

	/**Static mesh to represent the pickup in the level*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* PickupMesh;

	
	
};
