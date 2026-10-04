
undefined4 __fastcall FUN_005c7280(undefined4 param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  undefined2 uVar4;
  undefined4 uVar3;
  undefined4 *puVar5;
  int local_94;
  uint local_90;
  undefined1 local_8c [4];
  uint local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_64 [22];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_006614c6;
  local_c = ExceptionList;
  fVar1 = param_2[3];
  fVar2 = *param_2;
  uVar4 = (undefined2)((uint)ExceptionList >> 0x10);
  uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                         (ushort)(fVar1 == fVar2) << 0xe);
  if (fVar1 >= fVar2) {
    fVar1 = param_2[4];
    fVar2 = param_2[1];
    uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 >= fVar2) {
      fVar1 = param_2[5];
      fVar2 = param_2[2];
      uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                             | (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 >= fVar2) {
        ExceptionList = &local_c;
        FUN_0059a42e(&local_94);
        local_4 = 0;
        FUN_005c7260(local_8c);
        local_4 = CONCAT31(local_4._1_3_,1);
        if (local_90 != local_88) {
          puVar5 = local_64;
          do {
            local_84 = *(undefined4 *)(local_94 + (local_90 & 1) * 0xc);
            local_80 = *(undefined4 *)(local_94 + 4 + (local_90 >> 1 & 1) * 0xc);
            local_7c = *(undefined4 *)(local_94 + 8 + (local_90 >> 2 & 1) * 0xc);
            FUN_005c4390(&local_78);
            puVar5[-1] = local_74;
            puVar5[-2] = local_78;
            *puVar5 = local_70;
            local_90 = local_90 + 1;
            puVar5 = puVar5 + 3;
          } while (local_90 != local_88);
        }
        uVar3 = FUN_005c74c0(8,0xc);
      }
    }
  }
  ExceptionList = local_c;
  return uVar3;
}

