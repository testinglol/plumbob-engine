
void FUN_004375cb(undefined4 param_1,undefined4 param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  char cVar3;
  undefined4 in_EAX;
  undefined2 uVar7;
  undefined2 extraout_var;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar8;
  undefined2 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  short local_14;
  short sStack_12;
  undefined2 local_10;
  undefined2 uStack_e;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar7 = (undefined2)((uint)in_EAX >> 0x10);
  if (DAT_006e4b3c == 0) {
    FUN_0043727f();
    uVar7 = extraout_var;
  }
  if ((DAT_006f0bcc != 0) && (-1 < param_3)) {
    FUN_00464479(&local_14,0,0,CONCAT22(uVar7,DAT_006c2aa2),CONCAT22(uVar7,DAT_006c2aa0));
    FUN_004643bc(&local_14,param_1,param_2);
    FUN_004643d8(&local_14,&DAT_006f0bc0,&local_14);
    cVar3 = FUN_004644a0(&local_14);
    if (cVar3 == '\0') {
      local_c = CONCAT22(sStack_12,local_14);
      local_8 = CONCAT22(uStack_e,local_10);
      FUN_004643bc(&local_c,CONCAT22((short)((uint)-local_c >> 0x10),param_3 * DAT_006c2aa2) -
                            CONCAT22(local_10,sStack_12),-local_c);
      iVar11 = (int)(short)local_c;
      iVar4 = (int)(short)local_8;
      if (*(int *)(DAT_006e486c + 0x34) == 0) {
        for (; iVar2 = DAT_006e4b38, iVar11 < iVar4; iVar11 = iVar11 + 1) {
          iVar8 = (int)local_c._2_2_;
          iVar4 = FUN_005d0a09();
          iVar5 = local_8._2_2_ - iVar8;
          iVar6 = (int)sStack_12 +
                  DAT_006f0bcc + (((int)local_14 - (int)(short)local_c) + iVar11) * DAT_006f0bbc;
          if (-1 < iVar5 + -1) {
            puVar10 = (undefined1 *)(iVar5 + -1 + iVar6);
            do {
              *puVar10 = puVar10[(iVar2 * iVar11 + iVar8 + iVar4) - iVar6];
              puVar10 = puVar10 + -1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          iVar4 = (int)(short)local_8;
        }
      }
      else {
        for (; iVar2 = DAT_006e4b38, iVar11 < iVar4; iVar11 = iVar11 + 1) {
          iVar12 = (int)local_c._2_2_;
          iVar5 = FUN_005d0a09();
          iVar4 = ((int)local_14 - (int)(short)local_c) + iVar11;
          iVar8 = DAT_006f0bcc + iVar4 * DAT_006f0bbc;
          iVar4 = DAT_006f0bd0 + ((DAT_006f0bd4 / 2) * iVar4 + (int)sStack_12) * 2;
          iVar6 = (local_8._2_2_ - iVar12) + -1;
          if (-1 < iVar6) {
            puVar9 = (undefined2 *)(iVar4 + iVar6 * 2);
            do {
              pbVar1 = (byte *)(iVar6 + iVar2 * iVar11 + iVar12 + iVar5);
              iVar6 = iVar6 + -1;
              *(undefined2 *)(((iVar8 + sStack_12 * 2) - iVar4) + (int)puVar9) =
                   *(undefined2 *)(*(int *)(DAT_006e486c + 0x14) + 0x420 + (uint)*pbVar1 * 2);
              *puVar9 = 1;
              puVar9 = puVar9 + -1;
            } while (-1 < iVar6);
          }
          iVar4 = (int)(short)local_8;
        }
      }
    }
  }
  return;
}

