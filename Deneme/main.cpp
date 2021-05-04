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
    bool isDead = false;
    
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
        if (!isDead)
        {
            player.setPosition(150.0f + xPozisyon, 600.0f);
        }
    }

    sf::Vector2f PlayerPozisyonu() 
    {
        return sf::Vector2f(player.getPosition());
    }

    sf::Sprite PlayerSpriteGetir() 
    {
        return sf::Sprite(player);
    }

    void Ol() 
    {
        if (isDead)
        {
            player.setPosition(-100, -100);
        }
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
        return sf::Vector2f(enemyBullet.getPosition());
    }

    sf::Sprite PlayerBulletSpriteGetir()
    {
        return sf::Sprite(bullet);
    }

    sf::Sprite EnemyBulletSpriteGetir()
    {
        return sf::Sprite(enemyBullet);
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
        kucukDusman.setTextureRect(sf::IntRect(73.0f, 32.0f, 478.0f, 515.0f));
        kucukDusman.setScale(0.125f, 0.125f);
        kucukDusman.setRotation(180.0f);
        kucukDusman.setPosition(pos[rand()%30], -100.0f);
    }

    void YarasaDusmanAyarla() 
    {
        yarasaDusman.setTexture(yarasaDusmanTextures[yarasaDusmanAnimFrame]);
        yarasaDusman.setTextureRect(sf::IntRect(65.0f, 62.0f, 375.0f, 392.0f));
        yarasaDusman.setScale(0.125f, 0.125f);
        yarasaDusman.setRotation(180.0f);
        yarasaDusman.setPosition(pos[rand() % 30], -100.0f);
    }

    void KucukDusmanAnimasyon()
    {
        kucukDusmanAnimFrame += 1;
        kucukDusmanAnimFrame = kucukDusmanAnimFrame % 5;
        kucukDusman.setTexture(kucukDusmanTextures[kucukDusmanAnimFrame]);
    }

    void YarasaDusmanAnimasyon() 
    {
        yarasaDusmanAnimFrame += 1;
        yarasaDusmanAnimFrame = yarasaDusmanAnimFrame % 4;
        yarasaDusman.setTexture(yarasaDusmanTextures[yarasaDusmanAnimFrame]);
    }

    void KucukDusmanHareket(int hiz) 
    {
        kucukDusman.setPosition(kucukDusman.getPosition().x, kucukDusman.getPosition().y + hiz);
    }

    void YarasaDusmanHareket(int hiz) 
    {
        yarasaDusman.setPosition(yarasaDusman.getPosition().x, yarasaDusman.getPosition().y + hiz);
    }

    sf::Vector2f KucukDusmanPozisyonAl() 
    {
        return sf::Vector2f(kucukDusman.getPosition());
    }

    sf::Vector2f YarasaDusmanPozisyonAl() 
    {
        return sf::Vector2f(yarasaDusman.getPosition());
    }

    sf::Sprite KucukDusmanSpriteGetir() 
    {
        return sf::Sprite(kucukDusman);
    }

    sf::Sprite YarasaDusmanSpriteGetir() 
    {
        return sf::Sprite(yarasaDusman);
    }
};

class UzayObjeleri 
{
public:
    sf::Texture istasyon[3];
    sf::Texture bomba[3];
    sf::Texture mayin[2];
    sf::Sprite istasyonS;
    sf::Sprite bombaS;
    sf::Sprite mayinS;
    int istasyonAnimFrame = 0;
    int bombaAnimFrame = 0;
    int mayinAnimFrame = 0;

    int pos[30] =
    {
        50, 60, 70, 80, 90, 100,110,120,130,140,
        150,160,170,180,190,200,210,220,230,240,
        250,260,270,280,290,300,310,320,330,340
    };

    void ImportImages()
    {
        istasyon[0].loadFromFile("resimler/uzay/comm/1.png");
        istasyon[1].loadFromFile("resimler/uzay/comm/2.png");
        istasyon[2].loadFromFile("resimler/uzay/comm/3.png");
        bomba[0].loadFromFile("resimler/uzay/Spacebombs/1.png");
        bomba[1].loadFromFile("resimler/uzay/Spacebombs/2.png");
        bomba[2].loadFromFile("resimler/uzay/Spacebombs/3.png");
        mayin[0].loadFromFile("resimler/uzay/Spacemines/1.png");
        mayin[1].loadFromFile("resimler/uzay/Spacemines/2.png");
    }

