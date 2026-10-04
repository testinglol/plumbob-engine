
void FUN_004b8a0b(int param_1,int param_2,byte *param_3,byte param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_c;
  
  local_c = 0;
  bVar1 = param_3[1];
  uVar5 = (uint)*param_3;
  iVar3 = ((uint)bVar1 - (uint)param_3[3]) + 4;
  iVar2 = 8 << (param_4 & 0x1f);
  iVar6 = (uVar5 - param_3[3]) + 2;
  iVar4 = param_2 - (uVar5 << (param_4 + 1 & 0x1f));
  if (0 < iVar2) {
    do {
      FUN_004b8af8(local_c + param_1,iVar4,iVar6,0);
      local_c = local_c + 4;
      iVar4 = iVar4 - ((bVar1 - uVar5) + 2);
      iVar6 = iVar6 + iVar3;
    } while (local_c < iVar2);
  }
  uVar5 = (uint)param_3[2];
  bVar1 = param_3[1];
  iVar6 = (uVar5 - param_3[3]) + 2;
  param_3 = (byte *)(param_2 - (uVar5 << (param_4 + 1 & 0x1f)));
  iVar4 = (0x10 << (param_4 & 0x1f)) + -4;
  if (iVar2 <= iVar4) {
    param_1 = iVar4 + param_1;
    _param_4 = (iVar4 - iVar2) + 4U >> 2;
    do {
      FUN_004b8af8(param_1,param_3,iVar6,0);
      param_3 = (byte *)((int)param_3 - ((bVar1 - uVar5) + 2));
      iVar6 = iVar6 + iVar3;
      param_1 = param_1 + -4;
      _param_4 = _param_4 - 1;
    } while (_param_4 != 0);
  }
  return;
}

