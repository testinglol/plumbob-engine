
uint __fastcall FUN_00457567(int param_1)

{
  int iVar1;
  uint uVar2;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0;
  uVar2 = 0xffffffff;
  if (*(short *)(*(int *)(param_1 + 0x60) + 0x72) != -1) {
    FUN_004318eb(&local_10,&local_c);
    iVar1 = FUN_0043ad41(param_1,local_10,local_c + -1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = 1;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + -1,local_c,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 2;
    }
    iVar1 = FUN_0043ad41(param_1,local_10,local_c + 1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 4;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + 1,local_c,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 8;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + -1,local_c + -1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 0x10;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + -1,local_c + 1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 0x20;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + 1,local_c + 1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 0x40;
    }
    iVar1 = FUN_0043ad41(param_1,local_10 + 1,local_c + -1,0);
    if ((iVar1 != 0) && (*(short *)(*(int *)(iVar1 + 0x60) + 0x72) != -1)) {
      local_8 = local_8 | 0x80;
    }
    uVar2 = local_8;
    if ((&DAT_006efc6c)[local_8 & 0xff] != '\x01') {
      local_8 = 0;
      uVar2 = local_8;
    }
  }
  return uVar2;
}