    void IstasyonAyarla() 
    {
        istasyonS.setTexture(istasyon[istasyonAnimFrame]);
        istasyonS.setTextureRect(sf::IntRect(234, 228, 579, 567));
        istasyonS.setScale(0.11f, 0.11f);
        istasyonS.setPosition(pos[rand() % 30], -130.0f);
    }

    void BombaAyarla() 
    {
        bombaS.setTexture(bomba[bombaAnimFrame]);
        bombaS.setTextureRect(sf::IntRect(55, 64, 156, 113));
        bombaS.setScale(0.35f, 0.35f);
        bombaS.setPosition(pos[rand() % 30], -140.0f);
    }

    void MayinAyarla() 
    {
        mayinS.setTexture(mayin[mayinAnimFrame]);
        mayinS.setTextureRect(sf::IntRect(9, 12.0f, 230, 227));
        mayinS.setScale(0.2f, 0.2f);
        mayinS.setPosition(pos[rand() % 30], -110.0f);
    }

    void Animasyon()
    {
        istasyonAnimFrame += 1;
        istasyonAnimFrame = istasyonAnimFrame % 3;
        istasyonS.setTexture(istasyon[istasyonAnimFrame]);

        bombaAnimFrame += 1;
        bombaAnimFrame = bombaAnimFrame % 3;
        bombaS.setTexture(bomba[bombaAnimFrame]);

        mayinAnimFrame += 1;
        mayinAnimFrame = mayinAnimFrame % 2;
        mayinS.setTexture(mayin[mayinAnimFrame]);
    }

    void IstasyonHareket(int hiz)
    {
        istasyonS.setPosition(istasyonS.getPosition().x, istasyonS.getPosition().y + hiz);
    }

    void BombaHareket(int hiz)
    {
        bombaS.setPosition(bombaS.getPosition().x, bombaS.getPosition().y + hiz);
    }

    void MayinHareket(int hiz)
    {
        mayinS.setPosition(mayinS.getPosition().x, mayinS.getPosition().y + hiz);
    }

    sf::Vector2f IstasyonPozisyon()
    {
        return sf::Vector2f(istasyonS.getPosition());
    }

    sf::Vector2f BombaPozisyon()
    {
        return sf::Vector2f(bombaS.getPosition());
    }

    sf::Vector2f MayinPozisyon()
    {
        return sf::Vector2f(mayinS.getPosition());
    }

    sf::Sprite IstasyonSpriteGetir() 
    {
        return sf::Sprite(istasyonS);
    }

    sf::Sprite BombaSpriteGetir() 
    {
        return sf::Sprite(bombaS);
    }

    sf::Sprite MayinSpriteGetir() 
    {
        return sf::Sprite(mayinS);
    }

    void IstasyonPatladi()
    {
        istasyonS.setPosition(-100, 800);
    }

    void BombaPatladi()
    {
        bombaS.setPosition(-100, 800);
    }

    void MayinPatladi()
    {
        mayinS.setPosition(-100, 800);
    }
};

class PatlamaEfekti 
{
public:
    sf::Texture efekt[17];
    sf::Sprite efektS;
    int animasyonIndex = 0;

