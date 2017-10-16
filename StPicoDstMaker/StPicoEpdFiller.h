#ifndef StPicoEpdFiller_h
#define StPicoEpdFiller_h

class StMuDst;
class StPicoDst;
class StEpdDbMaker;


/**
 * This class fills a TClonesArray of StPicoEpdTile objects that make up the EPD
 * detector.
 *
 * update 14 Oct 2017 - mal
 * 1) removing hard-coded mapping, in favor of DB
 * 2) calculating and storing single-float calibrated data in StPicoEpdTile
 */
class StPicoEpdFiller
{
public:

  StPicoEpdFiller(StPicoDst& picoDst, int year = 2017);

  void fill(const StMuDst& muDst, StEpdDbMaker* db);

private:

  StPicoDst&  mPicoDst;

  struct EpdAnalysisMap
  {
    Short_t qt_board_address; // channel number used in QT board or other physical numbering scheme 0x10...
    Short_t qt_channel_ADC; // QT board channel used 0....31
    Short_t qt_channel_TAC; // QT board channel used 0....31
  };

  EpdAnalysisMap mEpdMap[2][12][31];

  void setDefaultMapping_30may2017();

};

#endif

