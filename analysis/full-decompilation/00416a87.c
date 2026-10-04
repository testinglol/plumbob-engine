
void __thiscall FUN_00416a87(short *param_1,undefined4 *param_2)

{
  int iVar1;
  
  FUN_00465b21(param_2,*(undefined4 *)(DAT_006e486c + 0xc),500,*param_1 + 1);
  iVar1 = (**(code **)*param_2)();
  if (iVar1 == 0) {
    FUN_0046f847(s_Group_006c1fe0,0xffffffff);
    FUN_0046fa40(*(undefined4 *)param_1);
  }
  return;
}

