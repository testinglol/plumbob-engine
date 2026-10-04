
undefined4 __thiscall FUN_0046d3de(int param_1,short param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0x87) {
    if (*(int *)(param_1 + 0x1a8) == param_3) {
      *(int *)(param_1 + 0x1a8) = *(int *)(param_1 + 0x1a8) + 1;
    }
  }
  else if (param_2 == 0xd1) {
    FUN_0046cfd5(*(undefined4 *)(param_1 + 0xb0));
  }
  else if (param_2 == 0xde) {
    iVar1 = 999999;
    if (*(short *)(param_1 + 0x50) != 1) {
      iVar1 = *(int *)(param_1 + 0x90);
    }
    FUN_0046d9f8(iVar1 + param_3);
  }
  else if (param_2 == 0xe4) {
    *(undefined2 *)(param_1 + 0x16) = (undefined2)param_3;
  }
  else {
    if (param_2 != 0xf9) {
      return 0;
    }
    *(undefined2 *)(param_1 + 0x14) = (undefined2)param_3;
  }
  return 1;
}

