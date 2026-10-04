
undefined4 __thiscall FUN_004c7929(int param_1,short *param_2)

{
  int iVar1;
  
  if ((*(short *)(param_1 + 8) < param_2[2]) && (*(short *)(param_1 + 10) < param_2[3])) {
    if ((param_2[1] < *(short *)(param_1 + 0xe)) && (*param_2 < *(short *)(param_1 + 0xc))) {
      iVar1 = (int)param_2[1] - (int)*(short *)(param_1 + 10);
      *(int *)(param_1 + 0x1c) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x1c) = 0;
      }
      iVar1 = (int)*(short *)(param_1 + 0xe) - (int)param_2[3];
      *(int *)(param_1 + 0x20) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x20) = 0;
      }
      iVar1 = (int)*param_2 - (int)*(short *)(param_1 + 8);
      *(int *)(param_1 + 0x24) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      iVar1 = (int)*(short *)(param_1 + 0xc) - (int)param_2[2];
      *(int *)(param_1 + 0x28) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x28) = 0;
      }
      return 0;
    }
  }
  return 1;
}

