
void __thiscall FUN_004cfca7(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x220) = param_2;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x228) = DAT_006f0eb0;
    uVar1 = DAT_006f0eb4;
  }
  else if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x228) = DAT_006f0ea8;
    uVar1 = DAT_006f0eac;
  }
  else {
    if (param_2 != 2) goto LAB_004cfcf6;
    *(undefined4 *)(param_1 + 0x228) = DAT_006f0ea0;
    uVar1 = DAT_006f0ea4;
  }
  *(undefined4 *)(param_1 + 0x22c) = uVar1;
LAB_004cfcf6:
  *(byte *)(param_1 + 0xe) = *(byte *)(param_1 + 0xe) | 0x20;
  return;
}

