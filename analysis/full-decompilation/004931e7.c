
void __fastcall FUN_004931e7(int *param_1)

{
  int iVar1;
  
  if ((param_1[1] == 0) && (FUN_004931c9(), param_1[1] != 1)) {
    return;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  param_1[1] = (iVar1 != 0) + 2;
  return;
}

