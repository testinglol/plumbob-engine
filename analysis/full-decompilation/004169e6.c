
int * __thiscall FUN_004169e6(int *param_1,int param_2)

{
  int *piVar1;
  
  FUN_0046f824(param_1 + 4,0,0x100);
  param_1[1] = (int)&PTR_FUN_00666524;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  *param_1 = param_2;
  piVar1 = &DAT_006c1f88;
  do {
    if (*piVar1 == param_2) {
      param_1[0x45] = (int)piVar1;
    }
    piVar1 = piVar1 + 2;
  } while ((int)piVar1 < 0x6c1fe0);
  return param_1;
}

