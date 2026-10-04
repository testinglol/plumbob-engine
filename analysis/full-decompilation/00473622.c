
void __fastcall FUN_00473622(int *param_1)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  uint uVar4;
  
  DVar3 = timeGetTime();
  uVar2 = param_1[5];
  param_1[2] = DVar3;
  uVar4 = (param_1[4] + DVar3) - *param_1;
  param_1[1] = uVar4;
  if (uVar2 < uVar4) {
    iVar1 = uVar2 + *param_1;
    param_1[1] = uVar2;
    *param_1 = iVar1;
    param_1[4] = iVar1 - DVar3;
  }
  else {
    *param_1 = param_1[4] + DVar3;
  }
  param_1[3] = param_1[3] + 1;
  return;
}

