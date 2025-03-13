#ifndef _WAV_H_
#define _WAV_H_

namespace Wav
{
	using u16 = unsigned short;
	using u32 = unsigned int;

	union Marker
	{
		static constexpr u32 WordBytes = 4;

		/**
		 * @param[in] Extern buffer
		 * @param[in] Size of extern buffer
		 */
		Marker(u32 InWord);

		char Bytes[WordBytes];
		u32 Word;
	};

	struct Header
	{
		static constexpr u16 DefaultChannelsCount		= 2u;
		static constexpr u32 DefaultSamplesPerSecond	= 44100u;
		static constexpr u32 DefaultBitsPerSample		= 16u;

		Marker RIFFMarker		= 'RIFF';
		u32 FileSize			= 0u;
		Marker WAVEMarker		= 'WAVE';
		Marker FMTMarker		= 'FMT ';
		u32 SubChunkSize		= 0u;
		u16 AudioFormat			= 1u;
		u16 ChannelsCount		= DefaultChannelsCount;
		u32 SamplesPerSecond	= DefaultSamplesPerSecond;
		u32 BytesPerSecond		= DefaultChannelsCount * DefaultSamplesPerSecond * DefaultBitsPerSample;
		u16 BlockAlign			= 4u;
		u16 BitsPerSample		= DefaultBitsPerSample;
	};

	struct Data
	{
		Marker DATAMarker		= 'data';
		u32 DataSize			= 0u;
	};
}

#endif
