#include <SFML/Graphics.hpp>
#include <iostream>

#define GENISLIK 400
#define YUKSEKLIK 700

class Player 
{
public:
    sf::Texture playerTextures[8];
    sf::Sprite player; 
    int xPozisyon = 0;
    int index = 0; 
    
    void ImportImages()
    {
        playerTextures[0].loadFromFile("resimler/uzay/user/1.png");
        playerTextures[1].loadFromFile("resimler/uzay/user/2.png");
        playerTextures[2].loadFromFile("resimler/uzay/user/3.png");
        playerTextures[3].loadFromFile("resimler/uzay/user/4.png");
        playerTextures[4].loadFromFile("resimler/uzay/user/5.png");
        playerTextures[5].loadFromFile("resimler/uzay/user/6.png");
        playerTextures[6].loadFromFile("resimler/uzay/user/7.png");
        playerTextures[7].loadFromFile("resimler/uzay/user/8.png");
    }

    void PlayerAyarla() 
    {
        player.setTexture(playerTextures[index]);
        player.setTextureRect(sf::IntRect(28.0, 32.0f, 450.0f, 440.0f));
        player.setScale(0.15f, 0.15f);
    }

    void Animasyon() 
    {
        index += 1;
        index = index % 8;
        player.setTexture(playerTextures[index]);
    }

    void PlayerHareket() 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (player.getPosition().x <= 5.0f)
            {
                xPozisyon += 5;
            }
            else
            {
                xPozisyon -= 5;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (player.getPosition().x >= 335)
            {
                xPozisyon -= 5;
            }
            else
            {
                xPozisyon += 5;
            }
        }
        player.setPosition(150.0f + xPozisyon, 600.0f);
    }

    sf::Vector2f PlayerPozisyonu() 
    {
        return sf::Vector2f(player.getPosition());
    }
};

class Bullet 
{
public:
    sf::Texture bulletTexture;
    sf::Sprite bullet;

    sf::Texture enemyBulletTexture;
    sf::Sprite enemyBullet;

    void PlayerBulletAyarla() 
    {
        bulletTexture.loadFromFile("resimler/uzay/bullet.png");
        bullet.setTexture(bulletTexture);
        bullet.setTextureRect(sf::IntRect(48.0f, 28.0f, 33.0f, 66.0f));
        bullet.setScale(0.35f, 0.35f);
    }

    void EnemyBulletAyarla() 
    {
        enemyBulletTexture.loadFromFile("resimler/uzay/bullet_red.png");
        enemyBullet.setTexture(enemyBulletTexture);
        enemyBullet.setTextureRect(sf::IntRect(48.0f, 28.0f, 33.0f, 66.0f));
        enemyBullet.setScale(0.35f, 0.35f);
        enemyBullet.setRotation(180.0f);
    }

    void PlayerBulletHareket(float bulletHiz) 
    {
        bullet.move(0.0f, bulletHiz);
    }

    void EnemyBulletHareket(float bulletHiz) 
    {
        enemyBullet.move(0.0f, bulletHiz);
    }

    void BulletPozisyonAyarla(float x, float y) 
    {
        bullet.setPosition(x, y);
    }

    void EnemyBulletPozisyonAyarla(float x, float y) 
    {
        enemyBullet.setPosition(x, y);
    }

    sf::Vector2f PlayerBulletPozisyonAl()
    {
        return sf::Vector2f(bullet.getPosition());
    }

    sf::Vector2f EnemyBulletPozisyonAl()
    {
        return sf::Vector2f(bullet.getPosition());
    }
};

class Dusman 
{
public:
    int pos[30] = 
    {
        50, 60, 70, 80, 90, 100,110,120,130,140,
        150,160,170,180,190,200,210,220,230,240,
        250,260,270,280,290,300,310,320,330,340
    };

    sf::Texture kucukDusmanTextures[5];
    sf::Sprite kucukDusman;
    int kucukDusmanYPozisyon = 0;
    int kucukDusmanAnimFrame = 0;

    sf::Texture yarasaDusmanTextures[4];
    sf::Sprite yarasaDusman;
    int yarasaDusmanYPozisyon = 0;
    int yarasaDusmanAnimFrame = 0;

