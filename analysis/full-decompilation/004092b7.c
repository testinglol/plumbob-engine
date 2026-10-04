
int FUN_004092b7(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  undefined **local_58 [3];
  undefined1 local_4c [64];
  int local_c [2];
  
  if (DAT_006e4850 == DAT_006e4854) {
    thunk_FUN_005847fc();
    FUN_00580a92(local_c);
    uVar2 = DAT_006c0f86;
    while (DAT_006c0f86 = uVar2, local_c[0] != 0) {
      pcVar1 = *(char **)(local_c[0] + 8);
      iVar3 = *(int *)(local_c[0] + 0xc) - *(int *)(local_c[0] + 8);
      if ((((iVar3 < 5) || (*pcVar1 != DAT_006c0f84)) || (pcVar1[1] != DAT_006c0f85)) ||
         (((pcVar1[2] != (char)uVar2 || (pcVar1[3] != (char)((uint)uVar2 >> 8))) ||
          (DAT_006c0f86._2_1_ = (char)((uint)uVar2 >> 0x10), bVar4 = pcVar1[4] != DAT_006c0f86._2_1_
          , bVar4)))) {
        FUN_0046f824(local_4c,0,0x40);
        local_58[0] = &PTR_FUN_0066651c;
        FUN_0046f847(pcVar1,iVar3);
        FUN_0040f4f6(local_58);
      }
      FUN_0040fe8a();
      uVar2 = DAT_006c0f86;
    }
  }
  return param_1 * 0x4c + DAT_006e4850;
}

