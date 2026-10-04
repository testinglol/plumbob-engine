
int FUN_0041a318(int *param_1)

{
  int iVar1;
  
  if ((*param_1 != -1) && (iVar1 = FUN_0041a346(*param_1), iVar1 != 0)) {
    return iVar1;
  }
  if (param_1[3] != 0) {
    FUN_00420028(param_1[3]);
  }
  param_1[3] = 0;
  return 0;
}

