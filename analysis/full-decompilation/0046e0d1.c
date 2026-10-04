
void __thiscall
FUN_0046e0d1(int param_1,undefined4 param_2,undefined4 param_3,int param_4,char param_5)

{
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_4;
  if (param_5 == '\0') {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
    *(int *)(param_1 + 0x20) = param_4 + -1;
  }
  return;
}

