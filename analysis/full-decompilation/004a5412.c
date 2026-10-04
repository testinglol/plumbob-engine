
int FUN_004a5412(int param_1,int param_2,undefined4 param_3,int param_4,int *param_5,char param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int *piVar8;
  int local_8;
  
  iVar2 = FUN_0049e977(param_3,param_4);
  param_4 = 0;
  if (0 < param_2) {
    puVar4 = (undefined2 *)(param_1 + 4);
    do {
      uVar3 = FUN_0049cdb0((float)param_4 / (float)param_2);
      uVar1 = FUN_004a44f7(uVar3);
      puVar6 = puVar4 + -2;
      *puVar6 = uVar1;
      puVar4[-1] = uVar1;
      *puVar4 = uVar1;
      puVar4[1] = uVar1;
      if (param_5 != (int *)0x0) {
        local_8 = 4;
        piVar8 = param_5;
        do {
          if (*piVar8 != 0) {
            uVar3 = FUN_0049cdb0((float)(param_4 - *piVar8) / (float)param_2);
            uVar1 = FUN_004a44f7(uVar3);
            *puVar6 = uVar1;
          }
          piVar8 = piVar8 + 1;
          puVar6 = puVar6 + 1;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      iVar2 = param_4 + 1;
      puVar4 = puVar4 + 4;
      param_4 = iVar2;
    } while (iVar2 < param_2);
  }
  if ((param_6 != '\0') && (iVar7 = 0, 0 < param_2)) {
    puVar4 = (undefined2 *)(param_1 + 4);
    do {
      iVar2 = iVar7 / 4;
      iVar5 = iVar7 % 4;
      if (0 < iVar5) {
        do {
          uVar1 = puVar4[-2];
          iVar2 = CONCAT22((short)((uint)iVar2 >> 0x10),uVar1);
          puVar4[-2] = puVar4[-1];
          puVar4[-1] = *puVar4;
          *puVar4 = puVar4[1];
          iVar5 = iVar5 + -1;
          puVar4[1] = uVar1;
        } while (iVar5 != 0);
      }
      iVar7 = iVar7 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar7 < param_2);
  }
  return iVar2;
}

