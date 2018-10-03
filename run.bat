@echo off
set PATH=%PATH%;%~dp0pypy
cd /D %~dp0
pypy3 loader.py
