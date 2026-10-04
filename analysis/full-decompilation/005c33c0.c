
void __thiscall FUN_005c33c0(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    FUN_005c33c0(0);
  }
  else {
    iVar1 = param_1[1];
    if ((param_2 != iVar1) && (iVar1 != 0)) {
      thunk_FUN_005b8770();
      FUN_006321f0(iVar1);
    }
  }
  param_1[1] = param_2;
  *param_1 = 1;
  return;
}

