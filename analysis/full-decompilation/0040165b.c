
void __fastcall FUN_0040165b(int *param_1)

{
  int iVar1;
  
  if ((int *)*param_1 != (int *)0x0) {
    iVar1 = *(int *)*param_1;
    param_1[2] = 0;
    param_1[1] = iVar1;
    return;
  }
  param_1[1] = 0;
  param_1[2] = -1;
  return;
}

