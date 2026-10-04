
void __thiscall FUN_00523724(int param_1,undefined4 param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_1 + 300) = param_2;
  if (param_3 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x130) = *param_3;
    *(undefined4 *)(param_1 + 0x134) = param_3[1];
    *(undefined4 *)(param_1 + 0x138) = param_3[2];
    *(undefined4 *)(param_1 + 0x13c) = param_3[3];
  }
  if (((*(int *)(param_1 + 300) == 1) || (*(int *)(param_1 + 300) == 2)) &&
     (param_3 == (undefined4 *)0x0)) {
    *(undefined4 *)(param_1 + 300) = 0;
  }
  return;
}