    void ImportImages() 
    {
        efekt[0].loadFromFile("resimler/uzay/Effects/1_0.png");
        efekt[1].loadFromFile("resimler/uzay/Effects/1_1.png");
        efekt[2].loadFromFile("resimler/uzay/Effects/1_2.png");
        efekt[3].loadFromFile("resimler/uzay/Effects/1_3.png");
        efekt[4].loadFromFile("resimler/uzay/Effects/1_4.png");
        efekt[5].loadFromFile("resimler/uzay/Effects/1_5.png");
        efekt[6].loadFromFile("resimler/uzay/Effects/1_6.png");
        efekt[7].loadFromFile("resimler/uzay/Effects/1_7.png");
        efekt[8].loadFromFile("resimler/uzay/Effects/1_8.png");
        efekt[9].loadFromFile("resimler/uzay/Effects/1_9.png");
        efekt[10].loadFromFile("resimler/uzay/Effects/1_10.png");
        efekt[11].loadFromFile("resimler/uzay/Effects/1_11.png");
        efekt[12].loadFromFile("resimler/uzay/Effects/1_12.png");
        efekt[13].loadFromFile("resimler/uzay/Effects/1_13.png");
        efekt[14].loadFromFile("resimler/uzay/Effects/1_14.png");
        efekt[15].loadFromFile("resimler/uzay/Effects/1_15.png");
        efekt[16].loadFromFile("resimler/uzay/Effects/1_16.png");
    }

    void EfektAyarla()
    {
        efektS.setTexture(efekt[animasyonIndex]);
        efektS.setTextureRect(sf::IntRect(55, 44, 187, 157));
        efektS.setScale(1.0f, 1.0f);
    }

    void Animasyon() 
    {
        animasyonIndex += 1;
        animasyonIndex = animasyonIndex % 17;
        efektS.setTexture(efekt[animasyonIndex]);
    }

    void PozisyonAyarla(float x, float y) 
    {
        efektS.setPosition(x, y);
    }
};

#pragma region Çarpýþma Fonksiyon Baþlýklarý
void IstasyonCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& playerEfekt, sf::RenderWindow& window);
void BombaCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& playerEfekt, sf::RenderWindow& window);
void MayinCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& playerEfekt, sf::RenderWindow& window);
void BulletKucukDusmanCarpismaKontrol(Bullet& bullet, Dusman& dusman, PatlamaEfekti& efekt);
void BulletYarasaDusmanCarpismaKontrol(Bullet& bullet, Dusman& dusman, PatlamaEfekti& efekt);
void EnemyBulletPlayerCarpisma(Bullet& enemyBullet, Player& player, PatlamaEfekti& playerEfekt, sf::RenderWindow& window);
void UzayObjesiIstasyonPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& istEfekt);
void UzayObjesiBombaPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& bombEfekt);
void UzayObjesiMayinPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& mayinEfekt);
#pragma endregion

int main()
{
    srand(time(nullptr));

#pragma region Nesneler
    sf::RenderWindow window(sf::VideoMode(GENISLIK, YUKSEKLIK), "SPACE SHOOTER");
    sf::Event event;
    sf::Clock saat;
    sf::Clock saat2;

    Player player;
    player.ImportImages();
    player.PlayerAyarla();

    Bullet bullet;
    bullet.PlayerBulletAyarla();
    float mermiHizi = 10;

    Dusman kucukDusman;
    kucukDusman.ImportImages();
    kucukDusman.kucukDusmanAyarla();

    Bullet enemyBullet;
    enemyBullet.EnemyBulletAyarla();

    Dusman yarasaDusman;
    yarasaDusman.ImportImages();
    yarasaDusman.YarasaDusmanAyarla();

    Bullet yarasaDusmanBullet;
    yarasaDusmanBullet.EnemyBulletAyarla();

    UzayObjeleri istasyon;
    istasyon.ImportImages();
    istasyon.IstasyonAyarla();

    UzayObjeleri bomba;
    bomba.ImportImages();
    bomba.BombaAyarla();

    UzayObjeleri mayin;
    mayin.ImportImages();
    mayin.MayinAyarla();

    PatlamaEfekti efekt;
    PatlamaEfekti efekt2;
    PatlamaEfekti playerEfekt;
    PatlamaEfekti istEfekt;
    PatlamaEfekti bombEfekt;
    PatlamaEfekti mayinEfekt;
    efekt.ImportImages();
    efekt2.ImportImages();
    playerEfekt.ImportImages();
    istEfekt.ImportImages();
    bombEfekt.ImportImages();
    mayinEfekt.ImportImages();
#pragma endregion

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
                if (&bullet != NULL && !player.isDead)
                {
                    if (bullet.PlayerBulletPozisyonAl().y <= 0)
                    {
                        bullet.BulletPozisyonAyarla(player.player.getPosition().x + 25.0f, player.player.getPosition().y);
                        bullet.PlayerBulletAyarla();
                    }
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                player.isDead = false;
                player.PlayerAyarla();
                window.setTitle("SPACE SHOOTER");
            }
        }
        
