#ifndef TEXTURE_ROLL_HPP_INCLUDED
#define TEXTURE_ROLL_HPP_INCLUDED

#include "NanoVG.hpp"
#include "src/nanovg/nanovg.h"

START_NAMESPACE_DISTRHO

class PixelDrawingSurface : public NanoWidget
{
public:
  PixelDrawingSurface(NanoWidget *widget, Size<uint> size, int imageFlags = 0);

  void drawPixel(int posX, int posY, Color pixelColor);
  void setScaleX(float scale);
  void setBufferSize(int width, int height);
  void clear();

protected:
  void onNanoDisplay() override;

private:
  static constexpr int INTERNAL_BUFFER_WIDTH = 1024;
  static constexpr int INTERNAL_BUFFER_HEIGHT = 2048;

  int fFileId;
  unsigned char *fImageData;
  bool fDirty;
  float fScaleX;
  int fBufferWidth;
  int fBufferHeight;
  int fImageFlags;
};

class ScrollingTexture : public NanoWidget
{
public:
  ScrollingTexture(NanoWidget *widget, Size<uint> size);
  ~ScrollingTexture();

  void drawPixelOnCurrentLine(int pos, Color color);
  void scroll();
  void setScaleX(float scale);
  void setBlockSize(int blockSize);
  void setHorizontalScrolling(bool yesno);
  void clear();

protected:
  void onNanoDisplay() override;
  void onResize(const ResizeEvent &ev) override;

private:
  void verticalScroll();
  void horizontalScroll();
  void positionTextures();

  PixelDrawingSurface textureA;
  PixelDrawingSurface textureB;

  int scrollTicks;
  int blockSize;

  bool horizontalScrolling;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ScrollingTexture)
};

END_NAMESPACE_DISTRHO

#endif