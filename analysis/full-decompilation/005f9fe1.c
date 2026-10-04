
undefined4 __fastcall FUN_005f9fe1(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0xc0) = 0;
  if ((*(int *)(param_1 + 0x80) != 0) && (iVar1 = *(int *)(param_1 + 0xbc), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x28) != 0) {
      *(undefined4 *)(iVar1 + 0x28) = 0;
      timeKillEvent(*(UINT *)(*(int *)(param_1 + 0xbc) + 0x24));
      if (*(char *)(param_1 + 0x60) != '\0') {
        *(undefined1 *)(param_1 + 0x60) = 0;
        timeEndPeriod(0xc0);
      }
    }
    *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x18) = 1;
    if (*(int *)(*(int *)(param_1 + 0xbc) + 0x2c) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0xbc) + 0x2c) = 0;
      (**(code **)(**(int **)(param_1 + 0x80) + 0x48))(*(int **)(param_1 + 0x80));
    }
    if ((int *)**(int **)(param_1 + 0xbc) != (int *)0x0) {
      (**(code **)(*(int *)**(int **)(param_1 + 0xbc) + 8))();
      FUN_006321f0(**(undefined4 **)(param_1 + 0xbc));
      **(undefined4 **)(param_1 + 0xbc) = 0;
    }
  }
  return 1;
}