#pragma region Tanýmlama Fonksiyonlarý
        player.Animasyon();
        player.PlayerHareket();
        bullet.PlayerBulletHareket(-mermiHizi);

        kucukDusman.KucukDusmanHareket(2);
        kucukDusman.KucukDusmanAnimasyon();
        enemyBullet.EnemyBulletHareket(mermiHizi/2);

        yarasaDusman.YarasaDusmanHareket(3);
        yarasaDusman.YarasaDusmanAnimasyon();
        yarasaDusmanBullet.EnemyBulletHareket(mermiHizi * 0.75f);

        istasyon.IstasyonHareket(1);
        istasyon.Animasyon();

        bomba.BombaHareket(1.5);
        bomba.Animasyon();

        mayin.MayinHareket(1);
        mayin.Animasyon();

        efekt.Animasyon();
        efekt2.Animasyon();
        istEfekt.Animasyon();
        bombEfekt.Animasyon();
        mayinEfekt.Animasyon();
        playerEfekt.Animasyon();

#pragma endregion 

#pragma region ÇarpýþmaTestleri

        IstasyonCarpismaKontrol(player, istasyon, istEfekt, window);
        BombaCarpismaKontrol(player, bomba, bombEfekt, window);
        MayinCarpismaKontrol(player, mayin, mayinEfekt, window);
        BulletKucukDusmanCarpismaKontrol(bullet, kucukDusman, efekt2);
        BulletYarasaDusmanCarpismaKontrol(bullet, yarasaDusman, efekt);
        EnemyBulletPlayerCarpisma(enemyBullet, player, playerEfekt, window);
        EnemyBulletPlayerCarpisma(yarasaDusmanBullet, player, playerEfekt, window);
        UzayObjesiIstasyonPatlatma(bullet, istasyon, istEfekt);
        UzayObjesiBombaPatlatma(bullet, bomba, bombEfekt);
        UzayObjesiMayinPatlatma(bullet, mayin, mayinEfekt);

#pragma endregion

#pragma region Sahneye Yeniden Giriþ ve Düþman Gemi Ateþi

        if (istasyon.IstasyonPozisyon().y >= 725)
        {
            istasyon.IstasyonAyarla();
        }

        if (bomba.BombaPozisyon().y >= 725)
        {
            bomba.BombaAyarla();
        }

        if (mayin.MayinPozisyon().y >= 725)
        {
            mayin.MayinAyarla();
        }

        auto kucukDusmanPos = kucukDusman.KucukDusmanPozisyonAl();
        if (kucukDusmanPos.y >= 740)
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

        auto yarasaDusmanPos = yarasaDusman.YarasaDusmanPozisyonAl();
        if (yarasaDusmanPos.y >= 740)
        {
            yarasaDusman.YarasaDusmanAyarla();
            saat2.restart();
        }
        else if (yarasaDusmanPos.y <= 740)
        {
            auto gecenSure2 = saat2.getElapsedTime().asSeconds();
            if (gecenSure2 > 2.5f)
            {
                std::cout << "ATES!" << std::endl;
                if (&yarasaDusmanBullet != NULL)
                {
                    yarasaDusmanBullet.EnemyBulletPozisyonAyarla(yarasaDusman.yarasaDusman.getPosition().x - 22.5f,
                        yarasaDusman.yarasaDusman.getPosition().y - 5.0f);
                    yarasaDusmanBullet.EnemyBulletAyarla();
                }
                saat2.restart();
            }
        }

