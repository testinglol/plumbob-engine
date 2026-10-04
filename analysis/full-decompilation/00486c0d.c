
undefined4 __fastcall FUN_00486c0d(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x1ac);
  }
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x40) = (int)*(short *)(iVar3 + 0x4c);
  }
  if ((iVar1 != 0) && (iVar3 != 0)) {
    sVar2 = FUN_00421a41();
    if (sVar2 != 0) {
      if (*(int *)(param_1 + 0x30) != 0) {
        FUN_0049341e(*(int *)(param_1 + 0x30));
        FUN_00485b4c();
        *(undefined4 *)(param_1 + 0x30) = 0;
      }
      FUN_00487f26();
      uVar4 = 1;
    }
  }
  FUN_00486e21();
  return uVar4;
}

