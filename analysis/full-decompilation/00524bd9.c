
int __fastcall FUN_00524bd9(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x10c) - *(int *)(param_1 + 0x104) == 0x2d) &&
     (*(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x108) == 0x2d)) {
    iVar1 = FUN_004096c2();
    return *(int *)(iVar1 + 0x20);
  }
  return *(int *)(param_1 + 0x110) - *(int *)(param_1 + 0x108);
}

