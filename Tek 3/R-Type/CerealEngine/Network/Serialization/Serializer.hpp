#include <vector>
#include <cstring>
#include "../Components.hpp"

namespace Cereal {
    namespace Network {
        namespace Serialization {
            class TransformSerializer {
                public:
                    static std::vector<std::byte> serializeTransform(const Transform& transform) {
                        std::vector<std::byte> serializedData(sizeof(Vector3) * 2 + sizeof(float));

                        // Copiez la position dans les octets sérialisés
                        std::memcpy(serializedData.data(), &transform.position, sizeof(Vector3));

                        // Copiez la rotation dans les octets sérialisés
                        std::memcpy(serializedData.data() + sizeof(Vector3), &transform.rotation, sizeof(Vector3));

                        // Copiez l'échelle dans les octets sérialisés
                        std::memcpy(serializedData.data() + 2 * sizeof(Vector3), &transform.scale, sizeof(float));

                        return serializedData;
                    }
            };
            class StatsSerializer {
                public:
                    static std::vector<std::byte> serializeStats(const Stats& stats) {
                        std::vector<std::byte> serializedData(sizeof(float) * 3);

                        // Copiez la position dans les octets sérialisés
                        std::memcpy(serializedData.data(), &stats.health, sizeof(float));

                        // Copiez la rotation dans les octets sérialisés
                        std::memcpy(serializedData.data() + sizeof(float), &stats.damage, sizeof(float));

                        // Copiez l'échelle dans les octets sérialisés
                        std::memcpy(serializedData.data() + 2 * sizeof(float), &stats.velocity, sizeof(float));

                        return serializedData;
                    }
            };
            class Model3DSerializer {
                public:
                    static std::vector<std::byte> serializeModel3D(const Model3D& model3D) {
                        std::vector<std::byte> serializedData(sizeof(Vector3) + sizeof(float));

                        // Copiez la position dans les octets sérialisés
                        std::memcpy(serializedData.data(), &model3D.rotationAxis, sizeof(Vector3));

                        // Copiez la rotation dans les octets sérialisés
                        std::memcpy(serializedData.data() + sizeof(Vector3), &model3D.rotationAngle, sizeof(float));

                        return serializedData;
                    }
            };
            class RenderSerializer {
                public:
                    static std::vector<std::byte> serializeRender(const Render& render) {
                        std::vector<std::byte> serializedData(sizeof(bool));

                        // Copiez la position dans les octets sérialisés
                        std::memcpy(serializedData.data(), &render.enabled, sizeof(bool));

                        return serializedData;
                    }
            };
            class BoxColliderSerializer {
                public:
                    static std::vector<std::byte> serializeBoxCollider(const BoxCollider& boxCollider) {
                        std::vector<std::byte> serializedData(sizeof(Vector3) * 2);

                        // Copiez la position dans les octets sérialisés
                        std::memcpy(serializedData.data(), &boxCollider.box.min, sizeof(Vector3));

                        // Copiez la rotation dans les octets sérialisés
                        std::memcpy(serializedData.data() + sizeof(Vector3), &boxCollider.box.max, sizeof(Vector3));

                        return serializedData;
                    }
            };
            class InputSerializer {
                public:
                    static std::vector<std::byte> serializeInput(const std::string& input) {
                        std::vector<std::byte> serializedData(input.size());
                        std::memcpy(serializedData.data(), input.data(), input.size());
                        return serializedData;
                    }
            };
        }

        namespace Deserialization {
            class TransformDeserializer {
                public:
                    static Transform deserializeTransform(const std::vector<std::byte>& serializedData) {
                        Transform transform;
                        std::memcpy(&transform.position, serializedData.data(), sizeof(Vector3));
                        std::memcpy(&transform.rotation, serializedData.data() + sizeof(Vector3), sizeof(Vector3));
                        std::memcpy(&transform.scale, serializedData.data() + 2 * sizeof(Vector3), sizeof(float));
                        return transform;
                    }
            };
            class StatsDeserializer {
                public:
                    static Stats deserializeStats(const std::vector<std::byte>& serializedData) {
                        Stats stats;
                        std::memcpy(&stats.health, serializedData.data(), sizeof(float));
                        std::memcpy(&stats.damage, serializedData.data() + sizeof(float), sizeof(float));
                        std::memcpy(&stats.velocity, serializedData.data() + 2 * sizeof(float), sizeof(float));
                        return stats;
                    }
            };
            class Model3DDeserializer {
                public:
                    static Model3D deserializeModel3D(const std::vector<std::byte>& serializedData) {
                        Model3D model3D;
                        std::memcpy(&model3D.rotationAxis, serializedData.data(), sizeof(Vector3));
                        std::memcpy(&model3D.rotationAngle, serializedData.data() + sizeof(Vector3), sizeof(float));
                        return model3D;
                    }
            };
            class RenderDeserializer {
                public:
                    static Render deserializeRender(const std::vector<std::byte>& serializedData) {
                        Render render;
                        std::memcpy(&render.enabled, serializedData.data(), sizeof(bool));
                        return render;
                    }
            };
            class BoxColliderDeserializer {
                public:
                    static BoxCollider deserializeBoxCollider(const std::vector<std::byte>& serializedData) {
                        BoxCollider boxCollider;
                        std::memcpy(&boxCollider.box.min, serializedData.data(), sizeof(Vector3));
                        std::memcpy(&boxCollider.box.max, serializedData.data() + sizeof(Vector3), sizeof(Vector3));
                        return boxCollider;
                    }
            };
            class InputDeserializer {
                public:
                    static std::string deserializeInput(const std::vector<std::byte>& serializedData) {
                        std::string input;
                        input.assign(reinterpret_cast<const char*>(serializedData.data()), serializedData.size());
                        return input;
                    }
            };
        }
    }
}
