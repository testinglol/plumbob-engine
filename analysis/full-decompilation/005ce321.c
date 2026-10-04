
char * __thiscall FUN_005ce321(char *param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != param_2) {
    if (*param_1 != *param_2) {
      *param_1 = *param_2;
      param_1[0x28] = '\x01';
    }
    if (param_1[1] != param_2[1]) {
      param_1[1] = param_2[1];
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 4) != *(int *)(param_2 + 4)) {
      *(int *)(param_1 + 4) = *(int *)(param_2 + 4);
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 8) != *(int *)(param_2 + 8)) {
      *(int *)(param_1 + 8) = *(int *)(param_2 + 8);
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 0xc) != *(int *)(param_2 + 0xc)) {
      *(int *)(param_1 + 0xc) = *(int *)(param_2 + 0xc);
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
      *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10);
      param_1[0x28] = '\x01';
    }
    if (param_1[0x14] != param_2[0x14]) {
      param_1[0x14] = param_2[0x14];
      param_1[0x28] = '\x01';
    }
    if (param_1[0x15] != param_2[0x15]) {
      param_1[0x15] = param_2[0x15];
      param_1[0x28] = '\x01';
    }
    if (param_1[0x16] != param_2[0x16]) {
      param_1[0x16] = param_2[0x16];
      param_1[0x28] = '\x01';
    }
    if (param_1[0x17] != param_2[0x17]) {
      param_1[0x17] = param_2[0x17];
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 0x18) != *(int *)(param_2 + 0x18)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_2 + 0x18);
      param_1[0x28] = '\x01';
    }
    if (*(int *)(param_1 + 0x1c) != *(int *)(param_2 + 0x1c)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_2 + 0x1c);
      param_1[0x28] = '\x01';
    }
    if (*(float *)(param_1 + 0x20) != *(float *)(param_2 + 0x20)) {
      uVar1 = *(undefined4 *)(param_2 + 0x20);
      param_1[0x28] = '\x01';
      *(undefined4 *)(param_1 + 0x20) = uVar1;
    }
    if (*(float *)(param_1 + 0x24) != *(float *)(param_2 + 0x24)) {
      uVar1 = *(undefined4 *)(param_2 + 0x24);
      param_1[0x28] = '\x01';
      *(undefined4 *)(param_1 + 0x24) = uVar1;
    }
  }
  return param_1;
}

