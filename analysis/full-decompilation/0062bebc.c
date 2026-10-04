
undefined4 __fastcall FUN_0062bebc(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24ac);
  if (*(int *)(param_1 + 0x24a4) == 0) {
    uVar1 = *(uint *)(param_1 + 0x4a3c);
  }
  else {
    uVar1 = *(uint *)((*(int *)(param_1 + 0x24ac) >> 3) + *(int *)(param_1 + 0x24a4));
    uVar1 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  }
  iVar2 = FUN_0062bceb(uVar1);
  if (iVar2 == -1) {
    uVar3 = 0xffffffff;
  }
  else {
    *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + 0x20;
    *(int *)(param_1 + 0x24ac) = *(int *)(param_1 + 0x24a8) + *(int *)(param_1 + 0x2498) * 8;
    uVar3 = 0;
  }
  return uVar3;
}

