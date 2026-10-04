
void __thiscall FUN_00401aae(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == -1) {
    FUN_004018ec();
  }
  else {
    if (param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_00401742(param_2);
    }
    *param_1 = iVar1;
    param_1[1] = iVar1;
    param_1[2] = iVar1 + param_2;
  }
  return;
}