    void ImportImages()
    {
        kucukDusmanTextures[0].loadFromFile("resimler/uzay/smallship/1.png");
        kucukDusmanTextures[1].loadFromFile("resimler/uzay/smallship/2.png");
        kucukDusmanTextures[2].loadFromFile("resimler/uzay/smallship/3.png");
        kucukDusmanTextures[3].loadFromFile("resimler/uzay/smallship/4.png");
        kucukDusmanTextures[4].loadFromFile("resimler/uzay/smallship/5.png");
        yarasaDusmanTextures[0].loadFromFile("resimler/uzay/yarasaucak/1.png");
        yarasaDusmanTextures[1].loadFromFile("resimler/uzay/yarasaucak/2.png");
        yarasaDusmanTextures[2].loadFromFile("resimler/uzay/yarasaucak/3.png");
        yarasaDusmanTextures[3].loadFromFile("resimler/uzay/yarasaucak/4.png");
    }

    void kucukDusmanAyarla()
    {
        kucukDusman.setTexture(kucukDusmanTextures[kucukDusmanAnimFrame]);
        kucukDusman.setTextureRect(sf::IntRect(73.0, 32.0f, 478.0f, 515.0f));
        kucukDusman.setScale(0.125f, 0.125f);
        kucukDusman.setRotation(180.0f);
        kucukDusman.setPosition(pos[rand()%30], -100.0f);
    }

    void KucukDusmanAnimasyon()
    {
        kucukDusmanAnimFrame += 1;
        kucukDusmanAnimFrame = kucukDusmanAnimFrame % 5;
        kucukDusman.setTexture(kucukDusmanTextures[kucukDusmanAnimFrame]);
    }

    void KucukDusmanHareket(int hiz) 
    {
        kucukDusman.setPosition(kucukDusman.getPosition().x, kucukDusman.getPosition().y + hiz);
    }

    sf::Vector2f KucukDusmanPozisyonAl() 
    {
        return sf::Vector2f(kucukDusman.getPosition());
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(GENISLIK, YUKSEKLIK), "STAR WARS");
    sf::Event event;
    sf::Clock saat;
    sf::Time zaman;

    Player player;
    player.ImportImages();
    player.PlayerAyarla();

    Bullet bullet;
    bullet.PlayerBulletAyarla();
    float mermiHizi = 8.0f;

    Dusman kucukDusman;
    kucukDusman.ImportImages();
    kucukDusman.kucukDusmanAyarla();

    Bullet enemyBullet;
    enemyBullet.EnemyBulletAyarla();

    while (window.isOpen())
    {
        window.setFramerateLimit(60);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if (&bullet != NULL)
                {
                    if (bullet.PlayerBulletPozisyonAl().y <= 0)
                    {
                        bullet.BulletPozisyonAyarla(player.player.getPosition().x + 25.0f, player.player.getPosition().y);
                        bullet.PlayerBulletAyarla();
                    }
                }
            }
        }
        
        player.Animasyon();
        player.PlayerHareket();
        bullet.PlayerBulletHareket(-mermiHizi);

        kucukDusman.KucukDusmanHareket(2);
        kucukDusman.KucukDusmanAnimasyon();
        enemyBullet.EnemyBulletHareket(mermiHizi);

        auto kucukDusmanPos = kucukDusman.KucukDusmanPozisyonAl();
        if (kucukDusmanPos.y >= 750)
        {
            kucukDusman.kucukDusmanAyarla();
            saat.restart();
        }
        else if (kucukDusmanPos.y <= 740)
        {
            auto gecenSure = saat.getElapsedTime().asSeconds();
            if (gecenSure > 2.5f)
            {
                std::cout << "ATES!" << std::endl;
                if (&enemyBullet != NULL)
                {
                    enemyBullet.EnemyBulletPozisyonAyarla(kucukDusman.kucukDusman.getPosition().x-22.5f, 
                        kucukDusman.kucukDusman.getPosition().y-5.0f);
                    enemyBullet.EnemyBulletAyarla();
                }
                saat.restart();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(player.player);
        window.draw(bullet.bullet);
        window.draw(kucukDusman.kucukDusman);
        window.draw(enemyBullet.enemyBullet);
        window.display();
    }
    return 0;
}