@echo off
REM Usage: run_tar_and_map.bat "<tar command>"
if "%1"=="" (
  echo Usage: run_tar_and_map.bat "<tar command>"
  exit /b 1
)
set "TCMD=%~1"
echo Running tar command: %TCMD%
cmd /c "%TCMD%"
if ERRORLEVEL 1 (
  echo Tar command failed with exit code %ERRORLEVEL%
  exit /b %ERRORLEVEL%
)
echo Tar completed. Running Dependency Mapper...
python scripts/dep_mapper.py
echo Done.
