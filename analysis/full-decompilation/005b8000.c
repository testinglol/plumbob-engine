
void FUN_005b8000(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((&DAT_006d24ac)[param_1 * 3] != 0) {
    if (DAT_006fd8ec == 0) {
      FUN_005b7ed0();
    }
    FUN_005b8050(param_1,param_2);
    iVar1 = FUN_006384a8("PRINT_DEVICE");
    if (iVar1 != 0) {
      FUN_005b8080(iVar1);
    }
  }
  return;
}

