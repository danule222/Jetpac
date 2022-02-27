/**
 * @file sound.cc
 * @author Daniel Ramírez
 * @brief Lógica relacionada con el
 * sistema de audio del juego.
 */

SoLoud::Soloud canal;
SoLoud::Wav sound[18];

enum SoundName
{
  bonus_get = 0,
  despegue,
  despegue2,
  despegue3,
  disparo,
  enemigos,
  fuel_deposit,
  fuel_picked,
  nave_pick_mid,
  objetos,
  rock_dies,
  ship_assemble,
  ship_lands,
  ship_launches,
  shoot1,
  shoot2,
  shoot3,
  shoot4
};

void StartSound()
{
  canal.init();

  sound[0].load("../assets/audio/bonus_get.ogg");
  sound[1].load("../assets/audio/despegue.ogg");
  sound[2].load("../assets/audio/despegue2.ogg");
  sound[3].load("../assets/audio/despegue3.ogg");
  sound[4].load("../assets/audio/disparo.ogg");
  sound[5].load("../assets/audio/enemigos.ogg");
  sound[6].load("../assets/audio/fuel_deposit.ogg");
  sound[7].load("../assets/audio/fuel_picked.ogg");
  sound[8].load("../assets/audio/nave_pick_mid.ogg");
  sound[9].load("../assets/audio/objetos.ogg");
  sound[10].load("../assets/audio/rock_dies.ogg");
  sound[11].load("../assets/audio/ship_assemble.ogg");
  sound[12].load("../assets/audio/ship_lands.ogg");
  sound[13].load("../assets/audio/ship_launches.ogg");
  sound[14].load("../assets/audio/shoot1.ogg");
  sound[15].load("../assets/audio/shoot2.ogg");
  sound[16].load("../assets/audio/shoot3.ogg");
  sound[17].load("../assets/audio/shoot4.ogg");
}

void EndSound()
{
  canal.deinit();
}

void PlaySound(SoundName sName)
{
  sound[sName].stop();
  canal.play(sound[sName]);
}