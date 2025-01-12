#include <DSPI.h>
#include <OpenBCI_32bit_Library.h>
#include <OpenBCI_32bit_Library_Definitions.h>

void setup() {
  // Bring up the OpenBCI Board
  board.begin();
  // Don't use the accel
  board.useAccel(false);
}

void loop() {
  if (board.streaming) {
    if (board.channelDataAvailable) {
      // Read from the ADS(s), store data, set channelDataAvailable flag to false
      board.updateChannelData();
      // Send that channel data
      board.sendChannelData();
    }
  }
  // Check the serial ports for new data
  if (board.hasDataSerial0()) board.processChar(board.getCharSerial0());
  if (board.hasDataSerial1()) board.processChar(board.getCharSerial1());
  board.loop();
}