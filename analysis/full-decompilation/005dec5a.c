
undefined1 __fastcall FUN_005dec5a(int param_1)

{
  char cVar1;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    cVar1 = FUN_00606a8f();
    if (cVar1 != '\0') goto LAB_005dec82;
  }
  if (*(int *)(param_1 + 0x48) != 0) {
    cVar1 = FUN_005dec8a();
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 4) = 0;
      return 0;
    }
  }
LAB_005dec82:
  *(undefined1 *)(param_1 + 4) = 1;
  return 1;
}

