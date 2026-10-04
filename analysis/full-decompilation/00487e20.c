
uint __thiscall FUN_00487e20(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 0x84) == 0)) {
    iVar2 = FUN_0045741b();
    piVar4 = (int *)*param_1;
    uVar3 = 0;
    uVar1 = param_1[1] - (int)piVar4 >> 2;
    if (uVar1 != 0) {
      do {
        if (*piVar4 == iVar2) {
          return uVar3;
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < uVar1);
    }
    uVar1 = uVar1 + 1;
  }
  else {
    uVar1 = FUN_004cba72();
  }
  return uVar1;
}

