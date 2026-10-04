
int __thiscall FUN_00540fd1(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  if ((iVar2 == param_1[2]) || (param_2 != iVar2)) {
    FUN_0054113b(param_2,param_3);
  }
  else {
    FUN_00541926(iVar2,param_3);
    param_1[1] = param_1[1] + 4;
  }
  return *param_1 + (param_2 - iVar1 >> 2) * 4;
}

