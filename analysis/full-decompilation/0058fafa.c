
void __fastcall FUN_0058fafa(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(short *)(*(int *)(param_1 + 0x138) + 0x5c8);
  if ((uVar2 & 0x80) != 0) {
    uVar2 = 0x7f;
  }
  if ((uVar2 == 0) || (uVar2 == 0x80)) {
    if (*(int *)(param_1 + 0x250) != 0) {
      FUN_00599480(*(int *)(param_1 + 0x250));
      *(undefined4 *)(param_1 + 0x250) = 0;
      *(undefined4 *)(param_1 + 0x254) = 0;
    }
  }
  else if ((*(uint *)(param_1 + 0x254) != uVar2) || (*(int *)(param_1 + 0x250) == 0)) {
    if (*(int *)(param_1 + 0x250) != 0) {
      FUN_00599480(*(int *)(param_1 + 0x250));
      *(undefined4 *)(param_1 + 0x250) = 0;
      *(undefined4 *)(param_1 + 0x254) = 0;
    }
    uVar1 = FUN_0059943e(*(undefined4 *)(param_1 + 0x24c),0,0,uVar2);
    *(undefined4 *)(param_1 + 0x250) = uVar1;
    *(uint *)(param_1 + 0x254) = uVar2;
  }
  return;
}

