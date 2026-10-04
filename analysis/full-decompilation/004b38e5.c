
void __thiscall FUN_004b38e5(int param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  *param_2 = DAT_006f0088;
  uVar2 = DAT_006f008c;
  param_2[5] = *(undefined4 *)(param_1 + 0x28);
  param_2[1] = uVar2;
  param_2[2] = *(undefined4 *)(param_1 + 0x18);
  uVar2 = DAT_006f0080;
  param_2[6] = *(undefined4 *)(param_1 + 0x2c);
  param_2[3] = uVar2;
  uVar2 = DAT_006f0084;
  param_2[7] = *(undefined4 *)(param_1 + 0x30);
  param_2[4] = uVar2;
  *(undefined1 *)(param_2 + 9) = *(undefined1 *)(param_1 + 0x48);
  uVar1 = *(undefined1 *)(param_1 + 0x1f8);
  *(undefined1 *)((int)param_2 + 0x25) = *(undefined1 *)(param_1 + 0x49);
  param_2[8] = *(undefined4 *)(param_1 + 0x34);
  *(undefined1 *)((int)param_2 + 0x26) = uVar1;
  return;
}

