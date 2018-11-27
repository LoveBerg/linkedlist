<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "linkedList.h"
#include <Windows.h>
#include "cache.h"

std::string GetDestinationFrom(int destinationId, cache *cache)
{
	DisplayMessageDestinationService service;
	std::string destination(cache->GetFromCache(destinationId));
	if (destination.empty()) {
		destination = service.GetDestinationName(destinationId);
		cache->AddToCache(destinationId, destination);
		return destination;
	}
	else
	{
		return destination;
	}
}

void main()
{
	SetConsoleOutputCP(1252);
	cache* LRUcache = new cache();
	
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId, LRUcache)
			<< std::endl;
	}
=======
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "DisplayMessageEndpoint.h"
#include "linkedList.h"
#include <Windows.h>

std::string GetDestinationFrom(int destinationId)
{
	TXT = getFromID()
	DisplayMessageDestinationService service;
	return service.GetDestinationName(destinationId);
	//This call is really slow!!!

	//Uppgift: Skapa en LRU cache...
	//Du f�r dock spara h�gst 10 st f�r det finns s� lite minne i displayen

	//1. Skapa en C-only linkedlist - varf�r? - den ska anv�ndas i en c-only device senare.. 
	//struct Node
	//{
	//	int id;
	//	char *txt;
	//	struct Node *next;
	//};
	//kom ih�g att malloc och free p� b�de noder och char *

	//2. Anropa denna h�rifr�n sas
	// if linkedlist_get(id) == NULL
	//{
	//fetch from remote service.GetDestinationName(destinationId)
	//	Add to linked list (FRONT)
	//	Ta bort sista om > 10!
	//}
	//else if linkedlist_get(id) != NULL
	//	Move it to FRONT!
	//
}

void main()
{
	SetConsoleOutputCP(1252);
	DisplayMessageEndpoint *endPoint = new DisplayMessageEndpoint();
	while (true)
	{
		DisplayMessageEndpoint::DisplayEntry nextDisplayMessage = endPoint->GetDisplayMessage();
		std::cout << nextDisplayMessage.time << "   " << nextDisplayMessage.newTime 
			<< "      " << nextDisplayMessage.track << "  " << GetDestinationFrom(nextDisplayMessage.destinationId)
			<< std::endl;
	}
>>>>>>> e82198077a6a3162c73b88c60ec50f9e5654b18f
}