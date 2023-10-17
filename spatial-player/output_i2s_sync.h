#ifndef output_i2s_sync_h_
#define output_i2s_sync_h_

#include <Arduino.h>
#include <AudioStream.h>
#include <DMAChannel.h>

class AudioOutputI2SSync : public AudioStream
{
public:
	AudioOutputI2SSync(void) : AudioStream(2, inputQueueArray) { }
	virtual void update(void);
	void begin(void);
	friend class AudioInputI2S;
	friend class AudioInputPDM;
#if defined(__IMXRT1062__)
	friend class AudioOutputI2SQuad;
	friend class AudioInputI2SQuad;
	friend class AudioOutputI2SHex;
	friend class AudioInputI2SHex;
	friend class AudioOutputI2SOct;
	friend class AudioInputI2SOct;
#endif
protected:
	AudioOutputI2SSync(int dummy): AudioStream(2, inputQueueArray) {} // to be used only inside AudioOutputI2Sslave !!
	static void config_i2s(bool only_bclk = false);
	static audio_block_t *block_left_1st;
	static audio_block_t *block_right_1st;
	static bool update_responsibility;
	static DMAChannel dma;
	static void isr(void);
private:
	static audio_block_t *block_left_2nd;
	static audio_block_t *block_right_2nd;
	static uint16_t block_left_offset;
	static uint16_t block_right_offset;
	audio_block_t *inputQueueArray[2];
};

#endif
