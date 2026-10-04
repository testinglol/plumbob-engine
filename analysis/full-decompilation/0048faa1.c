
void __fastcall FUN_0048faa1(int param_1)

{
  int iVar1;
  SHORT SVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x59) == '\0') goto LAB_0048fadd;
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 == 0) {
    SVar2 = GetKeyState(0x11);
    if (-1 < SVar2) goto LAB_0048fac6;
    uVar3 = 1;
  }
  else {
LAB_0048fac6:
    if (iVar1 != 1) goto LAB_0048fadd;
    SVar2 = GetKeyState(0x11);
    if (SVar2 < 0) goto LAB_0048fadd;
    uVar3 = 0;
  }
  FUN_004905d0(uVar3);
LAB_0048fadd:
  if (*(char *)(param_1 + 0x58) == '\0') {
    *(undefined1 *)(param_1 + 0x58) = 1;
  }
  return;
}

