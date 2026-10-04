
void __thiscall FUN_0060730b(int *param_1,int param_2)

{
  int iVar1;
  
  if (*param_1 != param_2) {
    *param_1 = param_2;
    if ((param_2 == 0) && (param_1[6] == 0)) {
      iVar1 = FUN_005fd96f();
      param_1[6] = iVar1;
    }
    param_1[4] = 0;
    param_1[2] = 0;
    param_1[5] = 0;
    param_1[3] = 0;
  }
  return;
}

