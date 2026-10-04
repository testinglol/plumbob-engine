
void __thiscall FUN_004259ec(int param_1,short *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = (int)*param_2;
  FUN_0040766a(0xfb,iVar3);
  iVar2 = FUN_0042a8e3(iVar3);
  if (iVar2 != 0) {
    FUN_0041f4e7(0);
    FUN_0041f4e7(1);
    FUN_0041f4e7(2);
    FUN_0041f4e7(3);
    FUN_0041f4e7(4);
    FUN_0041f4e7(5);
    FUN_0041f4e7(6);
    FUN_0041f4e7(7);
    FUN_0041f4e7(8);
    FUN_0041f4e7(9);
  }
  piVar4 = *(int **)(param_1 + 0x148);
  piVar1 = *(int **)(param_1 + 0x14c);
  piVar4[iVar3 + -1] = 0;
  for (; piVar4 != piVar1; piVar4 = piVar4 + 1) {
    if (*piVar4 != 0) {
      FUN_00465090(iVar3);
    }
  }
  if (param_2 != (short *)0x0) {
    FUN_00423852();
    FUN_006321f0(param_2);
  }
  return;
}

