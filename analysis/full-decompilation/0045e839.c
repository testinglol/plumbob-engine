
void __thiscall FUN_0045e839(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0xa50) != 0) {
    FUN_0041edc1(param_1 + 0xa48);
    *(uint *)(param_1 + 0xacc) = *(uint *)(param_1 + 0xacc) & 0xffffffdf;
    if (*(char *)(param_1 + 0x20) != '\0') {
      *(uint *)(param_1 + 0xacc) = *(uint *)(param_1 + 0xacc) | 0x20;
    }
  }
  FUN_0041edc1(param_2);
  if (*(int *)(param_1 + 0xa50) != 0) {
    *(undefined2 *)(param_1 + 0x5d8) = 0;
    *(undefined2 *)(param_1 + 0x5da) = 0;
    if (*(int *)(param_1 + 0xa84) == 0) {
      FUN_0041f15a();
    }
  }
  *(short *)(param_1 + 0x5ce) = (short)*(undefined4 *)(param_1 + 0xa64);
  FUN_004609a6(*(undefined4 *)(param_1 + 0xad0),*(undefined4 *)(param_1 + 0xad4));
  if (*(short *)(param_1 + 0x61e) != 0) {
    *(undefined2 *)(param_1 + 0x61e) = 0;
    FUN_00433dbb(param_1 + 0xf4,param_1 + 0x100);
  }
  *(undefined2 *)(param_1 + 0x61c) = 0;
  *(undefined2 *)(param_1 + 0x61a) = 0;
  return;
}

