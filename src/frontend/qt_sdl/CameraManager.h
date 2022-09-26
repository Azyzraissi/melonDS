/*
    Copyright 2016-2022 melonDS team

    This file is part of melonDS.

    melonDS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <QCamera>
#include <QCameraInfo>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QMutex>

#include "types.h"

class CameraManager;

class CameraFrameDumper : public QAbstractVideoSurface
{
    Q_OBJECT

public:
    CameraFrameDumper(QObject* parent = nullptr);

    bool present(const QVideoFrame& frame) override;
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle) const override;

private:
    QList<CameraManager*> camList;
};

class CameraManager : public QObject
{
    Q_OBJECT

public:
    CameraManager(int num, int width, int height, bool yuv);
    ~CameraManager();

    void init();
    void deInit();

    void start();
    void stop();
    bool isStarted();

    void captureFrame(u32* frame, int width, int height, bool yuv);

    void feedFrame(u32* frame, int width, int height, bool yuv);

signals:
    void camStartSignal();
    void camStopSignal();

private slots:
    void camStart();
    void camStop();

private:
    int num;

    int startNum;

    int inputType;
    QString imagePath;
    QString camDeviceName;

    QCamera* camDevice;
    CameraFrameDumper* camDumper;

    int frameWidth, frameHeight;
    bool frameFormatYUV;
    u32* frameBuffer;
    QMutex frameMutex;

    void copyFrame_Straight(u32* src, int swidth, int sheight, u32* dst, int dwidth, int dheight, bool yuv);
    void copyFrame_RGBtoYUV(u32* src, int swidth, int sheight, u32* dst, int dwidth, int dheight);
    void copyFrame_YUVtoRGB(u32* src, int swidth, int sheight, u32* dst, int dwidth, int dheight);
};

#endif // CAMERAMANAGER_H
