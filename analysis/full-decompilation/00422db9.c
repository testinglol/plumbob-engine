
void __thiscall FUN_00422db9(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 400);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    iVar1 = param_1;
    iVar2 = param_1;
  }
  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18c)) {
    FUN_00422d79(10,0,0);
  }
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x18c)) {
    FUN_004331d4(param_2);
  }
  if ((char)param_2 != '\0') {
    FUN_00447d6b(param_1);
  }
  return;
}

