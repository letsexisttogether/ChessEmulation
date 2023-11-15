#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Spawn/Associative/Loader/AssociativeLoader.hpp"

template <class _Association>
class TextureFileLoader : 
    public AssociativeLoader<_Association, sf::Texture, std::string>
{
public:
    using Super = AssociativeLoader<_Association, sf::Texture, std::string>;
    using typename Super::ObjStorage;

public:
    TextureFileLoader() = delete;

    TextureFileLoader(const ObjStorage& storage)
        : Super{ storage }
    {}
    TextureFileLoader(ObjStorage&& storage)
        : Super{ std::move(storage) }
    {}

    ~TextureFileLoader() = default;

protected:
    sf::Texture* LoadInstance(const std::string& loadBy) 
        noexcept(false) override
    {
        sf::Texture* texture = new sf::Texture{};
        texture->loadFromFile(loadBy);

        return texture;
    }
};