#pragma endregion 

        
        window.clear(sf::Color::Black);

        window.draw(player.player);
        window.draw(bullet.bullet);

        window.draw(kucukDusman.kucukDusman);
        window.draw(enemyBullet.enemyBullet);

        window.draw(yarasaDusman.yarasaDusman);
        window.draw(yarasaDusmanBullet.enemyBullet);

        window.draw(istasyon.istasyonS);
        window.draw(bomba.bombaS);
        window.draw(mayin.mayinS);

        window.draw(efekt.efektS);
        window.draw(playerEfekt.efektS);
        window.draw(efekt2.efektS);
        window.draw(istEfekt.efektS);
        window.draw(bombEfekt.efektS);
        window.draw(mayinEfekt.efektS);

        window.display();
    }
    return 0;
}

#pragma region Çarpýþma Kontrol Fonksiyonlarý
void IstasyonCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& istEfekt, sf::RenderWindow& window)
{
    if (player.PlayerSpriteGetir().getGlobalBounds().intersects(uzayobj.IstasyonSpriteGetir().getGlobalBounds()))
    {
        std::cout << "PLAYER ISTASYONA CARPTI" << std::endl;
        istEfekt.EfektAyarla();
        istEfekt.PozisyonAyarla(player.PlayerPozisyonu().x-25.0f, player.PlayerPozisyonu().y-50.0f);
        istEfekt.Animasyon();
        player.isDead = true;
        player.Ol();
        window.setTitle("PRESS R TO RESTART");
    }
    else
    {
        istEfekt.efektS.setScale(0, 0);
    }
}

void BombaCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& bombEfekt, sf::RenderWindow& window)
{
    if (player.PlayerSpriteGetir().getGlobalBounds().intersects(uzayobj.BombaSpriteGetir().getGlobalBounds()))
    {
        std::cout << "PLAYER BOMBAYA CARPTI" << std::endl;
        bombEfekt.EfektAyarla();
        bombEfekt.PozisyonAyarla(player.PlayerPozisyonu().x - 25.0f, player.PlayerPozisyonu().y - 50.0f);
        bombEfekt.Animasyon();
        player.isDead = true;
        player.Ol();
        window.setTitle("PRESS R TO RESTART");
    }
    else
    {
        bombEfekt.efektS.setScale(0, 0);
    }
}

void MayinCarpismaKontrol(Player& player, UzayObjeleri& uzayobj, PatlamaEfekti& mayinEfekt, sf::RenderWindow& window)
{
    if (player.PlayerSpriteGetir().getGlobalBounds().intersects(uzayobj.MayinSpriteGetir().getGlobalBounds()))
    {
        std::cout << "PLAYER MAYINA CARPTI" << std::endl;
        mayinEfekt.EfektAyarla();
        mayinEfekt.PozisyonAyarla(player.PlayerPozisyonu().x - 25.0f, player.PlayerPozisyonu().y - 50.0f);
        mayinEfekt.Animasyon();
        player.isDead = true;
        player.Ol();
        window.setTitle("PRESS R TO RESTART");
    }
    else
    {
        mayinEfekt.efektS.setScale(0, 0);
    }
}

void BulletKucukDusmanCarpismaKontrol(Bullet& bullet, Dusman& dusman, PatlamaEfekti& efekt2)
{
    if (bullet.PlayerBulletSpriteGetir().getGlobalBounds().intersects(dusman.KucukDusmanSpriteGetir().getGlobalBounds()))
    {
        std::cout << "DUSMAN OLDURULDU!" << std::endl;
        bullet.BulletPozisyonAyarla(0.0f, -50.0f);
        efekt2.EfektAyarla();
        efekt2.PozisyonAyarla(dusman.KucukDusmanPozisyonAl().x - 100.0f, dusman.KucukDusmanPozisyonAl().y - 120.0f);
        efekt2.Animasyon();
        sf::Clock zaman;
        if (zaman.getElapsedTime().asSeconds() < 0.5f)
        {
            zaman.restart();
            dusman.kucukDusmanAyarla();
        }
    }
    else
    {
        efekt2.efektS.setScale(0, 0);
    }
}

