
uint __fastcall FUN_005fd8ea(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  LARGE_INTEGER local_c;
  
  local_c.s.LowPart = (DWORD)param_1;
  local_c.s.HighPart = (LONG)param_1;
  if (param_1[2] != 0 || param_1[3] != 0) {
    QueryPerformanceCounter(&local_c);
    param_1[4] = local_c.s.LowPart - param_1[2];
    param_1[5] = (local_c.s.HighPart - param_1[3]) - (uint)(local_c.s.LowPart < (int *)param_1[2]);
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 1000000;
  }
  else {
    iVar2 = (-(uint)(iVar1 != 1) & 0xfffffc19) + 1000;
  }
  uVar4 = __allmul(param_1[4],param_1[5],iVar2,0);
  uVar3 = __aulldiv(uVar4,param_1[6],0);
  if (iVar1 == 0) {
    uVar3 = -(uint)(uVar3 - DAT_006fed98 != 0) & uVar3 - DAT_006fed98;
  }
  return uVar3;
}

