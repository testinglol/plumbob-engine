
void __thiscall FUN_004a4e2a(int param_1,int param_2,int param_3,byte *param_4,byte param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_10;
  int local_c;
  int local_8;
  
  cVar6 = '\0';
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  uVar12 = (uint)*param_4;
  bVar1 = param_4[1];
  iVar7 = ((uint)bVar1 - (uint)param_4[3]) + 4;
  iVar13 = (uVar12 - param_4[3]) + 2;
  local_10 = param_3 - (uVar12 << (param_5 + 1 & 0x1f));
  bVar2 = *(byte *)(param_1 + 0xd);
  uVar8 = (uint)*(byte *)(param_1 + 0xc);
  bVar3 = *(byte *)(param_1 + 0xf);
  iVar5 = 8 << (param_5 & 0x1f);
  iVar11 = 0;
  local_c = uVar8 << 8;
  local_8 = local_c;
  if (0 < iVar5) {
    do {
      if (iVar13 == 0) {
        iVar9 = 0;
      }
      else {
        iVar9 = (local_c - local_8) / iVar13;
      }
      FUN_004a4fba(iVar13,uVar4,local_8,iVar9,local_10,iVar11 + param_2);
      cVar6 = cVar6 + '\x04';
      local_10 = local_10 - ((bVar1 - uVar12) + 2);
      local_8 = local_8 + ((int)((bVar2 - uVar8) * 0x100) >> (param_5 + 1 & 0x1f));
      iVar11 = (int)cVar6;
      iVar13 = iVar13 + iVar7;
      local_c = local_c + ((int)((bVar3 - uVar8) * 0x100) >> (param_5 + 1 & 0x1f));
    } while (iVar11 < iVar5);
  }
  uVar8 = (uint)param_4[2];
  bVar1 = param_4[1];
  iVar9 = (uVar8 - param_4[3]) + 2;
  param_3 = param_3 - (uVar8 << (param_5 + 1 & 0x1f));
  uVar12 = (uint)*(byte *)(param_1 + 0xe);
  bVar2 = *(byte *)(param_1 + 0xd);
  bVar3 = *(byte *)(param_1 + 0xf);
  iVar11 = uVar12 << 8;
  cVar6 = '\x10' << (param_5 & 0x1f);
  iVar13 = iVar11;
  while( true ) {
    cVar6 = cVar6 + -4;
    if (cVar6 < iVar5) break;
    iVar11 = iVar11 + ((int)((bVar3 - uVar12) * 0x100) >> (param_5 + 1 & 0x1f));
    iVar13 = iVar13 + ((int)((bVar2 - uVar12) * 0x100) >> (param_5 + 1 & 0x1f));
    if (iVar9 == 0) {
      iVar10 = 0;
    }
    else {
      iVar10 = (iVar11 - iVar13) / iVar9;
    }
    FUN_004a4fba(iVar9,uVar4,iVar13,iVar10,param_3,cVar6 + param_2);
    param_3 = param_3 - ((bVar1 - uVar8) + 2);
    iVar9 = iVar9 + iVar7;
  }
  return;
}

