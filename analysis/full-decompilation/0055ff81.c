
int * __fastcall FUN_0055ff81(int *param_1)

{
  int iVar1;
  
  *param_1 = *param_1 + 1;
  if (*param_1 < param_1[1]) {
    param_1[2] = param_1[2] + 1;
    FUN_0054b822(param_1[2],param_1 + 3);
    iVar1 = param_1[4];
    while( true ) {
      iVar1 = FUN_00635845(iVar1,&DAT_006c16d8);
      if (iVar1 != 0) break;
      param_1[2] = param_1[2] + 1;
      FUN_0054b822(param_1[2],param_1 + 3);
      iVar1 = param_1[4];
    }
    FUN_0063558d(iVar1);
  }
  return param_1;
}

