
void __thiscall FUN_004ffa7e(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x108) = param_2;
  if ((((*(int *)(param_1 + 0x7c) == *(int *)(param_1 + 0xd8)) &&
       (*(int *)(param_1 + 0x84) == *(int *)(param_1 + 0xe0))) &&
      (*(int *)(param_1 + 0x80) == *(int *)(param_1 + 0xdc))) &&
     (*(int *)(param_1 + 0x88) == *(int *)(param_1 + 0xe4))) {
    *(undefined4 *)(param_1 + 0x100) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x100) = 5;
  }
  return;
}

