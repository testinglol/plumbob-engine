
undefined4 * __thiscall FUN_0046be80(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  FUN_0046ba6b();
  uVar2 = FUN_0045741b();
  *param_1 = uVar2;
  uVar1 = *(undefined2 *)(param_2 + 0xf0);
  param_1[2] = 0xffffffff;
  *(undefined2 *)(param_1 + 3) = 0;
  param_1[4] = 0xffffffff;
  *(undefined2 *)(param_1 + 1) = uVar1;
  FUN_00636510(param_1 + 0x14,param_2 + 0x58c,0x200);
  return param_1;
}

