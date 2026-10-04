
/* WARNING: Removing unreachable block (ram,0x0044cc2a) */

void FUN_0044cb36(int *param_1,int *param_2,undefined4 param_3,int *param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *local_1c;
  short local_18;
  undefined1 local_14 [16];
  
  iVar1 = FUN_004558e0(*param_2,param_3,param_2[1] - *param_2);
  if (iVar1 != -1) {
    iVar6 = param_2[1];
    iVar4 = *param_2;
    iVar5 = param_1[1] - *param_1;
    *param_5 = 0xffffffff;
    iVar6 = (iVar6 - iVar4) + iVar1;
    *param_6 = 0xffffffff;
    if ((iVar6 < iVar5) && (*(char *)(*param_1 + iVar6) == ':')) {
      FUN_0046f824(local_14,0,0x10);
      iVar4 = iVar6;
      while ((iVar6 = iVar4 + 1, iVar6 < iVar5 &&
             (iVar2 = FUN_006368c3((int)*(char *)(*param_1 + iVar6)), iVar2 != 0))) {
        FUN_0046fa24(CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + iVar6)));
        iVar4 = iVar6;
      }
      if (local_18 != 0) {
        uVar3 = FUN_00635f62(local_1c);
        *param_5 = uVar3;
      }
      if ((iVar6 < iVar5) && (*(char *)(*param_1 + iVar6) == ':')) {
        iVar6 = iVar4 + 2;
        *local_1c = 0;
        while ((iVar6 < iVar5 &&
               (iVar4 = FUN_006368c3((int)*(char *)(*param_1 + iVar6)), iVar4 != 0))) {
          FUN_0046fa24(CONCAT31((int3)((uint)*param_1 >> 8),*(undefined1 *)(*param_1 + iVar6)));
          iVar6 = iVar6 + 1;
        }
      }
    }
    *param_4 = iVar6 - iVar1;
  }
  return;
}

