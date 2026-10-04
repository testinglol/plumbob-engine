
char __thiscall FUN_00452237(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = FUN_00474ff5(param_2);
  if (cVar1 != '\0') {
    if (*(short *)(param_1 + 0x7c) != 0) {
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + -1;
    }
    for (iVar3 = *(int *)(param_1 + 0x148); iVar3 != *(int *)(param_1 + 0x14c); iVar3 = iVar3 + 0x3c
        ) {
      cVar2 = FUN_0046e120();
      if (cVar2 != '\0') {
        FUN_004341a6(0);
      }
    }
  }
  return cVar1;
}

