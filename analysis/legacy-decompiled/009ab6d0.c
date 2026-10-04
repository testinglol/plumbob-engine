
undefined4 * __thiscall
FUN_009ab6d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00c4e897;
  local_10 = ExceptionList;
  uVar1 = DAT_00dd0b80 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = cTSFont::vftable;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0xffffffff;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[2] = param_4;
  local_8 = 1;
  uStack_7 = 0;
  param_1[1] = 5;
  param_1[10] = 0x100;
  param_1[6] = 1;
  param_1[3] = param_5;
  param_1[4] = 0;
  *(undefined1 *)((int)param_1 + 0x22) = 0;
  param_1[5] = 0xffffffff;
  iVar2 = FUN_00a30d62(0x18,uVar1);
  _local_8 = CONCAT31(uStack_7,2);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00960050(param_2);
  }
  param_1[0x20] = uVar3;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  *(undefined1 *)((int)param_1 + 0x23) = 1;
  ExceptionList = local_10;
  return param_1;
}

