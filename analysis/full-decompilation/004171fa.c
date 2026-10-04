
undefined4 __fastcall FUN_004171fa(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar5 = 0xffffffcf;
  }
  else {
    uVar5 = 0;
  }
  FUN_004659fc(uVar5);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    uVar5 = FUN_00401f6f();
    return uVar5;
  }
  (**(code **)(*param_1 + 0x1c))();
  for (puVar3 = (undefined4 *)param_1[6]; puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    for (puVar4 = (undefined4 *)puVar3[2]; puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      if (puVar4[4] != 0) {
        FUN_00420028(puVar4[4]);
      }
    }
  }
  FUN_00418267(param_1[6]);
  param_1[6] = 0;
  for (puVar3 = (undefined4 *)param_1[7]; puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    for (puVar4 = (undefined4 *)puVar3[2]; puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)*puVar4) {
      if (puVar4[4] != 0) {
        FUN_00420028(puVar4[4]);
      }
    }
  }
  FUN_00418267(param_1[7]);
  param_1[7] = 0;
  if (0x27ff < (uint)param_1[8]) {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (cVar1 != '\0') {
      FUN_004183a3();
    }
  }
  iVar2 = param_1[9];
  if (iVar2 != 0) {
    thunk_FUN_00418416();
    FUN_006321f0(iVar2);
    param_1[9] = 0;
  }
  uVar5 = FUN_00413154();
  FUN_004659fc(uVar5);
  return uVar5;
}

