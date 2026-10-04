
void __thiscall FUN_004b3938(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2[5];
  *(undefined4 *)(param_1 + 0x2c) = param_2[6];
  *(undefined4 *)(param_1 + 0x30) = param_2[7];
  *(undefined4 *)(param_1 + 0x34) = param_2[8];
  *(undefined1 *)(param_1 + 0x48) = *(undefined1 *)(param_2 + 9);
  *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)((int)param_2 + 0x25);
  *(undefined1 *)(param_1 + 0x1f8) = *(undefined1 *)((int)param_2 + 0x26);
  FUN_004a7da6(*param_2,0,0);
  FUN_004a8012(param_2[1],0,0);
  FUN_004a82db(param_2[2],0);
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  FUN_004a83dc(param_2[3],param_2[4],1);
  *(undefined1 *)(param_1 + 0x4e) = 1;
  FUN_004a7d36();
  return;
}

