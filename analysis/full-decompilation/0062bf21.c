
bool __fastcall FUN_0062bf21(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(uint **)(param_1 + 0x24a4) == (uint *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x4a3c);
  }
  else {
    uVar1 = **(uint **)(param_1 + 0x24a4);
  }
  iVar2 = FUN_0062bceb(uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                       uVar1 << 0x18);
  return iVar2 == -1;
}

