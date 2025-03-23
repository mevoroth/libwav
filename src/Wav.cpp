#include "Wav.h"

namespace Wav
{
	const Marker MarkerRIFF = 'RIFF';
	const Marker MarkerWAVE = 'WAVE';
	const Marker Markerfmt_ = 'fmt ';
	const Marker MarkerLIST = 'LIST';
	const Marker Markerdata = 'data';
	const Marker MarkerINFO = 'INFO';

	Marker::Marker(u32 InWord)
		: Word(InWord)
	{
		Word = ((Word & 0x000000FF) << 24)
			 | ((Word & 0x0000FF00) << 8)
			 | ((Word & 0x00FF0000) >> 8)
			 | ((Word & 0xFF000000) >> 24);
	}

	bool Marker::operator==(_In_ const Marker& InMarker) const
	{
		return Word == InMarker.Word;
	}
}
