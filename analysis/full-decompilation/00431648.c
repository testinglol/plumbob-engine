
void __thiscall FUN_00431648(int param_1,int param_2)

{
  int iVar1;
  
  if ((((param_2 != 0) && (*(int *)(param_2 + 0x1c) == *(int *)(param_1 + 0x1c))) &&
      (*(int *)(param_1 + 8) == *(int *)(param_2 + 8))) &&
     ((*(int *)(param_1 + 4) == *(int *)(param_2 + 4) &&
      (iVar1 = *(int *)(param_1 + 4) * *(int *)(param_1 + 8) * *(int *)(param_1 + 0x1c), 0 < iVar1))
     )) {
    FUN_00420050(**(undefined4 **)(param_2 + 0xc),**(undefined4 **)(param_1 + 0xc),iVar1);
  }
  return;
}

