#pragma once 

#include <string>

#include "Graphic/TextureLoader/TextureLoader.hpp"

template <class _MapIndex>
class FileTextureLoader : public TextureLoader<_MapIndex, std::string>
{
public:
    FileTextureLoader() = delete;

    FileTextureLoader(PreLoadedStorage&& storage)
        : TextureLoader<_MapIndex, std::string>{ std::move(storage) }
    {}

    ~FileTextureLoader() = default;

    sf::Texture* LoadTexture(const _MapIndex& index) noexcept(false) override
    {
        const auto& preLoadIter = this->m_PreLoadedStorage.find(index);

        if (preLoadIter == this->m_PreLoadedStorage.end())
        {
            // Change the message later
            throw std::exception{ "There's not such a texture association" };
        }

        if (const auto& loadedIter = this->m_LoadedStorage.find(index);
                loadedIter != this->m_LoadedStorage.end())
        {
            return loadedIter->second.get();
        }

        sf::Texture* texture = LoadTextureBy(preLoadIter->second);

        this->m_LoadedStorage[index] = TexturePointer{ texture }; 

        return texture;
    }

protected:
    sf::Texture* LoadTextureBy(const std::string& loadBy) noexcept(false) override
    {
        sf::Texture* texture = new sf::Texture{};

        texture->loadFromFile(loadBy);

        return texture;
    }
};
