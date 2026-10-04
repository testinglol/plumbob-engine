
int __thiscall FUN_00608a5c(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    param_2 = 0;
  }
  else {
    iVar1 = FUN_00608ca3(param_2);
    if (iVar1 == 0) {
      param_2 = param_1[8] * param_2;
    }
    else {
      uVar2 = FUN_00608aa7(param_2);
      if ((uint)param_1[10] <= uVar2) {
        uVar2 = 0;
      }
      param_2 = param_1[9] * uVar2 + param_1[8] * 0x100;
    }
    param_2 = param_1[1] + param_2;
  }
  return param_2;
}

