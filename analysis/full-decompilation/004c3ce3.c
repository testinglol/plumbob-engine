
undefined4 __fastcall FUN_004c3ce3(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006688a0;
    puVar2[1] = 4;
    puVar2[2] = 3;
  }
  *(undefined4 **)(param_1 + 4) = puVar2;
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_006688a0;
    puVar2[1] = 2;
    puVar2[2] = 3;
  }
  *(undefined4 **)(param_1 + 8) = puVar2;
  sVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))();
  if (sVar1 != 0) {
    sVar1 = (**(code **)(**(int **)(param_1 + 8) + 4))();
    if (sVar1 != 0) {
      return 1;
    }
    (**(code **)(**(int **)(param_1 + 4) + 8))();
  }
  return 0;
}

