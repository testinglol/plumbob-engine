
undefined4 __thiscall FUN_00599121(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < (uint)(*(int *)(param_1 + 0x74) - *(int *)(param_1 + 0x70) >> 2)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x70) + param_2 * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

