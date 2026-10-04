
int __fastcall FUN_00486a5e(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  iVar1 = FUN_0045741b();
  piVar3 = (int *)*param_1;
  uVar4 = 0;
  uVar2 = param_1[1] - (int)piVar3 >> 2;
  if (uVar2 != 0) {
    do {
      if (*piVar3 == iVar1) {
        return param_1[3] + uVar4;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 < uVar2);
  }
  return 0;
}

