
void __fastcall FUN_00491e92(int param_1)

{
  SHORT SVar1;
  int iVar2;
  
  SVar1 = GetKeyState(0x10);
  *(bool *)(param_1 + 0x5c) = SVar1 < 0;
  SVar1 = GetKeyState(0x11);
  *(bool *)(param_1 + 0x5d) = SVar1 < 0;
  iVar2 = ((-(uint)(*(char *)(param_1 + 0x5c) != '\0') & 0xfffffffe) + 1) * *(int *)(param_1 + 0x50)
  ;
  *(int *)(param_1 + 0x54) = iVar2;
  if (iVar2 < 1) {
    FUN_004d25a5(0);
    if (*(int *)(param_1 + 0x4c) == 0) {
      return;
    }
    *(undefined2 *)(*(int *)(param_1 + 0x4c) + 0x4a) = 1;
  }
  else {
    FUN_004d25a5(0);
    if (*(int *)(param_1 + 0x4c) == 0) {
      return;
    }
    *(undefined2 *)(*(int *)(param_1 + 0x4c) + 0x4a) = 0;
  }
  FUN_004341a6(0);
  return;
}

