
void __thiscall
FUN_004a4fba(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(DAT_006f0bd4 * param_6 + param_7 * 2 + DAT_006f0bd0);
  puVar1 = (undefined4 *)(DAT_006f0bbc * param_6 + param_7 * 2 + DAT_006f0bcc);
  if (0 < param_2) {
    param_6 = param_2;
    do {
      *puVar1 = *(undefined4 *)(param_3 + (param_4 >> 8) * 8);
      puVar1[1] = *(undefined4 *)(param_3 + 4 + (param_4 >> 8) * 8);
      puVar1 = (undefined4 *)((int)puVar1 + DAT_006f0bbc);
      *puVar2 = *(undefined4 *)(param_1 + 0x18);
      puVar2[1] = *(undefined4 *)(param_1 + 0x1c);
      puVar2 = (undefined4 *)((int)puVar2 + DAT_006f0bd4);
      param_4 = param_4 + param_5;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

