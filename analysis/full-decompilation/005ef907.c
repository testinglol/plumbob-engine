
undefined4 __fastcall FUN_005ef907(int param_1)

{
  int *piVar1;
  int iStack_14;
  int *local_10;
  int iStack_4;
  
  piVar1 = (int *)**(int **)(param_1 + 0xc0);
  iStack_4 = param_1;
  if (piVar1 != *(int **)(param_1 + 0xc0)) {
    do {
      local_10 = (int *)piVar1[6];
      if (local_10 != (int *)0x0) {
        iStack_14 = 0x5ef929;
        (**(code **)(*local_10 + 8))();
      }
      piVar1[6] = 0;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(param_1 + 0xc0));
  }
  iStack_14 = *(int *)(param_1 + 0xc0);
  local_10 = (int *)iStack_14;
  FUN_00602902(&iStack_14);
  FUN_005f0943(&iStack_4);
  return 1;
}

