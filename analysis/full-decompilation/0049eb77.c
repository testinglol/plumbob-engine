
undefined4 FUN_0049eb77(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00401742(param_1 << 2);
  }
  FUN_00635190(uVar1,param_2,(param_3 - param_2 >> 2) << 2);
  return uVar1;
}

