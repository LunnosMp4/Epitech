/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** main
*/

#include "ServerManager.hpp"

using namespace Cereal;

Network::Server* globalServer = nullptr;

void signalHandler(int signum) {
    if (signum == SIGINT && globalServer) {
        globalServer->stop();  // Gracefully stop the server
        exit(0);
    }
}

// check if args are valid port and return it
static int checkPort(char* port) {
    int portInt = std::stoi(port);
    if (portInt < 0 || portInt > 65535) {
        std::cerr << "Invalid port" << std::endl;
        exit(84);
    }
    return portInt;
}

static void performDatabaseOperation(Database& db, const std::string& databasePath) {
    // Example database operation
    // Make sure to handle exceptions and ensure thread safety as needed
    try {
        // std::string sqlRTYPE = "INSERT INTO RTYPE (NAME, SCORE) VALUES "
        //                        "('Player1', 100), ('Player2', 200), ('Player3', 300), "
        //                        "('Player4', 400), ('Player5', 500);";

        // std::string sqlClients = "INSERT INTO Clients (Name, LastConnected) VALUES "
        //                          "('Player1', '2021-10-01 00:00:00'), ('Player2', '2021-10-01 00:00:00'), "
        //                          "('Player3', '2021-10-01 00:00:00'), ('Player4', '2021-10-01 00:00:00'), "
        //                          "('Player5', '2021-10-01 00:00:00');";

        // db.insertData(databasePath.c_str(), sqlRTYPE);
        // db.insertData(databasePath.c_str(), sqlClients);
    } catch (const std::exception& e) {
        std::cerr << "Database operation error: " << e.what() << std::endl;
    }
}

static Database initDb() {
    std::string databasePath = "../Server/databases/database.db"; // Adjust the path as needed

    Database db(databasePath);
    db.createTables(databasePath.c_str());

    // Create a thread for a database operation
    std::thread dbThread(performDatabaseOperation, std::ref(db), databasePath);
    dbThread.detach(); // Detach the thread
    return db;
}

// static void createPlayer(const int id) {
//     std::cout << "Creating Player: " << "Player" + std::to_string(id) << std::endl;
//     /* Player */
//     CreateEntity("GameScene", "Player" + std::to_string(id))
//         .addComponent<Cereal::Transform>(Cereal::Transform({0, 0, 0}, {0, 0, 0}, 0.01f))
//         .addComponent<Stats>(Stats(100, 20, 0.1f))
//         .addComponent<Inventory>(Inventory())
//         .addComponent<BoxCollider>(Vector3{0, 0, 0}, Vector3{9, 5, 6})
//         .addTagToEntity("Elementary");
// }

int gameLoop(Network::Server& server, ServerManager serverManager, asio::ip::udp::endpoint& endpoint) {
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    using clock = std::chrono::steady_clock;
    std::chrono::milliseconds frameDuration(1000 / 60); // 60 frames per second

    int nbClients = 0;
    int ids = 1;

    bool isGameStarted = false;

    while (true) {
        auto frameStart = clock::now();

        int newNbClients = server.getClients().size();

        if (server.getGameStarted() && !isGameStarted) {
            server.sendDataToClient(PacketType::START_GAME, Cereal::Transform(), "Player" + std::to_string(serverManager.clientIds.back()), serverManager.clientIds.back());
            isGameStarted = true;
        }

        if (nbClients < newNbClients) {
            std::cout << "New client connected" << std::endl;
            nbClients = newNbClients;
            // Create a new entity for the new client SHIP
            serverManager.clientIds.push_back(ids);
            serverManager.entitiesIds.push_back(ids);
            ids++;
            std::cout << "Client id: " << serverManager.clientIds.back() << std::endl;
            std::cout << "Entity id: " << serverManager.entitiesIds.back() << std::endl;
            // createPlayer(clientIds.back());
            server.sendDataToClient(PacketType::GIVE_ID, Cereal::Transform(), "Player" + std::to_string(serverManager.clientIds.back()), serverManager.clientIds.back());
            serverManager.sendAllClients(server, serverManager);
        }
        if (nbClients) {
            serverManager.sendAllClients(server, serverManager);
        }

        auto frameEnd = clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
        if (elapsedTime < frameDuration) {
            std::this_thread::sleep_for(frameDuration - elapsedTime);
        }
        // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }

    return 0;
}

int main() {
    int tcp_port = checkPort("50000");
    int udp_port = checkPort("50001");

    ServerManager serverManager;
    Network::Server server(tcp_port, udp_port);
    globalServer = &server; // Set global server pointer for signal handler
    asio::ip::udp::endpoint endpoint(asio::ip::address::from_string("127.0.0.1"), udp_port);
    signal(SIGINT, signalHandler);

    /* Init */
    Database db = initDb();

    /* Run Server */
    std::thread serverThread([&server]() {
        server.start();
    });

    /* gameLoop */
    gameLoop(server, serverManager, endpoint);

    serverThread.join(); // Wait for the server thread to finish

    return 0;
}
