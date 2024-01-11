#include <SFML/Graphics.hpp>

class Drawable: public sf::Drawable
{
public:
    Drawable() = default;
    Drawable(const Drawable& drawable);
    Drawable(Drawable&& drawable);
    
    Drawable(sf::Texture* const texture);

    virtual ~Drawable() = default;

    const sf::Texture& GetTexture() const noexcept(false);
    void SetTexture(sf::Texture* const texture) noexcept;

    void draw(sf::RenderTarget& target, sf::RenderStates states) 
        const override;

    Drawable& operator = (const Drawable& drawable);
    Drawable& operator = (Drawable&& drawable);

private:
    void CheckTexture() const noexcept(false);

protected:
    std::shared_ptr<sf::Texture> m_Texture{};
};
