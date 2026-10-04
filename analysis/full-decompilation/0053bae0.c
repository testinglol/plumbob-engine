
void __thiscall FUN_0053bae0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar1 = *param_1;
    iVar2 = param_1[0x46];
  }
  else if (param_2 == 1) {
    iVar1 = *param_1;
    iVar2 = param_1[0x47];
  }
  else if (param_2 == 2) {
    iVar1 = *param_1;
    iVar2 = param_1[0x48];
  }
  else {
    if (param_2 != 3) {
      return;
    }
    iVar1 = *param_1;
    iVar2 = param_1[0x49];
  }
  (**(code **)(iVar1 + 300))(1,iVar2);
  return;
}

