@echo off
set PATH=%~dp0pypy;%PATH%
cd /D %~dp0
set PYTHONNOUSERSITE=1
pypy3 loader.py
