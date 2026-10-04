
undefined4 __fastcall FUN_005c8c6c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((*(char *)(param_1 + 0x578) == '\0') || (*(char *)(param_1 + 8) == '\0')) {
    FUN_005c8b39(*(undefined4 *)(param_1 + 0x60));
    *(undefined1 *)(param_1 + 0x54c) = 0;
    uVar2 = FUN_005c8e5f();
    return uVar2;
  }
  if (*(int *)(param_1 + 0x74) == 0) {
    piVar1 = *(int **)(param_1 + 0x70);
    if ((piVar1 == (int *)0x0) && (piVar1 = *(int **)(param_1 + 0x6c), piVar1 == (int *)0x0))
    goto LAB_005c8c9d;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x6c);
  }
  (**(code **)(*piVar1 + 0x28))(piVar1);
LAB_005c8c9d:
  *(undefined1 *)(param_1 + 0x578) = 0;
  return 0;
}

