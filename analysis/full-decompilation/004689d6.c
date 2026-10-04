
undefined4 __fastcall FUN_004689d6(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x77) == '\0') {
    iVar3 = *(int *)(param_1 + 4);
    *(undefined1 *)(param_1 + 0x76) = 1;
    for (; iVar3 != *(int *)(param_1 + 8); iVar3 = iVar3 + 3) {
      cVar1 = FUN_00468a47();
      if (cVar1 == '\0') {
        *(undefined1 *)(param_1 + 0x76) = 0;
        break;
      }
    }
    *(undefined1 *)(param_1 + 0x77) = 1;
  }
  if (*(char *)(param_1 + 0x76) == '\0') {
LAB_00468a42:
    uVar2 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x74) == '\0') {
      cVar1 = FUN_00468851();
      if (cVar1 != '\0') goto LAB_00468a42;
    }
    uVar2 = 1;
  }
  return uVar2;
}

