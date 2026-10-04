
void __thiscall FUN_0051c538(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x31c) != 0) {
    FUN_005e4fb5(0,0,0);
    *(undefined4 *)(param_1 + 0x31c) = 0;
  }
  if (param_2 == DAT_006f6b5c) {
    param_2 = 0;
  }
  else {
    if (param_2 == 0) {
      return;
    }
    iVar2 = FUN_004e98c0(param_2);
    if (iVar2 == -1) {
      return;
    }
    cVar1 = FUN_004ea8e8(iVar2);
    if (cVar1 != '\0') {
      iVar2 = FUN_00407498((int)*(short *)(param_2 + 0x638));
      if (iVar2 == 0) {
        return;
      }
      FUN_00434d92(1);
      return;
    }
    uVar3 = FUN_004e9957(iVar2);
    if ((int)uVar3 < 0) {
      return;
    }
    if ((uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) <= uVar3) {
      return;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xf0) + uVar3 * 4);
    *(int *)(param_1 + 0x31c) = iVar2;
    if (iVar2 != 0) {
      FUN_005e4fb5(*(undefined4 *)(param_1 + 0x318),0,0);
    }
  }
  FUN_00586fdc(param_2);
  return;
}

