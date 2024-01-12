#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

class Drawable: public sf::Drawable, public sf::Transformable
{
public:
    using Position = sf::Vector2f;

public:
    Drawable() = default;
    Drawable(const Drawable& drawable);
    Drawable(Drawable&& drawable);

    Drawable(sf::Texture* const texture, 
            const Position& position = DefaultPosition);

    virtual ~Drawable() = default;

    const sf::Texture& GetTexture() const noexcept(false);
    void SetTexture(sf::Texture* const texture) noexcept(false);

    void draw(sf::RenderTarget& target, sf::RenderStates states) 
        const override;

    Drawable& operator = (const Drawable& drawable) noexcept(false);
    Drawable& operator = (Drawable&& drawable) noexcept(false);

private:
    void CheckTexture() const noexcept(false);

public:
    static const Position DefaultPosition;

protected:
    std::shared_ptr<sf::Texture> m_Texture{};
};
