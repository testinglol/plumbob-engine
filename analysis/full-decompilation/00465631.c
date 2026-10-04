
void FUN_00465631(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  uint local_8;
  
  piVar3 = param_1;
  param_1 = (int *)(param_1[1] - *param_1 >> 2);
  FUN_00464a5e(&param_1,1);
  uVar4 = piVar3[1] - *piVar3 >> 2;
  if (uVar4 < param_1) {
    local_8 = 0;
    FUN_004657c3(piVar3[1],(int)param_1 - uVar4,&local_8);
  }
  while (iVar1 = piVar3[1], param_1 < (uint)(iVar1 - *piVar3 >> 2)) {
    iVar2 = *(int *)(iVar1 + -4);
    if (iVar2 != 0) {
      FUN_005481b6();
      FUN_006321f0(iVar2);
    }
    FUN_0052ea87(iVar1 + -4,iVar1);
  }
  piVar6 = (int *)*piVar3;
  do {
    if (piVar6 == (int *)piVar3[1]) {
      return;
    }
    local_8 = (uint)(*piVar6 != 0);
    FUN_00464a4e(&local_8,1);
    if (local_8 == 0) {
      iVar1 = *piVar6;
      if (iVar1 != 0) {
        FUN_005481b6();
        FUN_006321f0(iVar1);
        *piVar6 = 0;
        goto LAB_00465712;
      }
    }
    else {
      if (*piVar6 == 0) {
        puVar5 = operator_new(0x10);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          *puVar5 = 0;
          puVar5[1] = 0;
          puVar5[2] = 0;
          puVar5[3] = 0;
        }
        *piVar6 = (int)puVar5;
LAB_00465712:
        if (local_8 == 0) goto LAB_0046573d;
      }
      iVar1 = *piVar6;
      if (0 < param_3) {
        FUN_00464a5e(iVar1 + 0xc,1);
      }
      FUN_0046574a(iVar1,param_2,param_3);
    }
LAB_0046573d:
    piVar6 = piVar6 + 1;
  } while( true );
}

