
void __fastcall FUN_00468cce(int *param_1)

{
  int iVar1;
  
  if (param_1[1] != 0) {
    FUN_00469192(*(undefined4 *)(*param_1 + 4));
    iVar1 = *param_1;
    *(int *)(iVar1 + 8) = iVar1;
    *(undefined4 *)(iVar1 + 4) = 0;
    param_1[1] = 0;
    *(int *)(iVar1 + 0xc) = iVar1;
  }
  return;
}

