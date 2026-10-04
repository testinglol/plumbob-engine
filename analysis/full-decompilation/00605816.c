
undefined4 __thiscall FUN_00605816(int param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = param_2[1];
  _memset((undefined4 *)(param_1 + 0xf4),0,100);
  *(undefined4 *)(param_1 + 0xf4) = 100;
  cVar2 = (**(code **)(*DAT_006fefd8 + 0x34))();
  if (cVar2 == '\0') {
    *(undefined4 *)(param_1 + 0x158) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x158) = 0x200;
  }
  if ((uVar1 & 2) != 0) {
    *(byte *)(param_1 + 0x15a) = *(byte *)(param_1 + 0x15a) | 1;
    *(undefined4 *)(param_1 + 0x150) = *param_2;
    *(undefined4 *)(param_1 + 0x154) = *param_2;
  }
  if ((uVar1 & 4) != 0) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x800;
    *(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) | 2;
  }
  if ((uVar1 & 8) != 0) {
    *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) | 0x800;
    *(uint *)(param_1 + 0xf8) = *(uint *)(param_1 + 0xf8) | 4;
  }
  return 0x801;
}

