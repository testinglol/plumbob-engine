
undefined4 __fastcall FUN_005c73b0(undefined4 param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  undefined2 uVar5;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar6;
  undefined4 *unaff_FS_OFFSET;
  int local_88;
  uint local_84;
  undefined1 local_80 [4];
  uint local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_64 [22];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_006614e3;
  *unaff_FS_OFFSET = &local_c;
  fVar1 = param_2[3];
  fVar2 = *param_2;
  uVar5 = (undefined2)((uint)local_c >> 0x10);
  uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                         (ushort)(fVar1 == fVar2) << 0xe);
  if (fVar1 >= fVar2) {
    fVar1 = param_2[4];
    fVar2 = param_2[1];
    uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 >= fVar2) {
      fVar1 = param_2[5];
      fVar2 = param_2[2];
      uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                             | (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 >= fVar2) {
        FUN_0059a42e(&local_88);
        local_4 = 0;
        FUN_005c7260(local_80);
        local_4 = CONCAT31(local_4._1_3_,1);
        if (local_84 != local_7c) {
          puVar6 = local_64;
          do {
            uVar4 = *(undefined4 *)(local_88 + (local_84 & 1) * 0xc);
            local_74 = *(undefined4 *)(local_88 + 4 + (local_84 >> 1 & 1) * 0xc);
            uVar3 = local_84 >> 2;
            local_84 = local_84 + 1;
            local_70 = *(undefined4 *)(local_88 + 8 + (uVar3 & 1) * 0xc);
            puVar6[-1] = local_74;
            puVar6[-2] = uVar4;
            *puVar6 = local_70;
            puVar6 = puVar6 + 3;
          } while (local_84 != local_7c);
        }
        uVar4 = FUN_005c74c0(8,0xc);
        *unaff_FS_OFFSET = local_c;
        return uVar4;
      }
    }
  }
  *unaff_FS_OFFSET = local_c;
  return uVar4;
}

