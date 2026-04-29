param([string]$tarCommand)

if ([string]::IsNullOrWhiteSpace($tarCommand)) {
  Write-Host "Usage: run_tar_and_map.ps1 '<tar command>'" -ForegroundColor Yellow
  exit 1
}

Write-Host "[DependencyMapper] Executing tar command: $tarCommand"
# Execute the tar command. We delegate to the shell to allow complex quoting.
$exitCode = & cmd /c $tarCommand
if ($LASTEXITCODE -ne 0) {
  Write-Error "Tar command failed with exit code $LASTEXITCODE"
  exit $LASTEXITCODE
}

Write-Host "Tar completed successfully. Running Dependency Mapper..."
python .\scripts\dep_mapper.py
Write-Host "Dependency mapping updated."
