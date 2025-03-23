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
		Marker(u32 InWord = 0u);

		bool operator==(_In_ const Marker& InMarker) const;

		char Bytes[WordBytes];
		u32 Word;
	};

	extern const Marker MarkerRIFF;
	extern const Marker MarkerWAVE;
	extern const Marker Markerfmt_;
	extern const Marker MarkerLIST;
	extern const Marker Markerdata;
	extern const Marker MarkerINFO;

	struct Header
	{
		static constexpr u16 DefaultChannelsCount		= 2u;
		static constexpr u32 DefaultSamplesPerSecond	= 44100u;
		static constexpr u32 DefaultBitsPerSample		= 16u;

		Marker RIFFMarker		= MarkerRIFF;
		u32 FileSize			= 0u;
		Marker WAVEMarker		= MarkerWAVE;
		Marker FMTMarker		= Markerfmt_;
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
		Marker DATAMarker		= Markerdata;
		u32 DataSize			= 0u;
	};
}

#endif
