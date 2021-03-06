#include <iostream>

#include "StPicoEvent/StPicoBbcTile.h"
#include "St_base/StMessMgr.h"


StPicoBbcTile::StPicoBbcTile() : StPicoBbcTile(0, 0, 0, 0, false)
{
  /* no-op */
}


StPicoBbcTile::StPicoBbcTile(int ID, int ADC, int TAC, int TDC, bool hasTAC, bool statusIsGood) :
  TObject(),
  mId(ID),
  mQTdata( (ADC & 0x0FFF) | (TAC & 0x0FFF) << 12 | (TDC & 0x001F) << 24 | hasTAC << 29 | statusIsGood << 30)
{
  /* no-op */
}


void StPicoBbcTile::Print(const Char_t *option) const
{
  LOG_INFO << " BBC tile - PMT#: " << mId
           << " ADC: " << adc()
           << " TAC: " << tac()
           << " TDC: " << tdc()
           << " - This tile " << (hasTac() ? "has TAC" : "does not have TAC")
           << " - Status is " << (isGood() ? "good" : "bad")
           << endm;
}
