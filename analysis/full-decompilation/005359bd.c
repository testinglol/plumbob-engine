
undefined4 __thiscall FUN_005359bd(int param_1,undefined4 param_2)

{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  sVar2 = (short)param_2;
  if (((char)param_2 == 'r') || ((char)param_2 == 'R')) {
    *(bool *)(param_1 + 0xf0) = *(char *)(param_1 + 0xf0) == '\0';
    piVar1 = *(int **)(DAT_006e486c + 4);
    param_2._0_2_ = sVar2;
    local_c = param_1;
    local_8 = param_1;
    uVar3 = (**(code **)(*piVar1 + 0x38))();
    (**(code **)*piVar1)
              (&param_2,*(undefined4 *)(param_1 + 0xd4),*(undefined4 *)(param_1 + 0xd8),uVar3,
               DAT_006f0088,0);
    local_c = (int)param_2._2_2_;
    local_8 = (int)(short)param_2;
    FUN_00535baf(&local_c,0);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

