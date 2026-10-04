
void __thiscall FUN_0049290f(int param_1)

{
  int in_stack_00000010;
  
  if (((byte)*(undefined4 *)(param_1 + 0x2c) & 0xf) != 1) {
    if (((*(int *)(param_1 + 0x38) == 2) || (*(int *)(param_1 + 0x38) == 3)) &&
       ((*(byte *)(in_stack_00000010 + 0x11) & 1) != 0)) {
      FUN_004929ee();
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return;
}

