
void __fastcall FUN_00425b05(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = *(int **)(param_1 + 0x14c);
  for (piVar4 = *(int **)(param_1 + 0x148); (piVar4 != piVar1 && (*piVar4 != 0));
      piVar4 = piVar4 + 1) {
    uVar2 = FUN_00401f73();
    uVar2 = FUN_004e988f(uVar2);
    iVar3 = FUN_004e9744(uVar2);
    if (iVar3 != 0) {
      FUN_00425ab3(iVar3);
    }
  }
  return;
}

