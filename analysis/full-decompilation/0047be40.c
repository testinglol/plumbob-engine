
int FUN_0047be40(int param_1,int param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 local_10;
  
  iVar5 = param_2;
  iVar4 = *(int *)(param_1 + 8);
  local_10 = 0;
  iVar6 = iVar4;
  if (0 < iVar4) {
    do {
      iVar10 = 0;
      do {
        iVar9 = iVar5 * 2;
        if (local_10 % (iVar5 * 2) == 0) {
          iVar6 = iVar10 / iVar9;
          if (iVar10 % iVar9 != 0) {
            pcVar7 = (char *)FUN_0047cc9a(local_10,iVar10 - iVar5);
            cVar1 = *pcVar7;
            iVar6 = local_10;
            iVar9 = iVar10 + iVar5;
LAB_0047be9d:
            param_2 = (int)cVar1;
            pcVar7 = (char *)FUN_0047cc9a(iVar6,iVar9);
            iVar9 = (*pcVar7 + param_2) / 2;
            goto LAB_0047bf3b;
          }
        }
        else {
          if (iVar10 % iVar9 == 0) {
            pcVar7 = (char *)FUN_0047cc9a(local_10 - iVar5,iVar10);
            cVar1 = *pcVar7;
            iVar6 = local_10 + iVar5;
            iVar9 = iVar10;
            goto LAB_0047be9d;
          }
          pcVar7 = (char *)FUN_0047cc9a(local_10 - iVar5,iVar10 - iVar5);
          cVar1 = *pcVar7;
          pcVar7 = (char *)FUN_0047cc9a(local_10 + iVar5,iVar10 - iVar5);
          cVar2 = *pcVar7;
          pcVar7 = (char *)FUN_0047cc9a(local_10 - iVar5,iVar10 + iVar5);
          cVar3 = *pcVar7;
          pcVar7 = (char *)FUN_0047cc9a(local_10 + iVar5,iVar10 + iVar5);
          iVar9 = ((int)*pcVar7 + (int)cVar1 + (int)cVar2 + (int)cVar3) / 4;
LAB_0047bf3b:
          uVar8 = FUN_0046f556();
          iVar9 = iVar9 + (uVar8 % param_3 - (int)param_3 / 2);
          if (iVar9 < -0x80) {
            iVar9 = -0x80;
          }
          else if (0x7f < iVar9) {
            iVar9 = 0x7f;
          }
          iVar6 = *(int *)(*(int *)(param_1 + 0xc) + local_10 * 4);
          *(char *)(iVar6 + iVar10) = (char)iVar9;
        }
        iVar10 = iVar10 + iVar5;
      } while (iVar10 < iVar4);
      local_10 = local_10 + iVar5;
    } while (local_10 < iVar4);
  }
  return iVar6;
}

