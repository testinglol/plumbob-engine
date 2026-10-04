
undefined4 Catch_005c097c(void)

{
  HANDLE hThread;
  int nPriority;
  
  nPriority = 0;
  hThread = GetCurrentThread();
  SetThreadPriority(hThread,nPriority);
  return 0x5c0991;
}

