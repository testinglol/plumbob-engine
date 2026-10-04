
undefined4 __fastcall FUN_005dec8a(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x15c) != '\0') {
    iVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x60))(*(int **)(param_1 + 4));
    if (iVar1 != -0x7789fe3e) {
      return 1;
    }
  }
  return 0;
}

