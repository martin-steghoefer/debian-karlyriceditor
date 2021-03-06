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

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(resources);
	
	QApplication app(argc, argv);

	QCoreApplication::setOrganizationName("karlyriceditor.com");
	QCoreApplication::setOrganizationDomain("karlyriceditor.com");
	QCoreApplication::setApplicationName("karlyriceditor");

	MainWindow wnd;
	wnd.show();

	return app.exec();
}

#if defined (_WIN32)

// SDL defines its own main() function in SDL_main. And so does Qt, so if we continue without
// the #define below we'll end up with the following link error:
// libqtmain.a(qtmain_win.o):qtmain_win.cpp:(.text+0x159): undefined reference to `qMain(int, char**)'

int qMain( int argc, char ** argv )
{
	return main( argc, argv );
}

#endif
