
void __thiscall FUN_004ffbc4(int param_1,undefined4 *param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = timeGetTime();
  FUN_00473496(DVar1);
  uVar2 = __ftol();
  *param_2 = uVar2;
  FUN_00473496(DVar1);
  uVar2 = __ftol();
  param_2[1] = uVar2;
  FUN_00473496(DVar1);
  uVar2 = __ftol();
  param_2[2] = uVar2;
  FUN_00473496(DVar1);
  uVar2 = __ftol();
  param_2[3] = uVar2;
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
  return;
}

