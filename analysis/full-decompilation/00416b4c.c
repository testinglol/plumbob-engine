
void __thiscall FUN_00416b4c(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00416ad1();
  if (*(int *)(param_1 + 0x110) != 0) {
    uVar1 = FUN_004705f2(param_2 + 1,0xffffffff);
    FUN_0046f8cb(uVar1);
  }
  iVar2 = (**(code **)*param_3)();
  if (iVar2 == 0) {
    FUN_0046f847(s_Icon_006c1fe8,0xffffffff);
    FUN_0046fa40(param_2);
  }
  return;
}

