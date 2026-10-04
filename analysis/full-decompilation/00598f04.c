
void __thiscall FUN_00598f04(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0x130) + 1;
  *(int *)(param_1 + 0x150) = *(int *)(param_1 + 0x150) + 1;
  *(undefined4 *)(param_1 + 0x30) = *param_2;
  uVar1 = param_2[2];
  *(undefined4 *)(param_1 + 0x34) = param_2[1];
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}

