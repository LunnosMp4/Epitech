/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Action
*/

#include "Action.hpp"

using namespace Zappy;

Action::Action(std::shared_ptr<Info::Game> game, std::shared_ptr<Network> network, std::string teamName): _network(network)
{
    _network->send(teamName + "\n");
    _response = std::make_shared<Server::Response>(game, network, teamName);
}

void Action::Listen()
{
    _response->Listen();
}

/*  MOVE  */
void Action::Forward() {
    _network->send("Forward\n");
    _response->Forward();
}

void Action::Right() {
    _network->send("Right\n");
    _response->Right();
}

void Action::Left() {
    _network->send("Left\n");
    _response->Left();
}

/*  INFO  */
void Action::Look() {
    _network->send("Look\n");
    _response->Look();
}

void Action::Inventory() {
    _network->send("Inventory\n");
    _response->Inventory();
}

void Action::Broadcast(std::string message) {
    _network->send("Broadcast " + message + "\n");
    _response->Broadcast();
}

/* EXTRA */
void Action::ConnectNbr() {
    _network->send("Connect_nbr\n");
    _response->ConnectNbr();
}

void Action::Fork() {
    _network->send("Fork\n");
    _response->Fork();
}

void Action::Eject() {
    _network->send("Eject\n");
    _response->Eject();
}

void Action::Take(std::string object) {
    _network->send("Take " + object + "\n");
    _response->Take(object);
}

void Action::Set(std::string object) {
    _network->send("Set " + object + "\n");
    _response->Set(object);
}

void Action::Incantation() {
    _network->send("Incantation\n");
    _response->Incantation();
}
