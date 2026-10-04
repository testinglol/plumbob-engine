
void __thiscall FUN_00512ace(int param_1,int param_2,int param_3,undefined4 param_4)

{
  if ((param_2 < 5) || ((*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) + -5 <= param_2)) {
    if ((param_3 < 5) || ((*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -5 <= param_3)) {
      *(undefined4 *)(param_1 + 0x120) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x120) = 2;
    }
  }
  else if ((param_3 < 5) || ((*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80)) + -5 <= param_3))
  {
    *(undefined4 *)(param_1 + 0x120) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0x120) = 0;
    FUN_005de4fd(param_2,param_3,param_4);
  }
  return;
}

