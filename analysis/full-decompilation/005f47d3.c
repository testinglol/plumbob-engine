
void __thiscall FUN_005f47d3(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0xd4) = *param_2;
    *(undefined4 *)(param_1 + 0xd8) = param_2[1];
    *(undefined4 *)(param_1 + 0xdc) = param_2[2];
    *(undefined4 *)(param_1 + 0xe0) = param_2[3];
    FUN_005d499c(param_2 + 4);
    *(undefined4 *)(param_1 + 0xfc) = param_2[7];
    *(undefined4 *)(param_1 + 0x100) = param_2[8];
    *(undefined4 *)(param_1 + 300) = param_2[9];
    *(undefined4 *)(param_1 + 0x140) = param_2[10];
    *(undefined4 *)(param_1 + 0x144) = param_2[0xb];
    FUN_005f3a06(0);
  }
  return;
}

