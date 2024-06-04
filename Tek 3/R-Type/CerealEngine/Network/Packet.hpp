enum class PacketType: std::uint8_t {
    CREATE_ENTITY = 0,
    UPDATE_ENTITY = 1,
    DESTROY_ENTITY = 2,
    INPUT = 3,
    START_GAME = 4,
    JOIN_GAME = 5,
    GIVE_ID = 6,
};

struct PacketHeader {
    PacketType type;
    std::size_t bodySize;
    char entityName[20];
    int entityId;
};

struct Packet {
    PacketHeader header;
    std::vector<std::byte> body;
};
