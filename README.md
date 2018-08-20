# Wolf Spectrum 
[![Build Status](https://travis-ci.org/pdesaulniers/wolf-spectrum.svg?branch=master)](https://travis-ci.org/pdesaulniers/wolf-spectrum)
[![Chat on Matrix](https://matrix.to/img/matrix-badge.svg)](https://riot.im/app/#/user/@pdesaulniers:matrix.org?action=chat)

![Wolf Spectrum](https://raw.githubusercontent.com/pdesaulniers/wolf-spectrum/master/plugins/wolf-spectrum/Screenshot.png)

Wolf Spectrum is a spectrogram plugin. It can be built as an LV2 or VST plugin and as a standalone Jack application.

#### Features:
* Supports both log and linear frequency scaling
* Resizable UI

## Download

You can find some precompiled plugin binaries in the [Releases](https://github.com/pdesaulniers/wolf-spectrum/releases) tab. Wolf Spectrum is also available [in the AUR](https://aur.archlinux.org/packages/wolf-spectrum-git/). 

For building the plugin manually, see the section below.

## Build manually

First, clone the repo (note the "--recursive" argument):

```
git clone --recursive https://github.com/pdesaulniers/wolf-spectrum.git
cd wolf-spectrum
```

Then:

```
BUILD_VST2=true BUILD_LV2=true BUILD_JACK=true make
```

Prepend WIN32=true or MACOS=true to the command if applicable.

All plugin builds will then be placed in the bin folder. Copy them to their appropriate place so that your plugin host can find them, and you're done :)

## Updating

This project uses git submodules. Thus, to update your local copy of the repo, you need to run the following commands:
```
git pull
git submodule update
```
You should then be able to build the plugin with the most recent changes.
