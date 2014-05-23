/**************************************************************************
 *  Karlyriceditor - a lyrics editor and CD+G / video export for Karaoke  *
 *  songs.                                                                *
 *  Copyright (C) 2009-2013 George Yunaev, support@ulduzsoft.com          *
 *                                                                        *
 *  This program is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, either version 3 of the License, or     *
 *  (at your option) any later version.                                   *
 *																	      *
 *  This program is distributed in the hope that it will be useful,       *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *  GNU General Public License for more details.                          *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 **************************************************************************/

/**************************************************************************
 * This class uses ideas from QTFFmpegWrapper - QT FFmpeg Wrapper Class   *
 * Copyright (C) 2009,2010: Daniel Roggen, droggen@gmail.com              *
 * All rights reserved.                                                   *
 **************************************************************************/

#ifndef FFMPEGVIDEOENCODER_H
#define FFMPEGVIDEOENCODER_H

#include <QString>
#include <QImage>

#include "videoencodingprofiles.h"

class AudioPlayer;
class FFMpegVideoEncoderPriv;

class FFMpegVideoEncoder
{
	public:
		FFMpegVideoEncoder();
		virtual ~FFMpegVideoEncoder();

		// Returns non-empty error message if failed
		QString createFile( const QString& filename,
							const VideoEncodingProfile * profile,
							const VideoFormat * videoformat,
							unsigned int quality,
							bool  convert_audio,
							AudioPlayer * audio );

		bool close();
		int encodeImage( const QImage & img, qint64 time );

	private:
		FFMpegVideoEncoderPriv * d;
};

#endif // FFMPEGVIDEOENCODER_H
