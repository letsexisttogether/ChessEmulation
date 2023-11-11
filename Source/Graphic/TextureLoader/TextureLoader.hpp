#pragma once 

#include <SFML/Graphics/Texture.hpp>
#include <algorithm>
#include <memory>
#include <unordered_map>

template <class _MapIndex, class _LoadBy>
class TextureLoader
{
public:
    using TexturePointer = std::unique_ptr<sf::Texture>;

    using PreLoadedStorage = std::unordered_map<_MapIndex, _LoadBy>;
    using LoadedStorage = std::unordered_map<_MapIndex, TexturePointer>;

public:
    TextureLoader() = default;

    TextureLoader(PreLoadedStorage&& storage)
        : m_PreLoadedStorage{ std::move(storage) }
    {}

    virtual ~TextureLoader() = default;

    virtual sf::Texture* LoadTexture(const _MapIndex& index) noexcept(false) = 0;

protected:
    virtual sf::Texture* LoadTextureBy(const _LoadBy& loadBy) noexcept(false) = 0;

protected:
    const PreLoadedStorage m_PreLoadedStorage;
    LoadedStorage m_LoadedStorage{};
};
