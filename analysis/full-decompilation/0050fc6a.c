
void __thiscall FUN_0050fc6a(int *param_1,int param_2)

{
  int iVar1;
  
  if (((param_1[0x43] != 0) && (iVar1 = *(int *)(param_1[0x43] + 0x14), iVar1 != 0)) &&
     ((param_2 == 0 || (iVar1 != *(int *)(param_2 + 0x14))))) {
    FUN_005107a3(0);
  }
  param_1[0x43] = param_2;
  if (param_2 != 0) {
    FUN_005107a3(param_1);
  }
  FUN_0050fcbb();
  (**(code **)(*param_1 + 0x168))();
  return;
}