void BulletYarasaDusmanCarpismaKontrol(Bullet& bullet, Dusman& dusman, PatlamaEfekti& efekt)
{
    if (bullet.PlayerBulletSpriteGetir().getGlobalBounds().intersects(dusman.YarasaDusmanSpriteGetir().getGlobalBounds()))
    {
        std::cout << "DUSMAN OLDURULDU!" << std::endl;
        bullet.BulletPozisyonAyarla(0.0f, -50.0f);
        efekt.EfektAyarla();
        efekt.PozisyonAyarla(dusman.YarasaDusmanPozisyonAl().x - 100.0f, dusman.YarasaDusmanPozisyonAl().y - 120.0f);
        efekt.Animasyon();
        sf::Clock zaman;
        if (zaman.getElapsedTime().asSeconds() < 0.5f)
        {
            zaman.restart();
            dusman.YarasaDusmanAyarla();
        }
    }
    else
    {
        efekt.efektS.setScale(0, 0);
    }
}

void EnemyBulletPlayerCarpisma(Bullet& enemyBullet, Player& player, PatlamaEfekti& playerEfekt, sf::RenderWindow &window)
{
    if (enemyBullet.EnemyBulletSpriteGetir().getGlobalBounds().intersects(player.PlayerSpriteGetir().getGlobalBounds()))
    {
        std::cout << "may the force be with you" << std::endl;
        enemyBullet.EnemyBulletPozisyonAyarla(enemyBullet.EnemyBulletPozisyonAl().x, 1000.0f);
        playerEfekt.EfektAyarla();
        playerEfekt.PozisyonAyarla(player.PlayerPozisyonu().x - 25.0f, player.PlayerPozisyonu().y - 50.0f);
        playerEfekt.Animasyon();
        player.isDead = true;
        player.Ol();
        window.setTitle("PRESS R TO RESTART");
    }
    else
    {
        playerEfekt.efektS.setScale(0, 0);
    }
}

void UzayObjesiIstasyonPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& istEfekt)
{
    if (bullet.PlayerBulletSpriteGetir().getGlobalBounds().intersects(uzayObj.IstasyonSpriteGetir().getGlobalBounds()))
    {
        std::cout << "ISTASYON HAVAYA UCTU!" << std::endl;
        bullet.BulletPozisyonAyarla(0.0f, -50.0f);
        istEfekt.EfektAyarla();
        istEfekt.PozisyonAyarla(uzayObj.IstasyonPozisyon().x - 25.0f, uzayObj.IstasyonPozisyon().y - 50.0f);
        istEfekt.Animasyon();
        uzayObj.IstasyonPatladi();
    }
    else
    {
        istEfekt.efektS.setScale(0, 0);
    }
}

void UzayObjesiBombaPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& bombEfekt)
{
    if (bullet.PlayerBulletSpriteGetir().getGlobalBounds().intersects(uzayObj.BombaSpriteGetir().getGlobalBounds()))
    {
        std::cout << "BOMBA IMHA EDILDI!" << std::endl;
        bullet.BulletPozisyonAyarla(0.0f, -50.0f);
        bombEfekt.EfektAyarla();
        bombEfekt.PozisyonAyarla(uzayObj.BombaPozisyon().x - 25.0f, uzayObj.BombaPozisyon().y - 50.0f);
        bombEfekt.Animasyon();
        uzayObj.BombaPatladi();
    }
    else
    {
        bombEfekt.efektS.setScale(0, 0);
    }
}

void UzayObjesiMayinPatlatma(Bullet& bullet, UzayObjeleri& uzayObj, PatlamaEfekti& mayinEfekt)
{
    if (bullet.PlayerBulletSpriteGetir().getGlobalBounds().intersects(uzayObj.MayinSpriteGetir().getGlobalBounds()))
    {
        std::cout << "MAYIN ETKISIZ HALE GETIRILDI!" << std::endl;
        bullet.BulletPozisyonAyarla(0.0f, -50.0f);
        mayinEfekt.EfektAyarla();
        mayinEfekt.PozisyonAyarla(uzayObj.MayinPozisyon().x - 25.0f, uzayObj.MayinPozisyon().y - 50.0f);
        mayinEfekt.Animasyon();
        uzayObj.MayinPatladi();
    }
    else
    {
        mayinEfekt.efektS.setScale(0, 0);
    }
}

#pragma endregion