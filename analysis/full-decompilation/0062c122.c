
undefined4 __thiscall FUN_0062c122(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((char)param_1[0x128e] != '\0') {
    FUN_0062c20f();
  }
  *(undefined1 *)(param_1 + 0x128e) = 1;
  param_1[0x929] = param_2;
  if (param_2 == 0) {
    FUN_00634c51(s_CMpegBase__Open__p___d____ERROR__006da774,0,param_3);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 8))();
    if (iVar1 == 0) {
      FUN_0062bcc7();
      FUN_0062bf4f();
      FUN_0062c1e8();
      iVar1 = FUN_0062c1da(param_1[0x1288] + param_3,param_1[0x128b],
                           (param_1[0x1289] * param_1[0x128b] + param_1[0x128a]) * param_1[0x1288]);
      param_1[0x928] = iVar1;
      param_1[0x92c] = param_1[0x923] * iVar1;
      return 0;
    }
    FUN_00634c51(s_CMpegBase__Open_GetHeader___fail_006da750);
  }
  return 0xffffffff;
}

