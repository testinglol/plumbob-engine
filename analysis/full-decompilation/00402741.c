
int FUN_00402741(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  uint local_14;
  undefined4 local_10 [2];
  undefined1 local_5;
  
  if ((DAT_006de5dc & 1) == 0) {
    DAT_006de5dc = DAT_006de5dc | 1;
    FUN_0055e4e2(&local_5);
    FUN_00635543(&LAB_004028e0);
  }
  if ((DAT_006de5dc & 2) == 0) {
    DAT_006de5dc = DAT_006de5dc | 2;
    FUN_0055e4e2(&local_5);
    FUN_00635543(&LAB_004028d6);
  }
  FUN_005bd82a(DAT_006de5d0,DAT_006de5d4);
  FUN_005bd82a(DAT_006de5c0,DAT_006de5c4);
  FUN_004029df(&param_1);
  uVar2 = DAT_006de5d4 - DAT_006de5d0;
  psVar8 = DAT_006de5c4;
  iVar5 = DAT_006de5d0;
  while ((uVar2 & 0xfffffffe) != 0) {
    sVar1 = *(short *)(iVar5 + -2 + ((int)uVar2 >> 1) * 2);
    local_10[0] = CONCAT22((short)((int)uVar2 >> 0x11),sVar1);
    DAT_006de5d4 = DAT_006de5d4 + -2;
    for (psVar6 = DAT_006de5c0; (psVar6 != psVar8 && (*psVar6 != sVar1)); psVar6 = psVar6 + 1) {
    }
    if (psVar6 == psVar8) {
      FUN_004029df(local_10);
      iVar3 = FUN_0040204f(local_10[0]);
      iVar7 = 0;
      iVar5 = DAT_006de5d0;
      psVar8 = DAT_006de5c4;
      if ((iVar3 != 0) && (0 < *(short *)(iVar3 + 2))) {
        do {
          puVar4 = (undefined2 *)FUN_004020a6(local_10[0],iVar7);
          uVar2 = CONCAT22((short)((uint)puVar4 >> 0x10),*puVar4) & 0xffff7fff;
          if (0xff < (ushort)uVar2) {
            local_14 = uVar2;
            FUN_004029df(&local_14);
          }
          iVar7 = iVar7 + 1;
          iVar5 = DAT_006de5d0;
          psVar8 = DAT_006de5c4;
        } while (iVar7 < *(short *)(iVar3 + 2));
      }
    }
    uVar2 = DAT_006de5d4 - iVar5;
  }
  iVar3 = 0;
  iVar5 = FUN_0040204f(param_1);
  psVar8 = DAT_006de5c0;
  if (iVar5 != 0) {
    iVar3 = *(int *)(iVar5 + 8) << 0x10;
  }
  for (; psVar8 != DAT_006de5c4; psVar8 = psVar8 + 1) {
    iVar5 = FUN_0040204f(*psVar8);
    if (iVar5 != 0) {
      iVar3 = iVar3 + *(int *)(iVar5 + 8);
    }
  }
  return iVar3;
}

