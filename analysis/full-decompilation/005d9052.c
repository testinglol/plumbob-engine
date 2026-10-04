
bool FUN_005d9052(int param_1)

{
  HANDLE hThread;
  BOOL BVar1;
  int nPriority;
  int local_20 [7];
  
  local_20[2] = 0xffffffff;
  local_20[3] = 0;
  local_20[0] = -0xf;
  local_20[1] = 0xfffffffe;
  local_20[4] = 1;
  local_20[5] = 2;
  local_20[6] = 0xf;
  nPriority = local_20[param_1];
  hThread = GetCurrentThread();
  BVar1 = SetThreadPriority(hThread,nPriority);
  return BVar1 != 0;
}

