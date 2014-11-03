/***************************************************************************
*   Copyright (C) 2005-2014 by the Quassel Project                        *
*   devel@quassel-irc.org                                                 *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) version 3.                                           *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
***************************************************************************/

#ifndef PHONONACTIVITYNOTIFICATIONBACKEND_H_
#define PHONONACTIVITYNOTIFICATIONBACKEND_H_

#include <phonon/mediaobject.h>

#include "abstractnotificationbackend.h"
#include "settingspage.h"

#include "ui_phononactivitynotificationconfigwidget.h"

class PhononActivityNotificationBackend : public AbstractNotificationBackend
{
	Q_OBJECT

public:
	PhononActivityNotificationBackend(QObject *parent = 0);
	~PhononActivityNotificationBackend();

	void notify(const Notification &);
	void close(uint notificationId);
	virtual SettingsPage *createConfigWidget() const;

	private slots:
	void enabledChanged(const QVariant &);
	void audioFileChanged(const QVariant &);
	void createMediaObject(const QString &name);

private:
	class ConfigWidget;

	bool _enabled;
	bool _audioAvailable;
	Phonon::MediaObject *_media;
};


class PhononActivityNotificationBackend::ConfigWidget : public SettingsPage
{
	Q_OBJECT

public:
	ConfigWidget(QWidget *parent = 0);
	~ConfigWidget();

	void save();
	void load();
	bool hasDefaults() const;
	void defaults();

	private slots:
	void widgetChanged();
	void on_open_clicked();
	void on_play_clicked();

private:
	Ui::PhononActivityNotificationConfigWidget ui;

	bool enabled;
	bool _audioAvailable;
	QString filename;
	Phonon::MediaObject *audioPreview;
};


#endif