
void __thiscall
FUN_0053bb44(uint *param_1,byte *param_2,byte param_3,byte param_4,byte param_5,byte param_6)

{
  *param_1 = (uint)*param_2;
  param_1[1] = (uint)param_2[1];
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)((int)param_1 + 10) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(param_2 + 6);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)(param_2 + 10);
  if ((*param_1 & 0x10) == 0) {
    *(undefined2 *)((int)param_1 + 0x1e) = 0;
    *(undefined2 *)(param_1 + 7) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_2 + 10);
    *(undefined2 *)((int)param_1 + 0x1e) = *(undefined2 *)(param_2 + 0xc);
  }
  if ((*param_1 & 0x20) == 0) {
    *(undefined2 *)((int)param_1 + 0x22) = 0;
    *(undefined2 *)(param_1 + 8) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 10);
    *(undefined2 *)((int)param_1 + 0x22) = *(undefined2 *)(param_2 + 0xc);
  }
  param_1[9] = 0;
  param_1[10] = (((param_4 & 1) << 1 | param_3 & 1) << 1 | param_6 & 1) << 1 | param_5 & 1 | 0x10 |
                param_1[10] & 0xfffffff0;
  return;
}

