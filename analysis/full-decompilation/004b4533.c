
undefined4 * __thiscall FUN_004b4533(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  puVar3 = param_1;
  for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)((int)param_1 + 0x35) = 0;
  param_1[6] = param_2;
  *(undefined1 *)((int)param_1 + 0x36) = 0;
  uVar1 = (**(code **)(*param_2 + 0xc))();
  param_1[0xb] = uVar1;
  uVar1 = (**(code **)(*param_2 + 0x10))();
  param_1[0xc] = uVar1;
  iVar2 = (**(code **)(*param_2 + 0x18))();
  param_1[7] = iVar2 << 1;
  uVar1 = (**(code **)(*param_2 + 0x14))();
  param_1[8] = uVar1;
  (**(code **)(*(int *)param_1[6] + 0x20))(param_1 + 0xf,param_1 + 0x10);
  uVar1 = (**(code **)(*param_2 + 0x24))();
  param_1[0x11] = uVar1;
  *(undefined1 *)((int)param_1 + 0x39) = 0;
  param_1[0x12] = 0x3f000000;
  *(undefined1 *)(param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0x37) = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  uVar1 = (**(code **)(*param_2 + 0x34))();
  param_1[0x13] = uVar1;
  FUN_004b463f(0,0xf,1);
  FUN_004b463f(1,1,1);
  FUN_004b463f(1,2,1);
  return param_1;
}

