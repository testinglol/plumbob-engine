
bool __thiscall FUN_005d9007(int param_1,int param_2)

{
  BOOL BVar1;
  int local_20 [7];
  
  local_20[2] = 0xffffffff;
  local_20[3] = 0;
  local_20[0] = -0xf;
  local_20[1] = 0xfffffffe;
  local_20[4] = 1;
  local_20[5] = 2;
  local_20[6] = 0xf;
  BVar1 = SetThreadPriority(*(HANDLE *)(param_1 + 0xc),local_20[param_2]);
  return BVar1 != 0;
}

