
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00558038(int *param_1)

{
  float fVar1;
  char cVar2;
  DWORD DVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_1[0x4a] != 0) && (800 < param_1[0x21] - param_1[0x1f])) {
    cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x10);
    if (cVar2 != '\0') {
      (**(code **)(*(int *)param_1[0x17] + 0x9c))
                (param_1[0x4a],param_1[0x4a] + 0x14,(int *)param_1[0x17] + 5,0);
    }
    (**(code **)(*(int *)param_1[0x17] + 0x24))(0x10);
  }
  iVar4 = param_1[0x7f];
  DVar3 = timeGetTime();
  uVar5 = DVar3 - iVar4;
  fVar1 = _DAT_006687a0 / (float)uVar5;
  if (fVar1 <= (float)param_1[0x7e]) {
    param_1[0x76] = param_1[0x76] + 1;
    param_1[0x77] = param_1[0x77] + 1;
    param_1[0x7f] = iVar4 + uVar5;
  }
  if (param_1[0x76] == 6) {
    param_1[0x76] = 0;
  }
  if (param_1[0x77] == 0xc) {
    param_1[0x77] = 0;
  }
  iVar4 = param_1[0x77];
  if (iVar4 % 2 != 0) {
    iVar4 = iVar4 + -1;
  }
  if ((fVar1 <= (float)param_1[0x7e]) && (param_1[iVar4 / 2 + 0x78] != 0)) {
    (**(code **)(*(int *)param_1[0x67] + 0x19c))(param_1[iVar4 / 2 + 0x78],1,1);
  }
  (**(code **)(*param_1 + 0x168))();
  return 1;
}

