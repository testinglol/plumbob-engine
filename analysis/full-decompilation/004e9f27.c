
void FUN_004e9f27(int param_1,int *param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  bool bVar8;
  undefined1 local_24 [5];
  char local_1f;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  FUN_004071be(*param_2,param_2[1]);
  if ((((param_1 != -1) && (-1 < param_1)) && (param_1 < (DAT_006f264c - DAT_006f2648) / 0x44)) &&
     (local_10 = FUN_004ea2ce(param_1), local_10 != 0)) {
    local_14 = *(undefined4 *)(DAT_006e486c + 0x24);
    local_c = FUN_00425b5f(0);
    sVar2 = (short)local_c;
    while (sVar2 != 0) {
      iVar3 = FUN_0042573e((int)(short)local_c);
      if (iVar3 != 0) {
        uVar4 = FUN_0045741b();
        local_8 = FUN_004e988f(uVar4);
        if ((((local_8 != -1) && (iVar3 != local_10)) &&
            ((cVar1 = FUN_00423f63(), cVar1 != '\0' ||
             (iVar5 = FUN_004ea79e(local_8), *(short *)(iVar5 + 0x40) == 6)))) &&
           (((iVar5 = FUN_004ea79e(local_8), *(short *)(iVar5 + 0x7a) != 0 ||
             (iVar5 = FUN_004ea79e(local_8), *(short *)(iVar5 + 0x40) == 6)) &&
            (iVar5 = local_8, local_8 != -1)))) {
          iVar6 = FUN_004ea2ce(param_1);
          psVar7 = (short *)FUN_004ea2ce(iVar5);
          if (((iVar6 != 0) && (psVar7 != (short *)0x0)) &&
             (iVar5 = FUN_00465062((int)*psVar7), 0 < iVar5)) {
            if (param_3 == 0) {
              bVar8 = *(short *)(local_10 + 0xee) == *(short *)(iVar3 + 0xee);
LAB_004ea09c:
              if (!bVar8) goto LAB_004ea0ad;
            }
            else {
              if (param_3 == 1) {
                FUN_004ea17e(param_1,local_8,local_24);
                bVar8 = local_1f == '\x01';
                goto LAB_004ea09c;
              }
              if ((param_3 == 2) && (iVar3 = FUN_004ea79e(local_8), *(short *)(iVar3 + 0xa2) == 0))
              goto LAB_004ea0ad;
            }
            FUN_0042eab4(&local_8);
          }
        }
      }
LAB_004ea0ad:
      local_c = FUN_00425b5f(local_c);
      sVar2 = (short)local_c;
    }
    if (1 < (uint)(param_2[1] - *param_2 >> 2)) {
      FUN_004eb52d(*param_2,param_2[1],FUN_004ea0e9);
    }
  }
  return;
}

