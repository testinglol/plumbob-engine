
undefined4 __thiscall FUN_004a0d36(int *param_1,uint *param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  uint local_8;
  
  local_8 = 0xffffffff;
  uVar1 = *param_2;
  iVar2 = *param_1;
  local_10 = 0xffff;
  iVar3 = *(int *)(iVar2 + 8);
  while (iVar3 != iVar2) {
    if (((param_3 == '\0') || (*(int *)(iVar3 + 0x10) < 0xff)) &&
       ((*(uint *)(*(int *)(iVar3 + 0x14) + 0x2c) & 0xff) == (uVar1 & 0xff))) {
      uVar5 = *(uint *)(*(int *)(iVar3 + 0x14) + 0x2c);
      iVar6 = (uVar5 >> 0x18) - (uVar1 >> 0x18);
      iVar4 = (uVar5 >> 8 & 0xff) - (uVar1 >> 8 & 0xff);
      iVar7 = (uVar5 >> 0x10 & 0xff) - (uVar1 >> 0x10 & 0xff);
      uVar5 = iVar4 * iVar4 + iVar7 * iVar7 + iVar6 * iVar6;
      if (uVar5 < local_8) {
        local_10 = *(undefined4 *)(iVar3 + 0x10);
        local_8 = uVar5;
      }
    }
    FUN_0041674f();
  }
  return local_10;
}

