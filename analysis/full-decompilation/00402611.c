
ushort * __thiscall FUN_00402611(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  undefined **local_224 [3];
  undefined1 local_218 [260];
  undefined **local_114 [3];
  undefined1 local_108 [260];
  
  piVar2 = (int *)(**(code **)*param_1)(param_2);
  FUN_0046f824(local_108,0,0x104);
  local_114[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_218,0,0x104);
  local_224[0] = &PTR_FUN_006664e8;
  (**(code **)(*piVar2 + 0x24))(local_114);
  FUN_0041218d(local_114,local_224);
  iVar3 = (**(code **)(*piVar2 + 0x38))(0x42484156,param_2,0);
  puVar5 = (ushort *)0x0;
  if (iVar3 != 0) {
    sVar1 = FUN_004200a5(iVar3);
    if (sVar1 == 0) {
      FUN_00420048(iVar3);
    }
    iVar4 = FUN_00420048(iVar3);
    puVar5 = (ushort *)FUN_0042004f(iVar3);
    iVar6 = 0;
    iVar3 = DAT_006de708;
    if (0 < *(short *)(iVar4 + 2)) {
      puVar5 = (ushort *)(iVar4 + 0xc);
      do {
        *puVar5 = *puVar5 & 0x7fff;
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 6;
        iVar3 = DAT_006de708;
      } while (iVar6 < *(short *)(iVar4 + 2));
    }
    while (iVar3 != DAT_006de70c) {
      puVar5 = (ushort *)FUN_0046f973(local_224);
      if (puVar5 == (ushort *)0x0) {
        puVar5 = (ushort *)(int)(short)param_2;
        if (*(ushort **)(iVar3 + 0x4c) != puVar5) goto LAB_00402728;
        iVar6 = *(int *)(iVar3 + 0x50);
        if ((-1 < iVar6) && (iVar6 < *(short *)(iVar4 + 2))) {
          iVar6 = iVar6 * 3 + 3;
          puVar5 = (ushort *)(iVar4 + iVar6 * 4);
          *puVar5 = *puVar5 | 0x8000;
          puVar5 = (ushort *)(iVar4 + iVar6 * 4);
          goto LAB_00402728;
        }
        puVar5 = (ushort *)FUN_004029b7(iVar3);
        iVar3 = DAT_006de708;
      }
      else {
LAB_00402728:
        iVar3 = iVar3 + 0x54;
      }
    }
  }
  return puVar5;
}

