@echo off
set PATH=%PATH%;%~dp0pypy
cd %~dp0
pypy3 loader.py
