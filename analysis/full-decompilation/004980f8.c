
void __fastcall FUN_004980f8(int param_1)

{
  int iVar1;
  SHORT SVar2;
  
  if (*(char *)(param_1 + 0x30) != '\0') {
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar1 == 0) {
      SVar2 = GetKeyState(0x11);
      if (SVar2 < 0) {
        *(undefined4 *)(param_1 + 0x2c) = 1;
        goto LAB_00498134;
      }
    }
    if (iVar1 == 1) {
      SVar2 = GetKeyState(0x11);
      if (-1 < SVar2) {
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
    }
  }
LAB_00498134:
  if (*(char *)(param_1 + 0x4c) == '\0') {
    *(undefined1 *)(param_1 + 0x4c) = 1;
  }
  return;
}

