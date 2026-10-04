
undefined4 FUN_005f7d54(char *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  _memset(param_2,0,0x14);
  if ((*param_1 == -1) && (bVar1 = param_1[1], (bVar1 & 0xe0) == 0xe0)) {
    uVar8 = bVar1 >> 3 & 3;
    if ((uVar8 != 1) && ((bVar1 >> 1 & 3) != 0)) {
      bVar2 = param_1[2];
      if ((bVar2 >> 4 != 0xf) && (uVar9 = bVar2 >> 2 & 3, uVar9 != 3)) {
        uVar5 = bVar2 >> 1 & 1;
        bVar3 = param_1[3];
        if ((bVar1 >> 3 & 3) != 0) {
          uVar8 = uVar8 - 1;
        }
        uVar6 = (uint)((int)uVar8 < 2);
        iVar11 = 4 - (bVar1 >> 1 & 3);
        iVar4 = *(int *)(&DAT_0067606c + (uVar9 + uVar8 * 3) * 4);
        if (iVar11 == 1) {
          iVar10 = 0x180;
          iVar7 = (((int)(&PTR_LAB_00675ec8)[(iVar11 + uVar6 * 3) * 0xf + (uint)(bVar2 >> 4)] *
                   12000) / iVar4 + uVar5) * 4;
        }
        else {
          iVar7 = ((int)(&PTR_LAB_00675ec8)[(iVar11 + uVar6 * 3) * 0xf + (uint)(bVar2 >> 4)] *
                  0x23280) / iVar4;
          if ((iVar11 == 3) && (uVar6 != 0)) {
            iVar7 = iVar7 >> 1;
          }
          iVar7 = iVar7 + uVar5;
          if ((iVar11 != 3) || (iVar10 = 0x240, uVar6 == 0)) {
            iVar10 = 0x480;
          }
        }
        param_2[1] = iVar7;
        *param_2 = iVar11;
        param_2[2] = iVar10;
        param_2[4] = iVar4;
        param_2[3] = (bVar3 >> 6 != 3) + 1;
        return 0;
      }
    }
  }
  return 0xffffffff;
}

