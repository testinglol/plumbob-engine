
undefined4 __thiscall FUN_00535a39(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  local_c = param_1;
  local_8 = param_1;
  if (param_2 == 0x26) {
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
    uVar2 = 0x12;
    if (*(int *)(param_1 + 0xe0) < 0x13) goto LAB_00535a83;
  }
  else {
    if (param_2 != 0x28) {
      uVar2 = FUN_005dd72f(param_2,param_3);
      return uVar2;
    }
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + -1;
    uVar2 = 7;
    if (6 < *(int *)(param_1 + 0xe0)) goto LAB_00535a83;
  }
  *(undefined4 *)(param_1 + 0xe0) = uVar2;
LAB_00535a83:
  piVar1 = *(int **)(DAT_006e486c + 4);
  uVar2 = (**(code **)(*piVar1 + 0x38))();
  (**(code **)*piVar1)
            (&param_2,*(undefined4 *)(param_1 + 0xd4),*(undefined4 *)(param_1 + 0xd8),uVar2,
             DAT_006f0088,0);
  local_c = (int)param_2._2_2_;
  local_8 = (int)(short)param_2;
  FUN_00535baf(&local_c,0);
  return 1;
}

