#ifndef StPicoBbcEpdFiller_h
#define StPicoBbcEpdFiller_h

/*
   this makes a TClonesArray of StPicoBbcEpdTile objects
   that make up the BBC and EPD detectors.  The tile
   objects for these two detectors are the same, hence
   the name.

   One can either make one collection of all of these tiles,
   or one can make two collections where one is the BBC and
   the other is the EPD.  Here, I make the former choice.
   Dmitri, you can choose whichever you like.  It doesn't
   matter, since each tile "knows" what detector it belongs
   to, and can be asked to identify through isEpd() and
   isBbc().
*/

#include "StPicoBbcEpdTile.h"

class TClonesArray;
class StTriggerData;
class StMuDst;
class StPicoDst;


class StPicoBbcEpdFiller
{
public:
  StPicoBbcEpdFiller(StPicoDst& picoDst, Short_t year = 2017);
  virtual ~StPicoBbcEpdFiller();

  void Fill(const StMuDst& muDst);

  TClonesArray *BbcEpdTileCollection() {return mTileCollection;}

private:

  StPicoDst&  mPicoDst;

  TClonesArray *mTileCollection;
  struct EPDAnalysisMap {
    Short_t qt_board_address; // channel number used in QT board or other physical numbering scheme 0x10...
    Short_t qt_channel_ADC; // QT board channel used 0....31
    Short_t qt_channel_TAC; // QT board channel used 0....31
  };

  EPDAnalysisMap mEPDMap[2][12][31];

  void SetDefaultMapping_30may2017();

};

#endif
