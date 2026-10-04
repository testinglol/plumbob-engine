
undefined4 __fastcall FUN_00579f5b(int *param_1)

{
  undefined4 uVar1;
  
  if ((int *)param_1[1] == (int *)0x0) {
    uVar1 = 1;
  }
  else {
    uVar1 = (**(code **)(*(int *)param_1[1] + 0x78))
                      ((((*(int *)(param_1[3] + 0x10) * *(int *)(*param_1 + 0x28)) / 0x400) *
                       *(int *)(*(int *)(*param_1 + 0x34) + 4)) / 0x400);
  }
  return uVar1;
}

