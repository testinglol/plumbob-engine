
void __thiscall FUN_00406d9f(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_004659fc(0);
  iVar1 = (**(code **)*param_3)();
  if (iVar1 == 0) {
    FUN_0046f847(s_anonymous_0_006c0ed4,0xffffffff);
  }
  piVar2 = (int *)(param_1 + 0xc);
  do {
    if ((int *)*piVar2 == (int *)0x0) {
      return;
    }
    (**(code **)(*(int *)*piVar2 + 0x5c))(param_2,param_3);
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 5;
  } while (iVar3 < 8);
  return;
}

