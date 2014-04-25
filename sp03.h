#ifndef SP03_H
#define SP03_H

#define SP03_ADDRESS	0xC4 >> 1 // 0xC4
#define SP03_COMMAND	0x00
#define SP03_VERSION	0x01

#define SP03_NOP			0x00
#define SP03_SPKPRE1		0x01
#define SP03_SPKPRE2		0x02
#define SP03_SPKPRE3		0x03
// ...
#define SP03_SPKPRE30		0x1E

#define SP03_SPKBUF			0x40

class Sp03
{
public:
	Sp03() {};
	void say(const char* phrase);
	int getVersion();
	bool isSpeaking();
};


#endif